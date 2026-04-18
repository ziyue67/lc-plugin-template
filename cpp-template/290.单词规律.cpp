/*
 * @lc app=leetcode.cn id=290 lang=cpp
 * @lcpr version=30403
 *
 * [290] 单词规律
 */

#include <iostream>
#include <vector>
#include <string>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "unordered_set"
#include "unordered_map"
#include "algorithm"
#include "sstream"
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map;
        unordered_multimap<string, char> map2;
        basic_stringstream<char> ss(s);
       for(char c:pattern){
         if (!(ss >> s)) return false;
         if (map.count(c) == 1 && map[c] != s) return false;
         auto it = map2.find(s);
         if (it != map2.end() && it->second != c) return false;
         map[c] = s;
         map2.insert({s, c});
      }
      return !(ss >> s);

    }
};
// @lc code=end

int main() {
  Solution solution;
  // your test code here
}



/*
// @lcpr case=start
// "abba"\n"dog cat cat dog"\n
// @lcpr case=end

// @lcpr case=start
// "abba"\n"dog cat cat fish"\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n"dog cat cat dog"\n
// @lcpr case=end

 */

