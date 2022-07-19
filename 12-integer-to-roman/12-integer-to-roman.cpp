const vector<pair<int,string>>sol = {{1000, "M"},
                                            {900, "CM"},
                                            {500, "D"},
                                            {400, "CD"},
                                            {100, "C"},
                                            {90, "XC"},
                                            {50, "L"},
                                            {40, "XL"},
                                            {10, "X"},
                                            {9, "IX"},
                                            {5, "V"},
                                            {4, "IV"},
                                            {1, "I"}};

class Solution {
public:
    string intToRoman(int num) {
        string ans ="";
        int i =0;
        while(num){
            while(num>=sol[i].first){
                num -= sol[i].first;
                ans += sol[i].second;
            }
            i++;
        }
        return ans;
    }
};