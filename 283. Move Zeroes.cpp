/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

/*
    Use two pointers to iterate the array: first is slow and second is fast.
    If the first encounters a 0, then swap the two pointers' values.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int j = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0) {
                // Find the neareast number that is not 0.
                while (nums[j] == 0 && j < len) {
                    j++;
                }
                if (j < len) {
                    nums[i] = nums[j];  // Swap nums[i] and nums[j], namely move 0 back.
                    nums[j] = 0;
                }
            }
            j++;
        }
    }
};