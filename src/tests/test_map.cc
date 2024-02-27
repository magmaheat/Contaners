#include <gtest/gtest.h>

#include "../include/s21_map.h"

#include "../s21_containers.h"

TEST(MapTest, DefaultConstructor_1) {
  s21::map<int, int> myMap;
  std::map<int, int> stdMap;

  EXPECT_TRUE(myMap.size() == stdMap.size());
}

TEST(MapTest, InitConstructor_1) {
  s21::map<int, int> myMap{};
  s21::map<int, int> myMap1{{1, 10}, {2, 20}, {3, 30}};
  s21::map<int, int> myMap2{{-1, 10}, {0, 20}, {3, 30}};
  s21::map<int, char> myMap3{{1, 'a'}, {2, '@'}, {3, '+'}};
  s21::map<int, std::string> myMap4{
      {1, "Hello"}, {2, "Privet"}, {3, "Bonjour"}};
  s21::map<char, int> myMap5{{'a', 10}, {'b', 20}, {'c', 30}};
  std::map<int, int> stdMap{};
  std::map<int, int> stdMap1{{1, 10}, {2, 20}, {3, 30}};
  std::map<int, int> stdMap2{{-1, 10}, {2, 20}, {3, 30}};
  std::map<int, char> stdMap3{{1, 'a'}, {2, '@'}, {3, '+'}};
  std::map<int, std::string> stdMap4{
      {1, "Hello"}, {2, "Privet"}, {3, "Bonjour"}};
  std::map<char, int> stdMap5{{'a', 10}, {'b', 20}, {'c', 30}};

  EXPECT_TRUE(myMap.size() == stdMap.size());
  EXPECT_TRUE(myMap1.size() == stdMap1.size());
  EXPECT_TRUE(myMap2.size() == stdMap2.size());
  EXPECT_TRUE(myMap3.size() == stdMap3.size());
  EXPECT_TRUE(myMap4.size() == stdMap4.size());
  EXPECT_TRUE(myMap5.size() == stdMap5.size());
}

TEST(MapTest, InitConstructor_2) {
  s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}, {1, 'd'}};
  std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}, {1, 'd'}};

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
  s21::map<int, int> myCopiedMap(myMap);
  std::map<int, int> stdMap{{1, 10}, {2, 20}, {3, 30}};
  std::map<int, int> stdCopiedMap(stdMap);

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
  s21::map<int, int> myMovedMap(std::move(myMap));
  std::map<int, int> stdMap{{1, 10}, {2, 20}, {3, 30}};
  std::map<int, int> stdMovedMap(std::move(stdMap));

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
  s21::map<int, int> myMap2{{5, 6}, {7, 8}, {9, 10}};
  std::map<int, int> stdMap{{5, 6}, {7, 8}, {9, 10}};

  myMap1 = std::move(myMap2);

  EXPECT_EQ(myMap1.size(), static_cast<size_t>(3));
  EXPECT_EQ(myMap1[5], 6);
  EXPECT_EQ(myMap1[7], 8);
}

TEST(MapTest, Begin_1) {
  s21::map<int, int> myMap{{1, 2}, {3, 4}};

  auto it = myMap.begin();

  EXPECT_EQ((*it).first, 1);
  EXPECT_EQ((*it).second, 2);
}

TEST(MapTest, Begin_2) {
  s21::map<int, int> myMap{{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
  std::map<int, int> stdMap{{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};

  auto my_it = myMap.begin();
  auto std_it = stdMap.begin();

  EXPECT_EQ((*my_it).first, (*std_it).first);
  EXPECT_EQ((*my_it).second, (*std_it).second);
}

TEST(MapTest, End_1) {
  s21::map<int, int> myMap{{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
  std::map<int, int> stdMap{{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};

  auto my_it = myMap.end();
  auto std_it = stdMap.end();
  --my_it;
  --std_it;

  EXPECT_EQ((*my_it).first, (*std_it).first);
  EXPECT_EQ((*my_it).second, (*std_it).second);
}

TEST(MapTest, Empty_1) {
  s21::map<int, int> myMap{{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
  std::map<int, int> stdMap{{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};

  myMap.clear();
  stdMap.clear();

  EXPECT_EQ(myMap.empty(), stdMap.empty());
}

TEST(MapTest, Empty_2) {
  s21::map<int, int> myMap;
  std::map<int, int> stdMap;

  EXPECT_EQ(myMap.empty(), stdMap.empty());
}

TEST(MapTest, Empty_3) {
  s21::map<int, int> myMap{{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
  std::map<int, int> stdMap{{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};

  EXPECT_EQ(myMap.empty(), stdMap.empty());
}

TEST(MapTest, Size_1) {
  s21::map<int, int> myMap{{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
  std::map<int, int> stdMap{{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};

  EXPECT_EQ(myMap.size(), stdMap.size());
  myMap.clear();
  stdMap.clear();
  EXPECT_EQ(myMap.size(), stdMap.size());
}

TEST(MapTest, Clear_1) {
  s21::map<int, int> myMap;
  std::map<int, int> stdMap;

  EXPECT_EQ(myMap.size(), stdMap.size());

  myMap.clear();
  stdMap.clear();
  EXPECT_EQ(myMap.size(), stdMap.size());

  myMap.insert({2, 4});
  stdMap.insert({2, 4});
  EXPECT_EQ(myMap.size(), stdMap.size());

  myMap.clear();
  stdMap.clear();
  EXPECT_EQ(myMap.size(), stdMap.size());
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

TEST(MapTest, Insert_3) {
  s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};

  myMap.insert(4, 'z');
  stdMap.insert(std::make_pair(4, 'z'));

  EXPECT_EQ(myMap.size(), stdMap.size());

  myMap.insert(4, 'd');
  stdMap.insert(std::make_pair(4, 'd'));

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

TEST(MapTest, InsertOrAssign_1) {
  s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};

  myMap.insert_or_assign(1, '@');
  stdMap.insert_or_assign(1, '@');

  EXPECT_EQ(myMap.size(), stdMap.size());

  auto myIt = myMap.begin();
  auto stdIt = stdMap.begin();

  for (; myIt != myMap.end(); myIt++, stdIt++) {
    EXPECT_TRUE((*myIt).first == (*stdIt).first);
    EXPECT_TRUE((*myIt).second == (*stdIt).second);
  }
}

TEST(MapTest, InsertOrAssign_2) {
  s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};

  myMap.insert_or_assign(4, 'z');
  stdMap.insert_or_assign(4, 'z');

  EXPECT_EQ(myMap.size(), stdMap.size());

  auto myIt = myMap.begin();
  auto stdIt = stdMap.begin();

  for (; myIt != myMap.end(); myIt++, stdIt++) {
    EXPECT_TRUE((*myIt).first == (*stdIt).first);
    EXPECT_TRUE((*myIt).second == (*stdIt).second);
  }
}

TEST(MapTest, Erase_1) {
  s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};

  myMap.erase(myMap.begin());
  stdMap.erase(stdMap.begin());

  EXPECT_EQ(myMap.size(), stdMap.size());
}

TEST(MapTest, Erase_2) {
  s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};

  myMap.erase(++myMap.begin());
  stdMap.erase(++stdMap.begin());

  EXPECT_EQ(myMap.size(), stdMap.size());
}

TEST(MapTest, Erase_3) {
  s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'},
                            {4, 'd'}, {5, 'e'}, {6, 'f'}};
  s21::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'},
                             {4, 'd'}, {5, 'e'}, {6, 'f'}};

  myMap.erase(++myMap.begin());
  stdMap.erase(++stdMap.begin());

  EXPECT_EQ(myMap.size(), stdMap.size());
}

TEST(MapTest, Erase_4) {
  s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};

  myMap.erase(myMap.end());

  EXPECT_EQ(myMap.size(), stdMap.size());
}

TEST(MapTest, Swap_1) {
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

TEST(MapTest, Swap_2) {
  s21::map<int, char> myMap1{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> myMap2;
  std::map<int, char> stdMap1{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> stdMap2;

  myMap1.swap(myMap2);
  stdMap1.swap(stdMap2);

  EXPECT_EQ(myMap1.size(), stdMap1.size());
  EXPECT_EQ(myMap2.size(), stdMap2.size());
}

TEST(MapTest, Merge_1) {
  s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {4, 'd'}};
  s21::map<int, char> myMap2{{2, '$'}, {3, 'c'}, {5, 'w'}};
  std::map<int, char> stdMap{{1, 'a'}, {2, 'b'}, {4, 'd'}};
  std::map<int, char> stdMap2{{2, '$'}, {3, 'c'}, {5, 'w'}};

  myMap.merge(myMap2);
  stdMap.merge(stdMap2);

  EXPECT_EQ(myMap.size(), stdMap.size());

  auto myIt = myMap.begin();
  auto stdIt = stdMap.begin();

  for (; myIt != myMap.end(); myIt++, stdIt++) {
    EXPECT_TRUE((*myIt).first == (*stdIt).first);
    EXPECT_TRUE((*myIt).second == (*stdIt).second);
  }
}

TEST(MapTest, Merge_2) {
  s21::map<int, char> myMap;
  s21::map<int, char> myMap2{{2, '$'}, {3, 'c'}, {5, 'w'}};
  std::map<int, char> stdMap;
  std::map<int, char> stdMap2{{2, '$'}, {3, 'c'}, {5, 'w'}};

  myMap.merge(myMap2);
  stdMap.merge(stdMap2);

  EXPECT_EQ(myMap.size(), stdMap.size());

  auto myIt = myMap.begin();
  auto stdIt = stdMap.begin();

  for (; myIt != myMap.end(); myIt++, stdIt++) {
    EXPECT_TRUE((*myIt).first == (*stdIt).first);
    EXPECT_TRUE((*myIt).second == (*stdIt).second);
  }
}

TEST(MapTest, Contains_1) {
  s21::map<int, char> myMap{{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> myMap2;
  s21::map<int, char> myMap3{{1, 'c'}};

  EXPECT_EQ(myMap.contains(2), true);
  EXPECT_EQ(myMap2.contains(2), false);
  EXPECT_EQ(myMap3.contains(2), false);
}