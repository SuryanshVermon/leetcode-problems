class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0);
        map<int, int, greater<int>> mp;
        
        for(int num : nums) {
            for(const auto& p : mp) {
                mp[p.first|num] += p.second;
            }
            mp[num]++;
        }
        return mp.begin()->second;
    }
};