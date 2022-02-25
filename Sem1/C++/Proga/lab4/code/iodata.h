//
// Created by Roman on 10/10/2019.
//
#pragma once
#ifndef CLION_IODATA_H
#define CLION_IODATA_H

#endif //CLION_IODATA_H

#include <iostream>
#include <vector>
#include <string>

template<class T>
void readVec(std::vector<T> &t, int n) {
    int f_w = 0;
    std::cout << "\nEnter 1 to fill array from keyboard, 2 - random: ";
    std::cin >> f_w;
    switch (f_w) {
        case 1:
            double tmp;
            for (int i = 0; i < n; ++i) {
                std::cin >> tmp;
                t.push_back(tmp);
            }
            break;
        case 2:
            for (int i = 0; i < n; ++i) {
                t.push_back(rand() % 200 - 100);
            }
            break;
        default:
            std::cout << "Wrong!";
    }
    std::cout << std::endl;
}

template<class T>
void print(T &t) {
    std::cout << "Output data is " << t << std::endl;
}

template<class T>
void print(std::vector<T> t) {
    for (int i = 0; i < t.size() - 1; ++i) {
        std::cout << t.at(i) << ", ";
    }
    std::cout << t.at(t.size() - 1) << std::endl;
}

