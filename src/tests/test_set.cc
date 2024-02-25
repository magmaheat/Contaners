#include <gtest/gtest.h>

#include <chrono>
#include <set>
#include <vector>

#include "../s21_containers.h"

template <typename ValueType>
bool isEqual(s21::set<ValueType> &s21_set,
             std::set<ValueType> &std_set_compare);

template <typename ValueType>
void print(s21::set<ValueType> &s21);

template <typename ValueType>
void print(std::set<ValueType> &std);

TEST(set, create_1) {
  s21::set<int> s21_set_1 = {5, 7, 2, 0, 23, -5};
  std::set<int> std_set_1 = {5, 7, 2, 0, 23, -5};
  EXPECT_EQ(s21_set_1.size(), std_set_1.size());

  s21::set<int> s21_set_2{5, 7, 2, 0, 23, -5};
  std::set<int> std_set_2{5, 7, 2, 0, 23, -5};
  EXPECT_EQ(s21_set_2.size(), std_set_2.size());
}

TEST(set, create_2) {
  s21::set<int> s21_set_1;
  std::set<int> std_set_1;
  EXPECT_TRUE(s21_set_1.empty());
  EXPECT_TRUE(std_set_1.empty());
}

TEST(set, copy_1) {
  s21::set<int> s21_set_1 = {2, 4, 6};
  s21::set<int> s21_set_2(s21_set_1);
  std::set<int> std_set_1 = {2, 4, 6};
  std::set<int> std_set_2(std_set_1);
  EXPECT_EQ(s21_set_1.size(), std_set_1.size());
  EXPECT_EQ(s21_set_2.size(), std_set_2.size());
  EXPECT_TRUE(isEqual(s21_set_1, std_set_1));
  EXPECT_TRUE(isEqual(s21_set_2, std_set_2));
}

TEST(set, copy_2) {
  s21::set<int> s21_set_1 = {2, 4, 6};
  s21::set<int> s21_set_2;
  s21_set_2 = s21_set_1;
  EXPECT_EQ(s21_set_1.size(), s21_set_2.size());
  auto x = s21_set_1.begin();
  for (auto i = s21_set_2.begin(); i != s21_set_2.end(); ++i) {
    ASSERT_EQ(*i, *x);
    x++;
  }
}

TEST(set, move_1) {
  s21::set<int> s21_set_1 = {2, 4, 6};
  s21::set<int> s21_set_2(std::move(s21_set_1));
  std::set<int> std_set_1 = {2, 4, 6};
  std::set<int> std_set_2(std::move(std_set_1));
  EXPECT_EQ(s21_set_1.size(), std_set_1.size());
  EXPECT_EQ(s21_set_2.size(), std_set_2.size());
  EXPECT_TRUE(isEqual(s21_set_1, std_set_1));
  EXPECT_TRUE(isEqual(s21_set_2, std_set_2));
}

TEST(set, move_2) {
  s21::set<int> s21_set_1 = {2, 4, 6};
  s21::set<int> s21_set_2;
  s21_set_2 = std::move(s21_set_1);
  std::set<int> std_set_1 = {2, 4, 6};
  std::set<int> std_set_2;
  std_set_2 = std::move(std_set_1);

  EXPECT_EQ(s21_set_1.size(), std_set_1.size());
  EXPECT_EQ(s21_set_2.size(), std_set_2.size());
  EXPECT_TRUE(isEqual(s21_set_1, std_set_1));
  EXPECT_TRUE(isEqual(s21_set_2, std_set_2));
}

TEST(set, move_3) {
  s21::set<int> s21_set_1 = {2, 4, 6};
  s21_set_1 = std::move(s21_set_1);
  std::set<int> std_set_1 = {2, 4, 6};
  std_set_1 = std::move(std_set_1);

  EXPECT_EQ(s21_set_1.size(), std_set_1.size());
  EXPECT_TRUE(isEqual(s21_set_1, std_set_1));
}

TEST(set, contains_1) {
  s21::set<int> s21_set_1{2, 4, 6};
  std::set<int> std_set_1{2, 4, 6};

  EXPECT_FALSE(s21_set_1.contains(5));
  EXPECT_TRUE(s21_set_1.contains(6));
}

TEST(set, find_1) {
  s21::set<int> s21_set_1{2, 4, 6};
  std::set<int> std_set_1{2, 4, 6};

  auto x_6 = s21_set_1.find(6);
  auto y_6 = std_set_1.find(6);

  EXPECT_EQ(*x_6, 6);
  EXPECT_EQ(*y_6, 6);
}

TEST(set, find_2) {
  s21::set<int> s21_set = {1, -2, 3, 5, 8, -13, 55, -89, 144, 233};
  std::set<int> std_set = {1, -2, 3, 5, 8, -13, 55, -89, 144, 233};

  auto s21_x = s21_set.find(-89);
  auto std_y = std_set.find(-89);
  ASSERT_EQ(*std_y, -89);
  ASSERT_EQ(*s21_x, -89);

  s21_x = s21_set.find(233);
  std_y = std_set.find(233);
  ASSERT_EQ(*std_y, 233);
  ASSERT_EQ(*s21_x, 233);
}

TEST(set, find_3) {
  s21::set<int> s21_set = {1, -2, 3, 5, 8, -13, 55, -89, 144, 233};
  s21::set<int>::iterator s21_x;
  try {
    s21_x = s21_set.find(35);
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Iterator is not pointer to  a node");
  }
}

TEST(set, set_iter_begin_1) {
  s21::set<int> s21_set_1 = {5, 7, 2};
  std::set<int> std_set_1 = {5, 7, 2};
  s21::set<int>::iterator s21_iter = s21_set_1.begin();
  std::set<int>::iterator std_iter = std_set_1.begin();
  EXPECT_TRUE(*s21_iter == *std_iter);
}

TEST(set, set_iter_begin_2) {
  s21::set<int> s21_set_1;
  std::set<int> std_set_1;
  EXPECT_TRUE(s21_set_1.begin() == s21_set_1.end() &&
              std_set_1.begin() == std_set_1.end());
}

TEST(set, swap_1) {
  s21::set<int> s21_set_1{2, 4, 6};
  s21::set<int> s21_set_2{1, 3, 5, 7};
  std::set<int> std_set_1{2, 4, 6};
  std::set<int> std_set_2{1, 3, 5, 7};

  ASSERT_EQ(s21_set_1.size(), std_set_1.size());
  ASSERT_EQ(s21_set_2.size(), std_set_2.size());

  std_set_1.swap(std_set_2);
  s21_set_1.swap(s21_set_2);

  ASSERT_EQ(s21_set_1.size(), std_set_1.size());
  ASSERT_EQ(s21_set_2.size(), std_set_2.size());
  ASSERT_TRUE(isEqual(s21_set_1, std_set_1));
}

TEST(set, swap_2) {
  s21::set<int> s21_set1{5, 3, 7, 2, 4, 6, 8};
  s21::set<int> s21_set2{10, 6, 12, 3, 13, 2, -4, 1, 18};
  s21_set1.swap(s21_set2);

  std::set<int> std_set1{5, 3, 7, 2, 4, 6, 8};
  std::set<int> std_set2{10, 6, 12, 3, 13, 2, -4, 1, 18};
  std_set1.swap(std_set2);

  ASSERT_TRUE(isEqual(s21_set1, std_set1));
  ASSERT_EQ(s21_set1.size(), std_set1.size());
}

TEST(set, swap_3) {
  s21::set<int> s21_set = {};
  s21::set<int> s21_set2 = {1, 2, 3};
  s21_set.swap(s21_set2);

  std::set<int> std_set = {};
  std::set<int> std_set2 = {1, 2, 3};
  std_set.swap(std_set2);

  ASSERT_TRUE(isEqual(s21_set, std_set));
  ASSERT_EQ(s21_set.size(), std_set.size());
}

TEST(set, swap_4) {
  s21::set<int> s21_set = {1, 2, 3};
  s21::set<int> s21_set2 = {};
  s21_set.swap(s21_set2);

  std::set<int> std_set = {1, 2, 3};
  std::set<int> std_set2 = {};
  std_set.swap(std_set2);

  ASSERT_TRUE(isEqual(s21_set, std_set));
  ASSERT_EQ(s21_set.size(), std_set.size());
}

TEST(set, merge_1) {
  s21::set<int> s21_set_1{2, 4, 6};
  s21::set<int> s21_set_2{1, 3, 5, 7, 2, 6};

  std::set<int> std_set_1{2, 4, 6};
  std::set<int> std_set_2{1, 3, 5, 7, 2, 6};

  ASSERT_EQ(s21_set_1.size(), std_set_1.size());
  ASSERT_EQ(s21_set_2.size(), std_set_2.size());
  std_set_1.merge(std_set_2);
  s21_set_1.merge(s21_set_2);

  auto x = s21_set_1.begin();
  for (auto i = std_set_1.begin(); i != std_set_1.end(); ++i) {
    ASSERT_EQ(*i, *x);
    x++;
  }

  ASSERT_TRUE(isEqual(s21_set_1, std_set_1));

  ASSERT_EQ(s21_set_1.size(), std_set_1.size());
  ASSERT_EQ(s21_set_2.size(), std_set_2.size());
}

TEST(set, merge_2) {
  s21::set<double> s21_set = {1.1, 2.2};
  s21::set<double> s21_set2 = {3.3, 4.4};
  std::set<double> std_set = {1.1, 2.2};
  std::set<double> std_set2 = {3.3, 4.4};

  s21_set.merge(s21_set2);
  std_set.merge(std_set2);
  ASSERT_TRUE(isEqual(s21_set, std_set));

  std_set.clear();
  s21_set.clear();

  ASSERT_EQ(s21_set.size(), std_set.size());
  ASSERT_EQ(s21_set2.size(), std_set2.size());
}

TEST(set, merge_3) {
  s21::set<double> s21_set;
  s21::set<double> s21_set2 = {3.3, 4.4};
  std::set<double> std_set;
  std::set<double> std_set2 = {3.3, 4.4};

  s21_set.merge(s21_set2);
  std_set.merge(std_set2);
  ASSERT_TRUE(isEqual(s21_set, std_set));
}

TEST(set, merge_4) {
  s21::set<double> s21_set = {3.3, 4.4};
  s21::set<double> s21_set2;
  std::set<double> std_set = {3.3, 4.4};
  std::set<double> std_set2;

  s21_set.merge(s21_set2);
  std_set.merge(std_set2);
  ASSERT_TRUE(isEqual(s21_set, std_set));
  ASSERT_TRUE(isEqual(s21_set2, std_set2));
}

TEST(set, erase_1) {
  s21::set<int> s21_set = {1, 2, 3, 4, 5};
  std::set<int> std_set = {1, 2, 3, 4, 5};
  auto size_s21 = s21_set.size();

  s21_set.erase(s21_set.find(2));
  s21_set.erase(s21_set.find(4));
  std_set.erase(std_set.find(2));
  std_set.erase(std_set.find(4));

  EXPECT_EQ(s21_set.size(), std_set.size());

  EXPECT_FALSE(s21_set.contains(2));
  EXPECT_FALSE(s21_set.contains(4));

  s21_set.erase(s21_set.find(10));
  size_s21 = s21_set.size();
  // std_set.erase(std_set.find(10));

  EXPECT_EQ(s21_set.size(), size_s21);
  EXPECT_TRUE(s21_set.contains(1));
  EXPECT_TRUE(s21_set.contains(3));
  EXPECT_TRUE(s21_set.contains(5));
}

TEST(set, erase_2) {
  s21::set<int> s21_set = {2, 4, 6};
  std::set<int> std_set = {2, 4, 6};

  s21_set.erase(s21_set.begin());
  std_set.erase(std_set.begin());
  EXPECT_EQ(s21_set.size(), std_set.size());

  s21_set.erase(++s21_set.begin());
  std_set.erase(++std_set.begin());
  EXPECT_EQ(s21_set.size(), std_set.size());

  s21_set.clear();
  std_set.clear();
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(set, erase_3) {
  s21::set<int> s21_set = {2, 4, 6};
  std::set<int> std_set = {2, 4, 6};

  s21_set.erase(s21_set.begin());
  std_set.erase(std_set.begin());
  EXPECT_EQ(s21_set.size(), std_set.size());

  s21_set.erase(++s21_set.begin());
  std_set.erase(++std_set.begin());
  EXPECT_EQ(s21_set.size(), std_set.size());

  s21_set.insert(90);
  std_set.insert(90);
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(set, erase_4) {
  s21::set<int> s21_set = {2, 4, 6};
  std::set<int> std_set = {2, 4, 6};

  s21_set.erase(--s21_set.end());
  std_set.erase(--std_set.end());
  ASSERT_TRUE(isEqual(s21_set, std_set));

  EXPECT_EQ(s21_set.size(), std_set.size());

  s21_set.clear();
  std_set.clear();
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(set, insert_1) {
  s21::set<int> s21_set = {11};
  std::set<int> std_set = {11};
  EXPECT_EQ(s21_set.size(), std_set.size());
  std::pair<s21::set<int>::iterator, bool> s21_res = s21_set.insert(2);
  std::pair<std::set<int>::iterator, bool> std_res = std_set.insert(2);

  EXPECT_EQ(s21_set.size(), std_set.size());
  EXPECT_EQ(*s21_res.first, *std_res.first);
  EXPECT_EQ(s21_res.second, std_res.second);
}

TEST(set, insert_2) {
  s21::set<int> s21_set = {1, 5};
  std::set<int> std_set = {1, 5};

  EXPECT_EQ(s21_set.size(), std_set.size());

  auto s21_res = s21_set.insert(3);
  auto std_res = std_set.insert(3);
  EXPECT_EQ(s21_set.size(), std_set.size());

  EXPECT_EQ(*s21_res.first, *std_res.first);
  EXPECT_EQ(s21_res.second, std_res.second);
}

TEST(set, insert_3) {
  s21::set<int> s21_set = {1, 3, 5};
  std::set<int> std_set = {1, 3, 5};
  EXPECT_EQ(s21_set.size(), std_set.size());
  s21_set.insert(3);
  std_set.insert(3);
  EXPECT_EQ(s21_set.size(), std_set.size());
  ASSERT_TRUE(isEqual(s21_set, std_set));

  s21_set.clear();
  std_set.clear();
  EXPECT_EQ(s21_set.size(), std_set.size());

  s21_set.insert(3);
  std_set.insert(3);
  ASSERT_TRUE(isEqual(s21_set, std_set));
}

TEST(set, insert_4) {
  s21::set<int> s21_set;
  std::set<int> std_set;
  EXPECT_EQ(s21_set.empty(), std_set.empty());
  auto s21_res = s21_set.insert(2);
  auto std_res = std_set.insert(2);

  EXPECT_EQ(s21_set.size(), std_set.size());
  ASSERT_TRUE(isEqual(s21_set, std_set));
  EXPECT_EQ(*s21_res.first, *std_res.first);
  EXPECT_EQ(s21_res.second, std_res.second);
}

TEST(set, insert_5) {
  s21::set<int> s21_set = {11};
  std::set<int> std_set = {11};
  EXPECT_EQ(s21_set.empty(), std_set.empty());
  s21_set.insert(11);
  std_set.insert(11);
  EXPECT_EQ(s21_set.size(), std_set.size());
  ASSERT_TRUE(isEqual(s21_set, std_set));
}

// TEST(set, insert_6) {
//   const int num_elements = 1000000;
//   std::set<int> std_set;
//   s21::set<int> s21_set;
//   auto start_time_std = std::chrono::steady_clock::now();
//   for (int i = 0; i < num_elements; ++i) {
//     std_set.insert(i);
//   }
//   auto end_time_std = std::chrono::steady_clock::now();
//   auto start_time_s21 = std::chrono::steady_clock::now();
//   for (int i = 0; i < num_elements; ++i) {
//     s21_set.insert(i);
//   }
//   auto end_time_s21 = std::chrono::steady_clock::now();
//   auto duration_std = std::chrono::duration_cast<std::chrono::milliseconds>(
//       end_time_std - start_time_std);
//   auto duration_s21 = std::chrono::duration_cast<std::chrono::milliseconds>(
//       end_time_s21 - start_time_s21);
// EXPECT_TRUE(duration_s21 <= duration_std);
// EXPECT_EQ(std_set.size(), s21_set.size());
//   // std::cout << "Insertion of " << num_elements << " elements into std::set
//   // took "
//   //             << duration_std.count() << " ms." << std::endl;
//   // std::cout << "Insertion of " << num_elements << " elements into s21::set
//   // took "
//   //             << duration_s21.count() << " ms." << std::endl;
// }

TEST(set, insert_7) {
  std::set<int> std_set = {1, 3, 5, 7, 9};
  s21::set<int> s21_set = {1, 3, 5, 7, 9};

  auto insertion_result_std = std_set.insert(4);
  auto insertion_result_s21 = s21_set.insert(4);
  ASSERT_TRUE(isEqual(s21_set, std_set));

  EXPECT_TRUE(insertion_result_std.second == insertion_result_s21.second);
  EXPECT_TRUE(std_set.count(4) == s21_set.contains(4));
  EXPECT_EQ(*insertion_result_std.first, *insertion_result_s21.first);
  EXPECT_NE(insertion_result_std.first, std_set.end());
  EXPECT_NE(insertion_result_s21.first, s21_set.end());
}

TEST(set, max_size_1) {
  s21::set<double> s21_set = {-2, 6, 5, 8};
  std::set<double> std_set = {-2, 6, 5, 8};
  ASSERT_EQ(s21_set.empty(), std_set.empty());
  ASSERT_EQ(s21_set.size(), std_set.size());
  // ASSERT_EQ(s21_set.max_size(), std_set.max_size());
}

TEST(set, iterators_1) {
  s21::set<int> s21_set = {1, 2, 3};
  std::set<int> std_set = {1, 2, 3};
  ASSERT_EQ(s21_set.begin() != s21_set.begin(),
            std_set.begin() != std_set.begin());
  ASSERT_EQ(s21_set.begin() == s21_set.begin(),
            std_set.begin() == std_set.begin());
}

TEST(set, iterators_2) {
  s21::set<int> s21_set = {55, -89, 144, 233, 1, -2, 3, 5, 8, -13};
  std::set<int> std_set = {55, -89, 144, 233, 1, -2, 3, 5, 8, -13};
  auto s21_iter = s21_set.begin();
  auto std_iter = std_set.begin();

  for (int i = 0; i < 5; ++i) {
    ++s21_iter;
    ++std_iter;
  };
  ASSERT_EQ(*s21_iter, *std_iter);

  s21_iter--;
  std_iter--;
  ASSERT_EQ(*s21_iter, *std_iter);
}

TEST(set, insert_many_1) {
  std::set<int> std_set;
  s21::set<int> s21_set;
  std::vector<int> values_to_insert = {5, 10, 5, 15};
  std_set.insert({5, 10, 5, 15});
  auto insert_s21 = s21_set.insert_many(5, 10, 5, 15);

  EXPECT_TRUE(isEqual(s21_set, std_set));
  EXPECT_EQ(s21_set.size(), std_set.size());
}

TEST(set, insert_many_2) {
  std::set<int> std_set{5, 6, 7};
  s21::set<int> s21_set{5, 6, 7};
  std::set<int> std_set2;
  s21::set<int> s21_set2;
  std_set.insert(std_set2.begin(), std_set2.end());
  s21_set.insert_many();
  EXPECT_EQ(std_set.size(), s21_set.size());
}

TEST(set, insert_many_3) {
  std::set<int> std_set{5, 6, 7};
  s21::set<int> s21_set{5, 6, 7};
  std::set<int> std_set2;
  s21::set<int> s21_set2;
  std_set2.insert(std_set.begin(), std_set.end());
  s21_set2.insert_many(5, 6, 7);
  EXPECT_EQ(std_set.size(), s21_set.size());
  EXPECT_EQ(std_set2.size(), s21_set2.size());
}

template <typename ValueType>
bool isEqual(s21::set<ValueType> &s21_set,
             std::set<ValueType> &std_set_compare) {
  if (std_set_compare.size() != s21_set.size()) {
    return false;
  }
  auto s21_iter = s21_set.begin();
  auto std_iter = std_set_compare.begin();
  for (; std_iter != std_set_compare.end(); ++s21_iter, ++std_iter) {
    if (*s21_iter != *std_iter) {
      return false;
    }
  }
  return true;
}

template <typename ValueType>
void print(s21::set<ValueType> &s21_set) {
  std::cout << "s21_set elements: ";
  auto x = s21_set.begin();
  for (; x != s21_set.end();) {
    std::cout << *x << " ";
    x++;
  }
  std::cout << std::endl;
  std::cout << "s21_set size: " << s21_set.size() << std::endl;
}

template <typename ValueType>
void print(std::set<ValueType> &std_set) {
  std::cout << "std_set elements: ";
  auto x = std_set.begin();
  for (size_t i = 0; i < std_set.size(); ++i) {
    std::cout << *x << " ";
    x++;
  }
  std::cout << std::endl;
  std::cout << "std_set size: " << std_set.size() << std::endl;
}