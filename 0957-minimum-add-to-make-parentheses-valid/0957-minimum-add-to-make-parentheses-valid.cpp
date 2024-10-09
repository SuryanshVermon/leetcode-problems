#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int unmatchedClosing = 0; 
        for(char &ch : s) {
            if(ch == '(') {
                st.push(ch); 
            }
            else {
                if(!st.empty()) {
                    st.pop();  
                } else {
                    unmatchedClosing++;  
                }
            }
        }
        return st.size() + unmatchedClosing;
    }
};
