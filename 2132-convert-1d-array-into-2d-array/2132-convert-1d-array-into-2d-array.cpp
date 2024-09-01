class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m, vector<int>(n));
        int num =original.size();
        if(num != m*n) return {};
        for(int i=0;i<num;i++){
            int row=i/n;
            int col=i%n;
            ans[row][col]=original[i];
            }
        return ans;
    }
};