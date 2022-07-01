class MyCircularDeque {
public:
   vector<int> v; int len, front = -1, rear = -1;
    MyCircularDeque(int k) {
        v = vector<int>(k), len = k;
    }
    bool insertFront(int value) {
        if(front == -1 and rear == -1) {
            front = 0, rear = 0; 
            v[front] = value;
            return 1;
        }
        int insertidx = front -1; if(insertidx == -1) insertidx = len-1;
        if(insertidx == rear) return 0;
        v[insertidx] = value;
        front = insertidx;
        return 1;
    }
    bool insertLast(int value) {
        if((rear+1)%len == front) return 0;
        if(front == -1 and rear == -1) front = 0, rear = 0;
        else rear = (rear+1)%len;
        v[rear] = value;
        return 1;
    }
    bool deleteFront() {
        if(front == -1) return 0;
        if(front == rear) front = -1, rear = -1;
        else front = (front+1)%len;
        return 1;
    }
    bool deleteLast() {
        if(front == -1 and rear == -1) return 0;
        if(front == rear) front = -1, rear = -1;
        else {
            rear--; if(rear == -1) rear = len-1;
        }
        return 1;
    }
    int getFront() {
        if(front+1) return v[front];
        return -1;
    }
    int getRear() {
        if(rear + 1) return v[rear];
        return -1;
    }
    bool isEmpty() {
        return front == -1 and rear == -1;
    }
    bool isFull() {
        return ((rear+1)%len) == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */