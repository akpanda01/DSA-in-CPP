//Binary to Decimal

class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
        int decimal = 0;
        int power = 0; // Represents the power of 2

        // Traverse the string from right (least significant bit) to left
        for (int i = b.size() - 1; i >= 0; i--) {
            if (b[i] == '1') {
                decimal += pow(2, power);
            }
            power++; // Increase the power of 2
        }

        return decimal;
    }
};
