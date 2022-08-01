class MyCalendar {
public:
    map<int,int>m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        auto event=m.lower_bound(start);
        
        if(event!=m.end()&&event->first<end)
            return 0;
        if(event!=m.begin()&&(--event)->second>start)
            return 0;
        m[start]=end;
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */