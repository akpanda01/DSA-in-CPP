//Maximum Product of Three Numbers

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        // Initialize three largest and two smallest values
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        // Traverse the array to find max and min values
        for (int num : nums) {
            // Update the three largest values
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                max3 = num;
            }

            // Update the two smallest values
            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }

        // The maximum product is the greater of:
        // 1. Product of three largest numbers
        // 2. Product of the largest number and two smallest numbers (to handle negatives)
        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};
