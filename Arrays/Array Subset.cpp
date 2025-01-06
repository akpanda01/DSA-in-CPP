//Array Subset


class Solution {
public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Use a hash set to store elements of array 'a'
        unordered_set<int> elements(a.begin(), a.end());

        // Check if each element of 'b' exists in the set
        for (int num : b) {
            if (elements.find(num) == elements.end()) {
                return false; // If any element of 'b' is not in 'a', return false
            }
        }

        return true; // All elements of 'b' are in 'a'
    }
};
