#include <iostream>
#include <map>
#include <set>
#include <string>
#include "../include/s21_map.h"
#include "../include/s21_multiset.h"
#include "../include/s21_set.h"

int main() {
  s21::multiset<int> myMultiset1 = {10, 10, 1, 100, 0};
  s21::multiset<int> myMultiset2 = std::move(myMultiset1);

  std::multiset<int> stdMultiset1 = {10, 10, 1, 100, 0};
  std::multiset<int> stdMultiset2 = std::move(stdMultiset1);

//  EXPECT_TRUE(myMultiset2.size() == stdMultiset2.size());
//  EXPECT_EQ(stdMultiset1.empty(), myMultiset1.empty());
  std::cout << myMultiset2.size() << ' ' << stdMultiset2.size() << std::endl;
  return 0;
}