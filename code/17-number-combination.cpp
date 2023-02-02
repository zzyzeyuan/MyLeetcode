//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
//
// Related Topics 哈希表 字符串 回溯 👍 2279 👎 0

#include <iostream>
#include <string>
#include <vector>

#include <unordered_map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    vector<string> ans;

    unordered_map<char, string> hashMap{
            {'2', {"abc"}},
            {'3', {"def"}},
            {'4', {"ghi"}},
            {'5', {"jkl"}},
            {'6', {"mno"}},
            {'7', {"pqrs"}},
            {'8', {"tuv"}},
            {'9', {"wxyz"}}
    };
public:
    vector<string> letterCombinations(string digits) {

        if (digits.length() == 0) return ans;

        dfs({}, 0, digits);

        return ans;
    }

    void dfs(string result, int index, string digits){
        //结束条件
        if (index == digits.length()){
            ans.emplace_back(result);
            return ;
        }
        for( auto ch : hashMap[digits[index]]){
            dfs(result+ch, index+1, digits);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
