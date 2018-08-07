/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/


/*
    Here we can't use '^' since it could only be applied to integer.
    The recursive version is easier to understand.
*/
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0f;
        if (n == 1)
            return x;
        // If n equals -2147483648, -n will overflow. So this step is to avoid overflow.
        if (n == INT_MIN) {
            return myPow(x, INT_MIN + 1) / x;
        } else if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        
        // Method 1: Recursive version, easier to understand.
        // If (n%2 == 0), then x^n comes from  x^(2k) => (x^2)^k from last step, where k is n/2;
        // else x^n comes from some (x^(2k)) *x => ((x^2)^k) * x, where k is n/2.
        return (n%2 == 0) ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
        
        // Method 2: Iterative version.
        // return Method2(x, n);

    }
    
    double Method2(double x, int n) {
        double base = 1;
        while (n > 0) {
            if (n % 2 == 1)
                base *= x;
            x *= x;
            n /= 2;
        }
        return base;
    }
};