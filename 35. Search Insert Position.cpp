https://leetcode.com/problems/search-insert-position/



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = 0;
        int low = 0, high = nums.size()-1;
        if(nums[0] > target)    return 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid]>target){
                high = mid-1;
            }
            else if(nums[mid]<target){
                ans = mid;
                low = mid+1;
            }
        }
        // if(nums[0] > target)    return 0;
        return ans+1;
    }
};