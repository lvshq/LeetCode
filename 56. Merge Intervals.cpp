/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
*/

/*
    First sort the intervals: using self-defined function in sort().
    Then merge each interval one by one.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        int len = intervals.size();
        if (len < 2)
            return intervals;
        sort(intervals.begin(), intervals.end(), myLess);
        for (int i = 0; i < len - 1; i++) {
            if (canMerge(intervals[i], intervals[i + 1])) {
                intervals[i + 1] = merge(intervals[i], intervals[i + 1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        result.push_back(intervals[len - 1]);
        return result;
    }
    
    // Must use 'static' otherwise compiler will alert.
    // Use self-defined function to sort.
    bool myLess(const Interval &i1, const Interval &i2) {
        if (i1.start < i2.start || (i1.start == i2.start && i1.end < i2.end))
            return true;
        return false;
    }
    
    bool canMerge(Interval &i1, Interval &i2) {
        if (i1.end >= i2.start && i1.end <= i2.end || i2.end >= i1.start && i2.end <= i1.end)
            return true;
        return false;
    }
    
    Interval merge(Interval &i1, Interval &i2) {
        int new_start = min(i1.start, i2.start);
        int new_end = max(i1.end, i2.end);
        Interval new_interval(new_start, new_end);
        return new_interval;
    }
    
};