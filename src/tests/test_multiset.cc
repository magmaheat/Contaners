#include <gtest/gtest.h>

#include <map>
#include <set>
#include <vector>

#include "../include/s21_multiset.h"

#include "../s21_containersplus.h"

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

TEST(MultiSetTest, CopyConstructor) {
  s21::multiset<int> myMultiset1 = {1, 2, 3, 4};
   s21::multiset<int> myMultiset2(myMultiset1);

  std::multiset<int> stdMultiset1 = {1, 2, 3, 4};
   std::multiset<int> stdMultiset2(stdMultiset1);

   EXPECT_TRUE(myMultiset2.size() == stdMultiset2.size());
  EXPECT_TRUE(myMultiset1.size() == stdMultiset1.size());
}

TEST(MultiSetTest, CopyConstructor_1) {
   s21::multiset<int> myMultiset1 = {1, 2, 3, 4};
   s21::multiset<int> myMultiset;
   myMultiset = myMultiset1;

   std::multiset<int> stdMultiset1 = {1, 2, 3, 4};
   std::multiset<int> stdMultiset2(stdMultiset1);

   EXPECT_EQ(myMultiset.size(), stdMultiset2.size());
   EXPECT_EQ(myMultiset1.size(), stdMultiset1.size());
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
 std::multiset<int> stdMultiset1 = {10, 1, 100, 0};
 std::multiset<int> stdMultiset2 = {5, 20, 50};

 myMultiset2 = myMultiset1;
 stdMultiset2 = stdMultiset1;

  // Проверяем, что размеры мультисетовов совпадают
  EXPECT_EQ(myMultiset2.size(), stdMultiset2.size());

  EXPECT_TRUE(myMultiset2.contains(1));
  EXPECT_FALSE(myMultiset2.contains(50));

 EXPECT_TRUE(myMultiset2.find(1) != myMultiset1.end());
 EXPECT_FALSE(myMultiset2.find(50) != myMultiset1.end());
}

TEST(MultiSetTest, BeginIterstor_1) {
   s21::multiset<int> myMultiset = {1, 2, 3, 4};
   s21::multiset<int>::iterator it = myMultiset.begin();
   EXPECT_EQ(*it, 1);  // Проверяем, что начальный элемент равен 1
}

 TEST(MultiSetTest, BeginIterstor_2) {
 s21::multiset<int> myMultiset = {1, 2, 3, 4};
 std::multiset<int> stdMultiset = {1, 2, 3, 4};
  EXPECT_TRUE(*myMultiset.begin() == *stdMultiset.begin());
 }

TEST(MultiSetTest, EndIterator_1) {
  s21::multiset<int> myMultiset = {1, 2, 3, 4};
  std::multiset<int> stdMultiset = {1, 2, 3, 4};

  EXPECT_TRUE(*(--myMultiset.end()) == *(--stdMultiset.end()));
}

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

TEST(MultiSetTest, Insert_1) {
   s21::multiset<int> myMultiset;

   auto it1 = myMultiset.insert(5);
   auto it2 = myMultiset.insert(3);
   auto it3 = myMultiset.insert(7);

   EXPECT_EQ(*it1, 5);
   EXPECT_EQ(*it2, 3);
   EXPECT_EQ(*it3, 7);

   EXPECT_EQ(myMultiset.size(), static_cast<size_t>(3));
}

 TEST(MultiSetTest, Insert_2) {
   s21::multiset<double> myMultiset = {5.5, 6.6, 7.7};
   std::multiset<double> stdMultiset = {5.5, 6.6, 7.7};
   s21::multiset<double>::iterator myResult = myMultiset.insert(5.5);
   std::multiset<double>::iterator stdResult = stdMultiset.insert(5.5);
   EXPECT_TRUE(*myResult == *stdResult);
 }

TEST(MultiSetTest, Count_1) {
   s21::multiset<int> myMultiset = {4, 4, 1};
   std::multiset<int> stdMultiset = {4, 4, 1};

   // Проверяем количество вхождений различных элементов
   EXPECT_EQ(myMultiset.count(4), stdMultiset.count(4));
   EXPECT_EQ(myMultiset.count(1), stdMultiset.count(1));
   EXPECT_EQ(myMultiset.count(7), stdMultiset.count(7));
}

TEST(MultisetTest, EqualRange_1) {
  s21::multiset<int> myMultiset = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  std::multiset<int> stdMultiset = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  // Вызываем функцию equal_range для поиска элемента 3
  auto myRange = myMultiset.equal_range(3);
  auto stdRange = stdMultiset.equal_range(3);

  EXPECT_EQ(*myRange.first, *stdRange.first);
  EXPECT_EQ(*myRange.second, *stdRange.second);
}

TEST(MultiSetTest, LowerBound_1) {
  s21::multiset<int> myMultiset;
  std::multiset<int> stdMultiset;
  EXPECT_EQ(myMultiset.lower_bound(42), myMultiset.end());
  EXPECT_EQ(stdMultiset.lower_bound(42), stdMultiset.end());
}

TEST(MultiSetTest, LowerBound_2) {
  s21::multiset<int> myMultiset = {1, 2, 3, 3, 5, 5, 5};
  std::multiset<int> stdMultiset = {1, 2, 3, 3, 5, 5, 5};
  EXPECT_EQ(*myMultiset.lower_bound(2), 2);
  EXPECT_EQ(*stdMultiset.lower_bound(2), 2);
  EXPECT_EQ(*myMultiset.lower_bound(4), 5);
  EXPECT_EQ(*stdMultiset.lower_bound(4), 5);

  auto myIt = myMultiset.lower_bound(6);
  auto stdIt = stdMultiset.lower_bound(6);
  EXPECT_EQ(myIt, myMultiset.end());
  EXPECT_EQ(stdIt, stdMultiset.end());
}

 TEST(MultiSetTest, LowerBound_3) {
   s21::multiset<int> myMultiset = {2, 2, 5, 6, 7};
   std::multiset<int> stdMultiset = {2, 2, 5, 6, 7};
   auto myResult = myMultiset.lower_bound(2);
   auto stdResult = stdMultiset.lower_bound(2);
   EXPECT_TRUE(*(++(++myResult)) == *(++(++stdResult)));
 }

 TEST(MultiSetTest, LowerBound_4) {
   s21::multiset<int> myMultiset = {2, 2, 5, 6, 7};
   std::multiset<int> stdMultiset = {2, 2, 5, 6, 7};
   auto myResult = myMultiset.lower_bound(2);
   auto stdResult = stdMultiset.lower_bound(2);
   EXPECT_TRUE(*(++(++myResult)) == *(++(++stdResult)));
 }

TEST(MultiSetTest, UpperBound_1) {
  s21::multiset<int> myMultiset;
  std::multiset<int> stdMultiset;

   EXPECT_EQ(myMultiset.upper_bound(42), myMultiset.end());
  EXPECT_EQ(stdMultiset.upper_bound(42), stdMultiset.end());
}

TEST(MultiSetTest, UpperBound_2) {
   s21::multiset<int> myMultiset = {1, 2, 3, 3, 5, 5, 5};
   std::multiset<int> stdMultiset = {1, 2, 3, 3, 5, 5, 5};
   EXPECT_EQ(*myMultiset.upper_bound(2), 3);
   EXPECT_EQ(*stdMultiset.upper_bound(2), 3);
   EXPECT_EQ(*myMultiset.upper_bound(3), 5);
   EXPECT_EQ(*stdMultiset.upper_bound(3), 5);
   EXPECT_EQ(myMultiset.upper_bound(6), myMultiset.end());
   EXPECT_EQ(stdMultiset.upper_bound(6), stdMultiset.end());
 }

TEST(MultiSetTest, Size) {
  s21::multiset<int> myMultiset;
  std::multiset<int> stdMultiset;
  s21::multiset<int> myMultiset1 = {};
  std::multiset<int> stdMultiset1 = {};
  s21::multiset<int> myMultiset2 = {4, 4, 1};
  std::multiset<int> stdMultiset2 = {4, 4, 1};

  EXPECT_EQ(myMultiset.size(), static_cast<size_t>(0));
  EXPECT_TRUE(myMultiset.size() == stdMultiset.size());
  EXPECT_EQ(myMultiset1.size(), static_cast<size_t>(0));
  EXPECT_TRUE(myMultiset1.size() == stdMultiset1.size());
  EXPECT_EQ(myMultiset2.size(), static_cast<size_t>(3));
  EXPECT_TRUE(myMultiset2.size() == stdMultiset2.size());
}

TEST(MultiSetTest, MaxSize) {
  s21::multiset<int> myMultiset;
  std::multiset<int> stdMultiset;
  s21::multiset<int> myMultiset1 = {};
  std::multiset<int> stdMultiset1 = {};
  s21::multiset<int> myMultiset2 = {4, 4, 1};
  std::multiset<int> stdMultiset2 = {4, 4, 1};

  EXPECT_EQ(myMultiset.max_size(), static_cast<size_t>(0));
  EXPECT_TRUE(myMultiset.max_size() == stdMultiset.max_size());
  EXPECT_EQ(myMultiset1.max_size(), static_cast<size_t>(0));
  EXPECT_TRUE(myMultiset1.max_size() == stdMultiset1.max_size());
  EXPECT_EQ(myMultiset2.max_size(), static_cast<size_t>(3));
  EXPECT_TRUE(myMultiset2.max_size() == stdMultiset2.max_size());
}


TEST(MultiSetTest, ContainsOperator) {
 s21::multiset<int> myMultiset1 = {10, 1, 100, 0};
 s21::multiset<int> myMultiset2;

 EXPECT_TRUE(myMultiset1.contains(1));
 EXPECT_FALSE(myMultiset1.contains(50));
 EXPECT_FALSE(myMultiset2.contains(100));
}

TEST(MultiSetTest, ClearOperator) {
   s21::multiset<int> myMultiset = {1, 2, 3, 3, 5, 5, 5};
   std::multiset<int> stdMultiset = {1, 2, 3, 3, 5, 5, 5};

   myMultiset.clear();
   stdMultiset.clear();

   EXPECT_EQ(myMultiset.size(), stdMultiset.size());
}


TEST(MultiSetTest, EraseOperator) {
   s21::multiset<int> myMultiset = {1, 2, 3, 3, 5, 5, 5};
   std::multiset<int> stdMultiset = {1, 2, 3, 3, 5, 5, 5};

   auto myIt = myMultiset.find(3);
   if (myIt != myMultiset.end()) {
       myMultiset.erase(myIt);
   }

   auto stdIt = stdMultiset.find(3);
   if (stdIt != stdMultiset.end()) {
       stdMultiset.erase(stdIt);
   }

   EXPECT_EQ(myMultiset.size(), stdMultiset.size());
}

TEST(MultiSetTest, SwapOperator) {

 s21::multiset<int> myMultiset1 = {10, 1, 100, 0};
 s21::multiset<int> myMultiset2 = {5, 20, 50};
 std::multiset<int> stdMultiset1 = {10, 1, 100, 0};
 std::multiset<int> stdMultiset2 = {5, 20, 50};

 myMultiset1.swap(myMultiset2);
 stdMultiset1.swap(stdMultiset2);

 EXPECT_EQ(myMultiset1.size(), stdMultiset1.size());
}

TEST(MultiSetTest, MergeOperator) {

 s21::multiset<int> myMultiset1 = {10, 1, 100, 0};
 s21::multiset<int> myMultiset2 = {5, 20, 50};
 std::multiset<int> stdMultiset1 = {10, 1, 100, 0};
 std::multiset<int> stdMultiset2 = {5, 20, 50};

 myMultiset1.merge(myMultiset2);
 stdMultiset1.merge(stdMultiset2);

 EXPECT_EQ(myMultiset1.size(), stdMultiset1.size());
 EXPECT_EQ(myMultiset2.size(), static_cast<size_t>(0));

 EXPECT_TRUE(myMultiset1.find(1) != myMultiset1.end());
 EXPECT_TRUE(myMultiset1.find(50) != myMultiset1.end());
}

TEST(MultiSetTest, FindOperator) {
   s21::multiset<int> myMultiset = {1, 2, 3, 3, 5, 5, 5};
   std::multiset<int> stdMultiset = {1, 2, 3, 3, 5, 5, 5};
   s21::multiset<int> myMultiset2;
   std::multiset<int> stdMultiset2;

   auto myIt = myMultiset.find(3);
   auto stdIt = stdMultiset.find(3);

   EXPECT_TRUE(*myIt == 3);
   EXPECT_TRUE(*stdIt == 3);
   EXPECT_FALSE(*myIt == 10);
   EXPECT_FALSE(*stdIt == 10);

   auto myIt2 = myMultiset2.find(2);
   auto stdIt2 = stdMultiset2.find(2);
   EXPECT_FALSE(*myIt2 == 2);
   EXPECT_FALSE(*stdIt2 == 2);
}

// TEST(MultiSetTest, InsertMany) {
//   s21::multiset<int> myMultiset = {10, 1, 100, 66};

//   myMultiset.insert_many(1, 2, 3);

//   EXPECT_EQ(myMultiset.size(), static_cast<size_t>(7));
// }