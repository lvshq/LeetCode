/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for (auto w : wordDict) {
            wordSet.insert(w);
        }
        
        // Method 1: DFS
        int len = s.size();
        // mem is used to store search states: mem[i] means whether s[i:end] is breakable by words in wordDict.
        vector<short> mem(len, -1);
        return DFS(0, s, mem, wordSet);
        
        // Method 2: BFS
        // return BFS(s, wordSet);
    }
    // Method 1: DFS
    bool DFS(int start, string& s, vector<short>& mem, unordered_set<string>& wordSet) {
        int len = s.size();
        if (start == len)
            return true;
        if (mem[start] != -1)
            return mem[start];
        /* NOTE: boundary value is IMPORTANT!
        If started from start+1, then substr should be 's.substr(start, end - start)',
            and largest value should be len.
        */
        for (int end = start + 1; end <= len; end++) {
            string sub_str = s.substr(start, end - start);
            cout << sub_str << endl;
            if (wordSet.count(sub_str) > 0 && DFS(end, s, mem, wordSet)) {
                mem[start] = true;
                return true;
            }
        }
        mem[start] = false;
        return false;
    }
    
    // Method 2: BFS
    bool BFS(string &s, unordered_set<string>& wordSet) {
        int len = s.size();
        vector<bool> visited(len, false);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int start = q.front(); q.pop();
            if (visited[start] == true)
                continue;
            /* NOTE: boundary value is IMPORTANT!
            If started from start+1, then substr should be 's.substr(start, end - start)',
                and largest value should be len.
            */
            for (int end = start + 1; end <= len; end++) {
                string sub_str = s.substr(start, end - start);
                // cout << sub_str << endl;
                if (wordSet.count(sub_str) > 0) {
                    q.push(end);
                    if (end == len)
                        return true;
                }
            }
            visited[start] = true;
        }
        return false;
    }
    
};