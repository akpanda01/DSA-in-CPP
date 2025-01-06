//Square Root

class Solution {
  public:
    int floorSqrt(int n) {
        if (n == 0 || n == 1) return n;

        int low = 1, high = n, result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid * mid == n) {
                return mid;
            } else if (mid * mid < n) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};

