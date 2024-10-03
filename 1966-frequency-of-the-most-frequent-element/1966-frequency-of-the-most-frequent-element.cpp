class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int result =1;
        long long sum =0;
        int i=0;
        for(int j=0;j<nums.size();j++){
            sum =sum +(long long)nums[j];
            while((long long)nums[j] *(j-i+1) > sum +(long long)k){
                sum -= (long long)nums[i];
                i++;
            }
            result =max(result,j-i+1);
        }
        return result;
    }
};