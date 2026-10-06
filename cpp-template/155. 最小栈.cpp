/*
 * @lc app=leetcode.cn id=155 lang=cpp
 * @lcpr version=30404
 *
 * [155] 最小栈
 */

#include <iostream>
#include <vector>
#include <string>
#include "leetcode/editor/common/ListNode.cpp"
#include "leetcode/editor/common/TreeNode.cpp"
#include "stack"
using namespace std;

// @lc code=start
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int value) {
        s1.push(value);
        if(s2.empty() || value <=s2.top()){
            s2.push(value);
        }
    }
    
    void pop() {
        if(s1.top() ==s2.top()){
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
        
    }
    
    int getMin() {
        return s2.top();
        
    }
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main() {
    MinStack solution;
    // your test code here
}



/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */

