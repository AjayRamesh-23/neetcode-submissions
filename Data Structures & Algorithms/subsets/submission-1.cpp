class Solution {
public:
    void getSubset(int idx, int n, vector<int>& nums, vector<int>& subset, vector<vector<int>> &subsets){
        if(idx == n){
            subsets.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]);
        getSubset(idx+1, n, nums, subset, subsets);
        subset.pop_back();
        getSubset(idx+1, n, nums, subset, subsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        int n = nums.size();
        getSubset(0, n, nums, subset, subsets);
        return subsets;
    }
};
