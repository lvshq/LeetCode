/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

Example 1:

Input: 123
Output: "One Hundred Twenty Three"
Example 2:

Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Example 4:

Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
*/



/*
    Divide into parts which are less than one thousand, and cal hundred num, tens num and ones.
    When tens num is [10, 19], convert tens and ones to string together.
*/

class Solution {
public:
    string numberToWords(int num) {
        if (!num)
            return "Zero";
        int billion = 0, million = 0, thousand = 0, last = 0;
        string billion_str, million_str, thousand_str, last_str;
        const int BILLION = 1000000000;
        const int MILLION = 1000000;
        const int THOUSAND = 1000;
        if (num / BILLION) {
            billion = num / BILLION;
            num %= BILLION;
        }
        if (num / MILLION) {
            million = num / MILLION;
            num %= MILLION;
        }
        if (num / THOUSAND) {
            thousand = num / THOUSAND;
            num %= THOUSAND;
        }
        if (num) {
            last = num;
        }
        if (billion)
            billion_str = int_to_str(billion) + " Billion ";
        if (million)
            million_str = int_to_str(million) + " Million ";
        if (thousand)
            thousand_str = int_to_str(thousand) + " Thousand ";
        if (last)
            last_str = int_to_str(last);
        string words = billion_str + million_str + thousand_str + last_str;
        int words_len = words.size();
        int i;
        string result = "";
        // Eliminate duplicate spaces and final space.
        for (i = 0; i < words_len - 1; i++) {
            if (words[i] == ' ' && words[i + 1] == ' ') {
                i++;
            }
            result += words[i];
        }
        if (words[i] != ' ')
            result += words[i];
        return result;
    }
    string int_to_str(int num) {
        int hundred = 0, ten = 0, one = 0;
        string hundred_str, ten_str, one_str;
        if (num / 100) {
            hundred = num / 100;
            num %= 100;
        }
        if (num / 10) {
            ten = num / 10;
            if (ten == 1) {  // should use tens and ones together
                // ten_str = ten_to_string(num);
                one = num;
            }
            num %= 10;
        }
        if (ten != 1) {
            one = num;
        } else {
            ten = 0;
        }
        if (hundred)
            hundred_str = num_to_string[hundred] + " Hundred ";
        if (ten)
            ten_str = tens_to_string[ten] + " ";
        if (one)
            one_str = num_to_string[one];
        string str = hundred_str + ten_str + one_str;
        return str;
    }
private:
    map<int, string> num_to_string = {{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
                                      {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"},
                                      {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
                                      {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"},
                                      {19, "Nineteen"}};
    map<int, string> tens_to_string = {{2, "Twenty"},
                                      {3, "Thirty"},
                                      {4, "Forty"},
                                      {5, "Fifty"},
                                      {6, "Sixty"},
                                      {7, "Seventy"},
                                      {8, "Eighty"},
                                      {9, "Ninety"}};
};