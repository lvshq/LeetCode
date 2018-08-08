/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/*
    1. Pay attention to some details like the order of search and assitnment.
    2. Use Hashtable O(n) instead of O(n^2) brute-force search.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map is implemented using HashTable, faster than map which is RedBlack Tree.
        unordered_map<int, int> m;
        vector<int> result;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int complement = target - nums[i];
            if (m.count(complement) > 0 && m[complement] != i) {  // Find the solution
                result.push_back(m[complement]);
                result.push_back(i);
                break;
            }
            /* Pay attention that add the key to map should be later than search the value.
             Otherwise case like
                [3,3]
                6
             will return [], because the new {3:1} has overwrite the old {3:0}.
            */
            m[nums[i]] = i;
        }
        return result;
    }
};