class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        vector<int>ans;
        int k = nums.size()/3;
        for(auto it:nums){
            m[it]++;
            if(m[it]==k+1){
                ans.push_back(it);
            }
        }
        return ans;
    }
};