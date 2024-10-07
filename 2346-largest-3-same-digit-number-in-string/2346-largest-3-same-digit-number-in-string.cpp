class Solution {
public:
    string largestGoodInteger(string num) {
        char maxi=' ';
       for(int i=0;i<num.size();i++){
        if(num[i]==num[i+1] && num[i] == num[i+2]){
            maxi=max(maxi,num[i]);
        }
       }
       if(maxi ==' '){
        return "";
       }
        return string (3,maxi);
    }
};