class Solution {
public:
    int getSolution(vector<int> &nums, int start, int end){
        vector<int> dp(end - start);
        dp[0] = nums[start];
        for(int i = start + 1; i < end; i++){
            int idx = i - start;

            int pick = nums[i];
            if (idx >= 2) {
                pick += dp[idx - 2];
            }

            int notPick = dp[idx - 1];

            dp[idx] = max(pick, notPick);
        }
        return dp[end - start - 1]; 

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int max1 = getSolution(nums, 0, n-1);
        int max2 = getSolution(nums, 1, n);
        return max(max1, max2);
    }
};

