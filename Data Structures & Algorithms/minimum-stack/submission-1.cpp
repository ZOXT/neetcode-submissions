class MinStack {
    stack<int> s1;
    stack<int> minStack;

   public:
    MinStack() {}

    void push(int val) {
        s1.push(val);
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            minStack.push(min(val, minStack.top()));
        }
    }

    void pop() {
        s1.pop();
        minStack.pop();
    }

    int top() { return s1.top(); }

    int getMin() { return minStack.top(); }
};
