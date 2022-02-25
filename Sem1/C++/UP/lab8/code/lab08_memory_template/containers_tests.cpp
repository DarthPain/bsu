#include "containers.h"

#include "gtest.h"
#include "gmock.h"

namespace containers {

TEST(List_BaseOps, Sample) {
  BiDirectionalList<int> list;
  ASSERT_EQ(list.Size(), 0);
  ASSERT_TRUE(list.IsEmpty());

  list.PushBack(11);

  ASSERT_EQ(list.Size(), 1);
  ASSERT_FALSE(list.IsEmpty());
  ASSERT_EQ(list.Front()->value, 11);
  ASSERT_EQ(list.Back()->value, 11);

  list.PushBack(2222);

  ASSERT_EQ(list.Size(), 2);
  ASSERT_FALSE(list.IsEmpty());
  ASSERT_EQ(list.Front()->value, 11);
  ASSERT_EQ(list.Back()->value, 2222);

  list.PushFront(333333);

  ASSERT_EQ(list.Size(), 3);
  ASSERT_FALSE(list.IsEmpty());
  ASSERT_EQ(list.Front()->value, 333333);
  ASSERT_EQ(list.Back()->value, 2222);

  ASSERT_THAT(list.ToVector(), testing::ElementsAre(333333, 11, 2222));

  list.PopFront();

  ASSERT_EQ(list.Size(), 2);
  ASSERT_FALSE(list.IsEmpty());
  ASSERT_EQ(list.Front()->value, 11);
  ASSERT_EQ(list.Back()->value, 2222);

  list.PopBack();

  ASSERT_EQ(list.Size(), 1);
  ASSERT_FALSE(list.IsEmpty());
  ASSERT_EQ(list.Front()->value, 11);
  ASSERT_EQ(list.Back()->value, 11);

  list.PopFront();

  ASSERT_EQ(list.Size(), 0);
  ASSERT_TRUE(list.IsEmpty());

  ASSERT_THAT(list.ToVector(), testing::ElementsAre());
}

TEST(List_IndexOps, Sample) {
  BiDirectionalList<int> list;

  std::vector<int> values = {11, 2222, 333333, 333333, 2222, 333333};
  for (int value : values) {
    list.PushBack(value);
  }

  ASSERT_EQ(list.Find(11), 0);
  ASSERT_EQ(list.Find(2222), 1);
  ASSERT_EQ(list.Find(333333), 2);
  ASSERT_EQ(list.Find(1234567), -1);

  ASSERT_THAT(list.FindAll(11), testing::ElementsAre(0));
  ASSERT_THAT(list.FindAll(2222), testing::ElementsAre(1, 4));
  ASSERT_THAT(list.FindAll(333333), testing::ElementsAre(2, 3, 5));
  ASSERT_THAT(list.FindAll(1234567), testing::ElementsAre());

  for (int i = 0; i < values.size(); ++i) {
    ASSERT_EQ(list[i]->value, values[i]);
  }
}

TEST(List_InsertErase, Sample) {
  BiDirectionalList<int> list;
  list.PushBack(11);
  list.PushBack(22);

  list.InsertAfter(list[0], 33);
  ASSERT_EQ(list.Size(), 3);
  ASSERT_EQ(list[1]->value, 33);

  list.InsertBefore(list[1], 44);
  ASSERT_EQ(list.Size(), 4);
  ASSERT_EQ(list[1]->value, 44);

  list.Erase(list[1]);
  ASSERT_EQ(list.Size(), 3);
  ASSERT_EQ(list[1]->value, 33);
}

TEST(List_Misc, Sample) {
  BiDirectionalList<int> list1({1, 2, 3, 4});
  BiDirectionalList<int> list2({1, 2, 3, 4});
  BiDirectionalList<int> list3({-11, 22});
  ASSERT_EQ(list1, list2);
  ASSERT_NE(list1, list3);
}

TEST(Container, Sample_Queue) {
  std::vector<int> input = {1, 2, 3, 4, 5};
  std::vector<int> output;
  if (GetVariant() == Variant::kQueue) {
    output = {1, 2, 3, 4, 5};
  } else {
    output = {5, 4, 3, 2, 1};
  }

  Container<int> container;
  ASSERT_EQ(container.Size(), 0);
  ASSERT_TRUE(container.IsEmpty());

  for (int i = 0; i < input.size(); ++i) {
    container.Push(input[i]);
    ASSERT_EQ(container.Size(), i + 1);
    ASSERT_FALSE(container.IsEmpty());
  }

  for (int i = 0; i < input.size(); ++i) {
    ASSERT_EQ(container.Get(), output[i]);
    container.Pop();
    ASSERT_EQ(container.Size(), output.size() - i - 1);
    ASSERT_EQ(container.IsEmpty(), i == input.size() - 1);
  }
}

}  // namespace containers
