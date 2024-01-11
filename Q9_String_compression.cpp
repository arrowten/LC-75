//Question 9 - LC problem 443
//Given an array of characters chars, compress it using the following algorithm: 
//Begin with an empty string s. For each group of consecutive repeating characters in chars: if the group's length is 1, append the character to s, otherwise, append the character followed by the group's length. The compressed string s should not be returned seperately, but instead, be stored int the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars. After you are done modifying the input array, return the new length of the array. You must write an algorithm that uses only constant extra space.

#include <iostream>
#include <vector>
#include <string>

int compress(std::vector<char>& chars) {
	int n = chars.size();
	if(n <= 1) return n;

	int index = 0, count = 1;
	char current_char = chars[0];

	for(int i = 1; i < n; i++) {
		if(chars[i] == current_char) count++;
		else {
			chars[index++] = current_char;
			if(count > 1) {
				//Convert count to characters and update the array
				std::string count_str = std::to_string(count);
				for(char digit: count_str) {
					chars[index++] = digit;
				}
			}
			current_char = chars[i];
			count = 1;
		}
	}

	//Handle the last character group
	chars[index++] = current_char;
	if(count > 1) {
		std::string count_str = std::to_string(count);
		for(char digit: count_str) chars[index++] = digit;
	}

	return index;
}

int main() {
	std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
	int result = compress(chars);
	for(int i = 0; i < result; ++i) std::cout << chars[i] << " ";	// Output: "a 2 b 2 c 3"
	std::cout << '\n';

	std::vector<char> chars2 = {'a'};
	int result2 = compress(chars2);
	for(int i = 0; i < result2; ++i) std::cout << chars2[i] << " ";	// Output: "a"
	std::cout << '\n';

	std::vector<char> chars3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
	int result3 = compress(chars3);
	for(int i = 0; i < result3; ++i) std::cout << chars3[i] << " ";	// Output: "a b 1 2"
	
	return 0;
}
