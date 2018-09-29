/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
 */
/*
    First find the rotating/turning point of the rotated sorted array using binary search,
    then search like normal binary search in the part that target lies in.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if (left > right)
            return -1;
        if (nums[left] > nums[right]) {  // the sorted array has been rotated.
            while (left <= right) {  // search the turning point.
                int mid = (left + right) / 2;
                if (nums[mid] > nums[mid + 1]) {  // find the turning point
                    if (nums[0] <= target && target <= nums[mid]) {  // the target is in left part
                        right = mid; left = 0;
                    } else {
                        left = mid + 1; right = nums.size() - 1;
                    }
                    break;
                } else if (nums[mid] >= nums[left]) {
                    // [2,3,4,5,0,1]  5>2, so left part is ordered, we should search in right part
                    left = mid;
                } else {  // search in left part
                    right = mid;
                }
            }
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
