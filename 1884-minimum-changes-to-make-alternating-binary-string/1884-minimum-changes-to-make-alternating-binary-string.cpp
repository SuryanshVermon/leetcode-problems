class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        int count =0;
        for (int i = 0; i < n ; i++) {
            if (s[i] -'0' != i%2) {
                count ++;
            }
        }
        return min(count,n - count);
    }
};