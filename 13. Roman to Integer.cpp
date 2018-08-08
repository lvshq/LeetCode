/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: C = 100, L = 50, XXX = 30 and III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

/*
    For
        1. Check the special rule, which is 4* and 9*, add corresponding number.
        2. Check each character and add corresponding number.
    End
*/
class Solution {
public:
    int romanToInt(string s) {
        /*
        It is more gently to initialize a map using this way instead of:
        m[a] = 1; m[b] = 2; ... 
        */
        unordered_map<char, int> roman_map = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
        unordered_map<string, int> roman_49_rule;
        roman_49_rule["IV"] = 4;
        roman_49_rule["IX"] = 9;
        roman_49_rule["XL"] = 40;
        roman_49_rule["XC"] = 90;
        roman_49_rule["CD"] = 400;
        roman_49_rule["CM"] = 900;
        int len = s.size();
        int result = 0;
        for (int i = 0; i < len; i++) {
            // It is strange using ""+s[i]+s[i+1] won't work. So I temperally use this method.
            string str = "XX";
            if (i + 1 < len) {
                str[0] = s[i]; str[1] = s[i + 1];
            }
            if (roman_49_rule.count(str) > 0) {
                result += roman_49_rule[str];
                i++;
            } else {
                result += roman_map[s[i]];
            }
        }
        return result;
    }
};