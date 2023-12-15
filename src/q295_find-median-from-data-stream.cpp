#include <queue>
#include <vector>

using std::vector;

// Two priority queues:
//  - A max-heap lo to store the smaller half of the numbers
//  - A min-heap hi to store the larger half of the numbers

// The max-heap lo is allowed to store, at worst, one more element more than the min-heap hi. Let k be the total number of elements, if k=2n+1, then lo is allow to store n+1 element, if k=2n, then both lo and hi store n elements. 

class MedianFinder {
public:
    std::priority_queue<int> lo;    //max heap
    std::priority_queue<int, vector<int>, std::greater<int>> hi; //min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo.push(num);
        int largest_in_lo = lo.top();
        hi.push(largest_in_lo);
        lo.pop();

        if (lo.size()<hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        if (lo.size()>hi.size()) {
            return lo.top();
        } else {
            return (lo.top()+hi.top()) * 0.5;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */