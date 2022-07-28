class MedianFinder {
private:
    priority_queue<int>low;
    priority_queue<int,vector<int>,greater<int>>high;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(!low.size()||num<low.top())low.push(num);
        else high.push(num);
        if(high.size()>low.size()){
            low.push(high.top());
            high.pop();
        }
        if(low.size()>high.size()+1){
            high.push(low.top());
            low.pop();
        }
    }
    
    double findMedian() {
        if(low.size()>high.size())return double(low.top());
        return double(low.top()+high.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */