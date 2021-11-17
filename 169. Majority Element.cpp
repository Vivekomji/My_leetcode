https://leetcode.com/problems/majority-element/



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele = nums[0];
        int count =1;
        for(int i=1; i<n; i++){
            if(nums[i] == ele){
                count ++;
            }else{
                count --;
            }
            if(count == 0){
                ele = nums[i];
                count = 1;
            }
        }
        
        return ele;
        
    }
};