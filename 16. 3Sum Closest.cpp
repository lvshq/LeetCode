/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/



/*
    Almost same as [15. 3Sum], but pay attention to the order of [target - cur_sum] and [cur_sum - target],
    or use abs(target - cur_sum) to avoid sign error.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        int closest_sum = 0;
        for (int i = 0; i < len; i++) {
            int l = i + 1;
            int r = len - 1;
            while (l < r) {
                int cur_sum = nums[i] + nums[l] + nums[r];
                if (target == cur_sum) {
                    closest_sum = cur_sum;
                    return closest_sum;
                } else if (target > cur_sum) {
                    if (target - cur_sum < min_diff) {
                        min_diff = target - cur_sum;
                        closest_sum = cur_sum;
                    }
                    l++;
                } else {
                    if (cur_sum - target < min_diff) {
                        min_diff = cur_sum - target;
                        closest_sum = cur_sum;
                    }
                    r--;
                }
            }
        }
    return closest_sum;
    }
};
