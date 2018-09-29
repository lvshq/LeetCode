/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> meetings;
        for (auto i : intervals) {
            meetings[i.start]++;  // A meeting start means a room is needed/allocated
            meetings[i.end]--;  // A meeting end means a room is not needed/released
        }
        int max_room = 0, cur_room = 0;
        for (auto m : meetings) {
            cur_room += m.second;  // accumulated rooms
            max_room = max(max_room, cur_room);
        }
        return max_room;
    }
};
