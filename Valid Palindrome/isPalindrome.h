/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s=="")return true;
        for(int i=0,j=s.length()-1;i!=j&&i!=j+1;i++,j--){
            while(!((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'))){
                i++;
                if(i>j) break;
            }
            while(!((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')||(s[j]>='0'&&s[j]<='9'))){
                j--;
                if(j<i)break;
            }
            if(i>j)break;
            if(i==j)return true;
            if(toupper(s[i])!=toupper(s[j]))return false;
        }
        return true;
    }
};