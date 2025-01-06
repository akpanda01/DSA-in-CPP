//Print N to 1 without loop


class Solution {
  public:
    void printNos(int N) {
        // code here
        int count = 1;
        if(N==0) return;
        
        cout<<N<<" ";
        printNos(N-1);
    }
};
