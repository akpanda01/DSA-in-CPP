//Maximum Consecutive Ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;     // Current count of consecutive ones
        int maxCount = 0;  // Maximum count of consecutive ones

        for (int num : nums) {
            if (num == 1) {
                count++;  // Increment the count for a '1'
                maxCount = max(maxCount, count);  // Update maxCount
            } else {
                count = 0;  // Reset count when a '0' is encountered
            }
        }

        return maxCount;
    }
};

//Time Complexity - O(n)
//Space Complexity - O(1)
