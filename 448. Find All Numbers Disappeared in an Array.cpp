https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/



class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>hash(n+1);
        for(auto x : nums){
            hash[x]++;
        }
        vector<int>v;
        for(int i=1; i<n+1; i++){
            if(hash[i] == 0){
                v.push_back(i);
            }
        }
        return v;
    }
};



// Using swap sort

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>v;
        int i=0;
        while(i<nums.size()){
            if(nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }else{
                i++;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i+1){
                v.push_back(i+1);
            }
        }
        return v;
    }
};