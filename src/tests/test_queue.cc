#include <gtest/gtest.h>

#include <queue>

#include "../s21_containers.h"

TEST(queue, create_1) {
  s21::queue<int> que;

  EXPECT_TRUE(que.empty());
  EXPECT_EQ(que.size(), 0);
  std::queue<int> s;
  EXPECT_EQ(s.size(), que.size());

  s21::queue<char> que_char;

  EXPECT_TRUE(que_char.empty());
  EXPECT_EQ(que_char.size(), 0);
  std::queue<char> s_char;
  EXPECT_EQ(s_char.size(), que_char.size());

  s21::queue<float> que_float;

  EXPECT_TRUE(que_float.empty());
  EXPECT_EQ(que_float.size(), 0);
  std::queue<float> s_float;
  EXPECT_EQ(s_float.size(), que_float.size());

  s21::queue<double> que_double;

  EXPECT_TRUE(que_double.empty());
  EXPECT_EQ(que_double.size(), 0);
  std::queue<float> s_double;
  EXPECT_EQ(s_double.size(), que_double.size());

  s21::queue<std::string> que_string;

  EXPECT_TRUE(que_string.empty());
  EXPECT_EQ(que_string.size(), 0);
  std::queue<std::string> s_string;
  EXPECT_EQ(s_string.size(), que_string.size());
}

TEST(queue, create_2) {
  s21::queue<int> que = {1, 2, 3, 4, 5};
  EXPECT_EQ(que.size(), 5);
  EXPECT_EQ(que.front(), 1);
  EXPECT_EQ(que.back(), 5);
}

TEST(queue, create_3) {
  s21::queue<char> que_char = {'h', 'e', 'l', 'l', 'o'};
  EXPECT_EQ(que_char.size(), 5);

  s21::queue<float> que_float = {1.2, 2.3, 3.4, 4.5, 5.0};

  s21::queue<std::string> que_string = {"Hello ", "world!"};
  EXPECT_EQ(que_string.size(), 2);
}

TEST(queue, copy_1) {
  s21::queue<int> que = {1, 2, 3, 4, 5};
  s21::queue<int> que2 = que;
  EXPECT_EQ(que.size(), 5);
  EXPECT_EQ(que.size(), que2.size());

  s21::queue<float> que_float = {1.2, 2.3, 3.4, 4.5, 5.0};
  s21::queue<float> que_float2 = que_float;
  EXPECT_EQ(que_float.size(), 5);
  EXPECT_EQ(que_float.size(), que_float2.size());
}

TEST(queue, copy_2) {
  s21::queue<char> que_char = {'h', 'e', 'l', 'l', 'o'};
  s21::queue<char> que_char2 = que_char;
  EXPECT_EQ(que_char.size(), 5);
  EXPECT_EQ(que_char.size(), que_char2.size());

  s21::queue<std::string> que_string = {"Hello ", "world!"};
  s21::queue<std::string> que_string2 = que_string;
  EXPECT_EQ(que_string.size(), 2);
  EXPECT_EQ(que_string.size(), que_string2.size());
}

TEST(queue, move_1) {
  s21::queue<int> que = {1, 2, 3, 4, 5};
  EXPECT_EQ(que.size(), 5);
  s21::queue<int> que2 = std::move(que);
  EXPECT_EQ(que.size(), 0);
  EXPECT_EQ(que2.size(), 5);

  s21::queue<float> que_float = {1.2, 2.3, 3.4, 4.5, 5.0};
  EXPECT_EQ(que_float.size(), 5);
  s21::queue<float> que_float2 = std::move(que_float);
  EXPECT_EQ(que_float.size(), 0);
  EXPECT_EQ(5, que_float2.size());
}

TEST(queue, move_2) {
  s21::queue<char> que_char = {'h', 'e', 'l', 'l', 'o'};
  EXPECT_EQ(que_char.size(), 5);
  s21::queue<char> que_char2;
  que_char2 = std::move(que_char);
  EXPECT_EQ(que_char.size(), 0);
  EXPECT_EQ(5, que_char2.size());

  s21::queue<std::string> que_string = {"Hello ", "world!"};
  EXPECT_EQ(que_string.size(), 2);
  s21::queue<std::string> que_string2 = std::move(que_string);
  EXPECT_EQ(que_string.size(), 0);
  EXPECT_EQ(2, que_string2.size());
}

TEST(queue, front_back_1) {
  s21::queue<int> que = {1, 2, 3, 4, 5};
  EXPECT_EQ(que.front(), 1);
  EXPECT_EQ(que.back(), 5);

  s21::queue<char> que_char = {'h', 'e', 'l', 'l', 'o'};
  EXPECT_EQ(que_char.front(), 'h');
  EXPECT_EQ(que_char.back(), 'o');

  s21::queue<float> que_float = {1.2, 2.3, 3.4, 4.5, 5.0};
  EXPECT_NEAR(que_float.front(), 1.2, 0.001);
  EXPECT_NEAR(que_float.back(), 5.0, 0.001);

  s21::queue<std::string> que_string = {"Hello ", "world!"};
  EXPECT_EQ(que_string.front(), "Hello ");
  EXPECT_EQ(que_string.back(), "world!");
}

TEST(queue, front_back_2) {
  s21::queue<double> s21_queue = {1.2, 5.4, 3.0};
  s21::queue<double> s21_queue_copy(std::move(s21_queue));
  EXPECT_EQ(s21_queue.size(), 0);
  EXPECT_EQ(3, s21_queue_copy.size());
  EXPECT_EQ(3.0, s21_queue_copy.back());
  EXPECT_EQ(1.2, s21_queue_copy.front());
}

TEST(queue, front_back_3) {
  s21::queue<int> s21_queue;
  EXPECT_THROW({ s21_queue.back(); }, std::out_of_range);
  EXPECT_THROW({ s21_queue.front(); }, std::out_of_range);
}

TEST(queue, PushPop_1) {
  s21::queue<int> que = {4, 5};
  que.push(6);
  EXPECT_EQ(que.size(), 3);

  std::queue<int> que_std;
  que_std.push(4);
  que_std.push(5);
  que_std.push(6);
  EXPECT_EQ(que_std.size(), que.size());

  EXPECT_EQ(que_std.front(), que.front());
  EXPECT_EQ(que_std.front(), 4);
  EXPECT_EQ(que.front(), 4);
  que.pop();
  que_std.pop();
  EXPECT_EQ(que.size(), 2);
  EXPECT_EQ(que_std.size(), 2);
  EXPECT_EQ(que_std.front(), 5);
  EXPECT_EQ(que.front(), 5);
  que.pop();
  que_std.pop();
  que.pop();
  que_std.pop();
  EXPECT_EQ(que.size(), 0);
  EXPECT_EQ(que_std.size(), 0);
  EXPECT_THROW({ que.front(); }, std::out_of_range);
}

TEST(queue, PushPop_2) {
  s21::queue<int> que_ = {1, 2, 3, 4, 5, 6};
  que_.push(7);
  que_.push(8);
  que_.pop();
  int i = 2;
  while (que_.size()) {
    EXPECT_EQ(que_.front(), i);
    que_.pop();
    i++;
  }
}

TEST(queue, swap_1) {
  s21::queue<int> que = {1, 2, 3};
  s21::queue<int> que2 = {4, 5};

  std::queue<int> que_std;
  que_std.push(1);
  que_std.push(2);
  que_std.push(3);

  std::queue<int> que_std2;
  que_std2.push(4);
  que_std2.push(5);

  EXPECT_EQ(3, que.size());
  EXPECT_EQ(2, que2.size());
  EXPECT_EQ(que_std.size(), 3);
  EXPECT_EQ(que_std2.size(), 2);

  que.swap(que2);
  EXPECT_EQ(2, que.size());
  EXPECT_EQ(3, que2.size());
  EXPECT_EQ(2, que.size());
  EXPECT_EQ(3, que2.size());
  EXPECT_EQ(que.front(), 4);
  EXPECT_EQ(que.back(), 5);
  EXPECT_EQ(que2.front(), 1);
  EXPECT_EQ(que2.back(), 3);

  que_std.swap(que_std2);
  EXPECT_EQ(2, que_std.size());
  EXPECT_EQ(3, que_std2.size());
  EXPECT_EQ(que_std.front(), 4);
  EXPECT_EQ(que_std.back(), 5);
  EXPECT_EQ(que_std2.front(), 1);
  EXPECT_EQ(que_std2.back(), 3);
}

TEST(queue, swap_2) {
  s21::queue<int> que;
  s21::queue<int> que2 = {4, 5};

  que.swap(que2);
  EXPECT_EQ(2, que.size());
  EXPECT_EQ(0, que2.size());
}

TEST(queue, insert_many_1) {
  s21::queue<int> que = {5, 10, 15};
  que.insert_many_back(3);
  EXPECT_EQ(que.back(), 3);
  EXPECT_EQ(que.front(), 5);
  EXPECT_EQ(que.size(), 4);

  que.insert_many_back(1, 2);
  que.pop();
  EXPECT_EQ(que.back(), 2);
  EXPECT_EQ(que.front(), 10);
  EXPECT_EQ(que.size(), 5);
}

TEST(queue, insert_many_2) {
  s21::queue<char> que = {'h'};
  que.insert_many_back('e', 'l', 'l', 'o');
  EXPECT_EQ(que.back(), 'o');
  EXPECT_EQ(que.front(), 'h');
  EXPECT_EQ(que.size(), 5);
  que.pop();
  EXPECT_EQ(que.back(), 'o');
  EXPECT_EQ(que.front(), 'e');
  EXPECT_EQ(que.size(), 4);
}
