class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& primes) {
        int n = primes.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            int prime = primes[i];
            int c = INT_MAX;
            bool abcd = false;
            int bit =0;
            while(bit <= 30) {
                if ((prime >> bit) & 1) {
                    int x = prime & ~(1 << bit);
                    
                    if (x < 0) continue;
                    
                    if ((x | (x + 1)) == prime) {
                        if (x < c) {
                            c = x;
                            abcd = true;
                        }
                    }
                }
                bit ++;
            }
            
            if (abcd) {
                result[i] = c;
            } else {
                result[i] = -1;
            }
        }
        
        return result;
    }
};
