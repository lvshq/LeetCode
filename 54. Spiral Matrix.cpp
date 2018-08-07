/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/


/*
    Same problme in 《算法竞赛入门经典》 程序3-3
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int rows = matrix.size();
        if (rows == 0)
            return result;
        int columns = matrix[0].size();
        // Allocation and initialize a 2-dimension array.
        // NOTE: memset() should only be applied on 1-dimension array.
        bool **visited = new bool* [rows];
        for (int i = 0; i < rows; i++) {
            visited[i] = new bool[columns];
            for (int j = 0; j < columns; j++) {
                visited[i][j] = false;
            }
        }
        int total_num = rows * columns;
        int row = 0, col = 0;
        while (total_num--) {
            // 1. Towards right.
            while (col < columns && !visited[row][col]) {
                visited[row][col] = true;
                result.push_back(matrix[row][col++]);
            }
            row++; col--;
            // 2. Towards down.
            while (row < rows && !visited[row][col]) {
                visited[row][col] = true;
                result.push_back(matrix[row++][col]);
            }
            row--; col--;
            // 3. Towards left.
            while (col >= 0 && !visited[row][col]) {
                visited[row][col] = true;
                result.push_back(matrix[row][col--]);
            }
            row--; col++;
            // 4. Towards up.
            while (row >= 0 && !visited[row][col]) {
                visited[row][col] = true;
                result.push_back(matrix[row--][col]);
            }
            row++; col++;
        }
        return result;
    }
};