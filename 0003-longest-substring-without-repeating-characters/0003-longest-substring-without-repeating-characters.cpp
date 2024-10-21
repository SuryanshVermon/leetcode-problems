class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int l = 0, maxLength = 0;

        for (int r = 0; r < s.size(); r++) {
            if (lastSeen.find(s[r]) != lastSeen.end()) {
                l = max(l, lastSeen[s[r]] + 1);
            }
            lastSeen[s[r]] = r;
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};

