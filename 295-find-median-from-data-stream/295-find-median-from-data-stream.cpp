class MedianFinder {
public:
    
    priority_queue<int> l;
    priority_queue<int,vector<int>,greater<int>> r;
    
    MedianFinder() {
        l=priority_queue<int>();
        r=priority_queue<int,vector<int>,greater<int>>();
    }
    
    void addNum(int num) {
        if(l.empty()&&r.empty())
        {
            l.push(num);
        }
        else if(l.size()==r.size())
        {
            if(l.top()<num)r.push(num);
            else l.push(num);
            
        }
        else if(l.size()>r.size())
        {
            if(l.top()<=num)
            {
                r.push(num);
            }
            else{
                int temp=l.top();l.pop();
                l.push(num);
                r.push(temp);
            }
        }
        else{
            if(r.top()>num)
            {
                l.push(num);
            }
            else
            {
                int temp=r.top();r.pop();
                l.push(temp);
                r.push(num);
            }
        }
    }
    
    double findMedian() {
        if(l.size()==r.size()) return ((double)(l.top())+(double)(r.top()))/2.0;
        else if(l.size()>r.size())return l.top();
        else return r.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */