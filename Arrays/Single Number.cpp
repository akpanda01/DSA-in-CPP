//Single Number

//Brute Force - Using Nested for loops - O(n^2)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count == 1) {
                return nums[i];
            }
        }
        return -1;  // In case no single number exists (not possible in the given constraints)
    }
};

//Better Approach - Hashing - T.C = O(n) & S.C = O(n)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Count occurrences of each element
        for (int num : nums) {
            freq[num]++;
        }
        
        // Find the element that appears only once
        for (auto it : freq) {
            if (it.second == 1) {
                return it.first;
            }
        }
        
        return -1;  // Should not reach here for valid input
    }
};

//Optimal Approach - Using XOR - T.C = O(n) & S.C = O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =0;
        for (int i :nums){
            ans=ans^i;
        }

        return ans;
        
    }
};
