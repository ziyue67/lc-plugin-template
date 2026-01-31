/*
 * @lc app=leetcode.cn id=LCR 141 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 141] 训练计划 III
 *
 * https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/description/
 *
 * algorithms
 * Easy (74.19%)
 * Likes:    643
 * Dislikes: 0
 * Total Accepted:    621.8K
 * Total Submissions: 838.1K
 * Testcase Example:  '[1,2,3,4,5]\n[1,2]\n[]'
 *
 * 给定一个头节点为 head 的单链表用于记录一系列核心肌群训练编号，请将该系列训练编号 倒序 记录于链表并返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [1,2]
 * 输出：[2,1]
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 <= Node.val <= 5000
 * 
 * 
 * 
 * 
 * 注意：本题与主站 206 题相同：https://leetcode.cn/problems/reverse-linked-list/
 * 
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
    ListNode* trainningPlan(ListNode* head) {
        ListNode*cur=head,*pre=nullptr;
        while(cur !=nullptr){
            ListNode *temp=cur->next;//保存下一个节点
            cur->next=pre; //当前节点指向前一个节点
            pre=cur; //前一个节点指向当前节点
            cur=temp; //当前节点指向下一个节点

        }
        return pre;
        
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

// 辅助函数：打印链表
void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    // 测试用例1: head = [1,2,3,4,5]
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    ListNode* res1 = solution.trainningPlan(head1);
    cout << "测试用例1: ";
    printList(res1);
    cout << endl;
    
    // 测试用例2: head = [1,2]
    ListNode* head2 = createList({1, 2});
    ListNode* res2 = solution.trainningPlan(head2);
    cout << "测试用例2: ";
    printList(res2);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

