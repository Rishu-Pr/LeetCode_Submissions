class MyCalendar {
    vector<pair<int,int>> V;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto t : V){
            int st = t.first;
            int end = t.second;
            if (startTime < end && endTime > st) {
                return false;
            }
        }
        V.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */