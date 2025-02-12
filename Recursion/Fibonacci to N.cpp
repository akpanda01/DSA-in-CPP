//Fibonacci to N

class Solution {
public:
    vector<int> nFibonacci(int N) {
        vector<int> result;
        
        if (N < 0) return result;
        
        int a = 0, b = 1;
        result.push_back(a);
        
        while (a <= N) {
            result.push_back(b);
            int next_fib = a + b;
            a = b;
            b = next_fib;
        }

        // Remove last element if it exceeds N
        if (result.back() > N) {
            result.pop_back();
        }

        return result;
    }
};
