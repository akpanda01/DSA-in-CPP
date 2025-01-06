class Solution {
  public:
    int evenlyDivides(int n) {
        int count = 0;
        int original = n; // Store the original number
        
        while (n != 0) {
            int d = n % 10; // Extract the last digit
            n = n / 10;     // Remove the last digit

            if (d != 0 && original % d == 0) { // Ignore 0 and check divisibility
                count++;
            }
        }
        return count;
    }
};
