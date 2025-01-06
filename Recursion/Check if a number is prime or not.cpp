//Check if a number is prime or not


class Solution {
public:
    bool isPrimeHelper(int num, int divisor) {
        // Base case: If divisor reaches 1, the number is prime
        if (divisor == 1) return true;

        // If num is divisible by divisor, it is not prime
        if (num % divisor == 0) return false;

        // Recursive call to check for the next smaller divisor
        return isPrimeHelper(num, divisor - 1);
    }

    bool checkPrime(int num) {
        // Handle edge cases
        if (num <= 1) return false; // 0 and 1 are not prime
        if (num == 2) return true;  // 2 is the only even prime number

        // Start recursion with divisor as num - 1
        return isPrimeHelper(num, num - 1);
    }
};
