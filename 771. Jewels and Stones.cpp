/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*/

/*
    Use HashTable to fasten search process.
*/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        int len_s = S.length();
        int len_j = J.length();
        for (int i = 0; i < len_j; i++) {
            jewels.insert(J[i]);
        }
        int jewel_num = 0;
        for (int i = 0; i < len_s; i++) {
            if (jewels.count(S[i]) > 0) {
                jewel_num++;
            }
        }
        return jewel_num;
    }
};