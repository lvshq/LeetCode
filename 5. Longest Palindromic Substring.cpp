/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

/*
DP formula:
DP(i, i) = True
DP(i, i+1) = (S(i) == S(i+1))
DP(i, j) = DP(i+1, j-1) & (S(i) == S(j))


Complexity Analysis

Time complexity : O(n^2)
This gives us a runtime complexity of O(n^2).

Space complexity : O(n^2).
It uses O(n^2) space to store the table.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        const int matrix_size = 1001;
        int total_len = s.length();
        bool dp[matrix_size][matrix_size];
        memset(dp, false, sizeof(dp));
        // First deal with basic two scenarios.
        for (int i = 0; i < total_len; i++) {
            dp[i][i] = true;
            if (s[i] == s[i+1] && i+1 < total_len)
                dp[i][i+1] = true;
        }
        int max_substr_len = 1;
        int substr_start_index = 0;
        // NOTE: it would fail if first loop is substr's start index, since many dp[i+1][j-1] hasn't been assigned.
        for (int len = 2; len <= total_len; len++)  // substr's length
            for (int start = 0; start <= total_len-len; start++) {  // substr's start index
                int end = start + len - 1;
                if (len > 2 && s[start] == s[end] && dp[start+1][end-1]) {
                    dp[start][end] = true;
                }
                if (dp[start][end]) {
                    int substr_len = len;
                    if (substr_len > max_substr_len) {
                        max_substr_len = substr_len;
                        substr_start_index = start;
                    }
                }
            }
        return s.substr(substr_start_index, max_substr_len);
    }
};