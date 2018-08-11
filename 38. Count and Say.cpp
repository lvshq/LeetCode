/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/


class Solution {
public:
    string countAndSay(int n) {
        int j = 1;
        string *strs = new string[n];
        for (int i = 0; i < n; i++)
            strs[i] = "";
        strs[0] = "1";
        while (j < n) {
            string str = strs[j - 1];
            int len = str.size();
            int cnt = 1;
            for (int i = 0; i < len; i++) {
                if (i < len - 1 && str[i] == str[i + 1]) {
                    cnt++;
                } else {
                    strs[j] += to_string(cnt) + str[i];
                    cnt = 1;
                }
            }
            j++;
        }
        return strs[n - 1];
    }
};