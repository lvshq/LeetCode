/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

/*
    This is an application of [Catalan number], the n-th Catalan number is 1/(n+1) * C(2n, n).
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> solution;
        DFS(solution, "", 0, 0, n);
        return solution;
    }

    void DFS(vector<string> &solution, string str, int left_paren, int right_paren, int n) {
        if (str.length() == n*2) {
            solution.push_back(str);
            return;
        }
        // left_paren must larger or equal than right_paren, otherwise paren won't match. 
        if (left_paren >= right_paren) {
            if (left_paren < n)
                DFS(solution, str + "(", left_paren + 1, right_paren, n);
            if (right_paren < n)
                DFS(solution, str + ")", left_paren, right_paren + 1, n);
        }
        
    }
};