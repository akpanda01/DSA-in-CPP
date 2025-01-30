//Repetitive Addition Of Digits

//BRUTE = O(log n)
class Solution {
public:
    int singleDigit(int n) {
        while (n >= 10) {
            int sum = 0;
            // Sum all digits
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            n = sum; // Update n to the sum of digits
        }
        return n; // Return the final single digit
    }
};

//OPTIMAL = O(1)
class Solution {
public:
    int singleDigit(int n) {
        if (n == 0) return 0;
        return (n % 9 == 0) ? 9 : n % 9;
    }
};

