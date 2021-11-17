https://leetcode.com/problems/majority-element-ii/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, a=0, b=1;
    
        for(auto x: nums){
            if (a==x){
                cnt1++;
            }
            else if (b==x){
                cnt2++;
            }
            else if (cnt1==0){
                a = x;
                cnt1 = 1;
            }
            else if (cnt2 == 0){
                b = x;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for(auto x: nums){
            if (x==a)   cnt1++;
            else if (x==b)  cnt2++;
        }

        vector<int> res;
        if (cnt1 > nums.size()/3)   res.push_back(a);
        if (cnt2 > nums.size()/3)   res.push_back(b);
        return res;
    }
};