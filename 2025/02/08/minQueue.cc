#include <deque>
#include <queue>
using namespace std;

class MinQueue {
private:
    queue<int> q;           // 正常的队列
    deque<int> minDeque;    // 维护最小值的单调队列, 升序

public:
    void push(int x) {
        q.push(x);
        while (!minDeque.empty() && minDeque.back() > x) {
            minDeque.pop_back();
        }
        minDeque.push_back(x);
    }

    void pop() {
        if (q.front() == minDeque.front()) {
            minDeque.pop_front();
        }
        q.pop();
    }

    int getMin() {
        return minDeque.front();
    }

    int front() {
        return q.front();
    }
};

int main() {
   MinQueue mq;
   mq.push(1);
   mq.push(2);
   mq.push(1);
   mq.push(3);
   mq.push(0);
   mq.push(1);

   return 0;
}
