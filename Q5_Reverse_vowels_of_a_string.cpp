//Question 5 - LC problem 345
//Given a string s, reverse only the vowels in the string return it. They can appear in both lower and upper cases and that too more than once.

#include <iostream>
#include <string>

bool is_vowel(char c) {
	switch(c) {
		case 'a': case 'e': case 'i': case 'o': case 'u': case 'A': case 'E': case 'I': case 'O': case 'U': return true;
	}
	return false;
}

std::string reverse_vowels(std::string& s) {
	short left = 0, right = s.length() - 1;
	
	while(left < right) {
		//Find the vowel from the left
		while(left < right && !is_vowel(s[left])) {
			++left;
		}
		
		//Find the vowel from the right
		while(left < right && !is_vowel(s[right])) {
			--right;
		}

		//Swap vowels if left is still less than right
		if(left < right) {
			std::swap(s[left], s[right]);
			++left;
			--right;
		}
	}

	return s;
}

int main() {
	std::string a = "hello";
	std::cout << reverse_vowels(a) << '\n';		// Output: "holle"
	
	std::string b = "leetcode";
	std::cout << reverse_vowels(b) << '\n';		// Output: "leotcede"

	return 0;
}
