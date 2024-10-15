class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        long long count = 0;
        long long oneCount = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                oneCount++;
            } else {
                count += oneCount;
            }
        }

        return count;
    }
};
