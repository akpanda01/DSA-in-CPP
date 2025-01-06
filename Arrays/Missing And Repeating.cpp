//Missing And Repeating

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        
        long long sum = 0, sumSquares = 0;
        for (int num : arr) {
            sum += num;
            sumSquares += (long long)num * num;
        }
        
        long long expectedSum = (long long)n * (n + 1) / 2;
        long long expectedSumSquares = (long long)n * (n + 1) * (2 * n + 1) / 6;
        
        long long diffSum = expectedSum - sum; // b - a
        long long diffSquares = expectedSumSquares - sumSquares; // b^2 - a^2
        
        // Solve b^2 - a^2 = (b - a)(b + a)
        long long b_plus_a = diffSquares / diffSum;
        long long b_minus_a = diffSum;
        
        int b = (b_plus_a + b_minus_a) / 2; // repeating number
        int a = b_plus_a - b; // missing number
        
        return {a, b};
    }
};

//T.C = O(n)
//S.C = O(1)
