class Solution {
public:
    void getPermutations(vector<int>& nums,
                        vector<vector<int>>& permutations,
                        vector<int>& permutation,
                        vector<bool>& used){
        if(permutation.size() == nums.size()){
            permutations.push_back(permutation);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            permutation.push_back(nums[i]);
            used[i] = true;
            getPermutations(nums, permutations, permutation, used);
            permutation.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> permutation;
        vector<bool> used(nums.size(), false);
        getPermutations(nums, permutations, permutation, used);
        return permutations;
    }
};
