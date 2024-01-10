//Question 7 - LC problem 334
//Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

#include <iostream>
#include <vector>

bool increasing_triplet(const std::vector<int>& nums) {
	int first_min = INT_MAX, second_min = INT_MAX;

	for(int i: nums) {
		if(i <= first_min) first_min = i;
		else if(i <= second_min) second_min = i;
		else return true;
	}

	return false;
}

int main() {
	std::vector<int> nums = {1, 2, 3, 4, 5};
	std::cout << std::boolalpha << increasing_triplet(nums) << '\n';	// Output: "true"

	std::vector<int> nums2 = {5, 4, 3, 2, 1};
	std::cout << std::boolalpha << increasing_triplet(nums2) << '\n';	// Output: "false"

	std::vector<int> nums3 = {2, 1, 5, 0, 4, 6};
	std::cout << std::boolalpha << increasing_triplet(nums3) << '\n';	// Output: "true"
	
	return 0;
}
