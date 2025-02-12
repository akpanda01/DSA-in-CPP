//Fibonacci Sum


class Solution {
public:
    const int MOD = 1000000007;

    long long int fibSum(long long int N) {
        if (N == 0) return 0;

        long long a = 0, b = 1, sum = 1; // f0 = 0, f1 = 1, sum starts with f0 + f1

        for (int i = 2; i <= N; i++) {
            long long nextFib = (a + b) % MOD;
            sum = (sum + nextFib) % MOD;
            a = b;
            b = nextFib;
        }

        return sum;
    }
};
