//Question 7 - LC problem 238
//Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix is guaranteed to fit in a 32-bit integer. You must write an algorithm that runs in O(n) time and without using the division operation.

#include <iostream>
#include <vector>

std::vector<int> product_except_self(std::vector<int>& nums) {
	int n = nums.size();
	std::vector<int> result(n, 1);

	//Calculate products to the left of each element and multiply with the result
	int l_product = 1;
	for(int i = 1; i < n; i++) {
		l_product *= nums[i - 1];
		result[i] *= l_product;
	}

	//Calculate products to the right of each element and multiply with the result
	int r_product = 1;
	for(int i = n - 2; i >= 0; i--) {
		r_product *= nums[i + 1];
		result[i] *= r_product;
	}

	return result;
}

int main() {
	std::vector<int> nums = {1, 2, 3, 4};
	std::vector<int> out = product_except_self(nums);
	int size = nums.size();
	for(int i: out) {
		std::cout << i << '\t';		// Output: "24 12 8 6"
	}
	std::cout << '\n';

	std::vector<int> nums2 = {-1, 1, 0, -3, 3};
	std::vector<int> out2 = product_except_self(nums2);
	size = nums2.size();
	for(int i: out2) {
		std::cout << i << '\t';		// Output: "0 0 9 0 0"
	}
	std::cout << '\n';

	return 0;
}

