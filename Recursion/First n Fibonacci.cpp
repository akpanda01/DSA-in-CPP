//First n Fibonacci 

class Solution {
  public:
    // Function to return list containing first n fibonacci numbers.
    vector<int> fibonacciNumbers(int n) {
        // code here
        vector<int> result;
        
        if(n==0) return result;
        result.push_back(0);
        
        if(n>1){
            result.push_back(1);
        }
        for(int i =2; i<n ;i++){
            int next = result[i-1] + result[i-2];
            result.push_back(next);
        }
        return result;
    }
};
