class Solution {
public:
    string getCommonPrefix(string a, string b){
        int s1 = a.size();
        int s2 = b.size();
        int length = max(s1, s2);
        string prefix = "";
        for(int i = 0; i < length; i++){
            if(a[i] == b[i]){
                prefix += a[i];
            }
         
            else break;
        }
        return prefix;

    }
    string longestCommonPrefix(vector<string>& strs) {
        int N = strs.size();
        string prefix;
        if(strs.size() == 1) return strs[0];
        if(strs.size() >= 2) prefix = getCommonPrefix(strs[0], strs[1]);
        for(int i = 1; i < N - 1; i++){
            prefix = getCommonPrefix(prefix, strs[i+1]);
            if(prefix == "") return prefix;
        }
        return prefix;
    }
};