class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;  
        

        for (const auto& query : queries) {
            int left = query[0];  
            int right = query[1]; 
            int currentXor = 0;    
            
            
            for (int i = left; i <= right; ++i) {
                currentXor ^= arr[i];
            }
            
            result.push_back(currentXor);  
        }
        
        return result;  
    }
};
