class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int st = intervals[0][0];
        int end = intervals[0][1];
        int n = intervals.size();
        for(int i = 1; i < n; i++){
            if(intervals[i][0] > end){
                ans.push_back({st, end});
                st = intervals[i][0];
                end = intervals[i][1];
            }
            else{
                st = min(st, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        ans.push_back({st, end});
        return ans;
    }
};