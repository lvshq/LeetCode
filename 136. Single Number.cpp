/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/

/*
Time complexity : O(n). We only iterate through nums, so the time complexity is the number of elements in nums.
Space complexity : O(1).


*/

/*
    Use bit operation is the fastest way without extra memory.
    a xor a = 0
    a xor 0 = a
    a xor b xor a = (a xor a) xor b = 0 xor b = b
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int single_num = nums[0];
        for (int i = 1; i < len; i++) {
            single_num = single_num ^ nums[i];
        }
        return single_num;
    }
};