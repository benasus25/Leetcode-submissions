class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        for(int i = 0;i<operations.size(); i++) {
            if(operations[i].contains('-')){
                val--;
            }
            else if (operations[i].contains('+')) {
                val++;
            }
        }
        return val;
    }
};