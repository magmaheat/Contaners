#include <iostream>
#include <map>
#include <set>
#include <string>
#include "../include/s21_map.h"
#include "../include/s21_multiset.h"
#include "../include/s21_set.h"
#include <vector>

int main() {
  s21::set<int> set21;
  s21::set<int> set_temp = {2, 3 , 4, 5};

  std::vector<std::pair<s21::set<int>::iterator , bool>> vec = set21.insert_many(*(set_temp.find(3)), *(set_temp.find(5)));
  std::cout << *vec[0].first << std::endl;
//  myMap.display();
  return 0;
}