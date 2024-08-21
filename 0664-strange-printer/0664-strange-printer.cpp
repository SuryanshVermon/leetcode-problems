class Solution {
public:
    int strangePrinter(string s) {
    if (s.empty()) {
        return 0;
    }

    int n = s.length();
    std::vector<std::vector<int>> state(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        state[i][i] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int dist = 1; dist + i < n; dist++) {
            int j = dist + i;
            if (dist == 1) {
                state[i][j] = (s[i] == s[j]) ? 1 : 2;
                continue;
            }
            state[i][j] = INT_MAX;
            for (int k = i; k + 1 <= j; k++) {
                int tmp = state[i][k] + state[k + 1][j];
                state[i][j] = std::min(state[i][j], tmp);
            }
            if (s[i] == s[j]) {
                state[i][j]--;
            }
        }
    }

    return state[0][n - 1];
        
    }
};