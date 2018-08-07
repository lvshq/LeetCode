/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/


/*
Two methods:
1. Sort each string to do normalization and mapping them.

Time Complexity: O(NKlog K), where N is the length of strs, and K is the maximum length of a string in strs.
The outer loop has complexity O(N) as we iterate through each string.
Then, we sort each string in O(Klog K) time.

Space Complexity: O(NK), the total information content stored in ans. 


2. Map each string to a key in format "2#1#0#...", where each number is the time of the character.
Time Complexity: O(NK), where N is the length of strs, and K is the maximum length of a string in strs.
Counting each string is linear in the size of the string, and we count every string.

Space Complexity: O(NK), the total information content stored in ans.
*/
#include <algorithm>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return Method1(strs);
        // return Method2(strs);
    }

    // 1. Sort each string to do normalization and mapping them.
    vector<vector<string>> Method1(vector<string>& strs) {
        vector<vector<string>> result;
        // USE unordered_map ! map is implemented by Red-Black tree, while unordered_map is implemented by HashTable.
        unordered_map<string, vector<string>> str_map;
        // Method 1:
        int len = strs.size();
        for (int i = 0; i < len; i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            str_map[key].push_back(strs[i]);
        }
        unordered_map<string, vector<string>>::iterator iter = str_map.begin();
        while (iter != str_map.end()) {
            result.push_back(iter->second);
            iter++;
        }
        return result;
    }
    
    // 2. Map each string to a key in format "2#1#0#...", where each number is the time of the character.
    vector<vector<string>> Method2(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> str_map;
        int len = strs.size();
        for (int i = 0; i < len; i++) {
            string key = generate_char_counting_key(strs[i]);
            str_map[key].push_back(strs[i]);
        }
        unordered_map<string, vector<string>>::iterator iter = str_map.begin();
        while (iter != str_map.end()) {
            result.push_back(iter->second);
            iter++;
        }
        return result;
    }
    
    string generate_char_counting_key(string str) {
        int len = str.size();
        string key = "";
        int char_count[26];
        memset(char_count, 0, sizeof(char_count));
        for (auto c : str) {
            char_count[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            key += to_string(char_count[i]) + "#";
        }
        return key;
    }

};