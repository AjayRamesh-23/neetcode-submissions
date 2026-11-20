class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return intervals;
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n; i++){
            if(result.empty() || result.back()[1] < intervals[i][0]){
                result.push_back(intervals[i]);
            }
            else{
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }
        return result;
    }
};

// [1,3],[1,5],[6,7]
// [1,2],[2,3]

// [1,4],[0,4]

// [1,4]

// [[1,3], [2,2], [2,2], [2,3], [3,3], [4,6], [5,7]]

// [[1,3], ]