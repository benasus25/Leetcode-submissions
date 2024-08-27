class Solution {
public:
    vector<string> validStrings(int n) {
        queue<string> q;
        vector<string> v;
        if (n == 1) {
            return {"0", "1"};
        }
        q.push("0"); q.push("1");
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            if (s.length() == n) {
                v.push_back(s);
            }
            else {
                if (s.back() == '1') {
                    q.push(s + "0");
                    q.push(s + "1");
                }
                else {
                    q.push(s + "1");
                }
            }
        }
        return v;
    }
};