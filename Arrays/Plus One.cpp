// Plus One

class Solution {
  public:
    vector<int> increment(vector<int> arr, int N) {
        // Start from the last digit and add 1
        for (int i = N - 1; i >= 0; i--) {
            if (arr[i] < 9) {
                arr[i]++;  // Simply increment if the digit is less than 9
                return arr; // No carry forward needed, return the result
            } else {
                arr[i] = 0;  // Set current digit to 0 and carry to the next digit
            }
        }

        // If all digits were 9, we need an extra leading 1 (e.g., 999 -> 1000)
        arr.insert(arr.begin(), 1);
        return arr;
    }
};
