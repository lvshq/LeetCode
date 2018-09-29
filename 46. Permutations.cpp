/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> result;
        if (nums.size() <= 1) {
            result.push_back(nums);
            return result;
        }
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        result.push_back(sorted_nums);
        while (next_permute(sorted_nums)) {
            result.push_back(sorted_nums);
        }
        return result;
    }
    
    bool next_permute(vector<int>& nums) {
        int len = nums.size();
        int i = len - 2;
        // 1. Find first decending num from right to left
        while (i >= 0) {
            if (nums[i + 1] > nums[i])
                break;
            i--;
        }
        // If all numbser are ascending from right to left, this are no more permutations, just return.
        if (i < 0)
            return false;
        // 2. Find the first num that is larger that nums[i]
        int j = len - 1;
        while (j >= i && nums[j] < nums[i]) {
            j--;
        }
        // these two functions are in <algorithm.h>, faster than hand-written functions.
        std::swap(nums[i], nums[j]);
        std::reverse(nums.begin() + i + 1, nums.end());
        return true;
    }
};