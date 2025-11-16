class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(int i=0; i<prefix.length(); i++) {
            char currChar = prefix[i];
            
            for(int j=1; j<strs.size(); j++) {
               if(i>=strs[j].length() || strs[j][i]!= currChar) {
                return prefix.substr(0,i);
               } 
            }
        }
        return prefix;
    }
};