/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

class Solution {
public:
    string reverseString(string s) {
        int len = s.size();
        for (int i = 0; i <= len / 2; i++) {
            int j = len -1 - i;
            if (j > i)
                swap(s[i], s[j]);
        }
        return s;
    }
    void swap(char &a, char &b) {
        char temp = a;
        a = b;
        b = temp;
    }
};