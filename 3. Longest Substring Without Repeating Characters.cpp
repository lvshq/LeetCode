/*
Sliding Window
Time complexity : O(2n) = O(n).
In the worst case each character will be visited twice by i and j.

Space complexity : O(min(m, n)).
Same as the previous approach. We need O(k)space for the sliding window, where k is the size of the Set.
The size of the Set is upper bounded by the size of the string n and the size of the charset/alphabet m. 
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int total_len = s.length();
        int max_len = 0;
        int index[256];
        for (int i = 0; i < 256; i++)
            index[i] = -1;
        for (int i = 0, j = 0; j < total_len; j++) {
            // j has a same character in [i, j).
            // NOTE: should not write as "i <= index[s[j]] < j", which is actually "(i <= index[s[j]]) < j"
            if (i <= index[s[j]] && index[s[j]] < j) {
                i = index[s[j]] + 1;  // continue from next character
            }
            int substr_len = j - i + 1;
            max_len = max(substr_len, max_len);
            index[s[j]] = j;  // record current character's index
        }
        return max_len;
    }
};