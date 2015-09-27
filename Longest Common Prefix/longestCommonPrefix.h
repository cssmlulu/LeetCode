/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        string prefix="";
        for(int i=0; size>0; i++) {
            for(int j=0; j<size; j++) {
                if(i>=strs[j].size() || (j>0 && (strs[j][i] != strs[j-1][i])))
                    return prefix;
            }
            prefix += strs[0][i];
        }
        return prefix;
    }
};