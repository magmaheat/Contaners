#include "../include/s21_set.h"
#include "../include/s21_map.h"
#include "../include/s21_multiset.h"
#include <set>
#include <map>
#include <iostream>
#include <string>


int main() {
  s21::map<int, std::string> s21_map = {{1, "hello"}};
  std::map<int, std::string> std_map = {{1, "hello"}};

  s21_map.insert_or_assign(1, "buy-buy");
  auto s21_it = s21_map.begin();
  auto std_it = std_map.insert({1, "buy-buy"}).first;

//  s21_it->first = "all";
  std::cout << s21_it->second << std::endl;
//  std_it->second = "all";
  std::cout << (*std_it).second << std::endl;
//  std_map[3] = "yep";
  std::cout << s21_map.size() << std::endl;
  std::cout << s21_map.at(1) << std::endl;
  std::cout << s21_map.size() << std::endl;


  std::cout << std_map.size() << std::endl;
  std::cout << std_map.at(3) << std::endl;
  std::cout << std_map.size() << std::endl;

return 0;
}