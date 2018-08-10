/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Suppose we can't modify digits's content, otherwise we could use digits directly.
        vector<int> result(digits);
        int len = result.size();
        if (len == 0)
            return result;
        int carry = (++result[len - 1]) / 10;
        int i = len - 1;
        while (carry && i >= 0) {
            result[i--] %= 10;
            if (i < 0)
                break;
            result[i]++;
            carry = result[i] / 10;
        }
        // This is how to insert an element in front of a vector:
        if (carry) {
            result.insert(result.begin(), 1);
        }
        return result;
    }
};