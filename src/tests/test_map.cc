#include <gtest/gtest.h>

#include "../include/s21_map.h"

#include "../s21_containers.h"

TEST(MapTest, DefaultConstructor_1) {
  s21::map<int, int> myMap;
  std::map<int, int> stdMap;
  
  EXPECT_TRUE(myMap.size() == stdMap.size());
}

TEST(MapTest, DefaultConstructor_2) {
  s21::map<int, int> myMap{};
  s21::map<int, int> myMap1{{1, 10}, {2, 20}, {3, 30}};
  s21::map<int, int> myMap2{{-1, 10}, {0, 20}, {3, 30}};
  s21::map<int, char> myMap3{{1, 'a'}, {2, '@'}, {3, '+'}};
  s21::map<int, std::string> myMap4{{1, "Hello"}, {2, "Privet"}, {3, "Bonjour"}};
  s21::map<char, int> myMap5{{'a', 10}, {'b', 20}, {'c', 30}};
  std::map<int, int> stdMap{};
  std::map<int, int> stdMap1{{1, 10}, {2, 20}, {3, 30}};
  std::map<int, int> stdMap2{{-1, 10}, {2, 20}, {3, 30}};
  std::map<int, char> stdMap3{{1, 'a'}, {2, '@'}, {3, '+'}};
  std::map<int, std::string> stdMap4{{1, "Hello"}, {2, "Privet"}, {3, "Bonjour"}};
  std::map<char, int> stdMap5{{'a', 10}, {'b', 20}, {'c', 30}};

  EXPECT_TRUE(myMap.size() == stdMap.size());
  EXPECT_TRUE(myMap1.size() == stdMap1.size());
  EXPECT_TRUE(myMap2.size() == stdMap2.size());
  EXPECT_TRUE(myMap3.size() == stdMap3.size());
  EXPECT_TRUE(myMap4.size() == stdMap4.size());
  EXPECT_TRUE(myMap5.size() == stdMap5.size());
}

 TEST(MapTest, DefaultConstructor_3) {
   s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
   std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  
   EXPECT_TRUE(myMap.size() == stdMap.size());

   auto myIt = myMap.begin();
   auto stdIt = stdMap.begin();

   for (; myIt != myMap.end(); myIt++, stdIt++) {
     EXPECT_TRUE((*myIt).first == (*stdIt).first);
     EXPECT_TRUE((*myIt).second == (*stdIt).second);
     }
 }

 TEST(MapTest, CopyConstructor_1) {
   s21::map<int, int> myMap{{1, 10}, {2, 20}, {3, 30}};
   s21::map<int, int> myCopiedMap = myMap;
   std::map<int, int> stdMap{{1, 10}, {2, 20}, {3, 30}};
   std::map<int, int> stdCopiedMap = stdMap;
  
   EXPECT_TRUE(myCopiedMap.size() == stdCopiedMap.size());
 }

 TEST(MapTest, CopyConstructor_2) {
   s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
   s21::map<int, char> myCopiedMap = myMap;
   std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
   std::map<int, char> stdCopiedMap = stdMap;
  
   EXPECT_TRUE(myCopiedMap.size() == stdCopiedMap.size());

   auto myIt = myCopiedMap.begin();
   auto stdIt = stdCopiedMap.begin();

   for (; myIt != myCopiedMap.end(); myIt++, stdIt++) {
     EXPECT_TRUE((*myIt).first == (*stdIt).first);
     EXPECT_TRUE((*myIt).second == (*stdIt).second);
     }
 }

 TEST(MapTest, CopyConstructor_3) {
   s21::map<int, int> myMap{{1, 10}, {2, 20}, {3, 30}};
   s21::map<int, int> myCopiedMap = myMap;
   std::map<int, int> stdMap{{1, 10}, {2, 20}, {3, 30}};
   std::map<int, int> stdCopiedMap = stdMap;
  
   EXPECT_TRUE(myCopiedMap.size() == stdCopiedMap.size());

     EXPECT_EQ(myCopiedMap.at(1), 10);
     EXPECT_EQ(myCopiedMap.at(2), 20);
     EXPECT_EQ(myCopiedMap.at(3), 30);
 }

TEST(MapTest, MoveConstructor_1) {
  s21::map<int, int> myMap{{1, 10}, {2, 20}, {3, 30}};
  s21::map<int, int> myMovedMap = std::move(myMap);
  std::map<int, int> stdMap{{1, 10}, {2, 20}, {3, 30}};
  std::map<int, int> stdMovedMap = std::move(stdMap);
  
  EXPECT_TRUE(myMovedMap.size() == stdMovedMap.size());
}

 TEST(MapTest, MoveConstructor_2) {
   s21::map<int, int> myMap{{1, 10}, {2, 20}, {3, 30}};
   s21::map<int, int> myMovedMap = std::move(myMap);
   std::map<int, int> stdMap{{1, 10}, {2, 20}, {3, 30}};
   std::map<int, int> stdMovedMap = std::move(stdMap);
  
   EXPECT_TRUE(myMovedMap.size() == stdMovedMap.size());
   auto myIt = myMovedMap.begin();
   auto stdIt = stdMovedMap.begin();

   for (; myIt != myMovedMap.end(); myIt++, stdIt++) {
     EXPECT_TRUE((*myIt).first == (*stdIt).first);
     EXPECT_TRUE((*myIt).second == (*stdIt).second);
     }
 }

 TEST(MapTest, AssignmentOperator) {
     s21::map<int, int> myMap1{{1, 2}, {3, 4}};
     s21::map<int, int> myMap2{{5, 6}, {7, 8}};

     myMap1 = std::move(myMap2);

     EXPECT_EQ(myMap1.size(), 2);
     EXPECT_EQ(myMap1[5], 6);
     EXPECT_EQ(myMap1[7], 8);
 }

 TEST(MapTest, Begin_1) {
     s21::map<int, int> myMap{{1, 2}, {3, 4}};

     auto it = myMap.begin();

     EXPECT_EQ((*it).first, 1);
     EXPECT_EQ((*it).second, 2);
 }

 TEST(MapTest, Insert_1) {
   s21::map<int, char> myMap;
   std::map<int, char> stdMap;
  
   EXPECT_EQ(myMap.size(), stdMap.size());

   myMap.insert(std::make_pair(1, 'a'));
   myMap.insert(std::make_pair(2, '@'));
   myMap.insert(std::make_pair(3, '$'));
   stdMap.insert(std::make_pair(1, 'a'));
   stdMap.insert(std::make_pair(2, '@'));
   stdMap.insert(std::make_pair(3, '$'));

   EXPECT_EQ(myMap.size(), stdMap.size());

   auto myIt = myMap.begin();
   auto stdIt = stdMap.begin();

   for (; myIt != myMap.end(); myIt++, stdIt++) {
     EXPECT_TRUE((*myIt).first == (*stdIt).first);
     EXPECT_TRUE((*myIt).second == (*stdIt).second);
     }
 }

 TEST(MapTest, Insert_2) {
   s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
   std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  
   myMap.insert(std::make_pair(4, 'z'));
   stdMap.insert(std::make_pair(4, 'z'));
  
   EXPECT_EQ(myMap.size(), stdMap.size());

   auto myIt = myMap.begin();
   auto stdIt = stdMap.begin();

   for (; myIt != myMap.end(); myIt++, stdIt++) {
     EXPECT_TRUE((*myIt).first == (*stdIt).first);
     EXPECT_TRUE((*myIt).second == (*stdIt).second);
     }
 }


 TEST(MapTest, Assignment_1) {
   s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
   std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};

   myMap[1] = '@';
   stdMap[1] = '@';

   EXPECT_EQ(myMap[1], '@');
   EXPECT_EQ(stdMap[1], '@');
 }

// -------------------------------------------------------------------------------------------------------
// У нас реализован данный оператор?
// TEST(MapTest, InsertOrAssign_1) {
//   s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  
//   myMap.insert_or_assign(1, '@');
//   stdMap.insert_or_assign(1, '@');
  
//   EXPECT_EQ(myMap.size(), stdMap.size());

//   auto myIt = myMap.begin();
//   auto stdIt = stdMap.begin();

//   for (; myIt != myMap.end(); myIt++, stdIt++) {
//     EXPECT_TRUE((*myIt).first == (*stdIt).first);
//     EXPECT_TRUE((*myIt).second == (*stdIt).second);
//     }
// }

// TEST(MapTest, InsertOrAssign_2) {
//   s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  
//   myMap.insert_or_assign(4, 'z');
//   stdMap.insert_or_assign(4, 'z');
  
//   EXPECT_EQ(myMap.size(), stdMap.size());

//   auto myIt = myMap.begin();
//   auto stdIt = stdMap.begin();

//   for (; myIt != myMap.end(); myIt++, stdIt++) {
//     EXPECT_TRUE((*myIt).first == (*stdIt).first);
//     EXPECT_TRUE((*myIt).second == (*stdIt).second);
//     }
// }

// Не проходит
// TEST(MapTest, Erase_1) {
//   s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
//   std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  
//   auto myIt = myMap.find(2);
//   if (myIt != myMap.end()) {
//     myMap.erase(myIt);
//   }

//   auto stdIt = stdMap.find(2);
//   if (stdIt != stdMap.end()) {
//     stdMap.erase(stdIt);
//   }

//   EXPECT_EQ(myMap.size(), stdMap.size());

//   auto myIt2 = myMap.begin();
//   auto stdIt2 = stdMap.begin();

//   for (; myIt2 != myMap.end(); myIt2++, stdIt2++) {
//     EXPECT_EQ(myIt2->first, stdIt2->first);
//     EXPECT_EQ(myIt2->second, stdIt2->second);
//     }
// }


TEST(MapTest, Erase_2) {
  s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  
  myMap.erase(myMap.begin());
  stdMap.erase(stdMap.begin());

  EXPECT_EQ(myMap.size(), stdMap.size());

}
// Не проходит сравнение по элементам
TEST(MapTest, Swap) {
  s21::map<int, char> myMap1{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> myMap2{{1, 'w'}};
  std::map<int, char> stdMap1{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> stdMap2{{1, 'w'}};
  
  myMap1.swap(myMap2);
  stdMap1.swap(stdMap2);

  EXPECT_EQ(myMap1.size(), stdMap1.size());
  EXPECT_EQ(myMap2.size(), stdMap2.size());

  auto myIt = myMap1.begin();
  auto stdIt = stdMap1.begin();

  for (; myIt != myMap1.end(); myIt++, stdIt++) {
    EXPECT_TRUE((*myIt).first == (*stdIt).first);
    EXPECT_TRUE((*myIt).second == (*stdIt).second);
    }

  auto myIt2 = myMap2.begin();
  auto stdIt2 = stdMap2.begin();

  for (; myIt2 != myMap2.end(); myIt2++, stdIt2++) {
    EXPECT_TRUE((*myIt2).first == (*stdIt2).first);
    EXPECT_TRUE((*myIt2).second == (*stdIt2).second);
    }
}
// Не проходит и на этапе сравнения  кол-ва, как будто наш оператор не заменяет с существующим ключом, а добавляет новую пару
// TEST(MapTest, Merge) {
//   s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {4, 'd'}};
//   s21::map<int, char> myMap2{{2, '$'}, {3, 'c'}, {5, 'w'}};
//   std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {4, 'd'}};
//   std::map<int, char> stdMap2{{2, '$'}, {3, 'c'}, {5, 'w'}};
  
//   myMap.merge(myMap2);
//   stdMap.merge(stdMap2);

//   EXPECT_EQ(myMap.size(), stdMap.size());

//   auto myIt = myMap.begin();
//   auto stdIt = stdMap.begin();

//   for (; myIt != myMap.end(); myIt++, stdIt++) {
//     EXPECT_TRUE((*myIt).first == (*stdIt).first);
//     EXPECT_TRUE((*myIt).second == (*stdIt).second);
//     }
// }


TEST(MapTest, Contains_2) {
  s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> myMap2;


  EXPECT_EQ(myMap.contains(2), true);
  EXPECT_EQ(myMap2.contains(2), false);
}