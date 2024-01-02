//Question 3 - LC problem 1431
//There are n kids with candles. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extra_candies, denoting the number of extra candies that you have. Return a boolean array result of length n, where result[i] is true if after giving the ith kid all the extra_candies, they will have the greatest number of candies among all the kids or false otherwise. Note that multiple kids can have the greatest number of candies.

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<bool> kids_with_candies(std::vector<int>& candies, short extra_candies) {
	int max_candies = *std::max_element(candies.begin(), candies.end());

	std::vector<bool> result;
	for(int i: candies) result.push_back(i + extra_candies >= max_candies);

	return result;
}

int main() {
	std::vector<int> candies1 = {2, 3, 5, 1, 3};
	int extraCandies1 = 3;
	std::vector<bool> result1 = kids_with_candies(candies1, extraCandies1);
	for(bool val: result1) std::cout << std::boolalpha << val << " ";	// Output: "true true true false true"
	std::cout << '\n';

	std::vector<int> candies2 = {4, 2, 1, 1, 2};
	int extraCandies2 = 1;
	std::vector<bool> result2 = kids_with_candies(candies2, extraCandies2);
	for(bool val: result2) std::cout << std::boolalpha << val << " ";	// Output: "true false false false false"
	std::cout << '\n';

	std::vector<int> candies3 = {12, 1, 12};
	int extraCandies3 = 10;
	std::vector<bool> result3 = kids_with_candies(candies3, extraCandies3);
	for(bool val : result3) std::cout << std::boolalpha << val << " ";	// Output: "true false true"
	std::cout << '\n';
}
