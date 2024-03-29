class MyCalendar {
set<pair<int,int>>s;
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        auto it = s.upper_bound({start,start});
        if(it!=s.end() and (*it).second<end)return false;
        s.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */