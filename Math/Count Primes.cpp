//Check Primes - Sieve of Eratosthenes

vector<bool> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                isPrime[multiple] = false; // Mark multiples of p as not prime
            }
        }
    }
    return isPrime;
}

// Function to check if all numbers in the range [l, r] are prime
bool areAllPrimesInRange(int l, int r, const vector<bool>& isPrime) {
    for (int i = l; i <= r; ++i) {
        if (!isPrime[i]) {
            return false; // Found a non-prime number in the range
        }
    }
    return true; // All numbers are prime
}

//Time Complexity - O(n log log n) - The outer loop runs until sqrt(n) and checks all numbers up to n and ach prime number's multiples are marked.
Once the sieve is prepared, checking each number in the range involves a simple lookup - O(r-l+1)
//Space Complexity - O(n) -store results for numbers within the specified range
