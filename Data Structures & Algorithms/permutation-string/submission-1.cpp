using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        int charactersS1[26] = {};
        int charactersS2[26] = {};

        for(int i = 0; i< s1.size();i++){
            charactersS1[s1[i] - 'a']++;
        }

        int s1Size = s1.size();
        int s2Size = s2.size();
        int L = 0;

        for(int R = 0; R < s2Size; R++){
            charactersS2[s2[R]-'a']++;
            if(R - L + 1 == s1Size){
                if (equal(begin(charactersS1), end(charactersS1), begin(charactersS2), end(charactersS2))) {    
                    return true;
                }
                charactersS2[s2[L] - 'a']--;
                L++;
            }
        }
        return false;
    }
};
