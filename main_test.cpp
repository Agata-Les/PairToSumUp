#include "findPairToSumUp.h"
#include "gtest/gtest.h"

TEST(findPairToSumUp, positive_sum_in_all_positive_input)
{
	//Given
	const std::vector<int> input { 2, 3, 5, 7, 13, 20 };
	const int sum = 12;
	std::pair<int, int> expected_result = { 5, 7 };

	//Expect
	EXPECT_EQ(findPair(input, sum), expected_result);
}

TEST(findPairToSumUp, positive_sum_in_all_negative_input)
{
	//Given
	const std::vector<int> input { -20, -8, -7, -5, -3, -1 };
	const int sum = 12;

	//Expect
	EXPECT_FALSE(findPair(input, sum));
}

TEST(findPairToSumUp, negative_sum_in_all_positive_input)
{
	//Given
	const std::vector<int> input { 2, 3, 5, 7, 13, 20 };
	const int sum = -12;

	//Expect
	EXPECT_FALSE(findPair(input, sum));
}

TEST(findPairToSumUp, negative_sum_in_all_negative_input)
{
	//Given
	const std::vector<int> input { -20, -8, -7, -5, -3, -1 };
	const int sum = -12;
	std::pair<int, int> expected_result = { -7, -5 };

	//Expect
	EXPECT_EQ(findPair(input, sum), expected_result);
}

TEST(findPairToSumUp, positive_sum_in_mixed_input)
{
	//Given
	const std::vector<int> input { -20, -8, -7, -5, -3, -1, 0, 2, 4, 7, 13, 20 };
	const int sum = 5;
	std::pair<int, int> expected_result = { -8, 13 };

	//Expect
	EXPECT_EQ(findPair(input, sum), expected_result);
}

TEST(findPairToSumUp, negative_sum_in_mixed_input)
{
	//Given
	const std::vector<int> input { -20, -9, -7, -5, -3, -1, 0, 3, 5, 7, 13, 20 };
	const int sum = -5;
	std::pair<int, int> expected_result = { -5, 0 };

	//Expect
	EXPECT_EQ(findPair(input, sum), expected_result);
}

TEST(findPairToSumUp, no_correct_pair_in_given_input)
{
	//Given
	const std::vector<int> input { -20, -8, -7, -5, -3, -1, 0, 3, 5, 7, 13, 20 };
	const int sum = 11;

	//Expect
	EXPECT_FALSE(findPair(input, sum));
}

TEST(findPairToSumUp, more_correct_pairs_in_given_input)
{
	//Given
	const std::vector<int> input { -20, -8, -7, -5, -3, -1, 0, 3, 5, 7, 13, 20 };
	const int sum = 12;
	std::pair<int, int> expected_result = { -8, 20 };
	std::pair<int, int> not_expected_but_correct_result = { 5, 7 };

	//Expect
	EXPECT_EQ(findPair(input, sum), expected_result);
	EXPECT_NE(findPair(input, sum), not_expected_but_correct_result);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}