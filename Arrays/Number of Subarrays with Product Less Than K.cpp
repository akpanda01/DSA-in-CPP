//Number of Subarrays with Product Less Than K

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // If k is 1 or less, no product can be strictly less than k
        
        int left = 0, product = 1, count = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];
            
            // Shrink the window if product >= k
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            
            // Count valid subarrays ending at 'right'
            count += (right - left + 1);
        }
        
        return count;
    }
};
