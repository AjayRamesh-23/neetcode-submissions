class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int idx = 0;
        int result = 0;

        int N = operations.size();
        for(int i = 0; i < N; i++){
            if(operations[i] == "C"){
                st.pop();
            }
            else if(operations[i] == "D"){
                int element = st.top();
                st.push(2*element);
            }
            else if(operations[i] == "+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.push(first);
                
                st.push(first + second);
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        while(!st.empty()){
            int element = st.top();
            result += element;
            st.pop();
        }
        return result;
        
    }
};