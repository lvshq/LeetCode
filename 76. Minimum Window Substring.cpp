/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 */


/*
    Using Sliding Window.
    Pay attention to when to move left and right pointers, and how to compare two string's characters frequency.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> char_freq;  // character frequency in T
        unordered_map<char, int> window;  // character frequency in window (substring of S)
        int t_len = t.size();
        int s_len = s.size();
        // Initialization
        int char_cnt = 0;  // Total characters (including same characters) in T
        for (int i = 0; i < t_len; i++) {
            char_freq[t[i]]++;
            char_cnt++;
        }
        bool has_finded = false;
        int l = 0, r = 0;
        int min_len = INT_MAX;
        int substr_start, substr_end;
        int window_char_cnt = 0;  // Use this to compare two string's character counts
        bool right_move = true;
        while (r < s_len) {
            if (char_freq.count(s[r]) > 0) {  // the character is in T
                // NOTE: no need to 'if (window.count(s[r]) > 0) {...}', the default value for int in pair is 0.
                window[s[r]]++;  // the character's frequency in window + 1
                // If current character's frequency has not exceed the target frequency,
                //   then each new letter will increase the total character's count.
                if (window[s[r]] <= char_freq[s[r]])
                    window_char_cnt++;
                // As long as we find a valid window, move left side of the window towards right.
                while (window_char_cnt >= char_cnt && l <= r) {
                    has_finded = true;
                    int str_len = r - l + 1;
                    if (str_len < min_len) {
                        min_len = str_len;
                        substr_start = l;
                        substr_end = r;
                    }
                    // Since the windows's left side will move right, the left most character is dropped.
                    if (window.count(s[l]) > 0) {
                        window[s[l]]--;
                        if (window[s[l]] < 0)
                            window[s[l]] = 0;
                    }
                    // The frequency shoud decrease if the dropped character is in T and its frequency doesn't meet T's requirment.
                    if (char_freq.count(s[l]) > 0 && window[s[l]] < char_freq[s[l]])
                        window_char_cnt--;
                    l++;
                }
            }
            r++;
        }
        if (!has_finded)
            return "";
        return s.substr(substr_start, min_len);
    }
};
