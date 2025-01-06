//Sum of first n^3 terms

class Solution {
  public:
    int sum = 0;
    int sumOfSeries(int n) {
        // code here
        if(n < 1) return 0;
        sum += (n*n*n);
        sumOfSeries(n-1);
        
        return sum;
    }
};
