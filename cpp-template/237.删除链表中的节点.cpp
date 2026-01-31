/*
 * @lc app=leetcode.cn id=237 lang=cpp
 * @lcpr version=30305
 *
 * [237] 删除链表中的节点
 *
 * https://leetcode.cn/problems/delete-node-in-a-linked-list/description/
 *
 * algorithms
 * Medium (86.93%)
 * Likes:    1423
 * Dislikes: 0
 * Total Accepted:    416.3K
 * Total Submissions: 478.9K
 * Testcase Example:  '[4,5,1,9]\n5\n[4,5,1,9]\n1'
 *
 * 有一个单链表的 head，我们想删除它其中的一个节点 node。
 * 
 * 给你一个需要删除的节点 node 。你将 无法访问 第一个节点  head。
 * 
 * 链表的所有值都是 唯一的，并且保证给定的节点 node 不是链表中的最后一个节点。
 * 
 * 删除给定的节点。注意，删除节点并不是指从内存中删除它。这里的意思是：
 * 
 * 
 * 给定节点的值不应该存在于链表中。
 * 链表中的节点数应该减少 1。
 * node 前面的所有值顺序相同。
 * node 后面的所有值顺序相同。
 * 
 * 
 * 自定义测试：
 * 
 * 
 * 对于输入，你应该提供整个链表 head 和要给出的节点 node。node 不应该是链表的最后一个节点，而应该是链表中的一个实际节点。
 * 我们将构建链表，并将节点传递给你的函数。
 * 输出将是调用你函数后的整个链表。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [4,5,1,9], node = 5
 * 输出：[4,1,9]
 * 解释：指定链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [4,5,1,9], node = 1
 * 输出：[4,5,9]
 * 解释：指定链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围是 [2, 1000]
 * -1000 <= Node.val <= 1000
 * 链表中每个节点的值都是 唯一 的
 * 需要删除的节点 node 是 链表中的节点 ，且 不是末尾节点
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;  // 将当前节点的值替换为下一个节点的值
        node->next=node->next->next;  // 将当前节点的 next 指针指向下下个节点
        
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

// 辅助函数：找到值为val的节点
ListNode* findNode(ListNode* head, int val) {
    while (head) {
        if (head->val == val) return head;
        head = head->next;
    }
    return nullptr;
}

int main() {
    Solution solution;
    
    // 测试用例1: head = [4,5,1,9], node = 5
    ListNode* head1 = createList({4, 5, 1, 9});
    ListNode* node1 = findNode(head1, 5);
    solution.deleteNode(node1);
    cout << "测试用例1: ";
    printList(head1);
    cout << endl;
    
    // 测试用例2: head = [4,5,1,9], node = 1
    ListNode* head2 = createList({4, 5, 1, 9});
    ListNode* node2 = findNode(head2, 1);
    solution.deleteNode(node2);
    cout << "测试用例2: ";
    printList(head2);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [4,5,1,9]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,5,1,9]\n1\n
// @lcpr case=end

 */

