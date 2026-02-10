/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=30307
 *
 * [146] LRU 缓存
 */
#include <unordered_map>
#include <list>
#include <utility>
using namespace std;
// @lc code=start

// LRUCache 实现说明（中文注释）
// - 使用一个双向链表 `cache_list` 保存键值对，链表头部为最近使用的元素，尾部为最久未使用的元素。
// - 使用一个哈希表 `key_to_iter` 将 key 映射到链表中的迭代器，以便在 O(1) 时间内定位并移动节点。
// - 通过 list::splice 将被访问或更新的节点移动到链表头部，保持最近使用顺序。
// - 当缓存大小超过容量时，从链表尾部删除最久未使用的元素，并从哈希表中移除对应的 key。

class LRUCache
{
private:
    int capacity; // 缓存容量上限
    // 链表保存 <key, value> 对，链表头是最近使用的元素
    list<pair<int, int>> cache_list;
    // 哈希表保存 key -> 链表节点迭代器 的映射
    unordered_map<int, list<pair<int, int>>::iterator> key_to_iter; 
public:
    // 构造函数：指定容量
    LRUCache(int capacity):capacity(capacity)
    {
    }

    // 获取 key 对应的值。如果不存在，返回 -1。
    // 如果存在，则将该节点移动到链表头部（表示最近使用）。
    int get(int key)
    {
        auto umap_it = key_to_iter.find(key);// 查找key
        if (umap_it == key_to_iter.end()) // 未找到
            return -1; // 未命中

        // 将找到的节点移动到链表头部
        auto list_iter = umap_it->second; // 获取节点迭代器
        cache_list.splice(cache_list.begin(), cache_list, list_iter); // 将节点移动到链表头部
        return list_iter->second; // 返回节点的值
    }

    // 插入或更新 key 的值。
    // - 若 key 已存在，更新其值并移动到头部。
    // - 若不存在，插入到头部；若超过容量，则删除尾部元素并从哈希表移除对应 key。
    void put(int key, int value)
    {
        auto umap_it = key_to_iter.find(key); // 查找key
        if (umap_it != key_to_iter.end()) { // key 已存在
            // key 已存在：更新 value 并移动到头部
            auto list_iter = umap_it->second;   // 获取节点迭代器
            list_iter->second = value;        // 更新节点的值
            cache_list.splice(cache_list.begin(), cache_list, list_iter);    // 将节点移动到链表头部
            return; // 返回
        }

        // key 不存在：在头部插入新节点
        cache_list.emplace_front(key, value);   // 在链表头部插入新节点
        key_to_iter[key] = cache_list.begin(); // 将 key 映射到新节点的迭代器

        // 超过容量：删除尾部最少使用的节点
        if ((int)key_to_iter.size() > capacity) { // 超过容量
            int old_key = cache_list.back().first; // 获取尾部节点的 key
            key_to_iter.erase(old_key); // 从哈希表移除 key
            cache_list.pop_back(); // 从链表删除尾部节点
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

/*
// @lcpr case=start
// ["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]\n
// @lcpr case=end

 */
