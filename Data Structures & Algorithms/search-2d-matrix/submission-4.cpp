class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto it: matrix){
            int L = 0;
            int R = it.size() - 1;
            while(L <= R){
                int MID = (L + R)/2;
                if(it[MID] == target){
                    return true;
                }
                else if(target > it[MID]){
                    L = MID + 1;
                }
                else{
                    R = MID - 1;
                }
            }
        }
        return false;
    }
};
