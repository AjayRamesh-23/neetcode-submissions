class Solution {
public:
    void getCombinations(vector<int>& candidates, int remaining, int start, vector<vector<int>>& result, vector<int>& path){
        if(remaining == 0){
            result.push_back(path);
            return;
        }
        if(remaining < 0){
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > remaining) break;

            path.push_back(candidates[i]);
            getCombinations(candidates, remaining - candidates[i], i + 1, result, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        getCombinations(candidates, target, 0,  result, path);
        return result;
        
    }
};

