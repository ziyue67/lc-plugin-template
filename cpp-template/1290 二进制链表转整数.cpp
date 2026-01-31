/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 * @lcpr version=30305
 *
 * [1290] 二进制链表转整数
 *
 * https://leetcode.cn/problems/convert-binary-number-in-a-linked-list-to-integer/description/
 *
 * algorithms
 * Easy (80.80%)
 * Likes:    207
 * Dislikes: 0
 * Total Accepted:    122.5K
 * Total Submissions: 151.6K
 * Testcase Example:  '[1,0,1]\n[0]'
 *
 * 给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。
 * 
 * 请你返回该链表所表示数字的 十进制值 。
 * 
 * 最高位 在链表的头部。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：head = [1,0,1]
 * 输出：5
 * 解释：二进制数 (101) 转化为十进制数 (5)
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [0]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表不为空。
 * 链表的结点总数不超过 30。
 * 每个结点的值不是 0 就是 1。
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result=0; // 二进制转十进制
        while(head){ // 遍历链表
            result=result*2+head->val; // 每次将结果乘2，再加上当前节点的值
            head=head->next;// 移动到下一个节点
        }
        return result; // 返回结果
    }
};
// @lc code=end

// 辅助函数：从vector创建链表
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for (int i = 1; i < vals.size(); i++) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

int main() {
    Solution solution;
    
    // 测试用例1: head = [1,0,1]
    ListNode* head1 = createList({1, 0, 1});
    cout << "测试用例1: " << solution.getDecimalValue(head1) << endl;
    
    // 测试用例2: head = [0]
    ListNode* head2 = createList({0});
    cout << "测试用例2: " << solution.getDecimalValue(head2) << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

