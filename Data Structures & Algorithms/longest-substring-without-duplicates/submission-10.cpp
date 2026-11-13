class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(s.size() == 0) return 0;
        int result = 0;
        vector<char> vec;
        int i = 0;

        while(i < n){
            int l = i;
            while(l < n && find(vec.begin(), vec.end(), s[l]) == vec.end()){
                vec.push_back(s[l]);
                l++;
                result = max(result, (int)vec.size());
            }
            vec.erase(vec.begin());
            i = l;
        }
        return result;
    }
};
