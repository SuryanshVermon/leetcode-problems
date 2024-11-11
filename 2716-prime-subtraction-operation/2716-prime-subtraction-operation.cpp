class Solution {
public:
    bool isPrime(int a){
        if(a<2){
            return false;
        }
        for(int i=2;i<=a/2;i++){
            if(a%i ==0){
                return false;
            }
        }
        return true;
    }
    int dec(int a, int b){
        for(int i=a;i<b;i++){
            if(isPrime(i)){
                return i;
            }
        }
        return 0;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n= nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]<=nums[i]){
                int l= dec(nums[i]-nums[i+1]+1, nums[i]);
                if(l==0){return false;}
                nums[i]-=l;
            }
        }
        return true;
    }
};