//Factorials Less than or Equal to n


class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
        vector<long long> result;
        long long product = 1;
        
        for (int i = 1; product <= n; i++) {
            
            product *= i ;
            
            if (product <= n) {
                result.push_back(product);
            }
        }
        
        return result;
    }
};
