//Longest Palindromic Substring


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return ""; // If the string is empty
        
        int start = 0, end = 0;
        
        for (int i = 0; i < n; i++) {
            // Expand around i (odd length palindrome)
            int len1 = expandAroundCenter(s, i, i);
            // Expand around i and i + 1 (even length palindrome)
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            
            // Update the start and end if a longer palindrome is found
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        
        return s.substr(start, end - start + 1);
    }
    
    int expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; // Length of the palindrome
    }
};
