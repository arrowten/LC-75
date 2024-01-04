//Question 4 - LC problem 605
//You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots. Given an integer array flower_bed, containing 0s and 1s, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no adjacent flowers rule and false otherwise.

#include <iostream>
#include <vector>

bool can_place_flowers(std::vector<short>& flower_bed, short n) {
	short count = 0;
	unsigned short size = flower_bed.size();

	for(short i = 0; i < size; i++) {
		if(flower_bed[i] == 0 && 
		(i == 0 || flower_bed[i - 1] == 0) && 
		(i == (size - 1) || flower_bed[i + 1] == 0)) {
			flower_bed[i] = true;
			++count;
			++i;
		}
	}

	return (count >= n);
}

int main() {
	std::vector<short> f_bed = {1, 0, 0, 0, 1};
	short n = 1;
	std::cout << std::boolalpha << can_place_flowers(f_bed, n) << '\n';	// Output: "true"

	std::vector<short> f_bed2 = {1, 0, 0, 0, 1};
	short n2 = 2;
	std::cout << std::boolalpha << can_place_flowers(f_bed2, n2) << '\n';	//Output: "false"

	return 0;
}