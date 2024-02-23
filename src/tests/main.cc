#include <iostream>
#include <map>
#include <set>
#include <string>
#include "../include/s21_map.h"
#include "../include/s21_multiset.h"
#include "../include/s21_set.h"
#include <vector>

int main() {
  s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};

  myMap.insert_or_assign(1, '@');
  stdMap.insert_or_assign(1, '@');

  std::cout << (*myMap.begin()).second << std::endl;
  std::cout << myMap.size() << std::endl;
//  myMap.display();
  return 0;
}