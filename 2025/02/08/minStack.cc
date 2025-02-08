class MinStack {
private:
    vector<int> vec;
    vector<int> minStack;
public:
    MinStack() {}
    
    void push(int val) {
        vec.push_back(val);
        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        } else {
            minStack.push_back(minStack.back());
        }
    }
    
    void pop() {
        assert(!vec.empty());
        assert(!minStack.empty());
        minStack.pop_back();
        vec.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        assert(!minStack.empty());
        return minStack.back();
    }
};
