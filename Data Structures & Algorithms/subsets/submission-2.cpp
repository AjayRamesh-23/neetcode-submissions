class Solution {
public:
    void getSubset(int start, vector<int>& nums, vector<int>& subset, vector<vector<int>> &subsets){
        subsets.push_back(subset);
        for(int i = start; i < nums.size(); i++){
            subset.push_back(nums[i]);
            getSubset(i + 1, nums, subset, subsets);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        getSubset(0, nums, subset, subsets);
        return subsets;
    }
};

