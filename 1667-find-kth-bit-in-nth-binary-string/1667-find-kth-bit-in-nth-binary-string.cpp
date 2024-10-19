class Solution {
public:
    char find( int n,int k){
        if(n==1) return '0';
        int m = (1 << n) - 1;
        if(k==(m/2)+1) return '1';

        if(k< (m/2)+1){
            return find(n-1,k);
        }
        return find(n - 1, m - k + 1) == '0' ? '1' : '0';
    }
    char findKthBit(int n, int k) {
        char s= find(n,k);
        return s;
    }
};