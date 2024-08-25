class Solution {
public:
    double myPow(double x, int n) {
        long long absN = abs(static_cast<long long>(n));
        double ans = 1.0;
        double currentProduct = x;
        
        while (absN > 0) {
            if (absN % 2 == 1) {
                ans *= currentProduct;
            }
            currentProduct *= currentProduct;
            absN /= 2;
        }
        
        if (n < 0) {
            ans = 1.0 / ans;
        }
        
        return ans;
    }
};
