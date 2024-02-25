#include <gtest/gtest.h>

#include "../include/s21_array.h"

#include "../s21_containersplus.h"

TEST(ArrayTest, DefaultConstructor_1) {
  s21::array<int, 66> myArray;
  std::array<int, 66> stdArray;

  EXPECT_EQ(myArray.size(), stdArray.size());
  EXPECT_EQ(myArray.max_size(), stdArray.max_size());
}

TEST(ArrayTest, DefaultConstructor_2) {
  s21::array<int, 5> myArray;
  std::array<int, 5> stdArray;

  EXPECT_EQ(myArray.size(), stdArray.size());
  EXPECT_EQ(myArray.max_size(), stdArray.max_size());
}

TEST(ArrayTest, InitListConstructor_1) {
  // int
  s21::array<int, 8> myArray{1, 14, 0, 99, 111, 75, 333, 500};
  std::array<int, 8> stdArray{1, 14, 0, 99, 111, 75, 333, 500};

  EXPECT_EQ(myArray.size(), stdArray.size());
  EXPECT_EQ(myArray.max_size(), stdArray.max_size());

  for (int i = 0; i < 8; i++) EXPECT_EQ(myArray.at(i), stdArray.at(i));
}
TEST(ArrayTest, InitListConstructor_2) {
  // string
  s21::array<std::string, 4> myStringArray{"Hello!", "I'm", "Sladkiy",
                                           "Pirozho4ek"};
  std::array<std::string, 4> stdStringArray{"Hello!", "I'm", "Sladkiy",
                                            "Pirozho4ek"};

  EXPECT_EQ(myStringArray.size(), stdStringArray.size());
  EXPECT_EQ(myStringArray.max_size(), stdStringArray.max_size());

  for (int i = 0; i < 4; i++)
    EXPECT_EQ(myStringArray.at(i), stdStringArray.at(i));
}

TEST(ArrayTest, CopyConstructor_1) {
  s21::array<int, 5> myArray = {1, 10, 25, 80, 150};
  s21::array<int, 5> copyArray(myArray);

  // Проверяем что размер скопировался верно
  EXPECT_EQ(copyArray.size(), static_cast<size_t>(5));

  // Проверяем что элементы скопировались верно
  for (size_t i = 0; i < myArray.size(); ++i) {
    EXPECT_EQ(copyArray[i], myArray[i]);
  }
}

TEST(ArrayTest, CopyConstructor_2) {
  // string
  s21::array<std::string, 4> myArray{"Hello!", "I'm", "Sladkiy", "Pirozho4ek"};
  s21::array<std::string, 4> copyArray(myArray);

  // Проверяем что размер скопировался верно
  EXPECT_EQ(copyArray.size(), static_cast<size_t>(4));

  // Проверяем что элементы скопировались верно
  for (size_t i = 0; i < myArray.size(); ++i) {
    EXPECT_EQ(copyArray[i], myArray[i]);
  }
}

TEST(ArrayTest, MoveConstructor_1) {
  // int
  s21::array<int, 5> myArray = {1, 10, 25, 80, 150};
  std::array<int, 5> stdArray = {1, 10, 25, 80, 150};
  s21::array<int, 5> movedArray(std::move(myArray));

  // Проверяем что размер скопировался верно
  EXPECT_EQ(movedArray.size(), static_cast<size_t>(5));

  for (size_t i = 0; i < movedArray.size(); ++i) {
    EXPECT_EQ(movedArray[i], stdArray[i]);
  }
}

TEST(ArrayTest, MoveConstructor_2) {
  // string
  s21::array<std::string, 4> myArray{"Hello!", "I'm", "Sladkiy", "Pirozho4ek"};
  s21::array<std::string, 4> stdArray{"Hello!", "I'm", "Sladkiy", "Pirozho4ek"};
  s21::array<std::string, 4> movedArray(std::move(myArray));

  // Проверяем что размер скопировался верно
  EXPECT_EQ(movedArray.size(), static_cast<size_t>(4));

  for (size_t i = 0; i < movedArray.size(); ++i) {
    EXPECT_EQ(movedArray[i], stdArray[i]);
  }
}

TEST(ArrayTest, Begin_1) {
  s21::array<int, 5> myArray = {5, 10, 25, 80, 150};
  auto it = myArray.begin();
  EXPECT_EQ(*it, 5);
  // Меняем первый элемент через итератор и проверяем, что он изменился
  *it = 30;
  EXPECT_EQ(myArray[0], 30);
}

TEST(ArrayTest, Begin_2) {
  s21::array<std::string, 4> myArray{"Hello", "Privet", "Salam", "Bonjour"};
  auto it = myArray.begin();
  EXPECT_EQ(*it, "Hello");
  // Меняем первый элемент через итератор и проверяем, что он изменился
  *it = "Hola";
  EXPECT_EQ(myArray[0], "Hola");
}

TEST(ArrayTest, End_1) {
  s21::array<int, 5> myArray = {5, 10, 25, 80, 150};
  auto it = myArray.end();
  auto beginIt = myArray.begin();
  // Проверяем, что итератор it, указывающий на конец массива, находится на
  // расстоянии, равном размеру массива, от начального итератора beginIt.
  EXPECT_EQ(it, beginIt + 5);
}

TEST(ArrayTest, End_2) {
  s21::array<std::string, 4> myArray{"Hello", "Privet", "Salam", "Bonjour"};
  auto it = myArray.end();
  auto beginIt = myArray.begin();
  // Проверяем, что итератор it, указывающий на конец массива, находится на
  // расстоянии, равном размеру массива, от начального итератора beginIt.
  EXPECT_EQ(it, beginIt + 4);
}
TEST(ArrayTest, CopyAssignmentOperator_1) {
  s21::array<int, 5> myArray1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> myArray2 = {6, 7, 8, 9, 10};

  myArray1 = myArray2;

  // Проверяем, что 1 массиву присвоились значения 2го
  for (size_t i = 0; i < myArray1.size(); ++i) {
    EXPECT_EQ(myArray1[i], myArray2[i]);
  }
}

TEST(ArrayTest, CopyAssignmentOperator2) {
  s21::array<std::string, 4> myArray1{"Hello", "Privet", "Salam", "Bonjour"};
  s21::array<std::string, 4> myArray2{"Hello", "Hello", "Hello", "Hello"};

  myArray1 = myArray2;

  // Проверяем, что 1 массиву присвоились значения 2го
  for (size_t i = 0; i < myArray1.size(); ++i) {
    EXPECT_EQ(myArray1[i], myArray2[i]);
  }
}

TEST(ArrayTest, MoveAssignmentOperator_1) {
  s21::array<int, 5> myArray1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> myArray2 = {6, 7, 8, 9, 10};

  myArray1 = std::move(myArray2);

  // Проверяем, что элементы 1го массива равны элементам 2го (увеличиваем на 6,
  // тк 2й массив теперь пустой)
  for (size_t i = 0; i < myArray1.size(); ++i) {
    EXPECT_EQ(myArray1[i], static_cast<int>(i) + 6);
  }
}

TEST(ArrayTest, MoveAssignmentOperator_2) {
  s21::array<std::string, 4> myArray1{"Hello", "Privet", "Salam", "Bonjour"};
  s21::array<std::string, 4> myArray2{"Hello", "Hello", "Hello", "Hello"};
  s21::array<std::string, 4> myArray3{"Hello", "Hello", "Hello", "Hello"};

  myArray1 = std::move(myArray2);

  // Проверяем, что элементы 1го массива равны элементам 2го (который теперь в
  // "неопределенном состоянии")
  for (size_t i = 0; i < myArray1.size(); ++i) {
    EXPECT_EQ(myArray1[i], myArray3[i]);
  }

  for (size_t i = 0; i < myArray2.size(); ++i) {
    EXPECT_NE(myArray2[i], myArray3[i]);
  }
}

TEST(ArrayTest, At_Method_1) {
  s21::array<int, 5> myArray = {5, 10, 25, 80, 150};
  int value = myArray.at(2);
  EXPECT_EQ(value, 25);
}
TEST(ArrayTest, At_Method_2) {
  s21::array<int, 5> myArray = {5, 10, 25, 80, 150};
  EXPECT_THROW(myArray.at(10), std::out_of_range);
}

TEST(ArrayTest, At_Method_3) {
  s21::array<std::string, 4> myArray{"Hello", "Privet", "Salam", "Bonjour"};
  auto value = myArray.at(2);
  EXPECT_EQ(value, "Salam");
}

TEST(ArrayTest, BracketOperator_1) {
  s21::array<int, 5> myArray = {1, 2, 3, 4, 5};

  // Проверяем, что оператор [] возвращает правильные значения
  EXPECT_EQ(myArray[0], 1);
  EXPECT_EQ(myArray[1], 2);
  EXPECT_EQ(myArray[2], 3);

  // Изменяем значение через оператор []
  myArray[2] = 10;
  EXPECT_EQ(myArray[2], 10);
}

TEST(ArrayTest, BracketOperator_2) {
  s21::array<std::string, 4> myArray{"Hello", "Privet", "Salam", "Bonjour"};

  // Проверяем, что оператор [] возвращает правильные значения
  EXPECT_EQ(myArray[0], "Hello");
  EXPECT_EQ(myArray[3], "Bonjour");

  // Изменяем значение через оператор []
  myArray[3] = "Hola";
  EXPECT_EQ(myArray[3], "Hola");
}

TEST(ArrayTest, Front_1) {
  s21::array<int, 5> myArray = {555, 10, 25, 80, 1000};
  int value = myArray.front();
  EXPECT_EQ(value, 555);
}

TEST(ArrayTest, Front_2) {
  s21::array<std::string, 4> myArray{"Hello", "Privet", "Salam", "Bonjour"};
  auto value = myArray.front();
  EXPECT_EQ(value, "Hello");
}

TEST(ArrayTest, Back_1) {
  s21::array<int, 6> myArray = {555, 10, 25, 80, 1000, 6969};
  int value = myArray.back();
  EXPECT_EQ(value, 6969);
}

TEST(ArrayTest, Back_2) {
  s21::array<std::string, 4> myArray{"Hello", "Privet", "Salam", "Bonjour"};
  auto value = myArray.back();
  EXPECT_EQ(value, "Bonjour");
}

TEST(ArrayTest, Empty_1) {
  s21::array<int, 5> myArray1 = {555, 10, 25, 80, 1000};
  s21::array<std::string, 4> myArray2{"Hello", "Privet", "Salam", "Bonjour"};
  EXPECT_FALSE(myArray1.empty());
  EXPECT_FALSE(myArray2.empty());
}

TEST(ArrayTest, Empty_2) {
  s21::array<int, 0> myArray;
  EXPECT_TRUE(myArray.empty());
}

TEST(ArrayTest, Size_1) {
  s21::array<int, 5> myArray1 = {555, 10, 25, 80, 1000};
  s21::array<int, 0> myArray2;
  EXPECT_EQ(myArray1.size(), static_cast<size_t>(5));
  EXPECT_EQ(myArray2.size(), static_cast<size_t>(0));
}

TEST(ArrayTest, MaxSize) {
  s21::array<int, 5> myArray1 = {555, 10, 25, 80, 1000};
  s21::array<std::string, 4> myArray2{"Hello", "Privet", "Salam", "Bonjour"};
  s21::array<int, 0> myArray3;

  EXPECT_EQ(myArray1.max_size(), static_cast<size_t>(1));
  EXPECT_EQ(myArray2.max_size(), static_cast<size_t>(4));
  EXPECT_EQ(myArray3.max_size(), static_cast<size_t>(0));
}

TEST(ArrayTest, Swap) {
  s21::array<int, 5> myArray1 = {1, 2, 3, 4, 5};
  s21::array<int, 5> myArray2 = {6, 7, 8, 9, 10};
  std::array<int, 5> stdArray1{1, 2, 3, 4, 5};
  std::array<int, 5> stdArray2{6, 7, 8, 9, 10};

  myArray1.swap(myArray2);

  // Проверяем, что элементы певого массива теперь равны элементам 2го
  for (size_t i = 0; i < myArray1.size(); ++i) {
    EXPECT_EQ(myArray1[i], stdArray2[i]);
  }

  // Проверяем, что элементы 2го массива теперь равны элементам 1го
  for (size_t i = 0; i < myArray2.size(); ++i) {
    EXPECT_EQ(myArray2[i], stdArray1[i]);
  }
}

TEST(ArrayTest, Fill) {
  s21::array<int, 5> myArray1;
  s21::array<std::string, 4> myArray2;
  myArray1.fill(10);
  myArray2.fill("Hello");

  for (size_t i = 0; i < myArray1.size(); ++i) {
    EXPECT_EQ(myArray1[i], 10);
  }

  for (size_t i = 0; i < myArray2.size(); ++i) {
    EXPECT_EQ(myArray2[i], "Hello");
  }
}
