//Majority Element

//Brute Force - Using Nested Loops - T.C = O(n^2) & S.C = O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count > n / 2) {
                return nums[i];
            }
        }
        return -1; // This line will never be reached as the problem guarantees a majority element.
    }
};


//Better Approach - Using hashmap - T.C = O(n) & S.C = O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > n / 2) {
                return num;
            }
        }
        return -1; // This line will never be reached as the problem guarantees a majority element.
    }
};


//Optimal Approach - Moore's Voting Algorithm - T.C = O(n) & S.C = O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1, count = 0;

        // Step 1: Find a candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        // Step 2: The problem guarantees that the majority element exists
        return candidate;
    }
};

