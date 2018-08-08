/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.
*/


class Solution {
public:
    // Method 1: recursive
    int getSum(int a, int b) {
        // return getSum2(a, b);

        if (b == 0)  // if there were no carry, means a^b in last step is just the answer. So just return!
            return a;
        int sum = a ^ b;  // the sum without carry bit, the sum 'body'.
        int carry = (a & b) << 1;  // the 'carry', which is also the sum 'head'.
        return getSum(sum, carry);  // add the carry and the sum body.
    }
    
    // Method 2: iterative
    int getSum2(int a, int b) {
        while (b != 0) {
            int sum = a ^ b;
            int carry = (a & b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};