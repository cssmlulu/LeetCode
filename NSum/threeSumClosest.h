/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int numsSize = nums.size();
        sort(nums.begin(),nums.end());
        int rst = nums[0]+nums[1]+nums[numsSize-1];
        
        for(int i=0; i<numsSize; i++) {
            int begin = i+1;
            int end = numsSize-1;
            while(begin<end) {
                int sum = nums[i]+nums[begin]+nums[end];
                if(abs(sum-target)<abs(rst-target)) rst = sum;
                if(sum<target) begin++;
                else if(sum>target) end--;
                else return rst;
            }
        }
        return rst;
    }
};