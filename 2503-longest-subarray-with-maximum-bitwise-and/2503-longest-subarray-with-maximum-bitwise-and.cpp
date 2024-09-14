class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end()); 
    int count = 0, maxCount = 0;
    
    for (int num : nums) {
        if (num == maxElement) {
            count++;          
        } else {
            maxCount = max(maxCount, count); 
            count = 0;         
        }
    }
    
   
    maxCount = max(maxCount, count);
    
    return maxCount;
    }
};