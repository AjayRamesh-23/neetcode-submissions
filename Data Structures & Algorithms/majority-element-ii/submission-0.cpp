class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> hashMap;
        vector<int> result;
        for(auto& num : nums){
            if(hashMap.contains(num)){
                hashMap[num]++;
            }
            else{
                hashMap[num] == 1;
            }
        }
        for(auto& [k, v] : hashMap){
            cout<<k<<" "<<v<<endl;
            if(v >= n/3) result.push_back(k);
        }
        return result;
    }
};