class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> st;
        
        for (int num : arr) {
            if (!st.empty()) {
                int top = st.top();
                // Check if one is negative and the other is non-negative
                if ((top >= 0 && num < 0) || (top < 0 && num >= 0)) {
                    st.pop(); // Remove both
                    continue;
                }
            }
            st.push(num);
        }
        
        // Convert stack to vector (in correct order)
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};
