//Question 10 - LC problem 283
//Given an integer array nums, move all 0s to the end of it while maintaining the relative order of the non zero elements.

#include <iostream>
#include <vector>

void move_zeroes(std::vector<int>& nums) {
    int ptr = 0;
    int size = nums.size();

    for(int i = 0; i < size; i++) {
        if(nums[i] != 0) nums[ptr++] = nums[i];
    }

    while(ptr < size) nums[ptr++] = 0;
}

int main() {
    std::vector<int> nums = {0, 1, 0, 3, 12};
    move_zeroes(nums);
    for(int n: nums) std::cout << n << '\t';    // Output: "1   3   12   0   0"

    std::cout << '\n';
    
    std::vector<int> nums2 = {0};
    move_zeroes(nums2);
    for(int n: nums2) std::cout << n << '\t';   // Output: "0"
}