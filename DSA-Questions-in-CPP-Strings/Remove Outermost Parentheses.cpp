//Remove Outermost Parentheses


class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int balance = 0; // Keeps track of the balance of parentheses
        
        for (char c : s) {
            if (c == '(') {
                // Only add '(' if balance > 0 (not the outermost one)
                if (balance > 0) {
                    result += c;
                }
                balance++;
            } else {
                balance--;
                // Only add ')' if balance > 0 (not the outermost one)
                if (balance > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};
