/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/


/*
    This problme's key point doesn't rely on how to store the stack. Stack/List/Array are all OK.
    The key is how to get the min element. With reference on [https://leetcode.com/problems/min-stack/discuss/49014/Java-accepted-solution-using-one-stack], I store [two elements] every time when [push] --
      one is the element, the other is the min element at that time.
    Thus each time [pop], we can get the min element by pop one more time.
*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_num = INT_MAX;
    }
    
    void push(int x) {
        my_stack.push(min_num);
        my_stack.push(x);
        if (x <= min_num)
            min_num = x;
    }
    
    void pop() {
        my_stack.pop();
        min_num = my_stack.top();
        my_stack.pop();
    }
    
    int top() {
        return my_stack.top();
    }
    
    int getMin() {
        return min_num;
    }

private:
    stack<int> my_stack;
    int min_num;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */