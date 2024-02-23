#include <iostream>
#include <map>
#include <set>
#include <string>
#include "../include/s21_map.h"
#include "../include/s21_multiset.h"
#include "../include/s21_set.h"

int main() {
  s21::multiset<int> myMultiset = {2, 2, 5, 6, 7};
  std::multiset<int> stdMultiset = {2, 2, 5, 6, 7};
  auto myResult = myMultiset.lower_bound(2);
  auto stdResult = stdMultiset.lower_bound(2);
  std::cout << *(++(++myResult)) << ' ' << *(++(++stdResult)) << std::endl;

  return 0;
}