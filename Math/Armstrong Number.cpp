//Armstrong Number -(also known as a narcissistic number) - equal to the sum of its own digits raised to the power of the number of digits.

class Solution {
public:
    bool isArmstrong(int n) {
        int original = n; // Store the original number
        int numDigits = 0, sum = 0;

        // Count the number of digits
        int temp = n;
        while (temp > 0) {
            numDigits++;
            temp /= 10;
        }

        // Calculate the sum of digits raised to the power of numDigits
        temp = n;
        while (temp > 0) {
            int digit = temp % 10;
            sum += pow(digit, numDigits); // Raise digit to numDigits power
            temp /= 10;
        }

        // Check if the sum is equal to the original number
        return (sum == original);
    }
};


//Another method -to use inbuilt functions

bool checkArmstrong(int num) {
   
    int k = to_string(num).length();
    int sum = 0;
    int n = num;
    while(n > 0){

        int ld = n % 10;

        sum += pow(ld, k); 
        n = n / 10;
    }
    return sum == num ? true : false;
}
