class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long sum = 0;

        for(auto &i: chalk) sum += i;
        k = k % sum;

        int i = 0;
        while(i < n) {
            if(k < chalk[i]) return i;
            k -= chalk[i];
            i++;
        }

        return 0;
    }
};
