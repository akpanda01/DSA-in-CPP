//Minimize the Heights I

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        // If there is only one tower, no modification is possible.
        if (n == 1) return 0;
        
        // Sort the array to easily access the smallest and largest elements.
        sort(arr.begin(), arr.end());
        
        // Initialize the result with the difference between the largest and smallest elements.
        int ans = arr[n-1] - arr[0];
        
        // Iterate over each tower and calculate the possible minimum difference.
        for (int i = 1; i < n; i++) {
            // Current minimum and maximum after modification.
            int min_height = min(arr[0] + k, arr[i] - k);
            int max_height = max(arr[n-1] - k, arr[i-1] + k);
            
            // Calculate the new possible minimum difference.
            ans = min(ans, max_height - min_height);
        }
        
        return ans;
    }
};
