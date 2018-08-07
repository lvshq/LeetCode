/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

/*
Time complexity : O(log10(n))
Because binary search cuts the search space roughly in half on each iteration, 
there can be at most log10(n) ​iterations.
Binary search is invoked twice, so the overall complexity is logarithmic.

Space complexity : O(1)
All work is done in place, so the overall memory usage is constant.
*/
/*
    Application of modified Binary Search.
    Pay attention to the change of [left] and [right]. They must change otherwise mid will stay unchanged.
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int L = -1, R = -1;
        int left = 0, right = len - 1;
        // 1. Find the largest num less than target.
        while (left <= right) {
            int mid = (left + right) / 2;
            if ((mid - 1 < 0 || nums[mid - 1] < target) && nums[mid] == target) {
                L = mid;
                break;
            // left and right must change in each if-branch, otherwise mid will stay unchanged and fall into dead loop.
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        left = 0, right = len - 1;
        // 2. Find the smallest num larger than target.
        while (left <= right) {
            int mid = (left + right) / 2;
            if ((mid + 1 >= len || nums[mid + 1] > target) && nums[mid] == target) {
                R = mid;
                break;
            } else if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        vector<int> result;
        result.push_back(L);
        result.push_back(R);
        return result;
    }
};