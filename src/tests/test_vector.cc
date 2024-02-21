#include <gtest/gtest.h>

#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

#include "../s21_containers.h"

template <typename ValueType>
void print(s21::vector<ValueType>& s21_vector);

template <typename ValueType>
void print(std::vector<ValueType>& std_vector);

template <typename ValueType>
bool isEqual(s21::vector<ValueType>& s21_vector,
             std::vector<ValueType>& std_vector_compare);

template <typename ValueType>
bool isEqual(s21::vector<ValueType>& s21_vector,
             s21::vector<ValueType>& s21_vector_compare);

TEST(vector, create_1) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  ASSERT_EQ(s21_vector.GetSize(), std_vector.size());
  ASSERT_TRUE(s21_vector.IsEmpty());
}

TEST(vector, create_2) {
  s21::vector<int> s21_vector = {0, 1, 2};
  std::vector<int> std_vector = {0, 1, 2};
  ASSERT_EQ(s21_vector.GetSize(), std_vector.size());
  ASSERT_TRUE(isEqual(s21_vector, std_vector));
}

TEST(vector, create_3) {
  s21::vector<int> s21_vector(3);
  std::vector<int> std_vector(3);
  ASSERT_EQ(s21_vector.GetSize(), std_vector.size());
  ASSERT_TRUE(isEqual(s21_vector, std_vector));

  s21::vector<int> s21_vector_2(3, 2);
  std::vector<int> std_vector_2(3, 2);
  ASSERT_TRUE(isEqual(s21_vector_2, std_vector_2));
  for (size_t i = 0; i < s21_vector_2.GetSize(); ++i) {
    ASSERT_EQ(s21_vector_2[i], 2);
  }
}

TEST(vector, create_4) {
  EXPECT_ANY_THROW({ s21::vector<int> s21_vector(-3); });
  EXPECT_THROW(
      { s21::vector<int> s21_vector(std::numeric_limits<size_t>::max()); },
      std::length_error);

  EXPECT_THROW({ std::vector<int> std_vector(-3); }, std::length_error);
  EXPECT_THROW(
      { std::vector<int> std_vector(std::numeric_limits<size_t>::max()); },
      std::length_error);
}

TEST(vector, copy_1) {
  s21::vector<int> s21_vector{0, 1, 2};
  s21::vector<int> s21_vector2(s21_vector);
  std::vector<int> std_vector{0, 1, 2};
  std::vector<int> std_vector2(std_vector);

  ASSERT_EQ(s21_vector.GetSize(), std_vector.size());
  ASSERT_TRUE(isEqual(s21_vector, s21_vector2));
  ASSERT_EQ(s21_vector2.GetSize(), std_vector2.size());
}

TEST(vector, copy_2) {
  s21::vector<int> s21_vector{0, 1, 2};
  s21::vector<int> s21_vector_2;
  s21_vector_2 = s21_vector;
  std::vector<int> std_vector{0, 1, 2};
  std::vector<int> std_vector_2;
  std_vector_2 = std_vector;

  ASSERT_EQ(s21_vector.GetSize(), std_vector.size());
  ASSERT_TRUE(isEqual(s21_vector, s21_vector_2));
  ASSERT_EQ(s21_vector_2.GetSize(), std_vector_2.size());
}

TEST(vector, move_1) {
  s21::vector<int> s21_vector{0, 1, 2};
  s21::vector<int> s21_vector_2(std::move(s21_vector));
  std::vector<int> std_vector{0, 1, 2};
  std::vector<int> std_vector_2(std::move(std_vector));

  ASSERT_EQ(s21_vector.IsEmpty(), std_vector.empty());
  ASSERT_FALSE(isEqual(s21_vector, s21_vector_2));
  ASSERT_EQ(s21_vector_2.GetSize(), std_vector_2.size());
}

TEST(vector, move_2) {
  s21::vector<int> s21_vector{0, 1, 2};
  s21::vector<int> s21_vector_2;
  s21_vector_2 = std::move(s21_vector);
  std::vector<int> std_vector{0, 1, 2};
  std::vector<int> std_vector_2;
  std_vector_2 = std::move(std_vector);

  ASSERT_EQ(s21_vector.IsEmpty(), std_vector.empty());
  ASSERT_FALSE(isEqual(s21_vector, s21_vector_2));
  ASSERT_EQ(s21_vector_2.GetSize(), std_vector_2.size());
}

TEST(vector, Front_Back_1) {
  s21::vector<double> s21_vector = {6, 5, 8};
  std::vector<double> std_vector = {6, 5, 8};
  ASSERT_EQ(s21_vector.Front(), std_vector.front());
  ASSERT_EQ(s21_vector.Back(), std_vector.back());
}

TEST(vector, Front_Back_2) {
  s21::vector<double> s21_vector;
  EXPECT_THROW({ s21_vector.Front(); }, std::out_of_range);
  EXPECT_THROW({ s21_vector.Back(); }, std::out_of_range);
}

TEST(vector, reserve_1) {
  s21::vector<double> s21_vector = {-2, 6, 5, 8};
  std::vector<double> std_vector = {-2, 6, 5, 8};
  s21_vector.Reserve(20);
  std_vector.reserve(20);
  ASSERT_EQ(s21_vector.IsEmpty(), std_vector.empty());
  ASSERT_EQ(s21_vector.GetSize(), std_vector.size());
  ASSERT_EQ(s21_vector.Capacity(), std_vector.capacity());
}

TEST(vector, reserve_2) {
  s21::vector<double> s21_vector;
  std::vector<double> std_vector;
  ASSERT_EQ(s21_vector.IsEmpty(), std_vector.empty());
  s21_vector.Reserve(20);
  std_vector.reserve(20);
  ASSERT_EQ(s21_vector.IsEmpty(), std_vector.empty());
  ASSERT_EQ(s21_vector.GetSize(), std_vector.size());
  ASSERT_EQ(s21_vector.Capacity(), std_vector.capacity());
}

TEST(vector, reserve_3) {
  s21::vector<double> s21_vector;
  std::vector<double> std_vector;
  EXPECT_ANY_THROW(s21_vector.Reserve(-5));
  EXPECT_ANY_THROW(std_vector.reserve(-5));
}

TEST(vector, PushBack_1) {
  s21::vector<int> s21_vector_1;
  s21_vector_1.PushBack(1);
  s21_vector_1.PushBack(50);

  std::vector<int> std_vector_1;
  std_vector_1.push_back(1);
  std_vector_1.push_back(50);

  EXPECT_EQ(s21_vector_1.GetSize(), std_vector_1.size());
  EXPECT_EQ(std_vector_1.back(), s21_vector_1.Back());
  EXPECT_EQ(std_vector_1.front(), s21_vector_1.Front());
  EXPECT_EQ(s21_vector_1.GetSize(), std_vector_1.size());
  EXPECT_EQ(s21_vector_1.Back(), std_vector_1.back());
  EXPECT_EQ(s21_vector_1.Front(), std_vector_1.front());
}

TEST(vector, PushBack_2) {
  s21::vector<int> s21_vector_1(5, 10);
  s21_vector_1.PushBack(1);
  s21_vector_1.PushBack(50);

  std::vector<int> std_vector_1(5, 10);
  std_vector_1.push_back(1);
  std_vector_1.push_back(50);

  EXPECT_EQ(s21_vector_1.GetSize(), std_vector_1.size());
  EXPECT_EQ(std_vector_1.back(), s21_vector_1.Back());
  EXPECT_EQ(std_vector_1.front(), s21_vector_1.Front());
  EXPECT_EQ(s21_vector_1.GetSize(), std_vector_1.size());
  EXPECT_EQ(s21_vector_1.Back(), std_vector_1.back());
  EXPECT_EQ(s21_vector_1.Front(), std_vector_1.front());
}

TEST(vector, Push_Pop_Back_1) {
  s21::vector<int> s21_vector_1;
  s21_vector_1.PushBack(1);
  s21_vector_1.PushBack(50);

  std::vector<int> std_vector_1;
  std_vector_1.push_back(1);
  std_vector_1.push_back(50);

  EXPECT_EQ(s21_vector_1.GetSize(), std_vector_1.size());
  EXPECT_EQ(std_vector_1.back(), s21_vector_1.Back());
  EXPECT_EQ(std_vector_1.front(), s21_vector_1.Front());

  s21_vector_1.PopBack();
  std_vector_1.pop_back();

  EXPECT_EQ(s21_vector_1.GetSize(), std_vector_1.size());
  EXPECT_EQ(s21_vector_1.Back(), std_vector_1.back());
  EXPECT_EQ(s21_vector_1.Front(), std_vector_1.front());
}

TEST(vector, Push_Pop_Back_2) {
  s21::vector<int> s21_vector_1;
  std::vector<int> std_vector_1;

  EXPECT_EQ(s21_vector_1.GetSize(), std_vector_1.size());
  EXPECT_TRUE(s21_vector_1.IsEmpty());
}

TEST(vector, Push_Pop_Back_3) {
  s21::vector<int> s21_vector_1;
  s21_vector_1.PushBack(1);
  s21_vector_1.PushBack(50);

  std::vector<int> std_vector_1;
  std_vector_1.push_back(1);
  std_vector_1.push_back(50);

  EXPECT_EQ(s21_vector_1.GetSize(), std_vector_1.size());
  EXPECT_EQ(std_vector_1.back(), s21_vector_1.Back());
  EXPECT_EQ(std_vector_1.front(), s21_vector_1.Front());

  s21_vector_1.PopBack();
  std_vector_1.pop_back();

  EXPECT_EQ(s21_vector_1.GetSize(), std_vector_1.size());
  EXPECT_EQ(s21_vector_1.Back(), std_vector_1.back());
  EXPECT_EQ(s21_vector_1.Front(), std_vector_1.front());
}

TEST(vector, iterators_1) {
  s21::vector<int> s21_vector;
  s21::vector<int> s21_vector2{1, 2, 3};
  std::vector<int> std_vector2{1, 2, 3};

  EXPECT_THROW({ s21_vector2.At(3); }, std::out_of_range);
  EXPECT_THROW({ s21_vector.At(1); }, std::out_of_range);

  s21::vector<int>::Iterator it{s21_vector2.Begin()};
  for (size_t i = 0; i < std_vector2.size(); ++i) {
    EXPECT_EQ(static_cast<size_t>(*it), i + 1);
    if (i != std_vector2.size() - 1) {
      ++it;
    }
  }
  for (size_t i = s21_vector2.GetSize(); i > 0; --i) {
    EXPECT_EQ(static_cast<size_t>(*it), i);
    if (i != 1) {
      --it;
    }
  }

  it += 2;
  EXPECT_EQ(*it, 3);
  it -= 2;
  EXPECT_EQ(*it, 1);
  it += 1;
  EXPECT_EQ(*it, 2);
  it -= 1;
  EXPECT_EQ(*it, 1);

  s21::vector<int>::Iterator it1{s21_vector2.Begin()};
  EXPECT_TRUE(it == it1);
  it++;
  EXPECT_FALSE(it == it1);
  EXPECT_TRUE(it != it1);
  it--;
  EXPECT_FALSE(it != it1);
}

TEST(vector, erase_1) {
  s21::vector<int> s21_vector{1, 2, 3, 4, 5};
  std::vector<int> std_vector{1, 2, 3, 4, 5};
  s21::vector<int>::Iterator s21_iter = s21_vector.Begin();
  std::vector<int>::iterator std_iter = std_vector.begin();
  s21_iter += 2;
  std_iter += 2;
  s21_vector.Erase(s21_iter);
  std_vector.erase(std_iter);
  EXPECT_EQ(s21_vector.GetSize(), std_vector.size());

  EXPECT_EQ(s21_vector[0], 1);
  EXPECT_EQ(s21_vector[1], 2);
  EXPECT_EQ(s21_vector[2], 4);
  EXPECT_EQ(s21_vector[3], 5);
  EXPECT_TRUE(isEqual(s21_vector, std_vector));
}

TEST(vector, erase_2) {
  s21::vector<int> s21_vector;
  EXPECT_THROW(s21_vector.Erase(s21_vector.Begin()), std::out_of_range);
  EXPECT_THROW(s21_vector.Erase(s21_vector.End()), std::out_of_range);
  s21::vector<int> s21_vector2{1, 2, 3};
  EXPECT_THROW(s21_vector2.Erase(s21_vector2.Begin() + 5), std::out_of_range);
}

TEST(vector, erase_3) {
  s21::vector<int> s21_vector{35};
  std::vector<int> std_vector{35};
  s21_vector.Erase(s21_vector.Begin());
  std_vector.erase(std_vector.begin());
}

TEST(vector, insert_1) {
  s21::vector<int> s21_vector = {-2, 6, 5, 8};
  std::vector<int> std_vector = {-2, 6, 5, 8};
  s21_vector.Insert(s21_vector.Begin(), 15);
  std_vector.insert(std_vector.begin(), 15);
  ASSERT_EQ(s21_vector.IsEmpty(), std_vector.empty());
  ASSERT_EQ(s21_vector.GetSize(), std_vector.size());
  ASSERT_EQ(s21_vector[0], std_vector[0]);
  ASSERT_EQ(s21_vector.Capacity(), std_vector.capacity());
}

TEST(vector, insert_2) {
  s21::vector<int> s21_vector = {11, 5};
  std::vector<int> std_vector = {11, 5};
  EXPECT_EQ(s21_vector.GetSize(), std_vector.size());

  s21_vector.Insert(s21_vector.Begin() + 1, 2);
  std_vector.insert(std_vector.begin() + 1, 2);
  s21_vector.Insert(s21_vector.Begin(), 77);
  std_vector.insert(std_vector.begin(), 77);
  s21_vector.Insert(s21_vector.End(), 88);
  std_vector.insert(std_vector.end(), 88);
  EXPECT_EQ(s21_vector.GetSize(), std_vector.size());
  EXPECT_TRUE(isEqual(s21_vector, std_vector));

  s21_vector.Clear();
  std_vector.clear();
  EXPECT_EQ(s21_vector.GetSize(), std_vector.size());
  s21_vector.Insert(s21_vector.End(), 15);
  std_vector.insert(std_vector.end(), 15);
}

TEST(vector, insert_3) {
  s21::vector<int> s21_vector = {11, 5};
  EXPECT_THROW(s21_vector.Insert(s21_vector.Begin() - 1, 2), std::out_of_range);
}

TEST(vector, ShrinkToFit_1) {
  s21::vector<int> s21_vector(5);
  std::vector<int> std_vector(5);
  s21_vector.ShrinkToFit();
  std_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
}

TEST(vector, ShrinkToFit_2) {
  s21::vector<int> s21_vector(10);
  std::vector<int> std_vector(10);
  s21_vector.PushBack(1);
  s21_vector.PushBack(2);
  s21_vector.ShrinkToFit();
  std_vector.push_back(1);
  std_vector.push_back(2);
  std_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
}

TEST(vector, ShrinkToFit_3) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  s21_vector.ShrinkToFit();
  std_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
}

TEST(vector, ShrinkToFit_4) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  s21_vector.PushBack(1);
  s21_vector.ShrinkToFit();
  std_vector.push_back(2);
  std_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.Capacity(), std_vector.capacity());
}

TEST(vector, swap_1) {
  s21::vector<int> s21_vector_1{2, 4, 6};
  s21::vector<int> s21_vector_2{1, 3, 5, 7};
  std::vector<int> std_vector_1{2, 4, 6};
  std::vector<int> std_vector_2{1, 3, 5, 7};

  ASSERT_EQ(s21_vector_1.GetSize(), std_vector_1.size());
  ASSERT_EQ(s21_vector_2.GetSize(), std_vector_2.size());

  std_vector_1.swap(std_vector_2);
  s21_vector_1.Swap(s21_vector_2);

  ASSERT_EQ(s21_vector_1.GetSize(), std_vector_1.size());
  ASSERT_EQ(s21_vector_2.GetSize(), std_vector_2.size());
  ASSERT_TRUE(isEqual(s21_vector_1, std_vector_1));
}

TEST(vector, swap_2) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21::vector<int> s21_vector2 = {3, 2, 1};
  std::vector<int> std_vector = {1, 2, 3};
  std::vector<int> std_vector2 = {3, 2, 1};
  s21_vector.Swap(s21_vector2);
  std_vector.swap(std_vector2);

  ASSERT_TRUE(isEqual(s21_vector, std_vector));
  ASSERT_TRUE(isEqual(s21_vector2, std_vector2));
  ASSERT_FALSE(isEqual(s21_vector, s21_vector2));
}

TEST(vector, insertmany_1) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  std::vector<int> args = {15, 10, -5, 5};
  EXPECT_EQ(s21_vector.GetSize(), std_vector.size());

  s21_vector.InsertMany(s21_vector.Begin(), 15, 10, -5, 5);
  std_vector.insert(std_vector.begin(), args.begin(), args.end());
  EXPECT_TRUE(isEqual(s21_vector, std_vector));
}

TEST(vector, insertmany_2) {
  s21::vector<int> s21_vector{1};
  std::vector<int> std_vector{1};
  std::vector<int> args = {15, 10, -5, 5};
  EXPECT_EQ(s21_vector.GetSize(), std_vector.size());

  s21_vector.InsertMany(s21_vector.Begin(), 15, 10, -5, 5);
  std_vector.insert(std_vector.begin(), args.begin(), args.end());
  EXPECT_TRUE(isEqual(s21_vector, std_vector));
}

TEST(vector, insertmany_3) {
  s21::vector<int> s21_vector{1, 11, 111, 1111};
  std::vector<int> std_vector{1, 11, 111, 1111};
  std::vector<int> args = {15, 10, -5, 5};
  EXPECT_EQ(s21_vector.GetSize(), std_vector.size());

  s21_vector.InsertMany(s21_vector.Begin() + 2, 15, 10, -5, 5);
  std_vector.insert(std_vector.begin() + 2, args.begin(), args.end());
  EXPECT_TRUE(isEqual(s21_vector, std_vector));
}

TEST(vector, insertManyToBack_1) {
  s21::vector<int> s21_vector{3};
  std::vector<int> std_vector{3};
  std::vector<int> args = {15, 10, -5, 5};
  EXPECT_EQ(s21_vector.GetSize(), std_vector.size());

  s21_vector.InsertManyToBack(15, 10, -5, 5);
  std_vector.insert(std_vector.end(), args.begin(), args.end());
  EXPECT_TRUE(isEqual(s21_vector, std_vector));
}

TEST(vector, insertManyToBack_2) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  std::vector<int> args = {15, 10, -5, 5};
  EXPECT_EQ(s21_vector.GetSize(), std_vector.size());

  s21_vector.InsertManyToBack(15, 10, -5, 5);
  std_vector.insert(std_vector.end(), args.begin(), args.end());
  EXPECT_TRUE(isEqual(s21_vector, std_vector));
}

TEST(vector, data_1) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;
  EXPECT_EQ(s21_vector.data(), nullptr);
  EXPECT_EQ(std_vector.data(), nullptr);
}

TEST(vector, data_2) {
  s21::vector<int> s21_vector{1, 2, 3};
  std::vector<int> std_vector{1, 2, 3};
  EXPECT_EQ(s21_vector.data(), &s21_vector[0]);
  EXPECT_EQ(std_vector.data(), &std_vector[0]);
}

TEST(vector, data_3) {
  s21::vector<int> s21_vector{-5, 1, 2, 3, -5, 1, 2, 3};
  std::vector<int> std_vector{-5, 1, 2, 3, -5, 1, 2, 3};
  int* s21_ptr = s21_vector.data();
  s21_ptr = s21_ptr + 4;
  *s21_ptr = 7777;
  int* std_ptr = std_vector.data();
  std_ptr = std_ptr + 4;
  *std_ptr = 7777;
  EXPECT_TRUE(isEqual(s21_vector, std_vector));
}

TEST(vector, at_1) {
  s21::vector<int> s21_vector{-5, 1, 2, 3};
  std::vector<int> std_vector{-5, 1, 2, 3};
  EXPECT_TRUE(isEqual(s21_vector, std_vector));
  s21_vector[2] = 777;
  std_vector[2] = 777;
  EXPECT_TRUE(isEqual(s21_vector, std_vector));
  for (size_t i = 0; i < s21_vector.GetSize(); i++) {
    EXPECT_EQ(s21_vector.At(i), std_vector.at(i));
  }
}

TEST(vector, at_2) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;

  EXPECT_ANY_THROW(s21_vector[0] = 777);

  EXPECT_THROW(s21_vector.At(0), std::out_of_range);
  EXPECT_THROW(std_vector.at(0), std::out_of_range);

  EXPECT_TRUE(isEqual(s21_vector, std_vector));
}

template <typename ValueType>
bool isEqual(s21::vector<ValueType>& s21_vector,
             std::vector<ValueType>& std_vector_compare) {
  if (std_vector_compare.size() != s21_vector.GetSize()) {
    return false;
  }
  auto s21_iter = s21_vector.Begin();
  auto std_iter = std_vector_compare.begin();
  for (size_t i = 0; i < std_vector_compare.size(); ++i) {
    if (*s21_iter != *std_iter) {
      return false;
    }
    ++s21_iter;
    ++std_iter;
  }
  return true;
}

template <typename ValueType>
bool isEqual(s21::vector<ValueType>& s21_vector,
             s21::vector<ValueType>& s21_vector_compare) {
  if (s21_vector_compare.GetSize() != s21_vector.GetSize()) {
    return false;
  }
  auto iter = s21_vector.Begin();
  auto iter_compare = s21_vector_compare.Begin();
  for (size_t i = 0; i < s21_vector_compare.GetSize(); ++i) {
    if (*iter != *iter_compare) {
      return false;
    }
    ++iter;
    ++iter_compare;
  }
  return true;
}

template <typename ValueType>
void print(s21::vector<ValueType>& s21_vector) {
  std::cout << "s21_vector elements: ";
  auto x = s21_vector.Begin();
  for (auto i = s21_vector.Begin(); i != s21_vector.End(); ++i) {
    std::cout << *x << " ";
    x++;
  }
  std::cout << std::endl;
  std::cout << "s21_vector size: " << s21_vector.GetSize() << std::endl;
}

template <typename ValueType>
void print(std::vector<ValueType>& std_vector) {
  std::cout << "std_vector elements: ";
  auto x = std_vector.begin();
  for (auto i = std_vector.begin(); i != std_vector.end(); ++i) {
    std::cout << *x << " ";
    x++;
  }
  std::cout << std::endl;
  std::cout << "std_vector size: " << std_vector.size() << std::endl;
}
