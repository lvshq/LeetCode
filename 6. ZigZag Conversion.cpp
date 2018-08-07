/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

/*
Time Complexity: O(n), where n == len(s)
Space Complexity: O(n)
*/
/*
    First construct a matrix, then scan row by row to generate the result.
    NOTE:
    (1) It could using dynamic array instead of a fixed char array, so that we don't need to calculate the column numbers.
    (2) Here I optimize the space by compress the multi-columns into one columns with the first and last column empty, which will reduce space complexity.
*/

class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        int char_num = s.length();
        if (numRows < 1 or char_num < 1)
            return result;
        if (numRows == 1)
            return s;
        int unit_char_num = numRows * 2 - 2;  // each unit is a full-char column (numRows) plus (numRows - 2) columns (char).
        // (char_num / unit_char_num) means how many unit there has, '2' is the number of columns each unit occupies.
        int col_num = char_num / unit_char_num * 2; 
        if ((char_num % unit_char_num) > 0)
            col_num += 2;
        // Allocation and initialize a 2-dimension array.
        // NOTE: memset() should only be applied on 1-dimension array.
        char **chars = new char* [numRows];
        for (int i = 0; i < numRows; i++) {
            chars[i] = new char[col_num];
            for (int j = 0; j < col_num; j++)
                chars[i][j] = 0;
        }
        int row = 0;
        int col = 0;
        int i = 0;
        while (i < char_num) {
            while (row < numRows && i < char_num)
                chars[row++][col] = s[i++];
            row -= 2; col++;
            while (row > 0 && col < col_num && i < char_num) {
                chars[row--][col] = s[i++];
            }
            col++;
        }
        for (int r = 0; r < numRows; r++)
            for (int c = 0; c < col_num; c++)
                if (chars[r][c] != 0) {
                    result += chars[r][c];
                }
        return result;
    }
};