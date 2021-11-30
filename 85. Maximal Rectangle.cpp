// https://leetcode.com/problems/maximal-rectangle/



class Solution {
public:
    vector<int> solveLeft(vector<int> v){
        vector<int>ans;
        stack<pair<int, int>>s;
        int defaultNo = -1;
        for(int i=0; i<v.size(); i++){
            if(s.size() == 0)   ans.push_back(defaultNo);
            else if(s.size()>0 && s.top().first < v[i]){
                ans.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first >= v[i]){
                while(s.size() > 0 && s.top().first >= v[i]){
                    s.pop();
                }
                if(s.size() == 0){
                    ans.push_back(defaultNo);
                }else{
                    ans.push_back(s.top().second);
                }
            }
                
            s.push({v[i], i});
        }
        return ans;
    }
    vector<int> solveRight(vector<int> v){
        vector<int>ans;
        stack<pair<int, int>>s;
        int defaultNo = v.size();
        for(int i=v.size()-1; i>=0; i--){
            if(s.size() == 0)   ans.push_back(defaultNo);
            else if(s.size()>0 && s.top().first < v[i]){
                ans.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first >= v[i]){
                while(s.size() > 0 && s.top().first >= v[i]){
                    s.pop();
                }
                if(s.size() == 0){
                    ans.push_back(defaultNo);
                }else{
                    ans.push_back(s.top().second);
                }
            }
                
            s.push({v[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;        
    }
    
    int maxArea(vector<int>& v){
        vector<int>left = solveLeft(v);
        vector<int>right = solveRight(v);
        vector<int>width;
        for(int i=0; i<v.size(); i++){
            width.push_back(right[i]-left[i]-1);
        }
        int mx = INT_MIN;
        for(int i=0; i<v.size(); i++){
            mx = max(mx, width[i]*v[i]);
        }
        return mx;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>v;
        
        int n = matrix.size();
        if(n==0)    return 0;
        int m = matrix[0].size();
        // if(n ==0 && m==0)   return 0;
        for(int j=0; j<m; j++){
            v.push_back(matrix[0][j] - '0');
        }
        int mx = maxArea(v);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '0')   v[j]=0;
                else    v[j] = v[j] + (matrix[i][j] - '0');
            }
            mx = max(mx, maxArea(v));
        }
        return mx;
    }
};