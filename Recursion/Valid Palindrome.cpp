//Valid Palindrome


class Solution {
public:
    bool isPalindromeHelper(const string& s, int left, int right) {
        // Base case: If pointers cross or are equal, it's a palindrome
        if (left >= right) {
            return true;
        }
        
        // Skip non-alphanumeric characters from the left
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        
        // Skip non-alphanumeric characters from the right
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        
        // Check if characters match
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        
        // Recursively check the next pair of characters
        return isPalindromeHelper(s, left + 1, right - 1);
    }
    
    bool isPalindrome(string s) {
        return isPalindromeHelper(s, 0, s.size() - 1);
    }
};
