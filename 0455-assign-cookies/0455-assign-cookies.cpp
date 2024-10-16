class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int index =0;
        int count =0;

        while( index < s.size() && count < g.size()){
        if(s[index] >=g[count]) count ++;
        index ++;
        }

        return count;
    }
};