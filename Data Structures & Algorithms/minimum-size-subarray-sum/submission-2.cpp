class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        int runningSum = 0;
        int l = 0;
        int r = 0;
        for(int r = 0; r < nums.size(); r++){
            runningSum += nums[r];
            while(runningSum >= target){
                result = min(result, r - l + 1);
                runningSum -= nums[l];
                l++;
            }
        }
        return result == INT_MAX ? 0 : result;;
    }
};