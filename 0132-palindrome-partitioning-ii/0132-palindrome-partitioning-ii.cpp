class Solution {
    bool isPalindrome(int i, int j, string &s){
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int minPartition(int ind, int n, string &s, vector<int> &dp){
        if(ind == n) return 0;
        int mini = INT_MAX;
        if(dp[ind] != -1) return dp[ind];
        for(int i = ind ; i<n; i++){
            if(isPalindrome(ind, i, s)){
                int part = 1 + minPartition(i+1, n, s, dp);
                mini = min(mini, part);
            }
        }
        return dp[ind] = mini;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n, -1);
        return minPartition(0, n, s, dp) -1;
    }
};