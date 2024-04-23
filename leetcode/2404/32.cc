// 按照分类来说，这题应该是动态规划，但括号匹配似乎和栈更搭。
// 根据评论区的提示，我使用了mark数组，用以标记合法的括号的index
// 最后遍历一遍mark即可得到最长合法子串
#include <iostream>
#include <stack>
#include <vector>

int main() {

    // std::string s = "()(()";
    // std::string s = "";
    // std::string s = "(()";
    // std::string s = ")()())";
    // std::string s = "()(())";
    // std::string s = ")()((())";
    std::string s = ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())";

    std::stack<int> myStack;
    std::vector<bool> mark(s.size());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            myStack.push(i);
        }
        if (!myStack.empty() && s[i] == ')') {
            mark[i] = true;
            mark[myStack.top()] = true;
            myStack.pop();
        } else {
            mark[i] = false;
        }
    }
    // 所有栈中剩余的'('全部丢弃，因为没有可匹配的')'
    while (!myStack.empty()) {
        mark[myStack.top()] = false;
        myStack.pop();
    }

    /**mark初始化完毕，下做收集操作**/

    int count = 0, maxcount = 0;
    for (bool flag : mark) {
        count = (flag) ? count + 1 : 0;
        maxcount = (maxcount > count) ? maxcount : count;
    }

    getchar();
    return 0;
}