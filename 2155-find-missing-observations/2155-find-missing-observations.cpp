class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
      int m =rolls.size();
      int sum =0;
      int S;
      for(int i=0;i<m;i++){
        sum+=rolls[i];
      }  
      S =(mean *(m+n)) -sum;
      cout<<S;
      if (S < n || S > 6 * n) {
        return {};
    }

    vector<int> array(n, 1);

    int remaining = S - n;

    int i = 0;
    while (remaining > 0) {
        int increment = min(remaining, 5);
        array[i] += increment;
        remaining -= increment;
        i = (i + 1) % n; 
    }

    return array;

    }
};