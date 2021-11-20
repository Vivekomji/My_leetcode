// https://leetcode.com/problems/longest-consecutive-sequence/



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        int count = 1;
        sort(nums.begin(), nums.end());
        int curr =1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1])    continue;
            if(nums[i] == nums[i-1]+1){
                curr++;
                count = max(count, curr);
            }
            else{
                // count = max(count, curr);
                curr =1;
            }
        }
        return count;
    }
};