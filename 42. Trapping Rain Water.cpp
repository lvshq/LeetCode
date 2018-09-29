/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/



/*
    A unit's water is limited by min(max_left, max_right) at this unit.
    Iterate from left to right to calculate each unit's max_lefts, and reversely calculate max_rights.
    In the second iteration, calculate the trapped water at the same time:
        min(max_lefts[i], max_rights[i]) - height[i]
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len == 0)
            return 0;
        vector<int> left_maxs(len);
        vector<int> right_maxs(len);
        int left_max, right_max;
        left_max = height[0];
        right_max = height[len - 1];
        for (int i = 0; i < len; i++) {
            if (height[i] > left_max)
                left_max = height[i];
            left_maxs[i] = left_max;
        }
        int trap_water_sum = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (height[i] > right_max)
                right_max = height[i];
            right_maxs[i] = right_max;
            trap_water_sum += min(left_maxs[i], right_maxs[i]) - height[i];
        }
        return trap_water_sum;
    }
};
