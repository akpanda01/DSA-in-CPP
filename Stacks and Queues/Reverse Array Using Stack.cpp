class Solution {
  public:
    void reverseArray(vector<int>& arr) {
        stack<int> s;
        
        // Push all elements into the stack
        for (int num : arr) {
            s.push(num);
        }
        
        // Pop elements from the stack and overwrite the array
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = s.top();
            s.pop();
        }
    }
};
