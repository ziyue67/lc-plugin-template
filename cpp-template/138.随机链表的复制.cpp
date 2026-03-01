/*
 * @lc app=leetcode.cn id=138 lang=cpp
 * @lcpr version=30400
 *
 * [138] 随机链表的复制
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
using namespace std;

// Minimal Node definition (original common/Node.cpp may be missing in this environment)
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr; // 处理空链表
        for(Node *cur =head;cur !=nullptr ;cur=cur->next->next){ // 复制节点
            Node *copy=new Node(cur->val); // 创建新节点
            copy->next=cur->next; // 将新节点插入到原节点之后
            cur->next=copy; // 将原节点的next指针指向新节点
        }
        for(Node *cur =head;cur !=nullptr;cur=cur->next->next){ // 复制random指针
            if(cur->random !=nullptr){ // 如果原节点的random指针不为空
                cur->next->random=cur->random->next; // 将新节点的random指针指向原节点random指针指向的节点的下一个节点
            }
        }
        Node dummy(0); // 创建一个虚拟头节点
        Node *tail=&dummy; // 创建一个尾指针
        for(Node *cur=head;cur!=nullptr;cur=cur->next,tail=tail->next){ // 遍历原链表
            Node *copy=cur->next; // 创建一个新节点
            tail->next=copy; // 将新节点插入到尾节点之后
            cur->next=copy->next; // 将原节点的next指针指向新节点的下一个节点
        }
        return dummy.next; 
    }
};
// @lc code=end

int main() {
    // helpers
    auto buildFromVec = [](const vector<pair<int,int>>& a)->Node*{
        if (a.empty()) return nullptr;
        vector<Node*> nodes; nodes.reserve(a.size());
        for (auto &pr: a) nodes.push_back(new Node(pr.first));
        for (size_t i=0;i+1<nodes.size();++i) nodes[i]->next = nodes[i+1];
        for (size_t i=0;i<a.size();++i) {
            int ridx = a[i].second;
            nodes[i]->random = (ridx==-1? nullptr : nodes[ridx]);
        }
        return nodes[0];
    };

    auto printList = [](Node* head){
        vector<Node*> nodes;
        for (Node* p=head; p; p=p->next) nodes.push_back(p);
        cout<<"[";
        for (size_t i=0;i<nodes.size();++i){
            if (i) cout<<",";
            cout<<"["<<nodes[i]->val<<",";
            if (!nodes[i]->random) cout<<"null";
            else {
                size_t idx=0; bool found=false;
                for (; idx<nodes.size(); ++idx) if (nodes[idx]==nodes[i]->random){ found=true; break; }
                if (found) cout<<idx; else cout<<"null";
            }
            cout<<"]";
        }
        cout<<"]"<<endl;
    };

    Solution solution;

    // case 1: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* t1 = buildFromVec({{7,-1},{13,0},{11,4},{10,2},{1,0}});
    Node* r1 = solution.copyRandomList(t1);
    printList(r1);

    // case 2: [[1,1],[2,1]]
    Node* t2 = buildFromVec({{1,1},{2,1}});
    Node* r2 = solution.copyRandomList(t2);
    printList(r2);

    // case 3: [[3,null],[3,0],[3,null]]
    Node* t3 = buildFromVec({{3,-1},{3,0},{3,-1}});
    Node* r3 = solution.copyRandomList(t3);
    printList(r3);

    return 0;
}



/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

 */

