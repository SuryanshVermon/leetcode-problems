class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
      unordered_set<string >st;

      for(auto &path :paths){
        string source =path[0];
        st.insert(source);
      }

      for(auto &path :paths){
        string destination = path[1];

        if(st.find(destination) == st.end()){
            return destination;
        }
      }

      return "";
    }
};