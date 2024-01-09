//Question 3 - LC problem 151
//Given an input string s, reverse the order of the words. Return a string of the words in reverse order concatenated by a single space. Note that s may contain leading or trailing spaces or multiple spaces between 2 words. The returned string should have a single space seperating the words. Do not include any extra spaces.

#include <iostream>
#include <sstream>
#include <vector>

std::string reverse_words (std::string& s) {
	std::vector<std::string> words;
	std::istringstream iss(s);
	std::string word;

	//Extracting words from the string
	while (iss >> word) {
		words.push_back(word);
	}

	//Constructing the reversed string
	std::string reversed;
	for (auto it = words.rbegin(); it != words.rend(); ++it) {
		reversed += *it;
		if(it + 1 != words.rend()) {
			reversed += " ";
		}
	}

	return reversed;
}

int main() {
	std::string a = "the sky is blue";
	std::cout << reverse_words(a) << '\n';	// Output: "blue is sky the"
	
	std::string b = "  hello world  ";
	std::cout << reverse_words(b) << '\n';	// Output: "world hello"

	std::string c = "a good    example";
	std::cout << reverse_words(c) << '\n';	// Output: "example good a"

	return 0;
}

