/*
    Area in [i, j] is limited by min(height[left], height[right]).
    So move the smaller bounder towards the middle to search for larger bounder.
	Time complexity : O(n). Single pass.
	Space complexity : O(1). Constant space is used.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int max_area = min(height[left], height[right]) * (right - left);
        while (right > left) {
            max_area = max(max_area, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])  // Limited by height[left], so keep right unchanged.
                left++;
            else
                right--;
        }
        return max_area;
    }
};