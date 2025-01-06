//Missing Number in an Array

//Brute Force - O(n^2)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        // Iterate through all numbers in the range [0, n]
        for (int i = 0; i <= n; i++) {
            bool found = false;
            
            // Check if i exists in the nums array
            for (int num : nums) {
                if (num == i) {
                    found = true;
                    break;
                }
            }
            
            // If i is not found, it is the missing number
            if (!found) {
                return i;
            }
        }
        
        return -1; // This line should never be reached
    }
};


//Better Approach - Hashing - T.C=O(n) & S.C=O(n)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> hashSet;
        
        // Insert all elements of nums into the hash set
        for (int num : nums) {
            hashSet.insert(num);
        }
        
        // Check for the missing number in the range [0, n]
        for (int i = 0; i <= nums.size(); i++) {
            if (hashSet.find(i) == hashSet.end()) {
                return i;
            }
        }
        
        return -1; // This line should never be reached
    }
};


//Optimal Approach 1 - Using Sum formula - T.C=O(n) & S.C=O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        
        for (int num : nums) {
            actualSum += num;
        }
        
        return expectedSum - actualSum;
    }
};


//Optimal Approach 1 - Using XOR operation - T.C=O(n) & S.C=O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorSum = 0;

        // XOR all numbers in the range [0, n]
        for (int i = 0; i <= n; i++) {
            xorSum ^= i;
        }

        // XOR with all elements in the array
        for (int num : nums) {
            xorSum ^= num;
        }

        return xorSum;
    }
};





