#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../include/s21_array.h"
#include "../include/s21_map.h"
#include "../include/s21_multiset.h"
#include "../include/s21_set.h"

int main() {

  std::multiset<std::string> stdMultiset2;
  std::multiset<long int> ints;

  std::cout << stdMultiset2.max_size() << std::endl;
  std::cout << ints.max_size() << std::endl;
}