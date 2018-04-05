// O(nlgn)
// O(1)
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() == 0) return res;
        // sort intervals by start
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start;});
        // put [0] into res
        res.push_back(intervals[0]);
        // for i=1 -> n-1
        for (int i = 1; i < intervals.size(); i++) {
            // if i overlaps with [i-1]
            if (intervals[i].start <= res.back().end) 
            // merge (change the end of [i-1])
                res.back().end = max(res.back().end, intervals[i].end);
            // else (not overlap)
            else
            // push back [i-1] to res
                res.push_back(intervals[i]);
        }
        return res;
    }
};