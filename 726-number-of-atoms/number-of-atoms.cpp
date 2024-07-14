class Solution {
public:
    int solve(int i, string s, int n, map<string, int>& prev_map) {
        map<string, int> t;
        
        for (; i < n; i++) {
            if (s[i] == '(') {
                i = solve(i + 1, s, n, t);
            } else if (isupper(s[i])) {
                string temp;
                temp += s[i];
                i++;

                if (i < n && islower(s[i])) {
                    temp += s[i];
                    i++;
                }

                int count = 0, j;
                for (j = i; j < n; j++) {
                    if (isdigit(s[j])) {
                        count = count * 10 + (s[j] - '0');
                    } else {
                        break;
                    }
                }

                t[temp] += (count == 0) ? 1 : count;
                i = (count == 0) ? i - 1 : j - 1;
            } else if (s[i] == ')') {
                i++;
                int count = 0, j = i;
                
                if (i < n && isdigit(s[i])) {
                    for (j = i; j < n; j++) {
                        if (isdigit(s[j])) {
                            count = count * 10 + (s[j] - '0');
                        } else {
                            break;
                        }
                    }
                }
                
                if (count) {
                    for (auto& it : t) {
                        it.second *= count;
                    }
                    i = j - 1;
                }

                for (auto& it : t) {
                    prev_map[it.first] += it.second;
                }
                return i - 1;
            }
        }
        
        for (auto& it : t) {
            prev_map[it.first] += it.second;
        }
        return i;
    }

    string countOfAtoms(string formula) {
        int n = formula.size();
        map<string, int> m;
        solve(0, formula, n, m);
        
        string res;
        for (auto& it : m) {
            res += it.first;
            if (it.second != 1) {
                res += to_string(it.second);
            }
        }
        return res;
    }
};