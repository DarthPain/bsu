#include "shared_ptr.h"

#include <vector>

#include "gtest.h"
#include "gmock.h"

namespace {
class Validator {
 public:
  explicit Validator(bool* validity_flag) : validity_flag_(validity_flag) {
    *validity_flag_ = true;
  }
  ~Validator() {
    *validity_flag_ = false;
  }
 private:
  bool* validity_flag_;
};
}  // anonymous namespace

namespace shared_ptr {

TEST(SharedPtr_MemoryMgmt, Sample_RefCounter) {
  bool is_object_valid;
  auto* validator = new Validator(&is_object_valid);
  ASSERT_TRUE(is_object_valid);

  std::vector<SharedPtr<Validator>> pointers;
  pointers.emplace_back(validator);
  ASSERT_TRUE(is_object_valid);

  for (int i = 0; i < 10; ++i) {
    pointers.push_back(pointers.back());
    ASSERT_TRUE(is_object_valid);
  }

  while (pointers.size() > 1) {
    pointers.pop_back();
    ASSERT_TRUE(is_object_valid);
  }

  pointers.pop_back();
  ASSERT_FALSE(is_object_valid);
}

TEST(SharedPtr_MemoryMgmt, Sample_Release) {
  bool is_object_valid;
  auto* validator = new Validator(&is_object_valid);
  ASSERT_TRUE(is_object_valid);

  {
    SharedPtr<Validator> ptr(validator);
    ptr.Release();
    ASSERT_TRUE(is_object_valid);
  }

  ASSERT_TRUE(is_object_valid);
  delete validator;
}

TEST(SharedPtr_Ops, Sample_Basic) {
  SharedPtr<std::vector<int>> shared_ptr(new std::vector<int>(123));

  auto* vector_ptr = shared_ptr.Get();
  ASSERT_EQ(vector_ptr->size(), 123);
  vector_ptr->push_back(123456);
  vector_ptr->push_back(654321);
  ASSERT_EQ(vector_ptr->size(), 125);

  auto& vector_ref = *shared_ptr;
  ASSERT_EQ(vector_ref.size(), 125);
  vector_ref.push_back(123456);
  vector_ref.push_back(654321);
  ASSERT_EQ(vector_ref.size(), 127);

  ASSERT_EQ(shared_ptr->size(), 127);
  shared_ptr->pop_back();
  shared_ptr->pop_back();
  ASSERT_EQ(shared_ptr->size(), 125);
}

TEST(SharedPtr_Ops, Sample_Const) {
  auto* raw_ptr = new std::vector<int>(123);
  const SharedPtr<std::vector<int>> shared_ptr(raw_ptr);

  const auto* vector_ptr = shared_ptr.Get();
  ASSERT_EQ(vector_ptr->size(), 123);
  raw_ptr->push_back(123456);
  raw_ptr->push_back(654321);
  ASSERT_EQ(vector_ptr->size(), 125);

  const auto& vector_ref = *shared_ptr;
  ASSERT_EQ(vector_ref.size(), 125);
  raw_ptr->push_back(123456);
  raw_ptr->push_back(654321);
  ASSERT_EQ(vector_ref.size(), 127);

  ASSERT_EQ(shared_ptr->size(), 127);
  raw_ptr->pop_back();
  raw_ptr->pop_back();
  ASSERT_EQ(shared_ptr->size(), 125);
}

}  // namespace shared_ptr
