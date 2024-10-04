class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        if (n % 2 != 0) return -1;

        sort(skill.begin(), skill.end()); 

        int target_sum = skill[0] + skill[n - 1];

        long long sum = 0;

        for (int i = 0; i < n / 2; ++i) {
            int pair_sum = skill[i] + skill[n - i - 1];
            if (pair_sum != target_sum) return -1; 
            
            sum += (long long)skill[i] * skill[n - i - 1];
        }

        return sum;
    }
};

