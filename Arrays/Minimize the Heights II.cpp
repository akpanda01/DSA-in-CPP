//Minimize the Heights II

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
 
    // Maximum possible height difference
    int ans = arr[n - 1] - arr[0];
 
    int tempmin, tempmax;
    tempmin = arr[0];
    tempmax = arr[n - 1];
 
    for (int i = 1; i < n; i++) {
 
        // If on subtracting k we got
        // negative then continue
        if (arr[i] - k < 0)
            continue;
 
        // Minimum element when we
        // add k to whole array
        tempmin = min(arr[0] + k, arr[i] - k);
 
        // Maximum element when we
        // subtract k from whole array
        tempmax = max(arr[i - 1] + k, arr[n - 1] - k);
 
        ans = min(ans, tempmax - tempmin);
    }
    return ans;
    }
};
