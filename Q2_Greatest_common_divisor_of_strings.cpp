//Question 2 - LC problem 1071
//For 2 strings, s and t, we say "t divides s" iff "s = t + t + ... + t". Given 2 strings str1 and str2, return the largest string x such that x divides both str1 and str2.

#include <iostream>
#include <string>

short gcd(short a, short b) {
	return ((b == 0) ? a : gcd(b, a % b));
}

std::string gcd_string(const std::string& str1, const std::string& str2) {
	short l1 = str1.length();
	short l2 = str2.length();

	//The GCD of the lengths of the string
	short l = gcd(l1, l2);

	//Extract a substring of length GCD from str1
	std::string test = str1.substr(0, l);
	
	//Check if test divides both str1 and str2 
	std::string con_str1 = "", con_str2 = "";

	while(con_str1.length() < l1) con_str1 += test;
	while(con_str2.length() < l2) con_str2 += test;

	if(con_str1 == str1 && con_str2 == str2) return test;
	else return "";
}

int main() {
	std::string a = "ABCABC", b = "ABC";
	std::cout << gcd_string(a, b) << '\n';	// Output: "ABC"

	std::string c = "ABABAB", d = "ABAB";
	std::cout << gcd_string(c, d) << '\n';	// Output: "AB"

	std::string e = "LEET", f = "CODE";
	std::cout << gcd_string(e, f) << '\n';	// Output: ""
}
