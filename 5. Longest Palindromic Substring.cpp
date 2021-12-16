// https://leetcode.com/problems/longest-palindromic-substring/




class Solution {
public:
    
    string expand(string s, int i, int j){
        if(s[i] != s[j])    return "";
        
        while(i-1 >= 0 && j+1 < s.length() && s[i-1]==s[j+1]){
            i--;
            j++;
        }
        return s.substr(i, j-i+1);
    }
    
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        
        string ans = "";
        for(int i=0; i<s.length(); i++){
            string s1 = expand(s, i, i);
            string s2 = expand(s, i, i+1);
            s1 = (s1.length() > s2.length()) ? s1 : s2;
            ans = (s1.length() > ans.length()) ? s1 : ans;
        }
        return ans;
    }
};