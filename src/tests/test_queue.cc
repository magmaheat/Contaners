#include <gtest/gtest.h>

#include <queue>

#include "../s21_containers.h"

TEST(queue, create_1) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;

  EXPECT_TRUE(s21_queue.empty());
  EXPECT_EQ(std_queue.size(), s21_queue.size());

  s21::queue<char> s21_queuechar;
  std::queue<char> std_char;
  EXPECT_TRUE(s21_queuechar.empty());
  EXPECT_EQ(std_char.size(), s21_queuechar.size());

  s21::queue<float> s21_queuefloat;
  std::queue<float> std_float;
  EXPECT_TRUE(s21_queuefloat.empty());
  EXPECT_EQ(std_float.size(), s21_queuefloat.size());

  s21::queue<double> s21_queuedouble;
  std::queue<float> std_double;
  EXPECT_TRUE(s21_queuedouble.empty());
  EXPECT_EQ(std_double.size(), s21_queuedouble.size());

  s21::queue<std::string> s21_queuestring;
  std::queue<std::string> std_string;
  EXPECT_TRUE(s21_queuestring.empty());
  EXPECT_EQ(std_string.size(), s21_queuestring.size());
}

TEST(queue, create_2) {
  s21::queue<int> s21_queue = {1, 2, 3, 4, 5};
  std::queue<int> std_queue({1, 2, 3, 4, 5});
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
}

TEST(queue, create_3) {
  s21::queue<char> s21_queue_char = {'h', 'e', 'l', 'l', 'o'};
  std::queue<char> std_queue_char({'h', 'e', 'l', 'l', 'o'});
  EXPECT_EQ(s21_queue_char.size(), std_queue_char.size());

  s21::queue<float> s21_queuefloat = {1.2, 2.3, 3.4, 4.5, 5.0};
  std::queue<float> std_float({1.2, 2.3, 3.4, 4.5, 5.0});
  EXPECT_EQ(s21_queuefloat.size(), std_float.size());

  s21::queue<std::string> s21_queuestring = {"Hello ", "world!"};
  std::queue<std::string> std_string({"Hello ", "world!"});
  EXPECT_EQ(s21_queuestring.size(), std_string.size());
}

TEST(queue, copy_1) {
  s21::queue<int> que = {1, 2, 3, 4, 5};
  std::queue<int> s21_queuestd({1, 2, 3, 4, 5});
  s21::queue<int> que2 = que;
  std::queue<int> s21_queuestd2 = s21_queuestd;
  EXPECT_EQ(que.size(), s21_queuestd.size());
  EXPECT_EQ(que2.size(), s21_queuestd2.size());

  s21::queue<float> s21_queuefloat({1.2, 2.3, 3.4, 4.5, 5.0});
  std::queue<float> s21_queuefloat_std({1.2, 2.3, 3.4, 4.5, 5.0});
  s21::queue<float> s21_queuefloat2 = s21_queuefloat;
  std::queue<float> s21_queuefloat_std2 = s21_queuefloat_std;
  EXPECT_EQ(s21_queuefloat.size(), s21_queuefloat_std.size());
  EXPECT_EQ(s21_queuefloat2.size(), s21_queuefloat_std2.size());
}

TEST(queue, copy_2) {
  s21::queue<char> s21_queue_char({'h', 'e', 'l', 'l', 'o'});
  std::queue<char> std_queue_char({'h', 'e', 'l', 'l', 'o'});
  s21::queue<char> s21_queue_char2 = s21_queue_char;
  std::queue<char> std_queue_char2 = std_queue_char;
  EXPECT_EQ(s21_queue_char.size(), std_queue_char.size());
  EXPECT_EQ(s21_queue_char2.size(), std_queue_char2.size());
}

TEST(queue, move_1) {
  s21::queue<int> s21_queue = {1, 2, 3, 4, 5};
  std::queue<int> std_queue({1, 2, 3, 4, 5});
  EXPECT_EQ(s21_queue.size(), std_queue.size());

  s21::queue<int> s21_queue2 = std::move(s21_queue);
  std::queue<int> std_queue2 = std::move(std_queue);
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue2.size(), std_queue2.size());
}

TEST(queue, move_2) {
  s21::queue<char> s21_queuechar = {'h', 'e', 'l', 'l', 'o'};
  std::queue<char> s21_queuechar_std({'h', 'e', 'l', 'l', 'o'});
  EXPECT_EQ(s21_queuechar.size(), s21_queuechar_std.size());
  s21::queue<char> s21_queuechar2;
  std::queue<char> s21_queuechar_std2;
  s21_queuechar2 = std::move(s21_queuechar);
  s21_queuechar_std2 = std::move(s21_queuechar_std);
  EXPECT_EQ(s21_queuechar.size(), s21_queuechar_std.size());
  EXPECT_EQ(s21_queuechar_std2.size(), s21_queuechar2.size());
}

TEST(queue, front_back_1) {
  s21::queue<int> s21_queue({1, 2, 3, 4, 5});
  std::queue<int> std_queue({1, 2, 3, 4, 5});
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());

  s21::queue<char> s21_queuechar({'h', 'e', 'l', 'l', 'o'});
  std::queue<char> s21_queuechar_std({'h', 'e', 'l', 'l', 'o'});
  EXPECT_EQ(s21_queuechar.front(), s21_queuechar_std.front());
  EXPECT_EQ(s21_queuechar.back(), s21_queuechar_std.back());
}

TEST(queue, front_back_2) {
  s21::queue<int> s21_queue;
  EXPECT_THROW({ s21_queue.back(); }, std::out_of_range);
  EXPECT_THROW({ s21_queue.front(); }, std::out_of_range);
}

TEST(queue, PushPop_1) {
  s21::queue<int> s21_queue({4, 5});
  std::queue<int> std_queue({4, 5});
  s21_queue.push(6);
  std_queue.push(6);
  EXPECT_EQ(s21_queue.size(), s21_queue.size());

  EXPECT_EQ(std_queue.front(), s21_queue.front());
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(std_queue.front(), s21_queue.front());
  EXPECT_EQ(std_queue.back(), s21_queue.back());
  s21_queue.pop();
  s21_queue.pop();
  std_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.size(), s21_queue.size());
  EXPECT_THROW({ s21_queue.front(); }, std::out_of_range);
  EXPECT_THROW({ s21_queue.back(); }, std::out_of_range);
}

TEST(queue, PushPop_2) {
  s21::queue<int> s21_queue = {1, 2, 3, 4, 5, 6};
  std::queue<int> std_queue({1, 2, 3, 4, 5, 6});
  s21_queue.push(7);
  s21_queue.push(8);
  std_queue.push(7);
  std_queue.push(8);
  s21_queue.pop();
  std_queue.pop();
  while (s21_queue.size()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(queue, swap_1) {
  s21::queue<int> s21_queue = {1, 2, 3};
  s21::queue<int> s21_queue2 = {4, 5};
  std::queue<int> std_queue({1, 2, 3});
  std::queue<int> std_queue2({4, 5});

  EXPECT_EQ(std_queue.size(), s21_queue.size());
  s21_queue.swap(s21_queue2);
  std_queue.swap(std_queue2);
  EXPECT_EQ(std_queue.size(), s21_queue.size());
  EXPECT_EQ(std_queue2.size(), s21_queue2.size());

  while (s21_queue.size()) {
    EXPECT_EQ(s21_queue.front(), std_queue.front());
    EXPECT_EQ(s21_queue.back(), std_queue.back());
    s21_queue.pop();
    std_queue.pop();
  }
}

TEST(queue, swap_2) {
  s21::queue<int> s21_queue = {1, 2, 3};
  s21::queue<int> s21_queue2;
  std::queue<int> std_queue({1, 2, 3});
  std::queue<int> std_queue2;

  EXPECT_EQ(std_queue.size(), s21_queue.size());
  s21_queue.swap(s21_queue2);
  std_queue.swap(std_queue2);
  EXPECT_EQ(std_queue.size(), s21_queue.size());
  EXPECT_EQ(std_queue2.size(), s21_queue2.size());
}

TEST(queue, swap_3) {
  s21::queue<int> s21_queue;
  s21::queue<int> s21_queue2 = {4, 5};
  std::queue<int> std_queue;
  std::queue<int> std_queue2({4, 5});

  EXPECT_EQ(std_queue.size(), s21_queue.size());
  s21_queue.swap(s21_queue2);
  std_queue.swap(std_queue2);
  EXPECT_EQ(std_queue.size(), s21_queue.size());
  EXPECT_EQ(std_queue2.size(), s21_queue2.size());
}

TEST(queue, swap_4) {
  s21::queue<int> s21_queue;
  s21::queue<int> s21_queue2;
  std::queue<int> std_queue;
  std::queue<int> std_queue2;

  EXPECT_EQ(std_queue.size(), s21_queue.size());
  s21_queue.swap(s21_queue2);
  std_queue.swap(std_queue2);
  EXPECT_EQ(std_queue.size(), s21_queue.size());
  EXPECT_EQ(std_queue2.size(), s21_queue2.size());
}

TEST(queue, insert_many_1) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue.insert_many_back(3);
  std_queue.push(3);
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}

TEST(queue, insert_many_2) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue.insert_many_back(1, 2);
  std_queue.push(1);
  std_queue.push(2);
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}

TEST(queue, insert_many_3) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  s21_queue.insert_many_back();
  EXPECT_THROW({ s21_queue.back(); }, std::out_of_range);
  EXPECT_THROW({ s21_queue.front(); }, std::out_of_range);
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}

TEST(queue, insert_many_4) {
  s21::queue<int> s21_queue = {5, 10, 15};
  std::queue<int> std_queue({5, 10, 15});
  s21_queue.insert_many_back(3);
  std_queue.push(3);
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  s21_queue.insert_many_back(1, 2);
  std_queue.push(1);
  std_queue.push(2);
  s21_queue.pop();
  std_queue.pop();
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
}
