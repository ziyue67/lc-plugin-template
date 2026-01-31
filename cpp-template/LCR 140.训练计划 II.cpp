/*
 * @lc app=leetcode.cn id=LCR 140 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 140] 训练计划 II
 *
 * https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/description/
 *
 * algorithms
 * Easy (79.22%)
 * Likes:    541
 * Dislikes: 0
 * Total Accepted:    536K
 * Total Submissions: 676.6K
 * Testcase Example:  '[2,4,7,8]\n1'
 *
 * 给定一个头节点为 head 的链表用于记录一系列核心肌群训练项目编号，请查找并返回倒数第 cnt 个训练项目编号。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [2,4,7,8], cnt = 1
 * 输出：8
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= head.length <= 100
 * 0 <= head[i] <= 100
 * 1 <= cnt <= head.length
 * 
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
    ListNode* trainingPlan(ListNode* head, int cnt) {
        ListNode *fast=head,*slow=head;//快慢指针
        for(int i=0;i<cnt;i++){ //快指针先走cnt步
            if(fast==nullptr)return nullptr; //如果cnt大于链表长度，则返回空
            fast=fast->next; //快指针先走cnt步
        }
        while(fast){ //快指针走到链表末尾，慢指针走到倒数第cnt个节点
            fast=fast->next;
            slow=slow->next;
        }
        return slow; //返回倒数第cnt个节点
        
        
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
    
    // 测试用例1: head = [2,4,7,8], cnt = 1
    ListNode* head1 = createList({2, 4, 7, 8});
    ListNode* res1 = solution.trainingPlan(head1, 1);
    cout << "测试用例1: " << (res1 ? res1->val : -1) << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [2,4,7,8]\n1\n
// @lcpr case=end

 */

