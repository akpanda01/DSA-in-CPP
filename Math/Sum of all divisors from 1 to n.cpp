//Sum of all divisors from 1 to n

class Solution {
  public:
    int sumOfDivisors(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i * (n / i); // Add the contribution of divisor i
        }
        return sum;
    }
};

//Intution - for a divisor k, it contributes k × (n/k) to the total sum.
