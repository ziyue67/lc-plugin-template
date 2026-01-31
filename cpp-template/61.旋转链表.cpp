/*
 * @lc app=leetcode.cn id=61 lang=cpp
 * @lcpr version=30305
 *
 * [61] 旋转链表
 *
 * https://leetcode.cn/problems/rotate-list/description/
 *
 * algorithms
 * Medium (41.43%)
 * Likes:    1170
 * Dislikes: 0
 * Total Accepted:    490K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4,5]\n2\n[0,1,2]\n4'
 *
 * 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[4,5,1,2,3]
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [0,1,2], k = 4
 * 输出：[2,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 500] 内
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 10^9
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
    ListNode* rotateRight(ListNode* head, int k) {
        // 处理边界条件
        // if(head==nullptr || k==0)return head;
        // ListNode *tail=head;
        // int n=1; // 至少有一个节点
        // for(ListNode *p=head;p->next!=nullptr;p=p->next){
        //     tail = p->next; // 找到链表尾
        //     n++;
        // }
        // k=k%n; // 处理k大于链表长度的情况
        // if(k==0) return head; // 旋转后链表不变
        // // 找到倒数第k+1个节点（新的尾节点）
        // ListNode *p=head;
        // for(int i=0;i<n-k-1;i++)p=p->next;
        // // 重新连接链表
        // ListNode *newHead=p->next;
        // tail->next = head;
        // p->next = nullptr;
        // return newHead;
        ListNode *p = head;
        ListNode *q=head;
        int n=0;
        if(head==nullptr || k==0)return head;
        //O(n)时间复杂度
        for(ListNode *temp=head;temp!=nullptr;temp=temp->next){  //找到链表长度
            n++;
        }
        k=k%n;
        if(k==0) return head; // k是n的倍数时不需要旋转
        // 快慢指针法：先让p移动k步
        for(int i=0;i<k;i++){ //先让p移动k步
            p=p->next;
        }
        // 然后p和q同时移动，直到p到达最后一个节点
        while (p->next!=nullptr) //找到倒数第k+1个节点
        {
            p=p->next;
            q=q->next;
        }
        ListNode *newHead = q->next; // 新的头节点
        p->next=head;//连接
        q->next=nullptr;//断开
        return newHead;
        // O(1)空间复杂度 O(n)时间复杂度
        // 在选择遍历链表时候 找到倒数第k+1节点 然后在从这个节点设置为头节点(2) 与 从末尾链接到头节点 (1) 然后在断开节点这样就返回了(3)  头节点
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
    
    // 测试用例1: head = [1,2,3,4,5], k = 2
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    ListNode* res1 = solution.rotateRight(head1, 2);
    cout << "测试用例1: ";
    printList(res1);
    cout << endl;
    
    // 测试用例2: head = [0,1,2], k = 4
    ListNode* head2 = createList({0, 1, 2});
    ListNode* res2 = solution.rotateRight(head2, 4);
    cout << "测试用例2: ";
    printList(res2);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2]\n4\n
// @lcpr case=end

 */

