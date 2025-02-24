//Implement Pow()

class Solution {
  public:
    double power(double b, int e) {
        if (e == 0) return 1; // Base case: anything raised to 0 is 1

        double result = 1.0;
        long long exp = e;  // Handle negative exponents safely
        if (exp < 0) {
            b = 1 / b;
            exp = -exp;
        }

        while (exp > 0) {
            if (exp % 2 == 1) {  // If exponent is odd, multiply result by b
                result *= b;
            }
            b *= b;   // Square the base
            exp /= 2; // Halve the exponent
        }
        
        return result;
    }
};
