// https://leetcode.com/problems/jump-game-iii/submissions/



//BFS
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        q.push(start);
        
        int n = arr.size();
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(arr[curr] == 0)  return 1;
            
            if(arr[curr] < 0)   continue;
            
            if(curr - arr[curr] >= 0){
                q.push(curr - arr[curr]);
            }
            
            if(curr + arr[curr] < n){
                q.push(curr + arr[curr]);
            }
            
            arr[curr] = -arr[curr]; //we can use here any negative numbers.
        }
        return 0;                            
    }
};



// DFS
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 || start >= arr.size() || arr[start] <0)    return 0;
        
        if(arr[start] == 0) return 1;
        arr[start] = -arr[start];
        return canReach(arr, start+arr[start]) || canReach(arr, start-arr[start]);
    }
};