//Missing ranges of numbers

class Solution {
  public:
    vector<vector<int>> missingRanges(vector<int> &arr, int lower, int upper) {
        vector<vector<int>> result;
        int prev = lower - 1; // Initialize prev to one less than lower
        
        // Iterate through the array and consider upper as the last element
        for (int i = 0; i <= arr.size(); ++i) {
            int curr = (i < arr.size()) ? arr[i] : upper + 1; // Handle the last element
            
            if (curr - prev > 1) { // Missing range found
                result.push_back({prev + 1, curr - 1});
            }
            prev = curr; // Update prev for next iteration
        }
        
        return result;
    }
};
