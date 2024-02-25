#include <gtest/gtest.h>

#include <stack>

#include "../s21_containers.h"

TEST(stack, create_1) {
  s21::stack<int> s21_stack;
  EXPECT_TRUE(s21_stack.empty());
  std::stack<int> std_stack;
  EXPECT_EQ(std_stack.size(), s21_stack.size());

  s21::stack<double> s21_stack_double;
  EXPECT_TRUE(s21_stack.empty());
  std::stack<double> std_stack_double;
  EXPECT_EQ(std_stack_double.size(), s21_stack_double.size());

  s21::stack<char> s21_stack_char;
  std::stack<char> std_stack_char;
  EXPECT_EQ(std_stack_char.size(), s21_stack_char.size());

  s21::stack<float> st_float;
  std::stack<float> s_float;
  EXPECT_EQ(s_float.size(), st_float.size());
}

TEST(stack, create_2) {
  s21::stack<double> s21_stack;
  std::stack<double> std_stack;
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
  if (!s21_stack.empty()) {
    s21_stack.pop();
  }

  if (!std_stack.empty()) {
    std_stack.pop();
  }
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(stack, create_3) {
  s21::stack<double> s21_stack;
  s21::stack<double> std_stack;
  EXPECT_EQ(s21_stack.empty(), std_stack.empty());
  s21_stack.push(5.25);
  s21_stack.push(1.52);
  std_stack.push(5.25);
  std_stack.push(1.52);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(stack, PushPop_1) {
  s21::stack<int> s21_stack;
  std::stack<int> std_stack;
  s21_stack.push(5);
  s21_stack.push(15);
  std_stack.push(5);
  std_stack.push(15);
  EXPECT_FALSE(s21_stack.empty());
  EXPECT_EQ(s21_stack.size(), std_stack.size());

  s21_stack.pop();
  std_stack.pop();
  EXPECT_FALSE(s21_stack.empty());
  EXPECT_EQ(s21_stack.size(), std_stack.size());

  s21_stack.pop();
  std_stack.pop();
  EXPECT_TRUE(s21_stack.empty());
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(stack, PushPop_2) {
  s21::stack<float> s21_stack;
  std::stack<float> std_stack;
  std_stack.push(5.5);
  std_stack.push(15.2);
  s21_stack.push(5.5);
  s21_stack.push(15.2);
  EXPECT_FALSE(s21_stack.empty());
  EXPECT_EQ(s21_stack.size(), std_stack.size());

  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());

  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(stack, PushPop_3) {
  s21::stack<double> s21_stack;
  std::stack<double> std_stack;
  s21_stack.push(5.5);
  s21_stack.push(15.2);
  std_stack.push(5.5);
  std_stack.push(15.2);
  EXPECT_FALSE(s21_stack.empty());
  EXPECT_EQ(s21_stack.size(), std_stack.size());

  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());

  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(stack, PushPop_4) {
  s21::stack<char> s21_stack;
  std::stack<char> std_stack({'h', 'e', 'l', 'l', 'o'});
  s21_stack.push('h');
  s21_stack.push('e');
  s21_stack.push('l');
  s21_stack.push('l');
  s21_stack.push('o');

  EXPECT_FALSE(s21_stack.empty());
  EXPECT_EQ(s21_stack.size(), std_stack.size());

  s21_stack.pop();
  std_stack.pop();
  EXPECT_EQ(s21_stack.size(), std_stack.size());
}

TEST(stack, PushPop_5) {
  std::stack<std::string> std_stack({"Hello", " world!", "Keep going!"});
  s21::stack<std::string> s21_stack;
  s21_stack.push("Hello");
  s21_stack.push(" world!");
  s21_stack.push("Keep going!");

  EXPECT_FALSE(s21_stack.empty());
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());

  s21_stack.pop();
  std_stack.pop();
  EXPECT_FALSE(s21_stack.empty());
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack.top(), std_stack.top());
}

TEST(stack, init_1) {
  s21::stack<int> s21_stack = {1, 4};
  std::stack<int> std_stack({1, 4});
  EXPECT_EQ(s21_stack.size(), std_stack.size());

  s21::stack<double> s21_stack_d = {1.5, 4.5, 6.4, 5.1, 8.0};
  std::stack<double> std_stack_d({1.5, 4.5, 6.4, 5.1, 8.0});
  EXPECT_FALSE(s21_stack_d.empty());
  EXPECT_EQ(s21_stack_d.size(), std_stack_d.size());

  s21::stack<char> s21_stack_char = {'h', 'e', 'l', 'l', 'o'};
  std::stack<char> std_stack_char({'h', 'e', 'l', 'l', 'o'});
  EXPECT_FALSE(s21_stack_char.empty());
  EXPECT_EQ(s21_stack_char.size(), std_stack_char.size());

  s21::stack<std::string> s21_stack_st = {"hello,", "my", "dear"};
  std::stack<std::string> std_stack_st({"hello,", "my", "dear"});
  EXPECT_FALSE(s21_stack_st.empty());
  EXPECT_EQ(s21_stack_st.size(), std_stack_st.size());
}

TEST(stack, init_2) {
  s21::stack<int> s21_stack = {1, 4, 6, 5, 8};
  std::stack<int> std_stack({1, 4, 6, 5, 8});
  s21::stack<int> s21_stack_copy(s21_stack);
  std::stack<int> std_stack_copy(std_stack);
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack_copy.size(), std_stack_copy.size());
}

TEST(stack, init_3) {
  s21::stack<int> s21_stack = {1, 4, 6, 5, 8};
  std::stack<int> std_stack({1, 4, 6, 5, 8});
  s21::stack<int> s21_stack_copy(std::move(s21_stack));
  std::stack<int> std_stack_copy(std::move(std_stack));
  EXPECT_TRUE(s21_stack.empty());
  EXPECT_EQ(std_stack_copy.size(), s21_stack_copy.size());

  s21_stack = std::move(s21_stack_copy);
  std_stack = std::move(std_stack_copy);
  EXPECT_EQ(std_stack.size(), s21_stack.size());
  EXPECT_EQ(std_stack_copy.size(), s21_stack_copy.size());
}

TEST(stack, init_4) {
  s21::stack<int> s21_stack = {1, 4, 6, 5, 8};
  std::stack<int> std_stack({1, 4, 6, 5, 8});
  s21::stack<int> s21_stack_copy;
  std::stack<int> std_stack_copy;
  s21_stack_copy = s21_stack;
  std_stack_copy = std_stack;

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(s21_stack_copy.size(), std_stack_copy.size());
}

TEST(stack, top_1) {
  s21::stack<std::string> s21_stack = {"What", "are", "we", "doing", "next"};
  std::stack<std::string> std_stack({"What", "are", "we", "doing", "next"});
  s21::stack<std::string> s21_stack_copy(std::move(s21_stack));
  std::stack<std::string> std_stack_copy(std::move(std_stack));

  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(std_stack_copy.size(), s21_stack_copy.size());
  EXPECT_EQ(std_stack_copy.top(), s21_stack_copy.top());
}

TEST(stack, top_2) {
  s21::stack<double> s21_stack = {1.2, 5.4, 3.0};
  std::stack<double> std_stack({1.2, 5.4, 3.0});
  s21::stack<double> s21_stack_copy(std::move(s21_stack));
  std::stack<double> std_stack_copy(std::move(std_stack));
  EXPECT_EQ(s21_stack.size(), std_stack.size());
  EXPECT_EQ(std_stack_copy.size(), s21_stack_copy.size());
  EXPECT_EQ(std_stack_copy.top(), s21_stack_copy.top());
  s21_stack_copy.pop();
  std_stack_copy.pop();
  EXPECT_EQ(std_stack_copy.top(), s21_stack_copy.top());
}

TEST(stack, top_3) {
  s21::stack<int> s21_stack;
  EXPECT_THROW({ s21_stack.top(); }, std::out_of_range);
}

TEST(stack, size_1) {
  s21::stack<int> s21_stack = {5, 8, 15};
  std::stack<int> std_stack({5, 8, 15});
  EXPECT_EQ(std_stack.size(), s21_stack.size());

  s21::stack<int> s21_copy = s21_stack;
  std::stack<int> std_copy = std_stack;
  EXPECT_EQ(std_stack.size(), s21_stack.size());

  s21::stack<int> s21_copy2 = std::move(s21_stack);
  std::stack<int> std_copy2 = std::move(std_stack);
  EXPECT_EQ(std_copy2.size(), s21_copy2.size());
  EXPECT_EQ(std_stack.size(), s21_stack.size());
}

TEST(stack, swap_1) {
  s21::stack<int> stack1 = {5, 10, 15};
  s21::stack<int> stack2 = {98, 87, 76};
  std::stack<int> stack_std1({5, 10, 15});
  std::stack<int> stack_std2({98, 87, 76});
  EXPECT_EQ(stack_std1.size(), stack1.size());
  EXPECT_EQ(stack_std1.top(), stack1.top());
  EXPECT_EQ(stack_std2.size(), stack2.size());
  EXPECT_EQ(stack_std2.top(), stack2.top());

  stack1.swap(stack2);
  stack_std1.swap(stack_std2);
  EXPECT_EQ(stack_std1.size(), stack1.size());
  EXPECT_EQ(stack_std2.size(), stack2.size());
}

TEST(stack, swap_2) {
  s21::stack<int> stack1 = {5, 10, 15};
  s21::stack<int> stack2;
  std::stack<int> stack_std1({5, 10, 15});
  std::stack<int> stack_std2;
  EXPECT_EQ(stack_std1.size(), stack1.size());
  EXPECT_EQ(stack_std2.size(), stack2.size());

  stack1.swap(stack2);
  stack_std1.swap(stack_std2);
  EXPECT_EQ(stack_std1.size(), stack1.size());
  EXPECT_EQ(stack_std2.size(), stack2.size());
}

TEST(stack, swap_3) {
  s21::stack<int> stack1 = {5, 10, 15};
  s21::stack<int> stack2;
  std::stack<int> stack_std1({5, 10, 15});
  std::stack<int> stack_std2;
  EXPECT_EQ(stack_std1.size(), stack1.size());
  EXPECT_EQ(stack_std2.size(), stack2.size());

  stack2.swap(stack1);
  stack_std2.swap(stack_std1);
  EXPECT_EQ(stack_std1.size(), stack1.size());
  EXPECT_EQ(stack_std2.size(), stack2.size());
}

TEST(stack, insert_many_1) {
  s21::stack<int> stack1{5, 10, 15};
  std::stack<int> stack_std1({5, 10, 15});
  stack1.insert_many_front(3);
  stack_std1.push(3);
  EXPECT_EQ(stack1.top(), 3);
  EXPECT_EQ(stack1.size(), stack_std1.size());
  stack1.insert_many_front(1, 2);
  stack_std1.push(1);
  stack_std1.push(2);
  EXPECT_EQ(stack1.top(), stack_std1.top());
  EXPECT_EQ(stack1.size(), stack_std1.size());
}

TEST(stack, insert_many_2) {
  s21::stack<std::string> stack1{"git add", "git commit", "git push"};
  s21::stack<std::string> stack_std1{"git add", "git commit", "git push"};
  stack1.insert_many_front("origin develop");
  stack_std1.push("origin develop");
  EXPECT_EQ(stack1.top(), stack_std1.top());
  EXPECT_EQ(stack1.size(), stack_std1.size());
  stack1.insert_many_front("good job!", "work is done");
  stack_std1.push("good job!");
  stack_std1.push("work is done");
  EXPECT_EQ(stack1.top(), stack_std1.top());
  EXPECT_EQ(stack1.size(), stack_std1.size());
}
