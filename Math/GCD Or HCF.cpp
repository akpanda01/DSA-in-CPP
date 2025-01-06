//GCD Or HCF - Use the Euclidean Algorithm to compute the GCD of two numbers

class Solution {
  public:
    vector<long long> lcmAndGcd(long long a, long long b) {
        // Compute GCD using Euclidean Algorithm
        long long gcd = __gcd(a, b);

        // Compute LCM using the formula
        long long lcm = (a * b) / gcd;

        return {lcm, gcd};
    }
};

//Another Solution - logic behind the __gcd function
class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        int gcd = calculateGCD(a, b);
        int lcm = (a / gcd) * b; 

        return {lcm, gcd};
    }

  private:
    int calculateGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

//Time Complexity : O(log(min(a,b)))
//Space Complexity : O(1)
