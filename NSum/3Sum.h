/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rst;
        int numsSize = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<numsSize; i++) {
            int target = -nums[i];
            int begin = i+1;
            int end = numsSize-1;
            while(begin<end) {
                int sum = nums[begin]+nums[end];
                if(sum<target) begin++;
                else if(sum>target) end--;
                else {
                    vector<int> ans{nums[i],nums[begin],nums[end]};
                    rst.push_back(ans);
                    while(begin<end && nums[begin]==ans[1]) begin++;
                    while(begin<end && nums[end]==ans[2]) end--;
                }
            }
            while(i+1<numsSize && nums[i]==nums[i+1]) i++;
        }
        return rst;
    }
};