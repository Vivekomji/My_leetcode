// https://leetcode.com/problems/longest-substring-without-repeating-characters/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>v(256, -1);
        int ans = 0;
        int startlen = -1;
        for(int i=0; i<s.length(); i++){
            if(v[s[i]] > startlen){
                startlen = v[s[i]];
            }
            v[s[i]] = i;
            ans = max(ans, i-startlen);
        }
        return ans;
    }
};