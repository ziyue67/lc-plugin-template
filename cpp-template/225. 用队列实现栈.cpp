/*
 * @lc app=leetcode.cn id=225 lang=cpp
 * @lcpr version=30404
 *
 * [225] 用队列实现栈
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <queue>
using namespace std;

// @lc code=start
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {  
        q1.push(x);
    }
    
    int pop() {   
        while(q1.size()>1){ 
            q2.push(q1.front());
            q1.pop();
        }
        int res=q1.front();
        q1.pop();
        swap(q1,q2);
        return res;
        
        
    }
    
    int top() {   
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int res=q1.front();
        q2.push(res);
        q1.pop();
        swap(q1,q2);
        return res;
        
    }
    
    bool empty() {   
        return q1.empty();
        
    }
    queue<int> q1;
    queue<int> q2;
// push：O(1)
// pop：O(n)
// top：O(n)
// empty：O(1)
// 空间：O(n)
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main() {
    MyStack solution;
    // your test code here
}



/*
// @lcpr case=start
// ["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]\n
// @lcpr case=end

 */

