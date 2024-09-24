class Solution {
public:
     int length(int n){
        string S= to_string(n);
        return S.size();
     }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> u;
        for(auto it :arr1){
            while(it>0){
                u.insert(it);
                it=it/10;
            }
        }
        int maxi =0;
        for(auto it: arr2){
            while(it>0){
                if(u.find(it)!=u.end()){
                    maxi = max(maxi,length(it));
                    break;
                }
                it =it/10;
            }
        }
        return maxi;
    }
};