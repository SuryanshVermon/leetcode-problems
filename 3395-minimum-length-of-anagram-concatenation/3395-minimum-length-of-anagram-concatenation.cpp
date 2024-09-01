#include <vector>
#include <string>

class Solution {
public:
    int minAnagramLength(std::string s) {
        for (int i = 1; i <= s.length(); i++) {
            if (s.length() % i == 0 && isPossible(s, i)) {
                return i;
            }
        }
        return -1;
    }

    bool isPossible(const std::string& s, int length) {
        std::vector<int> first(26, 0);
        for (int i = 0; i < length; i++) {
            first[s[i] - 'a']++;
        }

        for (int i = length; i < s.length(); i += length) {
            std::vector<int> thisOccurrence(26, 0);
            for (int j = i; j < i + length; j++) {
                thisOccurrence[s[j] - 'a']++;
            }
            for (int k = 0; k < 26; k++) {
                if (thisOccurrence[k] != first[k]) {
                    return false;
                }
            }
        }
        return true;
    }
};
