class Solution {
public:
    char findTheDifference(string s, string t) {
        int z =0;

        for(char & ch : s){
            z ^=ch;
        }

        for(char & ch : t){
            z ^=ch;
        }
        return (char)z;
  }
};