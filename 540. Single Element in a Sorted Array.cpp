// https://leetcode.com/problems/single-element-in-a-sorted-array/



class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int Xor = 0;
        for(int i=0; i<nums.size(); i++){
            Xor ^= nums[i];
        }
        return Xor;
    }
};




// Optimal Approach: (Binary Search)

// We will use the fact that the vector is sorted.

// Observation: If you divide the array in two parts, PART A: where elements are before target element and PART B: where elements are after target element then:

// a. In PART A, the first instance of element occurs at even index and the second instance of the element occurs at odd index.

// b. In PART B, the first instance of element occurs at odd index and the second instance of the element occurs at even index.

// c. You can visualize using following example:

// index:   0 1 2 3 4 5 6 7 8
// vector: [1,1,2,3,3,4,4,8,8]
//              👆 (Target element is 2 since it appears once)
// In this example, before 2 every first instance of element occurs at even instance and second instance at odd index (see element 1) and after 2 every first instance of element occurs at odd index and second instance at even index (see element 3, 4 and 8).

// So from the above observation we will apply binary search on our array, and if we are on the PART - B side of array, we go to left, otherwise we go right.
// Code:

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-2; 
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            
            // If we are on left side, move right
            if(nums[mid] == nums[mid^1]) low = mid+1;
            // if we are on right side, move left
            else high = mid-1;
        }
        
        return nums[low];
    }
};

// mid^1 explanation:
// If mid is odd then (mid^1) will always be the even number before mid
// If mid is even then (mid^1) will always be the odd number after mid

// And hence I am able to check whether mid is in left half or right half as:

// Suppose mid is odd: then mid^1 will give even number before it, 
// then if nums[mid] == nums[mid^1] 
// then 1st instance at even (mid^1) and 2nd instance at odd (mid), 
// hence we are on left side otherwise we are on right side.

// Suppose mid is even: then mid^1 will give odd number after it, 
// then if nums[mid] == nums[mid^1]
// then 1st instance at even (mid) and 2nd instance at odd (mid^1), 
// hence we are on left side otherwise we are on right side
// Time Complexity: O(Log(N))
// Space Complexity: O(1)