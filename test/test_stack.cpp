// тесты для стека

#include "stack.h"
#include <gtest.h>

TEST(stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> s(5));
}
TEST(stack, cant_create_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> s(-5));
}
TEST(stack, can_push_in_stack)
{
	TStack<int> s(5);
	ASSERT_NO_THROW(s.push(5));
}
TEST(stack, can_pop_in_stack)
{
	TStack<int> s(5);
	s.push(5);
	ASSERT_NO_THROW(s.pop());
}
TEST(stack, cant_pop_empty_stack)
{
	TStack<int> s(2);
	s.push(1);
	s.pop();
	ASSERT_ANY_THROW(s.pop());
}
TEST(stack, can_top_stack)
{
	TStack<int> s(2);
	s.push(1);
	s.push(2);
	EXPECT_EQ(2, s.top_stack());
}
TEST(stack, cant_top_emty_stack)
{
	TStack<int> s(2);
	s.push(1);
	s.push(2);
	s.pop();
	s.pop();
	ASSERT_ANY_THROW(s.top_stack());
}
TEST(stack, can_check_for_empty_stack)
{
	TStack<int> s(1);
	s.push(1);
	s.pop();
	EXPECT_EQ(s.empty(), true);
}
TEST(stack, can_check_for_non_empty_stack)
{
	TStack<int> s(1);
	s.push(1);
	EXPECT_EQ(s.empty(), false);
}
TEST(stack, can_return_size_stack)
{
	TStack<int> s(3);
	s.push(1);
	s.push(1);
	s.push(1);
	EXPECT_EQ(s.size(), 3);
}
TEST(stack, can_return_correct_size_stack)
{
	TStack<int> s(3);
	s.push(1);
	s.push(1);
	s.push(1);
	EXPECT_NE(s.size(), 2);
}
TEST(stack, can_return_size_emty_stack)
{
	TStack<int> s(2);
	s.push(1);
	s.push(1);
	s.pop();
	s.pop();
	EXPECT_EQ(s.size(), 0);
}
TEST(stack, can_push_in_less_stack_size)
{
	TStack<int> s(1);
	s.push(1);
	ASSERT_NO_THROW(s.push(1));
}
TEST(stack, can_push_after_pop_stack)
{
	TStack<int> s(2);
	s.push(1);
	s.push(1);
	s.pop();
	s.pop();
	ASSERT_NO_THROW(s.push(1));
}
TEST(stack, can_top_after_push_after_pop_stack)
{
	TStack<int> s(2);
	s.push(1);
	s.push(1);
	s.pop();
	s.pop();
	s.push(5);
	EXPECT_EQ(s.top_stack(), 5);
}
