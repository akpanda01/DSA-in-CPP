//Non Fibonacci Number

class Solution {
public:
    long long int nonFibonacci(int N) {
        long long a = 1, b = 2, c; // Start from F(2) = 1 and F(3) = 2
        while (true) {
            c = a + b; // Next Fibonacci number
            long long gap = c - b - 1; // Number of non-Fibonacci numbers between b and c
            
            if (N <= gap) {
                return b + N; // The Nth non-Fibonacci number lies in this gap
            }
            
            N -= gap; // Reduce N by the number of non-Fibonacci numbers in this range
            a = b;
            b = c;
        }
    }
};
