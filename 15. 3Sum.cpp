/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

/*
    First sort the array, then search each non-repeat triple.
    Skip those repeat number (after sorting, same numbers are close to each other) while search.
*/

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector< vector<int> > result;
        int len = nums.size();
        if (len < 3)
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            if ( !(i == 0 || (i > 0 && nums[i] != nums[i - 1])) )
                continue;
            int front = i + 1;
            int rear = len - 1;
            int sum = 0 - nums[i];
            while (front < rear) {
                if (nums[front] + nums[rear] == sum) {
                    result.push_back( vector<int>{nums[i], nums[front], nums[rear]});
                    // Skip same numbers
                    while (front < rear && nums[front] == nums[front + 1])
                        front++;
                    while (front < rear && nums[rear] == nums[rear - 1])
                        rear--;
                    front++; rear--;
                } else if (nums[front] + nums[rear] > sum) {
                    rear--;
                } else {
                    front++;
                }
                
                
            }
        }
        return result;
    }
};