/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        // DON'T for get NULL situation!!!
        if (digits.size() == 0)
            return result;
        combine(0, 0, "", digits, result);
        return result;
    }
    // DFS
    void combine(int pos, int index, string cur_str, string& digits, vector<string>& result) {
        if (pos == digits.size()) {
            result.push_back(cur_str);
            return;
        }
        int max_index = u_m[ digits[pos] ].size();
        // Try each character of current position.
        for (int i = 0; i < max_index; i++) {
            string new_str = cur_str + u_m[ digits[pos] ][i];
            // Since current position has been filled by u_m[ digits[pos] ][i],
            //   next time should search in next position, so pos + 1.
            combine(pos + 1, i, new_str, digits, result);
        }
    }

private:
    unordered_map<char, string> u_m = { {'2', "abc"},
                                       {'3', "def"},
                                       {'4', "ghi"},
                                       {'5', "jkl"},
                                       {'6', "mno"},
                                       {'7', "pqrs"},
                                       {'8', "tuv"},
                                       {'9', "wxyz"}};
};