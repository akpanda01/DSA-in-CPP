//Decimal to binary

class Solution {
  public:
    string decToBinary(int n) {
        // Base case: If n is 0, return "0"
        if (n == 0) return "0";
        
        return decToBinaryHelper(n);
    }

  private:
    string decToBinaryHelper(int n) {
        // Base case: If n is 0, return an empty string
        if (n == 0) return "";

        // Recursive step: Divide by 2, get the remainder
        return decToBinaryHelper(n / 2) + std::to_string(n % 2);
    }
};
