#include <iostream>
#include <map>
#include <set>
#include <string>
#include "../include/s21_map.h"
#include "../include/s21_multiset.h"
#include "../include/s21_set.h"
#include "../include/s21_array.h"
#include <vector>

int main() {
  s21::set<double> s21_set = {1.1, 2.2};
  s21::set<double> s21_set2 = {3.3, 4.4};
  std::set<double> std_set = {1.1, 2.2};
  std::set<double> std_set2 = {3.3, 4.4};

  s21_set.merge(s21_set2);
  std_set.merge(std_set2);
    std::cout << s21_set.size() << ' ' <<  std_set.size() << std::endl;

  std_set.clear();
  s21_set.clear();

  std::cout << s21_set.size() << ' ' <<  std_set.size() << std::endl;
  std::cout << s21_set2.size() << ' ' <<  std_set2.size() << std::endl;

}