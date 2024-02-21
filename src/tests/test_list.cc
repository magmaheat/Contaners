#include <gtest/gtest.h>

#include <list>

#include "../s21_containers.h"

template <typename ValueType>
void print(s21::list<ValueType>& s21_list);

template <typename ValueType>
void print(std::list<ValueType>& std_list);

template <typename ValueType>
bool isEqual(s21::list<ValueType>& s21_list,
             std::list<ValueType>& std_list_compare);

TEST(list, create_1) {
  s21::list<int> list_1;
  std::list<int> std_list_1;
  EXPECT_TRUE(list_1.IsEmpty());
  EXPECT_TRUE(std_list_1.empty());
}

TEST(list, create_2) {
  s21::list<int> s21_list(5);
  std::list<int> std_list(5);
  EXPECT_EQ(std_list.size(), s21_list.GetSize());
  EXPECT_EQ(std_list.front(), s21_list.Front());
  EXPECT_EQ(std_list.back(), s21_list.Back());
}

TEST(list, create_3) {
  s21::list<int> s21_list(3);
  std::list<int> std_list(3);
  ASSERT_EQ(s21_list.GetSize(), std_list.size());
  ASSERT_TRUE(isEqual(s21_list, std_list));

  s21::list<int> s21_list_2(3, 2);
  std::list<int> std_list_2(3, 2);
  ASSERT_TRUE(isEqual(s21_list_2, std_list_2));
}

TEST(list, copy_1) {
  s21::list<int> s21_list_1;
  s21::list<int> s21_list_2(s21_list_1);

  std::list<int> std_list_1;
  std::list<int> std_list_2(std_list_1);

  EXPECT_EQ(s21_list_1.GetSize(), static_cast<size_t>(0));
  EXPECT_EQ(s21_list_1.GetSize(), s21_list_2.GetSize());
  EXPECT_EQ(std_list_1.size(), static_cast<size_t>(0));
  EXPECT_EQ(std_list_1.size(), std_list_2.size());

  EXPECT_EQ(std_list_1.front(), 0);
  EXPECT_EQ(std_list_1.back(), 0);
  EXPECT_THROW({ s21_list_1.Front(); }, std::out_of_range);
  EXPECT_THROW({ s21_list_1.Back(); }, std::out_of_range);
}

TEST(list, copy_2) {
  s21::list<int> s21_list_1 = {2, 4, 6};
  s21::list<int> s21_list_2;

  std::list<int> std_list_1 = {2, 4, 6};
  std::list<int> std_list_2;

  s21_list_2 = s21_list_1;
  std_list_2 = std_list_1;
  EXPECT_EQ(std_list_1.size(), s21_list_1.GetSize());
  EXPECT_EQ(s21_list_1.GetSize(), s21_list_2.GetSize());
  EXPECT_EQ(std_list_1.size(), std_list_2.size());
  EXPECT_EQ(std_list_1.front(), s21_list_1.Front());
  EXPECT_EQ(std_list_1.back(), s21_list_1.Back());
}

TEST(list, copy_3) {
  s21::list<int> s21_list_1 = {2, 4, 6};
  s21::list<int> s21_list_2(s21_list_1);

  std::list<int> std_list_1 = {2, 4, 6};
  std::list<int> std_list_2(std_list_1);

  EXPECT_EQ(std_list_1.size(), s21_list_1.GetSize());
  EXPECT_EQ(s21_list_1.GetSize(), s21_list_2.GetSize());
  EXPECT_EQ(std_list_1.size(), std_list_2.size());
  EXPECT_EQ(std_list_1.front(), s21_list_1.Front());
  EXPECT_EQ(std_list_1.back(), s21_list_1.Back());
}

TEST(list, copy_4) {
  s21::list<int> s21_list_1 = {2, 4, 6};
  s21::list<int> s21_list_2{1, 3};
  s21_list_1 = s21_list_2;

  std::list<int> std_list_1 = {2, 4, 6};
  std::list<int> std_list_2{1, 3};
  std_list_1 = std_list_2;

  EXPECT_EQ(std_list_1.size(), s21_list_1.GetSize());
  EXPECT_EQ(s21_list_1.GetSize(), s21_list_2.GetSize());
  EXPECT_EQ(std_list_1.size(), std_list_2.size());
  EXPECT_EQ(std_list_1.front(), s21_list_1.Front());
  EXPECT_EQ(std_list_1.back(), s21_list_1.Back());
}

TEST(list, move_1) {
  s21::list<int> s21_list_1 = {2, 4, 6};
  s21::list<int> s21_list_2;
  s21_list_2 = std::move(s21_list_1);

  std::list<int> std_list_1 = {2, 4, 6};
  std::list<int> std_list_2;
  std_list_2 = std::move(std_list_1);

  EXPECT_THROW({ s21_list_1.Front(); }, std::out_of_range);
  EXPECT_THROW({ s21_list_1.Back(); }, std::out_of_range);

  EXPECT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_EQ(s21_list_2.GetSize(), std_list_2.size());
  EXPECT_EQ(std_list_1.front(), 0);
  EXPECT_EQ(std_list_1.back(), 0);

  EXPECT_EQ(std_list_2.front(), s21_list_2.Front());
  EXPECT_EQ(std_list_2.back(), s21_list_2.Back());
}

TEST(list, move_2) {
  s21::list<int> s21_list_1 = {2, 4, 6};
  s21::list<int> s21_list_2(std::move(s21_list_1));

  std::list<int> std_list_1 = {2, 4, 6};
  std::list<int> std_list_2(std::move(std_list_1));

  EXPECT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_EQ(s21_list_2.GetSize(), std_list_2.size());
  EXPECT_THROW({ s21_list_1.Front(); }, std::out_of_range);
  EXPECT_THROW({ s21_list_1.Back(); }, std::out_of_range);
  EXPECT_EQ(std_list_1.front(), 0);
  EXPECT_EQ(std_list_1.back(), 0);
  EXPECT_EQ(s21_list_2.Front(), std_list_2.front());
  EXPECT_EQ(s21_list_2.Back(), std_list_2.back());
}

TEST(list, move_3) {
  s21::list<int> s21_list_1 = {2, 4, 6};
  s21::list<int> s21_list_2 = {1, 3};
  s21_list_1 = (std::move(s21_list_2));

  std::list<int> std_list_1 = {2, 4, 6, 8};
  std::list<int> std_list_2{1, 3};
  std_list_1 = (std::move(std_list_2));

  EXPECT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_EQ(s21_list_2.GetSize(), std_list_2.size());
  EXPECT_THROW({ s21_list_2.Front(); }, std::out_of_range);
  EXPECT_THROW({ s21_list_2.Back(); }, std::out_of_range);
  EXPECT_EQ(std_list_2.front(), 0);
  EXPECT_EQ(std_list_2.back(), 0);
  EXPECT_EQ(s21_list_1.Front(), std_list_1.front());
  EXPECT_EQ(s21_list_1.Back(), std_list_1.back());
}

TEST(list, PushFront_1) {
  s21::list<int> s21_list_1;
  s21_list_1.PushFront(1);
  s21_list_1.PushFront(50);

  std::list<int> std_list_1;
  std_list_1.push_front(1);
  std_list_1.push_front(50);

  EXPECT_EQ(std_list_1.size(), s21_list_1.GetSize());
  EXPECT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_EQ(s21_list_1.Back(), std_list_1.back());
  EXPECT_EQ(s21_list_1.Front(), std_list_1.front());
}

TEST(list, PushFront_2) {
  s21::list<int> s21_list_1(5, 10);
  s21_list_1.PushFront(1);
  s21_list_1.PushFront(50);

  std::list<int> std_list_1(5, 10);
  std_list_1.push_front(1);
  std_list_1.push_front(50);

  EXPECT_EQ(std_list_1.size(), s21_list_1.GetSize());
  EXPECT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_EQ(s21_list_1.Back(), std_list_1.back());
  EXPECT_EQ(s21_list_1.Front(), std_list_1.front());
}

TEST(list, PushBack_1) {
  s21::list<int> s21_list_1;
  s21_list_1.PushBack(1);
  s21_list_1.PushBack(50);

  std::list<int> std_list_1;
  std_list_1.push_back(1);
  std_list_1.push_back(50);

  EXPECT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_EQ(std_list_1.back(), s21_list_1.Back());
  EXPECT_EQ(std_list_1.front(), s21_list_1.Front());
  EXPECT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_EQ(s21_list_1.Back(), std_list_1.back());
  EXPECT_EQ(s21_list_1.Front(), std_list_1.front());
}

TEST(list, PushBack_2) {
  s21::list<int> s21_list_1(5, 10);
  s21_list_1.PushBack(1);
  s21_list_1.PushBack(50);

  std::list<int> std_list_1(5, 10);
  std_list_1.push_back(1);
  std_list_1.push_back(50);

  EXPECT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_EQ(std_list_1.back(), s21_list_1.Back());
  EXPECT_EQ(std_list_1.front(), s21_list_1.Front());
  EXPECT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_EQ(s21_list_1.Back(), std_list_1.back());
  EXPECT_EQ(s21_list_1.Front(), std_list_1.front());
}

TEST(list, PopFront_1) {
  s21::list<int> s21_list_1;
  s21_list_1.PushBack(1);
  s21_list_1.PushFront(50);

  std::list<int> std_list_1;
  std_list_1.push_back(1);
  std_list_1.push_front(50);

  EXPECT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_EQ(std_list_1.back(), s21_list_1.Back());
  EXPECT_EQ(std_list_1.front(), s21_list_1.Front());

  s21_list_1.PopFront();
  std_list_1.pop_front();

  EXPECT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_EQ(s21_list_1.Back(), std_list_1.back());
  EXPECT_EQ(s21_list_1.Front(), std_list_1.front());
}

TEST(list, PopFront_2) {
  s21::list<int> s21_list_1;
  std::list<int> std_list_1;

  EXPECT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_TRUE(s21_list_1.IsEmpty());
  s21_list_1.PopFront();
  s21_list_1.PopBack();
  EXPECT_TRUE(s21_list_1.IsEmpty());
}

TEST(list, PopBack_1) {
  s21::list<int> s21_list_1;
  s21_list_1.PushBack(1);
  s21_list_1.PushFront(50);

  std::list<int> std_list_1;
  std_list_1.push_back(1);
  std_list_1.push_front(50);

  EXPECT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_EQ(std_list_1.back(), s21_list_1.Back());
  EXPECT_EQ(std_list_1.front(), s21_list_1.Front());

  s21_list_1.PopBack();
  std_list_1.pop_back();

  EXPECT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_EQ(s21_list_1.Back(), std_list_1.back());
  EXPECT_EQ(s21_list_1.Front(), std_list_1.front());
}

TEST(list, begin_1) {
  s21::list<int> s21_list_1 = {10, 20, 30, 40};
  s21::list<int> s21_list_2 = {1, 2, 3, 4};
  std::list<int> std_list_1 = {10, 20, 30, 40};
  std::list<int> std_list_2 = {1, 2, 3, 4};

  EXPECT_EQ(*std_list_1.begin(), 10);
  EXPECT_EQ(*std_list_2.begin(), 1);
  EXPECT_EQ(*s21_list_1.Begin(), 10);
  EXPECT_EQ(*s21_list_2.Begin(), 1);
}

TEST(list, begin_2) {
  s21::list<int> s21_list_1 = {10, 20, 30, 40};
  std::list<int> std_list_1 = {10, 20, 30, 40};

  EXPECT_EQ(*std_list_1.begin(), *std_list_1.begin());
  auto x = s21_list_1.Begin();
  for (auto i = std_list_1.begin(); i != std_list_1.end(); ++i) {
    ASSERT_EQ(*i, *x);
    x++;
  }

  auto y = std_list_1.begin();
  for (auto i = s21_list_1.Begin(); i != s21_list_1.End(); ++i) {
    ASSERT_EQ(*i, *y);
    y++;
  }
}

TEST(list, end_1) {
  s21::list<int> s21_list_1 = {10, 20, 30, 40, 505};
  s21::list<int> s21_list_2 = {1, 2, 3, 44};
  std::list<int> std_list_1 = {10, 20, 30, 40, 505};
  std::list<int> std_list_2 = {1, 2, 3, 44};

  EXPECT_EQ(*std_list_1.end(), 5);
  EXPECT_EQ(*std_list_2.end(), 4);
  EXPECT_ANY_THROW(*s21_list_1.End());
  EXPECT_ANY_THROW(*s21_list_2.End());
}

TEST(list, erase_1) {
  s21::list<int> s21_list_1 = {10, 20, 30, 40, 50};
  std::list<int> std_list_1 = {10, 20, 30, 40, 50};
  EXPECT_EQ(std_list_1.size(), s21_list_1.GetSize());
  auto i = s21_list_1.Begin();
  i += 2;
  s21_list_1.Erase(i);

  auto j = std_list_1.begin();
  j++;
  j++;
  std_list_1.erase(j);
  EXPECT_EQ(std_list_1.size(), s21_list_1.GetSize());

  auto x = s21_list_1.Begin();
  for (auto i = std_list_1.begin(); i != std_list_1.end(); ++i) {
    ASSERT_EQ(*i, *x);
    x++;
  }
}

TEST(list, erase_2) {
  s21::list<int> s21_list;

  EXPECT_THROW(s21_list.Erase(s21_list.Begin()), std::out_of_range);
  EXPECT_THROW(s21_list.Erase(s21_list.End()), std::out_of_range);
  s21::list<int> s21_list2{1, 2, 3};
  std::list<int> std_list2{1, 2, 3};
  auto i = s21_list.Begin();
  EXPECT_THROW(i += 5, std::out_of_range);
}

TEST(list, erase_3) {
  s21::list<int> s21_list{35};
  std::list<int> std_list{35};
  s21_list.Erase(s21_list.Begin());
  std_list.erase(std_list.begin());
}

TEST(list, erase_4) {
  s21::list<int> s21_list{-5, 1, 2, 3, 0, 0, 0, 0, 1, 2, 3};
  ;
  std::list<int> std_list{-5, 1, 2, 3, 0, 0, 0, 0, 1, 2, 3};
  ;

  auto std_x = std_list.begin();
  auto s21_x = s21_list.Begin();

  for (int i = 0; i < 4; i++) {
    std_x++;
    s21_x++;
  }

  auto std_y = std_list.begin();
  auto s21_y = s21_list.Begin();

  for (int i = 0; i < 8; i++) {
    std_y++;
    s21_y++;
  }

  s21_list.Erase(s21_x, s21_y);
  std_list.erase(std_x, std_y);

  EXPECT_TRUE(isEqual(s21_list, std_list));
}

TEST(list, resize_1) {
  s21::list<int> s21_list_1 = {10, 20, 30, 40, 50};
  std::list<int> std_list_1 = {10, 20, 30, 40, 50};
  std_list_1.resize(7, 5);
  s21_list_1.Resize(7, 5);

  auto x = s21_list_1.Begin();
  for (auto i = std_list_1.begin(); i != std_list_1.end(); ++i) {
    ASSERT_EQ(*i, *x);
    x++;
  }
}

TEST(list, resize_2) {
  s21::list<int> s21_list_1{10, 20, 30, 40, 50};
  std::list<int> std_list_1{10, 20, 30, 40, 50};
  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  std_list_1.resize(2);
  s21_list_1.Resize(2);
  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());

  auto x = s21_list_1.Begin();
  for (auto i = std_list_1.begin(); i != std_list_1.end(); ++i) {
    ASSERT_EQ(*i, *x);
    x++;
  }
}

TEST(list, resize_3) {
  s21::list<int> s21_list_1{10, 20, 30, 40, 50};
  std::list<int> std_list_1{10, 20, 30, 40, 50};
  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  std_list_1.resize(0);
  s21_list_1.Resize(0);
  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
}

TEST(list, resize_4) {
  s21::list<int> s21_list_1;
  std::list<int> std_list_1;
  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  std_list_1.resize(10, 5);
  s21_list_1.Resize(10, 5);
  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  auto x = s21_list_1.Begin();
  for (auto i = std_list_1.begin(); i != std_list_1.end(); ++i) {
    ASSERT_EQ(*i, *x);
    x++;
  }
}

TEST(list, splice_1) {
  s21::list<int> s21_list_1;
  s21::list<int> s21_list_2;
  std::list<int> std_list_1;
  std::list<int> std_list_2;

  std_list_1.resize(3, 5);
  std_list_2.resize(4, 10);
  s21_list_1.Resize(3, 5);
  s21_list_2.Resize(4, 10);

  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  ASSERT_EQ(s21_list_2.GetSize(), std_list_2.size());

  auto pos_s21 = s21_list_1.Begin();
  auto pos_std = std_list_1.begin();
  pos_std++;
  pos_std++;

  s21_list_1.Splice(pos_s21 += 2, s21_list_2);
  std_list_1.splice(pos_std, std_list_2);

  auto x = s21_list_1.Begin();
  for (auto i = std_list_1.begin(); i != std_list_1.end(); ++i) {
    ASSERT_EQ(*i, *x);
    x++;
  }
}

TEST(list, splice_2) {
  s21::list<int> s21_list_1;
  s21::list<int> s21_list_2;
  std::list<int> std_list_1;
  std::list<int> std_list_2;

  std_list_1.resize(3, 5);
  std_list_2.resize(4, 10);
  s21_list_1.Resize(3, 5);
  s21_list_2.Resize(4, 10);

  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  ASSERT_EQ(s21_list_2.GetSize(), std_list_2.size());

  auto pos_s21 = s21_list_1.End();
  auto pos_std = std_list_1.end();

  s21_list_1.Splice(pos_s21, s21_list_2);
  std_list_1.splice(pos_std, std_list_2);

  auto x = s21_list_1.Begin();
  for (auto i = std_list_1.begin(); i != std_list_1.end(); ++i) {
    ASSERT_EQ(*i, *x);
    x++;
  }
}

TEST(list, splice_3) {
  s21::list<int> s21_list_1;
  s21::list<int> s21_list_2;
  std::list<int> std_list_1;
  std::list<int> std_list_2;

  std_list_1.resize(3, 5);
  s21_list_1.Resize(3, 5);

  s21_list_1.Splice(s21_list_1.Begin(), s21_list_2);
  std_list_1.splice(std_list_1.begin(), std_list_2);

  EXPECT_TRUE(isEqual(s21_list_1, std_list_1));
  EXPECT_EQ(s21_list_2.IsEmpty(), std_list_2.empty());
}

TEST(list, splice_4) {
  s21::list<int> s21_list_1;
  s21::list<int> s21_list_2;
  std::list<int> std_list_1;
  std::list<int> std_list_2;

  std_list_2.resize(3, 5);
  s21_list_2.Resize(3, 5);

  s21_list_1.Splice(s21_list_1.Begin(), s21_list_2);
  std_list_1.splice(std_list_1.begin(), std_list_2);

  EXPECT_TRUE(isEqual(s21_list_1, std_list_1));
  EXPECT_EQ(s21_list_2.IsEmpty(), std_list_2.empty());
}

TEST(list, splice_5) {
  s21::list<int> s21_list_1;
  s21::list<int> s21_list_2;
  std::list<int> std_list_1;
  std::list<int> std_list_2;

  std_list_1.resize(3, 5);
  std_list_2.resize(4, 10);
  s21_list_1.Resize(3, 5);
  s21_list_2.Resize(4, 10);

  auto pos_s21 = s21_list_1.Begin();
  auto pos_std = std_list_1.begin();
  pos_s21 += 2;
  pos_std++;
  pos_std++;

  s21_list_1.Splice(pos_s21, s21_list_2);
  std_list_1.splice(pos_std, std_list_2);

  auto x = s21_list_1.Begin();
  for (auto i = std_list_1.begin(); i != std_list_1.end(); ++i) {
    ASSERT_EQ(*i, *x);
    x++;
  }
}

TEST(list, splice_6) {
  s21::list<int> s21_list_1;
  std::list<int> std_list_1;

  std_list_1.resize(3, 5);
  s21_list_1.Resize(3, 5);

  auto pos_s21 = s21_list_1.Begin();
  auto pos_std = std_list_1.begin();
  pos_s21 += 2;
  pos_std++;
  pos_std++;

  s21::list<int> s21_list_2(s21_list_1);
  std::list<int> std_list_2(std_list_1);

  s21_list_1.Splice(pos_s21, s21_list_2);
  std_list_1.splice(pos_std, std_list_2);

  EXPECT_TRUE(isEqual(s21_list_1, std_list_1));
  EXPECT_TRUE(s21_list_2.IsEmpty() && std_list_2.empty());

  auto x = s21_list_1.Begin();
  for (auto i = std_list_1.begin(); i != std_list_1.end(); ++i) {
    ASSERT_EQ(*i, *x);
    x++;
  }
}

TEST(list, splice_7) {
  s21::list<int> s21_list_1;
  s21_list_1.Resize(3, 5);

  auto s21_size = s21_list_1.GetSize();

  auto pos_s21 = s21_list_1.Begin();
  pos_s21 += 2;
  s21_list_1.Splice(pos_s21, s21_list_1);
  EXPECT_EQ(s21_size, s21_list_1.GetSize());
  EXPECT_FALSE(s21_list_1.IsEmpty());
}

TEST(list, swap_1) {
  s21::list<int> s21_list_1{2, 4, 6};
  s21::list<int> s21_list_2{1, 3, 5, 7};
  std::list<int> std_list_1{2, 4, 6};
  std::list<int> std_list_2{1, 3, 5, 7};

  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  ASSERT_EQ(s21_list_2.GetSize(), std_list_2.size());

  std_list_1.swap(std_list_2);
  s21_list_1.Swap(s21_list_2);

  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  ASSERT_EQ(s21_list_2.GetSize(), std_list_2.size());
}

TEST(list, merge_1) {
  s21::list<int> s21_list_1{2, 4, 6};
  s21::list<int> s21_list_2{1, 3, 5, 7};

  std::list<int> std_list_1{2, 4, 6};
  std::list<int> std_list_2{1, 3, 5, 7};

  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  ASSERT_EQ(s21_list_2.GetSize(), std_list_2.size());

  std_list_1.merge(std_list_2);
  s21_list_1.Merge(s21_list_2);

  ASSERT_TRUE(isEqual(s21_list_1, std_list_1));

  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  ASSERT_EQ(s21_list_2.GetSize(), std_list_2.size());
}

TEST(list, sort_1) {
  s21::list<int> s21_list_1{22, 14, 1};
  s21::list<int> s21_list_2{1, 83, -45, 22};

  std::list<int> std_list_1{22, 14, 1};
  std::list<int> std_list_2{1, 83, -45, 22};

  s21_list_1.Sort();
  std_list_1.sort();
  s21_list_2.Sort();
  std_list_2.sort();
  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  ASSERT_EQ(s21_list_2.GetSize(), std_list_2.size());

  ASSERT_TRUE(isEqual(s21_list_1, std_list_1));
  ASSERT_TRUE(isEqual(s21_list_2, std_list_2));
}

TEST(list, unique_1) {
  s21::list<int> s21_list_1{22, 14, 22};
  s21::list<int> s21_list_2{1, 1, -45, 22};

  std::list<int> std_list_1{22, 14, 22};
  std::list<int> std_list_2{1, 1, -45, 22};

  std_list_1.merge(std_list_2);
  s21_list_1.Merge(s21_list_2);

  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  ASSERT_EQ(s21_list_2.GetSize(), std_list_2.size());

  s21_list_1.Unique();
  std_list_1.unique();
  ASSERT_TRUE(isEqual(s21_list_1, std_list_1));

  s21_list_1.Sort();
  std_list_1.sort();
  ASSERT_TRUE(isEqual(s21_list_1, std_list_1));
}

TEST(list, unique_2) {
  s21::list<int> s21_list_1;
  s21_list_1.Unique();
  ASSERT_TRUE(s21_list_1.IsEmpty());
}

TEST(list, reverse_1) {
  s21::list<int> s21_list_1{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> std_list_1{1, 2, 3, 4, 5, 6, 7, 8, 9};

  std_list_1.reverse();
  s21_list_1.Reverse();

  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  EXPECT_TRUE(isEqual(s21_list_1, std_list_1));

  s21::list<int> s21_list_2 = s21_list_1;
  s21_list_1.Clear();
  ASSERT_TRUE(isEqual(s21_list_2, std_list_1));
}

TEST(list, insert_remove_1) {
  s21::list<int> s21_list_1{22, 14, 22};
  std::list<int> std_list_1{22, 14, 22};

  std_list_1.insert(std_list_1.end(), 777);
  s21_list_1.Insert(s21_list_1.End(), 777);
  std_list_1.insert(std_list_1.begin(), 777);
  s21_list_1.Insert(s21_list_1.Begin(), 777);
  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  ASSERT_TRUE(isEqual(s21_list_1, std_list_1));
  std_list_1.remove(777);
  s21_list_1.Remove(777);
  ASSERT_EQ(s21_list_1.GetSize(), std_list_1.size());
  ASSERT_TRUE(isEqual(s21_list_1, std_list_1));
}

TEST(list, insert_2) {
  s21::list<int> s21_list = {11, 5};
  auto s21_iter = s21_list.Begin();
  EXPECT_ANY_THROW({ s21_list.Insert(s21_iter -= 2, 2); });
  EXPECT_ANY_THROW({ s21_list.Insert(s21_list.Begin() - 2, 2); });
}

TEST(list, insert_3) {
  s21::list<int> s21_list = {11, 5};
  std::list<int> std_list = {11, 5};

  s21_list.Insert(s21_list.Begin()++, 777);
  std_list.insert(std_list.begin()++, 777);
}

TEST(list, insert_many_1) {
  s21::list<int> s21_list_1{22};
  std::list<int> std_list_1{22};
  std_list_1.insert(std_list_1.begin(), 14);
  s21_list_1.InsertMany(s21_list_1.Begin(), 14);
  ASSERT_TRUE(isEqual(s21_list_1, std_list_1));

  std_list_1.insert(std_list_1.begin(), 17);
  std_list_1.insert(std_list_1.begin(), 16);
  std_list_1.insert(std_list_1.begin(), 15);
  s21_list_1.InsertMany(s21_list_1.Begin(), 15, 16, 17);
  ASSERT_TRUE(isEqual(s21_list_1, std_list_1));

  std_list_1.insert(std_list_1.end(), 0);
  std_list_1.insert(std_list_1.end(), 0);
  s21_list_1.InsertMany(s21_list_1.End(), 0, 0);
  ASSERT_TRUE(isEqual(s21_list_1, std_list_1));
}

TEST(list, insert_many_2) {
  s21::list<int> s21_list_1{22};
  std::list<int> std_list_1{22};
  std_list_1.insert(std_list_1.end(), 14);
  s21_list_1.InsertManyToBack(14);
  ASSERT_TRUE(isEqual(s21_list_1, std_list_1));

  std_list_1.insert(std_list_1.end(), 0);
  std_list_1.insert(std_list_1.end(), 0);
  s21_list_1.InsertManyToBack(0, 0);
  ASSERT_TRUE(isEqual(s21_list_1, std_list_1));
}

TEST(list, insert_many_3) {
  s21::list<int> s21_list_1{22};
  std::list<int> std_list_1{22};
  std_list_1.insert(std_list_1.begin(), 14);
  s21_list_1.InsertManyToFront(14);
  ASSERT_TRUE(isEqual(s21_list_1, std_list_1));

  std_list_1.insert(std_list_1.begin(), 0);
  std_list_1.insert(std_list_1.begin(), 0);
  s21_list_1.InsertManyToFront(0, 0);
  ASSERT_TRUE(isEqual(s21_list_1, std_list_1));
}

template <typename ValueType>
bool isEqual(s21::list<ValueType>& s21_list,
             std::list<ValueType>& std_list_compare) {
  if (std_list_compare.size() != s21_list.GetSize()) {
    return false;
  }
  auto s21_iter = s21_list.Begin();
  auto std_iter = std_list_compare.begin();
  for (size_t i = 0; i < std_list_compare.size(); ++i) {
    if (*s21_iter != *std_iter) {
      return false;
    }
    ++s21_iter;
    ++std_iter;
  }
  return true;
}

// COMPLETE

template <typename ValueType>
void print(s21::list<ValueType>& s21_list) {
  std::cout << "s21_list elements: ";
  auto x = s21_list.Begin();
  for (auto i = s21_list.Begin(); i != s21_list.End(); ++i) {
    std::cout << *x << " ";
    x++;
  }
  std::cout << std::endl;
  std::cout << "s21_list size: " << s21_list.GetSize() << std::endl;
}

template <typename ValueType>
void print(std::list<ValueType>& std_list) {
  std::cout << "std_list elements: ";
  auto x = std_list.begin();
  for (auto i = std_list.begin(); i != std_list.end(); ++i) {
    std::cout << *x << " ";
    x++;
  }
  std::cout << std::endl;
  std::cout << "std_list size: " << std_list.size() << std::endl;
}
