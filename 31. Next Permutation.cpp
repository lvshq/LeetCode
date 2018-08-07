/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

/*
  Time complexity : O(n). In worst case, only two scans of the whole array are needed.
  Space complexity : O(1). No extra space is used. In place replacements are done.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1)
            return;
        int pivot_index = -1;
        int right_pivot_index = -1;
        // 1. Find first a[i - 1] which is smaller than a[i] from right to left.
        for (int i = len - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                pivot_index = i - 1;
                right_pivot_index = i;
                break;
            }
        }
        // 2. Find the element in [i, len) which is just larger than a[i-1] from right to left.
        // This element will be the first one larger than a[i-1], because right part of a[i-1] is non-decrease from right to left.
        if (pivot_index >= 0) {
            for (int j = len - 1; j >= pivot_index + 1; j--) {
                if (nums[j] > nums[pivot_index]) {
                    right_pivot_index = j;
                    break;
                }
            }
            swap(nums, pivot_index, right_pivot_index);
        }
        reverse(nums, pivot_index + 1, len - 1);
    }

    void swap(vector<int> &nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }

    void reverse(vector<int> &nums, int index1, int index2) {
        while (index2 > index1) {
            swap(nums, index1, index2);
            index2--;
            index1++;
        }
    }
};