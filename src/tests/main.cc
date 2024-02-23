#include <iostream>
#include <map>
#include <set>
#include <string>
#include "../include/s21_map.h"
#include "../include/s21_multiset.h"
#include "../include/s21_set.h"
#include <vector>

int main() {
////  s21::multiset<int> myMultiset = {10, 10, 7, 12, 20, 10, 10};
//  std::multiset<int> stdMultiset = {10, 10, 7, 12, 20, 10, 10};
////myMultiset.display();
//
//  auto it = stdMultiset.begin();
//  it++;

//  std::set<int> std_set;
//
//  for (int i = 0; i < 5000000; i++) {
//    std_set.insert(i);
//  }

  s21::set<int> std_set;

  for (int i = 0; i < 5000000; i++) {
    std_set.insert(i);
  }

  std_set.find(5000000);

//  std::set<int> std_set;
//
//  for (int i = 0; i < 10000; i++) {
//    std_set.insert(i);
//  }
  return 0;
}