class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> result(n, 0);
        for(int i = 0; i < n; i++){
            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){
                int idx = stk.top();
                stk.pop();
                result[idx] = i - idx;
            }  
            stk.push(i); 
        }
        return result;
    }
};
