/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=30305
 *
 * [86] 分隔链表
 *
 * https://leetcode.cn/problems/partition-list/description/
 *
 * algorithms
 * Medium (65.83%)
 * Likes:    955
 * Dislikes: 0
 * Total Accepted:    383.2K
 * Total Submissions: 582.1K
 * Testcase Example:  '[1,4,3,2,5,2]\n3\n[2,1]\n2'
 *
 * 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
 * 
 * 你应当 保留 两个分区中每个节点的初始相对位置。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [1,4,3,2,5,2], x = 3
 * 输出：[1,2,2,4,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [2,1], x = 2
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 200] 内
 * -100 <= Node.val <= 100
 * -200 <= x <= 200
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *smallDummy=new ListNode(0),*largHead=new ListNode(0); //创建两个虚拟头节点
        ListNode *sml = smallDummy, *big = largHead; //分别指向两个链表的当前节点
        while(head){ //遍历原链表
            if(head->val<x){ //小于x的节点接到小链表后面
                sml->next=head; //接到小链表后面
                sml=sml->next; //指针后移
            }
            else
            {
                big->next=head; //接到大链表后面
                big=big->next; //指针后移
            }   
            head=head->next;//指针后移

        }
        sml->next=largHead->next; //连接两个链表
        big->next=nullptr; //防止链表成环
        return smallDummy->next;

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
    
    // 测试用例1: head = [1,4,3,2,5,2], x = 3
    ListNode* head1 = createList({1, 4, 3, 2, 5, 2});
    ListNode* res1 = solution.partition(head1, 3);
    cout << "测试用例1: ";
    printList(res1);
    cout << endl;
    
    // 测试用例2: head = [2,1], x = 2
    ListNode* head2 = createList({2, 1});
    ListNode* res2 = solution.partition(head2, 2);
    cout << "测试用例2: ";
    printList(res2);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */

