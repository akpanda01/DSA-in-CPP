//Check Equal Arrays

class Solution {
  public:
    // Function to check if two arrays are equal or not.
    bool check(vector<int>& arr1, vector<int>& arr2) {
        // code here
       if (arr1.size() != arr2.size()) {
        return false;
    }

    // Use hash maps to store the frequency of elements in each array
    unordered_map<int, int> freq1, freq2;

    // Count frequencies in arr1
    for (int num : arr1) {
        freq1[num]++;
    }

    // Count frequencies in arr2
    for (int num : arr2) {
        freq2[num]++;
    }

    // Compare the frequency maps
    return freq1 == freq2; // Directly compare maps
}
};
