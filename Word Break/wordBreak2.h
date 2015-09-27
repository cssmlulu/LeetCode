/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/


//TLE :(
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        std::map<int,std::vector<std::string>> dp;
        
        for(int i=1; i<=s.size(); i++) {
            for(int j=i-1; j>=0; j--) {
                if(dp.find(j) == dp.end() && j!=0) continue;
                
                std::string sub = s.substr(j,i-j);
                if(wordDict.find(sub) != wordDict.end()) {
                    if(j==0) {
                        dp[i].push_back(sub);
                    }
                    else {
                        for(auto& s: dp[j])
                            dp[i].push_back(s+" "+sub);
                    }
                }
            }
        }
        
        if(dp.find(s.size()) != dp.end()) {
            return dp[s.size()];
        }
        else {
            vector<string> rst;
            return rst;
        }
    }
};








class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> rst;
        if (dict.size() == 0) return rst;

        vector<vector<int> > dp(s.size() + 1);
        dp[0].push_back(-1);

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j].size() && dict.count(s.substr(j, i - j))) {
                        dp[i].push_back(j);
                }
            }
        }

        return backTrack(s, dp, s.size());
    }

    vector<string> backTrack(string& s, vector<vector<int> >& spaceIdx, int idx) {
        vector<string> rst;
        if (idx <= 0) {rst.push_back(""); return rst;}

        vector<int> idxVec(spaceIdx[idx]);
        for (int i = 0; i < idxVec.size(); i++) {
            string str = s.substr(idxVec[i], idx - idxVec[i]);
            vector<string> subrst = backTrack(s, spaceIdx, idxVec[i]);
            for (auto& prev : subrst) {
                if (prev != "") prev = prev + " " + str;
                else prev = str;
                rst.push_back(prev);
            }
        }

        return rst;
    }
};