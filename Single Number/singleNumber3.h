/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            ret = ret ^ nums[i];
        }
        int lastOneVal = ret - (ret & (ret - 1)); //find last '1' bit
        vector<int> vec1;
        vector<int> vec2;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & lastOneVal) {
                vec1.push_back(nums[i]);
            }else {
                vec2.push_back(nums[i]);
            }
        }
        vector<int> retVec;
        retVec.push_back(singleNumber1(vec1));
        retVec.push_back(singleNumber1(vec2));
        return retVec;
    }
    int singleNumber1(vector<int>& nums) {
        int ret = 0;
        for(auto& i: nums) {
            ret ^= i;            
        }
        return ret;
    }
};