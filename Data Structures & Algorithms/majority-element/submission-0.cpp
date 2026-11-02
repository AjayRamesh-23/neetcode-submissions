class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            if(hashMap.count(nums[i])){
                hashMap[nums[i]]++;
            }
            else{
                hashMap[nums[i]] = 1;
            }
        }
        int element = -1;
        int maximum = 0;

        for(auto it : hashMap) {
            if(it.second > maximum) {
                maximum = it.second;
                element = it.first;
            }
        }

        return element;
        
    }
};