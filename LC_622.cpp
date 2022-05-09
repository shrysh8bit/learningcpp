class MyCircularQueue {
public:

    int head = -1, tail = -1;
    int size;
    vector<int> que;

    int modPtr(int k){
        return k % size;
    }

    MyCircularQueue(int k) {
        que.resize(k);
        size = k;
    }

    bool enQueue(int value) {

        if (modPtr(tail + 1) == head) return false;

        if (head == -1) head = 0;
        tail = modPtr(tail + 1);
        que[tail] = value;
        return true;
    }

    bool deQueue() {
        if (head == -1) return false;

        if (head == tail){
            head = -1;
            tail = -1;
        }else{
            head = modPtr(head + 1);
        }

        return true;
    }

    int Front() {
        if (head == -1) return -1;
        return que.at(head);

    }

    int Rear() {
        if (tail == -1) return -1;
        return que[tail];

    }

    bool isEmpty() {
        if(head == -1 && tail == - 1){
            return true;
        }else{
            return false;
        }

    }

    bool isFull() {
        if (modPtr(tail + 1) == head){
            return true;
        }else{
            return false;
        }

    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
