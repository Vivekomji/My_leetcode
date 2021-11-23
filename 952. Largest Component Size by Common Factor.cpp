// https://leetcode.com/problems/largest-component-size-by-common-factor/



// We know from the problem statement, that if any two number have a common factor, they need to be put in the same set. For this, we can iterate over the list, factorize the number, for each of its factor (not 1 and number itself), we should unite the sets using [Disjoin set Union](https://cp-algorithms.com/data_structures/disjoint_set_union.html) (use path compession for efficiency).
// For instance, if we have [4, 6]
// factorize 4: 2
// unite(4, 2)
// factorize 6: 2, 3
// unite(6, 2)
// unite(6, 3)

// at the end we see that 4 and 6 belong to the same set.
// we use unordered_map to store parents and their frequency at the end and get parent with maximum size.

// Code

class DSU {
public:
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool same_set(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { 
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};


class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
		DSU dsu(*max_element(nums.begin(), nums.end()) + 1); //create DSU struct with nodes 0, 1, 2, ... max element of the vector
		for(auto i: nums){
			for(int j = 2;j*j<=i;j++){ //factorize each number
				if(i%j == 0){
					dsu.unite(j, i);
					dsu.unite(i/j, i);
				}
			}
		}
		int ans = 1;
		unordered_map<int, int> freq;
		for(auto i: nums){
			int p = dsu.get(i); //get parent
			freq[p]++;
			ans = max(ans, freq[p]);
		}
		return ans;
	}
};




// Another:

// ✔️ Solution - I (Union-Find)

// The problem statement can be stated in simpler terms as - two element belong to same group if they share a common factor. We need to find largest of such groups.

// For eg. If we have numbers [2,3,5,6,25], then we can see 2 & 6 share a common factor. So lets say they belong to group A. 3 & 6 also share a common factor, so 3 belongs to group A as well. 5 and 25 is another pair sharing a common factor so they belong to one group, lets say B. So, out of all these groups, A is the largest and it will be our answer.

// There's a common Data Structure that can be used in such problems - Disjoint Set Union.

// Brief Description of DSU
// Here, we use DSU to group elements of nums and its factors into a single component. Once this is done, all elements of nums that share a common factor will belong to the same component and will have the same parent in DSU. Then we can just iterate over nums, and find the parent of component that it belongs to. We keep count of number of times that each parent is seen. The largest group will be the one whose parent is seen maximum number of times.

// We can find the factors of a number in O(sqrt(N)) time and union each factor with that number itself.

// standard Disjoin Set Union class template
class DSU {
    public:
    vector<int> par, sz;
    DSU(int n) : par(n), sz(n,1) {
        iota(begin(par), end(par), 0);                         // initializes each node's parent to be itself - fills as [0,1,2,3,...,n]
    }
    int find(int x) {
        if(par[x] == x) return x;                              // x is itself the parent of the component that it belongs to
        return par[x] = find(par[x]);                          // update parent of x before returning for each call -path compression
    }
    bool Union(int x, int y) {
        int xp = find(x), yp = find(y);                        // find parents of x and y, i.e, representatives of components that x and y belong to
        if(xp == yp) return false;                             // x and y already belong to same component - not possible to union
        if(sz[xp] > sz[yp]) par[yp] = par[xp], sz[xp] += sz[yp];   // union by size - join smaller sized to bigger one
        else par[xp] = par[yp], sz[yp] += sz[xp];
        return true;
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = size(nums), ans = 1;
        DSU ds(*max_element(begin(nums), end(nums)) + 1);      // max(nums) is largest element that will be stored in DSU
        unordered_map<int, int> mp;                            // maintains {parent of component: frequency}
        for(auto c : nums) 
            for(int f = 2; f <= sqrt(c); f++)                  // finding factors of each element
                if(c % f == 0)                                 // if f divides c, then f & c/f are its factor. So union them
                    ds.Union(c, f), 
                    ds.Union(c, c/f);
        
        for(int i = 0; i < n; i++)                             // iterate and find parent that is seen most. It'll give the largest group
            ans = max(ans, ++mp[ds.find(nums[i])]);
        return ans;
    }
};
// Time Complexity : O(N * sqrt(M)), where N is the number of elements in nums and M is the maximum element in nums. The time complexity of each find call after union-by-size and path compression comes out to be O(α(n)), where α(n) is the inverse Ackermann function. It doesn't exceed 4 for any n < 10600 and hence is practically constant. We take each N elements from nums and iterate upto sqrt(num[i]). Thus the overall time comes out to O(N * sqrt(M)).
// Space Complexity : O(M), for DSU