//Find the Smallest Divisor Given a Threshold


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(nums, mid, threshold)) {
                answer = mid; // Update to a smaller possible divisor
                right = mid - 1; // Look for smaller divisors
            } else {
                left = mid + 1; // Increase divisor
            }
        }

        return answer;
    }

private:
    bool isPossible(const vector<int>& nums, int divisor, int threshold) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor; // Rounded up division
            if (sum > threshold) return false; // Early exit if sum exceeds threshold
        }
        return sum <= threshold;
    }
};
