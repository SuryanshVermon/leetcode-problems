class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest =0;
        int sec =0;
        for(int &num :nums){
            if(num >largest){
                sec = largest;
                largest = num;
            }
            else
            {
                sec = max(sec ,num);
            }
        }
        return (largest-1)*(sec-1);
    }
};