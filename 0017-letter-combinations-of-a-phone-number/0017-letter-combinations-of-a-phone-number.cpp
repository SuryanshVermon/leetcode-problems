class Solution {
    void allCombinations(int ind, int n, unordered_map<char, string> &mpp, string temp, vector<string> &result, string digits){
        if(ind == n){
            result.push_back(temp);
            return;
        }
        char ch = digits[ind];
        string str = mpp[ch];
        for(int i=0; i<str.length(); i++){
            temp.push_back(str[i]);
            allCombinations(ind+1, n, mpp, temp, result, digits);
            temp.pop_back();
        }
        
    }

public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n==0)return {};
        vector<string>result;
        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        allCombinations(0, n, mpp, "", result, digits);
        return result;
    }
};