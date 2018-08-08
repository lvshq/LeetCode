/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/

/*
    Application of using bit operation.
    A good summary is in discussion: https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary:-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x ^ y;
        int different_bit = 0;
        while (temp > 0) {
            if (temp & 1) {  // is odd
                different_bit++;
            }
            temp = temp >> 1;
        }
        return different_bit;
    }
};