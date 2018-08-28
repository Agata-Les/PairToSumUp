#include <vector>
#include <utility>
#include <boost/optional.hpp>

boost::optional<std::pair<int, int>> findPair(const std::vector<int> input, const int sum)
{
	auto leftPtr = input.begin();
	auto rightPtr = input.rbegin();

	while(leftPtr != rightPtr.base()-1)
	{
		const int temporarySum = *leftPtr + *rightPtr;

		if(temporarySum == sum) return std::make_pair(*leftPtr, *rightPtr);

		if(temporarySum < sum) leftPtr++;

		else if(temporarySum > sum) rightPtr++;
	}

	return boost::none;
}
