class MedianFinder {
public:
    priority_queue<int> smallHeap;//maxheap we will try to maintain all elements in maxHeap is <= to all elements of minHeap. 
    priority_queue<int,vector<int>,greater<int>> largeHeap; //minHeap always have elements greater or equal to maxHeap elements.
    int size = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);
        if((!largeHeap.empty() && smallHeap.top() > largeHeap.top()))
        {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        
        //Uneven Size 
        if(smallHeap.size()-largeHeap.size() == 2) 
        {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        
        if(largeHeap.size()-smallHeap.size() == 2) 
        {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
        
        size++;
    }
    
    double findMedian() {
        if((size%2) == 1) 
        {
            if(smallHeap.size() > largeHeap.size()) 
                return double(smallHeap.top());
            else 
                return double(largeHeap.top());
        }
        else 
        {
            return ((smallHeap.top()+largeHeap.top())/2.0); 
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */