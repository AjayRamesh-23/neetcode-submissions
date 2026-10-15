class Solution {
public:
    void getCombinations(vector<int>& nums, int remaining, int start, vector<vector<int>>& result, vector<int>& path){
        if(remaining == 0){
            result.push_back(path);
            return;
        }
        if(remaining < 0){
            return;
        }
        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            getCombinations(nums, remaining - nums[i], i, result, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> path;
        getCombinations(nums, target, 0, result, path);
        return result;
    }
};
