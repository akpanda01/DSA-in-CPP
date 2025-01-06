//Rotate Array

class Solution {
public:

    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n; // To handle cases where d > n
        
        // Reverse the first d elements
        reverse(arr.begin(), arr.begin() + d);
        
        // Reverse the remaining n-d elements
        reverse(arr.begin() + d, arr.end());
        
        // Reverse the entire array
        reverse(arr.begin(), arr.end());
private:
  void reverse(vector<int>& nums, int l, int r) {
    while (l < r)
      swap(nums[l++], nums[r--]);
  }
    }
};


