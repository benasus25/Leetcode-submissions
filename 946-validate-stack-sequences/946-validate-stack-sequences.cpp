class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int i=0,j=0;
        for(int m:pushed){
            pushed[i++]=m;
            while(i>0&&pushed[i-1]==popped[j]){
                j++;
                i--;
            }
        }
        return i==0;
    } 
};