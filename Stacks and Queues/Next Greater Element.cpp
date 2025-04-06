class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);  // Initialize result with -1
        stack<int> st;  // stack to store indices

        for (int i = 0; i < n; i++) {
            // While stack is not empty and current element is greater
            // than element at index stored at top of stack
            while (!st.empty() && arr[i] > arr[st.top()]) {
                result[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);  // push current index
        }

        return result;
    }
};
