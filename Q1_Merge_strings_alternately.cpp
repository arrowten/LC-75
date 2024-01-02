//Question 1 - LC problem 1768
//You are given 2 strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

#include <iostream>
#include <string>

std::string merge_alternate_strings(const std::string& word1, const std::string& word2) {
	std::string merged;
	short i = 0, j = 0;

	while(i < word1.length() && j < word2.length()) {
		merged += word1[i];
		merged += word2[j];
		i++; j++;
	}

	//Append the remaining characters from both the strings, if any
	merged += word1.substr(i) + word2.substr(j);

	return merged;
}

int main() {
	std::string a = "abc", b = "pqr";
	std::cout << merge_alternate_strings(a, b) << '\n';	// Output: "apbqcr"

	std::string c = "ab", d = "pqrs";
	std::cout << merge_alternate_strings(c, d) << '\n';	// Output: "apbqrs"

	std::string e = "abcd", f = "pq";
	std::cout << merge_alternate_strings(e, f) << '\n';	// Output: "apbqcd"
}
