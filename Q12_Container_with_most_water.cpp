//Question 12 - LC problem 11
//You are given an integer array height of length n. There are n vertical lines drawn such that the 2 endpoints of the ith line are (i, 0) and (i, height[i]). Find 2 lines that tigether with the x axis form a container, such that the container contains the most water. Return the maximum amount of water a container can store.

#include <iostream>
#include <vector>

int maximum_area(std::vector<int>& height) {
    int max_area = 0, left = 0, right = height.size() - 1;

    while(left < right) {
        int width = right - left;
        int min_height = std::min(height[left], height[right]);
        int area = width * min_height;
        max_area = std::max(max_area, area);

        if(height[left] < height[right]) left++;
        else right--;
    }

    return max_area;
}

int main() {
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << maximum_area(height) << '\n';  // Output: "49"

    std::vector<int> height2 = {1, 1};
    std::cout << maximum_area(height2) << '\n'; // Output: "1"

    return 0;
}