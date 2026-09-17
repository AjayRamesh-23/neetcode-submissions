class Solution {
public:
    int characterReplacement(string s, int k) {
        int R = 0;
        int maxFreq = 0;
        int characters[26] = {};
        int ans = 0;
        int index;
        int L = 0;
        int N = s.size();

        for(int R = 0; R < N; R++){
            characters[s[R] - 'A']++;
            index = s[R] - 'A';
            maxFreq = max(maxFreq, characters[index]);

            while((R- L+ 1) - maxFreq > k){
                characters[s[L] - 'A']--;
                L++;
            }
            ans = max(ans, R-L+1);

        }
        return ans;
        
    }
};
