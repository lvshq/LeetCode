/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

/*
    A DP problem.
    sum[row][col] = min(sum[row-1][col], sum[row][col-1]) + grid[row][col];

    Time Complexity: O(m*2)
    Space Complexity: O(m*n)
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0)
            return 0;
        int columns = grid[0].size();
        int **sum = new int* [rows];
        for (int i = 0; i < rows; i++) {
            sum[i] = new int [columns];
        }
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < columns; col++) {
                if (row == 0 && col == 0) {
                    sum[row][col] = grid[row][col];
                } else if (row == 0 && col >= 1) {
                    sum[0][col] = grid[0][col] + sum[0][col-1];
                } else if (row >= 1 && col == 0) {
                    sum[row][0] = grid[row][0] + sum[row-1][0];
                } else {
                    sum[row][col] = min(sum[row-1][col], sum[row][col-1]) + grid[row][col];
                }
                
            }
        }
        return sum[rows - 1][columns - 1];
    }
};