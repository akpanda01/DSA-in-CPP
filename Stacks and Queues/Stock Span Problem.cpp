
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        stack<int> st; // stores indices

        for (int i = 0; i < n; i++) {
            // Pop indices from the stack while the price at those indices is <= current price
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // If stack is empty, it means no greater element to the left
            if (st.empty()) {
                span[i] = i + 1;
            } else {
                span[i] = i - st.top();
            }

            // Push this day's index onto the stack
            st.push(i);
        }

        return span;
    }
};
