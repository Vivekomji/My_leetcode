// https://leetcode.com/problems/minimum-height-trees/




class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)    return {0};
        vector<unordered_set<int>> adj(n);
        for(auto &x : edges){
            adj[x[0]].insert(x[1]);
            adj[x[1]].insert(x[0]);
        }
        
        queue<int> q;
        for(int i=0; i<adj.size(); i++){
            if(adj[i].size() == 1)  q.push(i);
        }
        
        while(n > 2){
            int len = q.size();
            n = n - len;
            for(int i=0; i<len; i++){
                int node = q.front();
                q.pop();
                for(auto &x : adj[node]){
                    adj[x].erase(node);
                    if(adj[x].size() == 1)  q.push(x);
                }
            }
        }
        vector<int> v;
        while(q.size() > 0){
            v.push_back(q.front());
            q.pop();
        }
        return v;
    }
};