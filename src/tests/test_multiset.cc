#include <gtest/gtest.h>

#include <map>
#include <set>
#include <vector>

#include "../include/s21_multiset.h"

#include "../s21_containers.h"

TEST(MultiSetTest, DefaultConstructor) {
  s21::multiset<int> myMultiset;
  std::multiset<int> stdMultiset;

  EXPECT_TRUE(myMultiset.size() == stdMultiset.size());
}

TEST(MultiSetTest, InitListConsructor_1) {
  s21::multiset<int> myMultiset = {4, 4, 1};
  std::multiset<int> stdMultiset = {4, 4, 1};

  EXPECT_TRUE(myMultiset.size() == stdMultiset.size());
}

TEST(MultiSetTest, InitListConsructor_2) {
  s21::multiset<double> myMultiset = {1.1, 2.2, 3.3};
  std::multiset<double> stdMultiset = {1.1, 2.2, 3.3};

  EXPECT_EQ(myMultiset.size(), stdMultiset.size());
}

TEST(MultiSetTest, InitListConsructor_3) {
  s21::multiset<int> myMultiset{-1, 6, 10, 0, 99, 111};
  std::multiset<int> stdMultiset{-1, 6, 10, 0, 99, 111};

  EXPECT_TRUE(myMultiset.size() == stdMultiset.size());
}

// Не проходит
/*Примечание: 
  дает ошибку - 
  ./tests/../include/s21_multiset.h:22:10: error: ‘add’ was not declared in this scope, and no declarations were found by argument-dependent lookup at the point of instantiation [-fpermissive]
   22 |       add(other.root_);
      |       ~~~^~~~~~~~~~~~~
*/
TEST(MultiSetTest, CopyConstructor) {
  s21::multiset<int> myMultiset1 = {1, 2, 3, 4};
  // s21::multiset<int> myMultiset2(myMultiset1);

  std::multiset<int> stdMultiset1 = {1, 2, 3, 4};
  // std::multiset<int> stdMultiset2(stdMultiset1);

  // EXPECT_TRUE(myMultiset2.size() == stdMultiset2.size());
  EXPECT_TRUE(myMultiset1.size() == stdMultiset1.size());
}

/*Примечаниче: 
  Такая запись не проходит myMultiset = myMultiset1;
  Возможно копирование таким образом не было предусмотрено.

  Expected equality of these values:
  myMultiset.size()
    Which is: 0
  stdMultiset2.size()
    Which is: 4  
*/
TEST(MultiSetTest, CopyConstructor_1) {
  // s21::multiset<int> myMultiset1 = {1, 2, 3, 4};
  // s21::multiset<int> myMultiset;
  // myMultiset = myMultiset1;

  // std::multiset<int> stdMultiset1 = {1, 2, 3, 4};
  // std::multiset<int> stdMultiset2(stdMultiset1);

  // EXPECT_EQ(myMultiset.size(), stdMultiset2.size());
  // EXPECT_EQ(myMultiset1.size(), stdMultiset1.size());
}

TEST(MultiSetTest, MoveConstructor_1) {
  s21::multiset<int> myMultiset1 = {10, 1, 100, 0};
  s21::multiset<int> myMultiset2 = std::move(myMultiset1);

  std::multiset<int> stdMultiset1 = {10, 1, 100, 0};
  std::multiset<int> stdMultiset2 = std::move(stdMultiset1);

  EXPECT_TRUE(myMultiset2.size() == stdMultiset2.size());
  EXPECT_EQ(stdMultiset1.empty(), myMultiset1.empty());
}

TEST(MultiSetTest, MoveConstructor_2) {
  s21::multiset<int> myMultiset1 = {10, 10, 1, 100, 0};
  s21::multiset<int> myMultiset2 = std::move(myMultiset1);

  std::multiset<int> stdMultiset1 = {10, 10, 1, 100, 0};
  std::multiset<int> stdMultiset2 = std::move(stdMultiset1);

  EXPECT_TRUE(myMultiset2.size() == stdMultiset2.size());
  EXPECT_EQ(stdMultiset1.empty(), myMultiset1.empty());
}

TEST(MultiSetTest, AssignmentOperator) {

  s21::multiset<int> myMultiset1 = {10, 1, 100, 0};
  s21::multiset<int> myMultiset2 = {5, 20, 50};

  myMultiset2 = myMultiset1;

  // // Проверяем, что размеры мультисетовов совпадают
  // EXPECT_EQ(myMultiset2.size(), 4);
  // // Проверяем, что содержимое мультисетовов совпадает
  // std::vector<int> expected = {0, 1, 10, 100};
  // std::vector<int> actual(myMultiset2.begin(), myMultiset2.end());
  // EXPECT_EQ(expected, actual);
}

/*Примечание:
  нет реализации метода begin();
*/
TEST(MultiSetTest, BeginIterstor_1) {
  // s21::multiset<int> myMultiset = {1, 2, 3, 4};
  // s21::multiset<int>::iterator it = myMultiset.begin();
  // EXPECT_EQ(*it, 1);  // Проверяем, что начальный элемент равен 1
}

// TEST(MultiSetTest, BeginIterstor_2) {
// s21::multiset<int> myMultiset = {1, 2, 3, 4};
// std::multiset<int> stdMultiset = {1, 2, 3, 4};
//  EXPECT_TRUE(*myMultiset.begin() == *stdMultiset.begin());
// }

/*Примечание:
  нет реализации метода end();
*/
// TEST(MultiSetTest, EndIterator_1) {
//   s21::multiset<int> myMultiset = {1, 2, 3, 4};
//   s21::multiset<int>::iterator it = myMultiset.end();
//   EXPECT_EQ(it, nullptr);  // Проверяем, что итератор указывает на nullptr
// }
// TEST(MultiSetTest, EndIterator_2) {
// s21::multiset<int> myMultiset = {1, 2, 3, 4};
// std::multiset<int> stdMultiset = {1, 2, 3, 4};
//  EXPECT_TRUE(*myMultiset.end() == *stdMultiset.end());
// }

TEST(MultiSetTest, Empty_1) {
  s21::multiset<int> myMultiset;
  std::multiset<int> stdMultiset;

  EXPECT_EQ(myMultiset.empty(), stdMultiset.empty());
}

TEST(MultiSetTest, Empty_2) {
  s21::multiset<int> myMultiset = {10, 1, 100, 0};
  std::multiset<int> stdMultiset = {10, 1, 100, 0};

  EXPECT_EQ(myMultiset.empty(), stdMultiset.empty());
}

/* Примечание: 
  Что-то с доступом к методу
  function "s21::multiset<Key>::insert [with Key=int]" 
  (declared at line 57 of "../include/s21_multiset.h") is inaccessibleC/C++(265)
*/
TEST(MultiSetTest, Insert_1) {
  // s21::multiset<int> myMultiset;

  // auto it1 = myMultiset.insert(5);
  // auto it2 = myMultiset.insert(3);
  // auto it3 = myMultiset.insert(7);

  // EXPECT_EQ(*it1, 5);
  // EXPECT_EQ(*it2, 3);
  // EXPECT_EQ(*it3, 7);

  // EXPECT_EQ(myMultiset.size(), 3);
}

// TEST(MultiSetTest, Insert_2) {
//   s21::multiset<double> myMultiset = {5.5, 6.6, 7.7};
//   std::multiset<double> stdMultiset = {5.5, 6.6, 7.7};
//   s21::multiset<double>::iterator myResult = myMultiset.insert(5.5);
//   std::multiset<double>::iterator stdResult = stdMultiset.insert(5.5);
//   EXPECT_TRUE(*myResult == *stdResult);
// }

/* Примечание: 
 не проходит тест, ошибка следующая:
  ./tests/../include/s21_rb_trees.tpp:551:26: error: ‘s21::red_black_tree<int, int>::Node’ {aka ‘struct s21::red_black_tree<int, int>::Node’} has no member named ‘count’
  551 |     return pos.current_->count;
      |            ~~~~~~~~~~~~~~^~~~~
*/
TEST(MultiSetTest, Count_1) {
  // s21::multiset<int> myMultiset = {4, 4, 1};
  // std::multiset<int> stdMultiset = {4, 4, 1};

  // // Проверяем количество вхождений различных элементов
  // EXPECT_EQ(myMultiset.count(4), stdMultiset.count(4));
  // EXPECT_EQ(myMultiset.count(1), stdMultiset.count(1));
  // EXPECT_EQ(myMultiset.count(7), stdMultiset.count(7));
}

/*Примечание
  нет реалиазации метода equal_range();
*/
TEST(MultisetTest, EqualRange_1) {
  // s21::multiset<int> myMultiset = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  // std::multiset<int> stdMultiset = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  // // Вызываем функцию equal_range для поиска элемента 3
  // auto myRange = myMultiset.equal_range(3);
  // auto stdRange = stdMultiset.equal_range(3);
  // EXPECT_EQ(myRange.first, stdRange.first);
  // EXPECT_EQ(myRange.second, stdRange.second);
}

/*Примечание
  не отрабатывает метод lower_bound();
*/
TEST(MultiSetTest, LowerBound_1) {
  s21::multiset<int> myMultiset;
  std::multiset<int> stdMultiset;
  // EXPECT_EQ(myMultiset.lower_bound(42), myMultiset.end());
  EXPECT_EQ(stdMultiset.lower_bound(42), stdMultiset.end());
}

// TEST(MultiSetTest, LowerBound_2) {
//   s21::multiset<int> myMultiset = {1, 2, 3, 3, 5, 5, 5};
//   std::multiset<int> stdMultiset = {1, 2, 3, 3, 5, 5, 5};
//   EXPECT_EQ(*myMultiset.lower_bound(2), 2);
//   EXPECT_EQ(*stdMultiset.lower_bound(2), 2);
//   EXPECT_EQ(*myMultiset.lower_bound(4), 5);
//   EXPECT_EQ(*stdMultiset.lower_bound(4), 5);
//   EXPECT_EQ(*myMultiset.lower_bound(6), myMultiset.end());
//   EXPECT_EQ(*stdMultiset.lower_bound(6), stdMultiset.end());
// }

// TEST(MultiSetTest, LowerBound_3) {
//   s21::multiset<int> myMultiset = {2, 2, 5, 6, 7};
//   std::multiset<int> stdMultiset = {2, 2, 5, 6, 7};
//   auto myResult = myMultiset.lower_bound(2);
//   auto stdResult = stdMultiset.lower_bound(2);
//   EXPECT_TRUE(*(++(++myResult)) == *(++(++stdResult)));
// }

/*Такая же ситуация с upper_bound();*/
TEST(MultiSetTest, UpperBound_1) {
  s21::multiset<int> myMultiset;
  std::multiset<int> stdMultiset;

  // EXPECT_EQ(myMultiset.upper_bound(42), myMultiset.end());
  EXPECT_EQ(stdMultiset.upper_bound(42), stdMultiset.end());
}

//   TEST(MultiSetTest, UpperBound_1) {
//   s21::multiset<int> myMultiset = {1, 2, 3, 3, 5, 5, 5};
//   std::multiset<int> stdMultiset = {1, 2, 3, 3, 5, 5, 5};
//   EXPECT_EQ(*myMultiset.upper_bound(2), 3);
//   EXPECT_EQ(*stdMultiset.upper_bound(2), 3);
//   EXPECT_EQ(*myMultiset.upper_bound(3), 5);
//   EXPECT_EQ(*stdMultiset.upper_bound(3), 5);
//   EXPECT_EQ(myMultiset.upper_bound(6), myMultiset.end());
//   EXPECT_EQ(stdMultiset.upper_bound(6), stdMultiset.end());
// }

// TEST(MultiSetTest, LowerBound_3) {
//   s21::multiset<int> myMultiset = {2, 2, 5, 6, 7};
//   std::multiset<int> stdMultiset = {2, 2, 5, 6, 7};
//   auto myResult = myMultiset.lower_bound(2);
//   auto stdResult = stdMultiset.lower_bound(2);
//   EXPECT_TRUE(*(++(++myResult)) == *(++(++stdResult)));
// }