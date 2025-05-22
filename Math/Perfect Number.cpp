class Solution {
public:
    bool isPerfect(int n) {
        if (n <= 1) return false;  // 1 is not considered a perfect number

        int sum = 0;
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                sum += i;
            }
        }
        return sum == n;
    }
};
