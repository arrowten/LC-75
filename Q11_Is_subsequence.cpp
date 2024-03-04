//Question 11 - LC problem 392
//Given 2 strings s and t, return true if s is a subsequence of t, or false otherwise.

#include <iostream>
#include <string>

bool is_subsequence(const std::string& s, const std::string t) {
    int i = 0, j = 0;
    int slen = s.length(), tlen = t.length();
    
    while(i < slen && j < tlen) {
        if(s[i] == t[j]) ++i;
        ++j;
    }

    return i == slen;
}

int main() {
    std::string s = "abc", t = "ahbgdc";
    std::cout << std::boolalpha << is_subsequence(s, t) << '\n';    // Output: "true"

    std::string s2 = "axc", t2 = "ahbgdc";
    std::cout << std::boolalpha << is_subsequence(s2, t2) << '\n';  // Output: "false"
}