/*
 * @lc app=leetcode.cn id=705 lang=cpp
 * @lcpr version=30305
 *
 * [705] 设计哈希集合
 *
 * https://leetcode.cn/problems/design-hashset/description/
 *
 * algorithms
 * Easy (65.05%)
 * Likes:    372
 * Dislikes: 0
 * Total Accepted:    141.9K
 * Total Submissions: 218.1K
 * Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n' +
  '[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
 *
 * 不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
 * 
 * 实现 MyHashSet 类：
 * 
 * 
 * void add(key) 向哈希集合中插入值 key 。
 * bool contains(key) 返回哈希集合中是否存在这个值 key 。
 * void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：
 * ["MyHashSet", "add", "add", "contains", "contains", "add", "contains",
 * "remove", "contains"]
 * [[], [1], [2], [1], [3], [2], [2], [2], [2]]
 * 输出：
 * [null, null, null, true, false, null, true, null, false]
 * 
 * 解释：
 * MyHashSet myHashSet = new MyHashSet();
 * myHashSet.add(1);      // set = [1]
 * myHashSet.add(2);      // set = [1, 2]
 * myHashSet.contains(1); // 返回 True
 * myHashSet.contains(3); // 返回 False ，（未找到）
 * myHashSet.add(2);      // set = [1, 2]
 * myHashSet.contains(2); // 返回 True
 * myHashSet.remove(2);   // set = [1]
 * myHashSet.contains(2); // 返回 False ，（已移除）
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= key <= 10^6
 * 最多调用 10^4 次 add、remove 和 contains
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class MyHashSet {
public:
    bool data[1000001];  // 使用布尔数组存储键的存在状态，索引即为键值
    MyHashSet() {
        memset(data, false, sizeof(data));  // 初始化数组为false，表示所有键都不存在
    }
     
    void add(int key) {
        data[key] = true;  // 将指定键标记为存在
    }
    
    void remove(int key) {
        data[key] = false;  // 将指定键标记为不存在
    }
    
    bool contains(int key) {
        return data[key];  // 返回指定键是否存在
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

int main() {
    MyHashSet myHashSet;
    cout << boolalpha;
    
    myHashSet.add(1);
    myHashSet.add(2);
    cout << "contains(1): " << myHashSet.contains(1) << endl;
    cout << "contains(3): " << myHashSet.contains(3) << endl;
    myHashSet.add(2);
    cout << "contains(2): " << myHashSet.contains(2) << endl;
    myHashSet.remove(2);
    cout << "contains(2): " << myHashSet.contains(2) << endl;
    
    return 0;
}



/*
// @lcpr case=start
// ["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n[[],[1],[2],[1],[3],[2],[2],[2],[2]]\n
// @lcpr case=end

 */

