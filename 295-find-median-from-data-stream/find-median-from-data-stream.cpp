class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
    if(maxpq.empty()||num<=maxpq.top()) maxpq.push(num);
    else minpq.push(num);
    if(maxpq.size()>minpq.size()+1){
        int element=maxpq.top();
        maxpq.pop();
        minpq.push(element);
    }
     if(minpq.size()>maxpq.size()+1){
        int element=minpq.top();
        minpq.pop();
        maxpq.push(element);
    }   
    }
    
    double findMedian() {
        if(minpq.size()>maxpq.size()) return minpq.top();
        else if (maxpq.size()>minpq.size()) return maxpq.top();
        else return (minpq.top()+maxpq.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */