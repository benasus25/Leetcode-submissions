class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="+"){
                int num = st.top();
                st.pop();
                int num2 = st.top();
                st.push(num);
                st.push(num+num2);
            }
            else if(ops[i]=="C")st.pop();
            else if(ops[i]=="D"){
                st.push(st.top()*2);
            }
            else{
                st.push(stoi(ops[i]));
            }
        }
        int res =0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};