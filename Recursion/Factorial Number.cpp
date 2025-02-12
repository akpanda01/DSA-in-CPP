//Factorial Number

class Solution {
public:
    bool isFactorialHelper(int N, int fact, int i) {
        // Base case: If factorial matches N, return true
        if (fact == N) return true;
        
        // If factorial exceeds N, return false
        if (fact > N) return false;
        
        // Recursive call with next factorial
        return isFactorialHelper(N, fact * (i + 1), i + 1);
    }
    
    int isFactorial(int N) {
        return isFactorialHelper(N, 1, 1) ? 1 : 0;
    }
};
