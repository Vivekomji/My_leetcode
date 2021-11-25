// https://leetcode.com/problems/maximum-subarray/



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0], currSum = nums[0];
        for(int i=1; i<nums.size(); i++){
            currSum = max(nums[i], currSum + nums[i]);
            mx = max(mx, currSum);            
        }
        return mx;
    }
};