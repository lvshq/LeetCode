/*
Given a text file file.txt, print just the 10th line of the file.

Example:

Assume that file.txt has the following content:

Line 1
Line 2
Line 3
Line 4
Line 5
Line 6
Line 7
Line 8
Line 9
Line 10
Your script should output the tenth line, which is:

Line 10
Note:
1. If the file contains less than 10 lines, what should you output?
2. There's at least three different solutions. Try to explore all possibilities.
*/


# Read from the file file.txt and output the tenth line to stdout.

# Method 1: NR: 已读的记录数  FNR: 浏览文件的记录数
# awk 'NR == 10' file.txt
# awk 'FNR == 10' file.txt

# Method 2: set -n 10p: 10p means show 10th line. 5,10p means show 5-10th lines.
# sed -n 10p file.txt

# Method 3: tail -n +10 file.txt : show from 1000th line, namely show lines after 1000th line.
tail -n +10 file.txt | head -n 1