/*
 * @lc app=leetcode.cn id=LCR 123 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 123] 图书整理 I
 *
 * https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/description/
 *
 * algorithms
 * Easy (73.88%)
 * Likes:    493
 * Dislikes: 0
 * Total Accepted:    697.4K
 * Total Submissions: 944K
 * Testcase Example:  '[3,6,4,1]'
 *
 * 
 * 书店店员有一张链表形式的书单，每个节点代表一本书，节点中的值表示书的编号。为更方便整理书架，店员需要将书单倒过来排列，就可以从最后一本书开始整理，逐一将书放回到书架上。请倒序返回这个书单链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [3,6,4,1]
 * 
 * 输出：[1,4,6,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 0 <= 链表长度 <= 10000
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
    vector<int> reverseBookList(ListNode* head) {
        vector<int> result; // 结果数组
        while(head){ // 遍历链表
            result.push_back(head->val); // 将当前节点的值加入结果数组
            head=head->next; // 移动到下一个节点
        }
        reverse(result.begin(),result.end()); // 反转结果数组
        return result; // 返回反转后的结果数组
        
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

// 辅助函数：打印数组
void printArray(vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    // 测试用例1: head = [3,6,4,1]
    ListNode* head1 = createList({3, 6, 4, 1});
    vector<int> res1 = solution.reverseBookList(head1);
    cout << "测试用例1: ";
    printArray(res1);
    cout << endl;
    
    return 0;
}



/*
// @lcpr case=start
// [3,6,4,1]\n
// @lcpr case=end

 */

