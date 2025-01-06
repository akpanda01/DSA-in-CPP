//Second Largest

class Solution {
  public:

    int getSecondLargest(vector<int> &arr) {
        if (arr.size() < 2) return -1;

        int largest = INT_MIN;
        int secLargest = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > largest) {
                secLargest = largest;
                largest = arr[i];
            } else if (arr[i] > secLargest && arr[i] != largest) {
                secLargest = arr[i];
            }
        }

        return (secLargest == INT_MIN) ? -1 : secLargest;
    }
};
