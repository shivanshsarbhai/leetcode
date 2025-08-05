class MedianFinder {
public:
    priority_queue<int>low;    //maxheap
    priority_queue<int,vector<int>, greater<int>>high;  //minheap;
    MedianFinder() {
        while(!low.empty())
            low.pop();
        
        while(!high.empty())
            high.pop();
    }
    
    void addNum(int num) {
        
        //add number to low;
        low.push(num);

        //rebalance
        if(low.size() > high.size()+1){
            int temp = low.top();
            low.pop();
            high.push(temp);
        }

        //make consistent
        if(!high.empty() && low.top() > high.top()){
            int lowEle = low.top();
            int highEle = high.top();

            low.pop();
            high.pop();

            low.push(highEle);
            high.push(lowEle);
        }
    }
    
    double findMedian() {
        double ans = 0.0;
        int n1 = low.size();
        int n2 = high.size();
        if(n1!=0 && n2!=0 && (n1+n2)%2==0)
            return (low.top() + high.top())/2.0;
        
        else
            return (low.top()/1.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */