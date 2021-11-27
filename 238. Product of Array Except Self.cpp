// https://leetcode.com/problems/product-of-array-except-self/



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count0 = 0;
        int pro = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0)  count0++;
            else    pro *= nums[i];
        }
        if(count0 > 1){
            for(int i=0; i<nums.size(); i++){
                nums[i] = 0;
            }
        }
        else if(count0 == 1){
            for(int i=0; i<nums.size(); i++){
                if(nums[i] != 0)    nums[i]=0;
                else nums[i] = pro;
            }
        }
        else{
            for(int i=0; i<nums.size(); i++){
                nums[i] = pro/nums[i];
            }
        }
        return nums;
    }
};