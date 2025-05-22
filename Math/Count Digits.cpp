class Solution {
public:
    int countDigit(int n) {
        if(n==0) return 1;
        int count = 0;
        while(n!=0){
            int digit = n%10;
            count++;
            n = n/10;

        }
        return count;

    }
};
