#include <vector>

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        q.resize(k);
        cnt = 0;
        sz = k;
        headIdx = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q[(headIdx + cnt) % sz] = value;
        cnt += 1;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        headIdx = (headIdx + 1) % sz;
        cnt -= 1;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[headIdx];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[(headIdx + cnt - 1) % sz];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == sz;
    }
    
private:
    int cnt, sz, headIdx;
    vector<int> q;
};
