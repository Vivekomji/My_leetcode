//https://leetcode.com/problems/interval-list-intersections/



class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        int i=0, j=0;
        vector<vector<int>>v;
        // vector<int>v1(2);
        while(i<n && j<m){
            int front = max(firstList[i][0], secondList[j][0]);
            int back = min(firstList[i][1], secondList[j][1]);
            if(front <= back){
                v.push_back({front, back});
            }
            
            ////Now increment the pointer corresponding to the interval that ends first because it won't have any overlapping later
            if(firstList[i][1] < secondList[j][1])  i++;
            else j++;
            
        }
        return v;
    }
};