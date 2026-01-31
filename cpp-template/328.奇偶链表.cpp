/*
 * @lc app=leetcode.cn id=328 lang=cpp
 * @lcpr version=30305
 *
 * [328] 奇偶链表
 *
 * https://leetcode.cn/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (64.54%)
 * Likes:    858
 * Dislikes: 0
 * Total Accepted:    276.7K
 * Total Submissions: 428.7K
 * Testcase Example:  '[1,2,3,4,5]\n[2,1,3,5,6,4,7]'
 *
 * 给定单链表的头节点 head
 * ，将所有索引为奇数的节点和索引为偶数的节点分别分组，保持它们原有的相对顺序，然后把偶数索引节点分组连接到奇数索引节点分组之后，返回重新排序的链表。
 *
 * 第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。
 *
 * 请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。
 *
 * 你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 * 输入: head = [1,2,3,4,5]
 * 输出: [1,3,5,2,4]
 *
 * 示例 2:
 *
 *
 *
 * 输入: head = [2,1,3,5,6,4,7]
 * 输出: [2,3,6,7,1,5,4]
 *
 *
 *
 * 提示:
 *
 *
 * n ==  链表中的节点数
 * 0 <= n <= 10^4
 * -10^6 <= Node.val <= 10^6
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
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *oddHead = new ListNode(0);//虚拟头节点
        ListNode *evenHead = new ListNode(0);//
        ListNode *oddCur = oddHead;  // 当前奇数节点指针
        ListNode *evenCur = evenHead; // 当前偶数节点指针
        ListNode *cur=head; // 当前节点指针
        int index=1; // 当前节点索引  
        while(cur){ 
            if(index%2==1){ // 奇数节点
                oddCur->next = cur;//找到奇数节点
                oddCur = oddCur->next; // 找到下个节点
            }
            else
            {
                evenCur->next=cur; // 找到偶数节点 
                evenCur=evenCur->next; // 找到下个节点
            }
            cur=cur->next; // 找到下个节点
            index++; // 当前节点索引
        }
        oddCur->next=evenHead->next; // 连接奇数链表和偶数链表
        evenCur->next=nullptr; // 终止偶数链表
        return oddHead->next; 

        
        
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

int main()
{
    Solution solution;
    
    // 测试用例1: head = [1,2,3,4,5]
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    ListNode* res1 = solution.oddEvenList(head1);
    cout << "测试用例1: ";
    printList(res1);
    cout << endl;
    
    // 测试用例2: head = [2,1,3,5,6,4,7]
    ListNode* head2 = createList({2, 1, 3, 5, 6, 4, 7});
    ListNode* res2 = solution.oddEvenList(head2);
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
// [2,1,3,5,6,4,7]\n
// @lcpr case=end

 */
