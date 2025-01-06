//Array Leaders

class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> result; // To store the leaders
        int maxRight = arr[n - 1]; // The last element is always a leader
        
        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] >= maxRight) {
                result.push_back(arr[i]);
                maxRight = arr[i]; // Update maxRight
            }
        }
        
        // Reverse the result to maintain the original order of leaders
        reverse(result.begin(), result.end());
        return result;
    }
};

