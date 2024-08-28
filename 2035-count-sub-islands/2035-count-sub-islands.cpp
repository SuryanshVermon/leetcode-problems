class Solution {
public:
    void dfs(vector<vector<int>>& grid2, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) {
            return;
        }
        grid2[i][j] = 0;
        dfs(grid2, i + 1, j, m, n);
        dfs(grid2, i, j + 1, m, n);
        dfs(grid2, i, j - 1, m, n);
        dfs(grid2, i - 1, j, m, n);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1 && grid1[i][j] == 0) {
                    dfs(grid2, i, j, m, n);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    dfs(grid2, i, j, m, n);
                    ++count;
                }
            }
        }
        return count;
    }
};
