/*
Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/



//TLE
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if(wordDict.empty())
            return 0;
        if(isOneWordDiff(beginWord,endWord))
            return 2;
        
        queue<string> bfs;
        unordered_map<string,int> visited;

        
        visited[beginWord]=1;
        bfs.push(beginWord);
        
        while(!bfs.empty()) {
            string word = bfs.front(); bfs.pop();
            for(auto& dictWord: wordDict) {
                if(visited.find(dictWord) != visited.end()) continue;
                if(isOneWordDiff(word,dictWord)) {
                    visited[dictWord] = visited[word] +1;
                    if(isOneWordDiff(dictWord,endWord))
                        return visited[dictWord] +1;
                    else
                        bfs.push(dictWord);
                }
                
            }
        }
        return 0;       
    }
private:    
    bool isOneWordDiff(const string& w1, const string& w2) {
        if(w1.size() != w2.size())
            return false;
        
        int diff = 0;
        for(int i=0; i<w1.size(); i++) {
            if(w1[i] != w2[i])
                diff++;
            if(diff>2)
                return false;
        }
        return diff==1;
    }
};


//a two-end search solution
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        int dist = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            }
            else {
                phead = &tail; 
                ptail = &head;
            }
            unordered_set<string> temp; 
            for (auto itr = phead -> begin(); itr != phead -> end(); itr++) {
                string word = *itr;
                wordDict.erase(word);
                for (int p = 0; p < (int)word.length(); p++) {
                    char letter = word[p];
                    for (int k = 0; k < 26; k++) {
                        word[p] = 'a' + k;
                        if (ptail -> find(word) != ptail -> end())
                            return dist;
                        if (wordDict.find(word) != wordDict.end()) {
                            temp.insert(word);
                            wordDict.erase(word);
                        }
                    }
                    word[p] = letter;
                }
            }
            dist++;
            swap(*phead, temp);
        }
        return 0; 
    }
};