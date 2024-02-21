// #include <gtest/gtest.h>

// #include <stack>

// #include "../s21_containers.h"

// TEST(stack, create_1) {
//   s21::stack<int> st;
//   EXPECT_TRUE(st.empty());
//   EXPECT_EQ(st.size(), 0);
//   std::stack<int> s;
//   EXPECT_EQ(s.size(), st.size());

//   s21::stack<double> st_double;
//   EXPECT_TRUE(st.empty());
//   EXPECT_EQ(st.size(), 0);
//   std::stack<double> s_double;
//   EXPECT_EQ(s_double.size(), st_double.size());

//   s21::stack<char> st_char;
//   EXPECT_TRUE(st_char.empty());
//   EXPECT_EQ(st_char.size(), 0);
//   std::stack<char> s_char;
//   EXPECT_EQ(s_char.size(), st_char.size());

//   s21::stack<float> st_float;
//   EXPECT_TRUE(st_float.empty());
//   EXPECT_EQ(st_float.size(), 0);
//   std::stack<float> s_float;
//   EXPECT_EQ(s_float.size(), st_float.size());
// }

// TEST(stack, create_2) {
//   s21::stack<double> st;
//   EXPECT_TRUE(st.empty());
//   st.pop();
//   EXPECT_EQ(st.size(), 0);
// }

// TEST(stack, create_3) {
//   s21::stack<double> st;
//   EXPECT_TRUE(st.empty());
//   st.push(5.25);
//   st.push(1.52);
//   EXPECT_EQ(st.size(), 2);
//   st.pop();
//   EXPECT_EQ(st.size(), 1);
//   st.pop();
//   EXPECT_EQ(st.size(), 0);
// }

// TEST(stack, PushPop_1) {
//   s21::stack<int> st;
//   st.push(5);
//   st.push(15);
//   EXPECT_FALSE(st.empty());
//   EXPECT_EQ(st.size(), 2);

//   st.pop();
//   EXPECT_FALSE(st.empty());
//   EXPECT_EQ(st.size(), 1);

//   st.pop();
//   EXPECT_TRUE(st.empty());
//   EXPECT_EQ(st.size(), 0);
// }

// TEST(stack, PushPop_2) {
//   s21::stack<float> st;
//   st.push(5.5);
//   st.push(15.2);
//   EXPECT_FALSE(st.empty());
//   EXPECT_EQ(st.size(), 2);

//   st.pop();
//   EXPECT_FALSE(st.empty());
//   EXPECT_EQ(st.size(), 1);

//   st.pop();
//   EXPECT_TRUE(st.empty());
//   EXPECT_EQ(st.size(), 0);
// }

// TEST(stack, PushPop_3) {
//   s21::stack<double> st;
//   st.push(5.5);
//   st.push(15.2);
//   EXPECT_FALSE(st.empty());
//   EXPECT_EQ(st.size(), 2);

//   st.pop();
//   EXPECT_FALSE(st.empty());
//   EXPECT_EQ(st.size(), 1);

//   st.pop();
//   EXPECT_TRUE(st.empty());
//   EXPECT_EQ(st.size(), 0);
// }

// TEST(stack, PushPop_4) {
//   s21::stack<char> st;
//   st.push('h');
//   st.push('e');
//   st.push('l');
//   st.push('l');
//   st.push('o');

//   EXPECT_FALSE(st.empty());
//   EXPECT_EQ(st.size(), 5);

//   st.pop();
//   EXPECT_FALSE(st.empty());
//   EXPECT_EQ(st.size(), 4);
// }

// TEST(stack, PushPop_5) {
//   s21::stack<std::string> st;
//   st.push("Hello");
//   st.push(" world!");
//   st.push("Keep going!");

//   EXPECT_FALSE(st.empty());
//   EXPECT_EQ(st.size(), 3);
//   EXPECT_EQ(st.top(), "Keep going!");

//   st.pop();
//   EXPECT_FALSE(st.empty());
//   EXPECT_EQ(st.size(), 2);
//   EXPECT_EQ(st.top(), " world!");
// }

// TEST(stack, init_1) {
//   s21::stack<int> s21_stack = {1, 4};
//   std::stack<int> std_stack;
//   std_stack.push(1);
//   std_stack.push(4);
//   EXPECT_EQ(s21_stack.size(), std_stack.size());

//   s21::stack<double> s21_stack_d = {1.5, 4.5, 6.4, 5.1, 8.0};
//   EXPECT_FALSE(s21_stack_d.empty());
//   EXPECT_EQ(s21_stack_d.size(), 5);

//   s21::stack<char> s21_stack_char = {'h', 'e', 'l', 'l', 'o'};
//   EXPECT_FALSE(s21_stack_char.empty());
//   EXPECT_EQ(s21_stack_char.size(), 5);

//   s21::stack<std::string> s21_stack_st = {"hello,", "my", "dear"};
//   std::stack<std::string> std_stack_st;
//   std_stack_st.push("hello,");
//   std_stack_st.push(" my");
//   std_stack_st.push(" dear");
//   EXPECT_FALSE(s21_stack_st.empty());
//   EXPECT_EQ(s21_stack_st.size(), 3);
// }

// TEST(stack, init_2) {
//   s21::stack<int> s21_stack = {1, 4, 6, 5, 8};
//   s21::stack<int> s21_stack_copy(s21_stack);
//   EXPECT_EQ(s21_stack.size(), s21_stack_copy.size());
// }

// TEST(stack, init_3) {
//   s21::stack<int> s21_stack = {1, 4, 6, 5, 8};
//   s21::stack<int> s21_stack_copy(std::move(s21_stack));
//   EXPECT_EQ(s21_stack.size(), 0);
//   EXPECT_EQ(5, s21_stack_copy.size());

//   s21_stack = std::move(s21_stack_copy);
//   EXPECT_EQ(s21_stack.size(), 5);
//   EXPECT_EQ(0, s21_stack_copy.size());
// }

// TEST(stack, init_4) {
//   s21::stack<int> s21_stack = {1, 4, 6, 5, 8};
//   s21::stack<int> s21_stack_copy;
//   s21_stack_copy = s21_stack;
//   EXPECT_EQ(s21_stack.size(), s21_stack_copy.size());
// }

// TEST(stack, top_1) {
//   s21::stack<std::string> s21_stack = {"What", "are", "we", "doing", "next"};
//   s21::stack<std::string> s21_stack_copy(std::move(s21_stack));
//   EXPECT_EQ(s21_stack.size(), 0);
//   EXPECT_EQ(5, s21_stack_copy.size());
//   EXPECT_EQ("next", s21_stack_copy.top());
// }

// TEST(stack, top_2) {
//   s21::stack<double> s21_stack = {1.2, 5.4, 3.0};
//   s21::stack<double> s21_stack_copy(std::move(s21_stack));
//   EXPECT_EQ(s21_stack.size(), 0);
//   EXPECT_EQ(3, s21_stack_copy.size());
//   EXPECT_EQ(3.0, s21_stack_copy.top());
//   s21_stack_copy.pop();
//   EXPECT_EQ(5.4, s21_stack_copy.top());
// }

// TEST(stack, top_3) {
//   s21::stack<int> s21_stack;
//   EXPECT_THROW({ s21_stack.top(); }, std::out_of_range);
// }

// TEST(stack, top_4) {
//   s21::stack<int> s21_stack = {5, 8, 15};
//   EXPECT_EQ(3, s21_stack.size());

//   s21::stack<int> s21_copy = s21_stack;
//   EXPECT_EQ(3, s21_copy.size());
//   EXPECT_EQ(3, s21_stack.size());

//   s21::stack<int> s21_copy2 = std::move(s21_stack);
//   EXPECT_EQ(3, s21_copy2.size());
//   EXPECT_EQ(0, s21_stack.size());
// }

// TEST(stack, swap_1) {
//   s21::stack<int> stack1 = {5, 10, 15};
//   s21::stack<int> stack2 = {98, 87, 76};
//   EXPECT_EQ(3, stack1.size());
//   EXPECT_EQ(15, stack1.top());
//   EXPECT_EQ(3, stack2.size());
//   EXPECT_EQ(76, stack2.top());

//   stack1.swap(stack2);
//   EXPECT_EQ(76, stack1.top());
//   EXPECT_EQ(15, stack2.top());
// }

// TEST(stack, insert_many_1) {
//   s21::stack<int> stack1{5, 10, 15};
//   stack1.insert_many_front(3);
//   EXPECT_EQ(stack1.top(), 3);
//   EXPECT_EQ(stack1.size(), 4);
//   stack1.insert_many_front(1, 2);
//   EXPECT_EQ(stack1.top(), 2);
//   EXPECT_EQ(stack1.size(), 6);
// }

// TEST(stack, insert_many_2) {
//   s21::stack<std::string> stack1{"git add", "git commit", "git push"};
//   stack1.insert_many_front("origin develop");
//   EXPECT_EQ(stack1.top(), "origin develop");
//   EXPECT_EQ(stack1.size(), 4);
//   stack1.insert_many_front("good job!", "work is done");
//   EXPECT_EQ(stack1.top(), "work is done");
//   EXPECT_EQ(stack1.size(), 6);
// }
