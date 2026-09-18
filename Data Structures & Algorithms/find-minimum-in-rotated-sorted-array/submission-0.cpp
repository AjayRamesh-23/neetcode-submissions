class Solution {
public:
    int findMin(vector<int> &nums) {
        int L = 0;
        int MIN = 0;
        int R = nums.size() - 1;
        int MID;
        while(L<R){
            if(nums[L] < nums[R]){
                return nums[L];
            }
            MID = (L + R)/2;
            if(nums[MID] > nums[R]){
                L = MID + 1;
            }
            else{
                R = MID;
            }
        }
        return nums[L];
        
    }
};
