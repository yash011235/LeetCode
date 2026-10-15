class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 1;
        int st = points[0][0];
        int end = points[0][1];
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] <= end){
                st = max(st, points[i][0]);
                end = min(end, points[i][1]);
            }
            else{
                st = points[i][0];
                end = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};