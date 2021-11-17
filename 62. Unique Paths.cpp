// https://leetcode.com/problems/unique-paths/


// Hello everyone, I hope you all are doing great.
// Note: Please do upvote if you find this post helpful!

// This is a combinatorics problem that can be easily solved without DP or recursion.

// Observation: If you observe it care fully, our robot has to move n-1 steps right and m-1 steps down in any order to reach the right bottom of the grid. You will understand this more with the following example.

// Example: We had 3x7 grid, robot needs to take (3-1) = 2 steps down overall and 7-1 = 6 steps right overall to reach the bottom right of the grid. This is a total of 8 steps. And the ordering doesn't matter like: D D R R R R R R or D R D R R R R R or R R R R R R D D will all do the job, and all of this is noting but the permutation of total steps. So this is nothing but number of ways of choose D in the 8 blanks or number of ways of choosing R in the 8 blanks which is nothing but 8C6 or 8C2 = 28 (both will do the job) [Someone please tell me how to type nCr the way it looks on this discussion post 😂]

// Approach: So, we only need to choose number of ways of picking right from the total steps or number of ways of choosing down from the total steps. Which is nothing but (total) C (right) or (total) C (down).


class Solution {
public:
    int ncr(int total, int n){
        double ans = 1;
        if(total == n)  return ans;
        for(int i=1; i<=n; i++){
            ans = (ans*(total-i+1))/i;
            // cout << ans <<" ";
        }
        return (int)ans;
    }
    
    int uniquePaths(int m, int n) {
        int steps = m+n-2;
        // cout << ncr(8, 2);
        return ncr(steps, min(m, n)-1);
    }
};