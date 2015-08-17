/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/


//int 数据共有32位，可以用32变量存储 这 N 个元素中各个二进制位上1出现的次数，最后进行模三操作，如果为1，那说明这一位是要找元素二进制表示中为 1 的那一位。
//24ms
class Solution {
public:
    int singleNumber(int A[], int n) {
        int bitnum[32]={0};
        int res=0;
        for(int i=0; i<32; i++){
            for(int j=0; j<n; j++){
                bitnum[i]+=(A[j]>>i)&1;
            }
            res|=(bitnum[i]%3)<<i;
        }
        return res;
    }
};

//2015-08-17
//12ms
//http://www.cnblogs.com/x1957/p/3373994.html
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0;
        int two = 0;
        int three = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            two |= nums[i] & one;
            one = nums[i] ^ one;
            three = ~(one&two);
            one &= three;
            two &= three;
        }
        return one;
        
    }
};