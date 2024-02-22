#include "../include/s21_set.h"
#include "../include/s21_map.h"
#include "../include/s21_multiset.h"
#include <set>
#include <map>
#include <iostream>
#include <string>


int main() {
  s21::set<int> s21_set = {2, 4, 6};

  s21_set.erase(s21_set.begin());

return 0;
}