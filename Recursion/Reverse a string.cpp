//Reverse a string


class Solution{	
private:
    /* Recursive function to reverse the 
    string character by character */
    void reverse(vector<char>& s, int left, int right) {
        
        // Base case
        if (left >= right) return;
        
        // Swap characters at left and right positions
        swap(s[left],s[right]);
        
        // Recursive call with updated indices
        reverse(s, left + 1, right - 1);
    }
    
public:
    // Function to reverse the given string
    vector<char> reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        reverse(s, left, right);
        return s;
    }
};
