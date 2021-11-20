https://leetcode.com/problems/two-sum/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int, int> map;
        
        for(int i=0; i<nums.size(); i++){
            if(map.find(target-nums[i]) != map.end()){
                v.push_back(i);
                v.push_back(map[target-nums[i]]);
                return v;
            }
            map[nums[i]]=i;
        }
        return v;
    }
};