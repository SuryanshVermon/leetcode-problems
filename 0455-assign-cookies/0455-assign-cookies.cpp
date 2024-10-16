class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int m = g.size();
        int n = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int count = 0;
        while(i<m && j<n){
            if(s[j] >= g[i]){
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};