/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * @lcpr version=30404
 *
 * [232] 用栈实现队列
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <stack>
using namespace std;

// @lc code=start
class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x) //O(1)
    {
        s1.push(x);
    }

    int pop()//O(n)
    {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push((s1.top()));
                s1.pop();
            }
        }
        int res =s2.top();
        s2.pop();
        return res;
    }

    int peek() //O(n)
    {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push((s1.top()));
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() //O(1)
    {
        return s1.empty() && s2.empty();
    }

    stack<int> s1;
    stack<int> s2;
//push：O(1)
//pop：最坏 O(n)，均摊 O(1)
//peek：最坏 O(n)，均摊 O(1)
//empty：O(1)
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main()
{
    MyQueue solution;
    solution.push(1);
    solution.push(2);
    std::cout << solution.peek() << std::endl; // 返回 1
    std::cout << solution.pop() << std::endl;  // 返回 1
    std::cout << solution.empty() << std::endl; // 返回 false
    
    // your test code here
}

/*
// @lcpr case=start
// ["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]\n
// @lcpr case=end

 */
