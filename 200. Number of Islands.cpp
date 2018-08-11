/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

/*
    Iterate the grid, and mark each position an island_number.
    A '1' position has the same island_number with its up, down, left, right positon,
      and continue this mark recursively.
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        if (rows == 0)
            return 0;
        columns = grid[0].size();
        // Initialize the island_number matrix;
        int* *a = new int* [rows];
        for (int i = 0; i < rows; i++) {
            a[i] = new int [columns];
            for (int j = 0; j < columns; j++) {
                a[i][j] = -1;
            }
        }
        int island_num = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == '1' && a[i][j] == -1) {
                    a[i][j] = island_num;
                    mark_island(grid, a, i, j, i+1, j);
                    mark_island(grid, a, i, j, i, j+1);
                    mark_island(grid, a, i, j, i-1, j);
                    mark_island(grid, a, i, j, i, j-1);
                    island_num++;
                }
            }
        return island_num;
    }
    
    // Mark each position an island number recursively.
    void mark_island(vector<vector<char>>& grid, int* *a, int i, int j, int row, int col) {
        // When write a long if and condition, put the one that is easiest to be false in front, this will shorten the judge time.
        if (!(grid[i][j] == '1' && a[i][j] != -1 && 0 <= row && row < rows && 0 <= col && col < columns
              && grid[row][col] == '1' && a[row][col] == -1 ))
            return;
        a[row][col] = a[i][j];
        mark_island(grid, a, row, col, row+1, col);
        mark_island(grid, a, row, col, row, col+1);
        mark_island(grid, a, row, col, row-1, col);
        mark_island(grid, a, row, col, row, col-1);
    }
private:
    int rows, columns;
};