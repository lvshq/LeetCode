/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 */


class Solution {
public:
    int numDecodings(string s) {
        int s_len = s.size();
        if (s.size() == 0)
            return 0;
        decode_num = 0;
        vector<int> decode_ways(s_len + 1, 0);
        // Method 1: DFS with Pruning(剪枝)/States Memory.
        // DFS(s, 0, s_len, decode_ways);
        
        // Method 2: DP
        DP(s, s_len, decode_ways);
        return decode_num;
    }
    
    // Method 2: DP
    void DP(string &s, int s_len, vector<int> &decode_ways) {
        // one number
        if (is_valid(s[0]))
            decode_ways[0] = 1;
        int num = std::stoi(s.substr(0, 2));
        // two numbers
        if (is_valid(s[1]))
            decode_ways[1] = decode_ways[0];
        if (10 <= num && num <= 26)
            decode_ways[1]++;
        // more than two numbers
        for (int i = 2; i < s_len; i++) {
            if (is_valid(s[i]))
                decode_ways[i] = decode_ways[i - 1];
            // using 'substr()' will cost much time, use below will save much time
            // if (s[i - 1] == '1' && s[i] <= '9' || s[i - 1] == '2' && s[i] <= '6') {
            string num = s.substr(i - 1, 2);
            if ("10" <= num && num <= "26") {
                decode_ways[i] += decode_ways[i - 2];
            }
        }
        decode_num = decode_ways[s_len - 1];
    }
    
    bool is_valid(char c) {
        return ('1' <= c && c <= '9');
    }
    
    // Method 1: DFS with Pruning(剪枝)/States Memory.
    void DFS(string& s, int start, int str_len, vector<int> &decode_ways) {
        if (start == str_len) {
            decode_num++;
            return;
        }
        if (!is_valid(s[start]))
            return;
        // If decodes numbers starts from start has been recored, then there is no need to DFS from start again.
        if (decode_ways[start] != 0) {
            decode_num += decode_ways[start];
            return;
        }
        // try one number
        DFS(s, start + 1, str_len, decode_ways);
        // try two numbers
        if (start <= str_len - 2) {
            int num = std::stoi(s.substr(start, 2));
            if (1 <= num && num <= 26) {
                DFS(s, start + 2, str_len, decode_ways);
            }
        }
        decode_ways[start] = decode_num;
    }
private:
    int decode_num;
};