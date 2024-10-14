class Solution {
public:
    int minTimeToType(string word) {
        int n = word.size();
        char prev ='a';
        int sum =0;

        for(char &c :word){
            int dist = abs(c -prev);
             sum += min(dist,(26-dist));
             sum = sum +1;
             prev = c;
        }
         return sum;
    }
};