/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        std::vector<std::string> rst;
        if(s.length()<10)
            return rst;
        
        std::unordered_map<char,int> convert;
        convert['A'] = 0;
        convert['C'] = 1;
        convert['G'] = 2;
        convert['T'] = 3;
        
        int substr=0;
        for(int i=0; i<10 ;i++) {
            substr <<= 2;
            substr |= convert[s[i]];
        }
        //substr = 'AAAAACCCCC'
        std::unordered_set<int> substrs; 
        std::unordered_set<int> findstrs; 
        substrs.insert(substr);

        for(int i=10; i<s.length(); i++) {
            substr <<= 2;
            substr &= ~(0x300000); //clean bit 20-23(first character)
            substr |= convert[s[i]]; //add new character
            if(substrs.find(substr)==substrs.end()) {
                substrs.insert(substr);
            }
            else if(findstrs.find(substr)==findstrs.end()){
                rst.push_back(s.substr(i - 9, 10));
                findstrs.insert(substr);
            }
        }
        return rst;
    }
};