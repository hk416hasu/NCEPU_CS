// 尝试使用打包重复元素的思路 解决重复元素子集问题, 但失败了
// 因为我需要记录每个元素选中与否, 不论它是否重复

#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

class foo {
public:
    bool m_enable = false;
    char m_ch;  // 只能是数字字符 48<=ch<=57, 后续还可以加字母字符
    size_t m_times;

    foo() { m_ch = 0; m_times = 0; }
    foo(char ch, size_t times) {
        m_ch = ch;
        m_times = times;
    }
    ~foo() {}
    // =重载? new重载?
};

// class foo {
// public:
//     char m_ch;  // 只能是数字字符 48<=ch<=57, 后续还可以加字母字符
//     size_t m_times;

//     foo() { m_ch = 0; m_times = 0; }
//     foo(char ch, size_t times) {
//         m_ch = ch;
//         m_times = times;
//     }
//     ~foo() {}
//     // =重载? new重载?
// };

bool input(vector<char> &str) {
    size_t n = 0;
    scanf("%d", &n);
    str.resize(n);
    for (size_t i = 0; i < n; i++) {
        scanf("%c", &str[i]);   // 多读取一次, 
        scanf("%c", &str[i]);   // 把读到的空格顶掉
    }
    return true;
}

void output(vector<char> vec) {
    for(char elem : vec) {
        printf("%c ", elem);
    }
    printf("\n");
}

bool GetFrequency(const vector<char> &str, vector<foo> &Frequency) {
    // step1: 统计各字符的出现频次
    size_t bucket[10] = {0};    // 存放各数字字符的出现频次
    size_t index = 0;
    for (size_t i = 0; i < str.size(); i++) {
        assert(str[i] >= '1' && str[i] <= '9');
        index = str[i] - 48;
        bucket[index]++;
    }

    // step2: 将各数字字符及其出现频次打包成类数组
    for (size_t i = 0; i < 10; i++) {
        Frequency[i] = foo(i+48, bucket[i]);
        if (bucket[i] > 0) { Frequency[i].m_enable = true; }
    }

    return true;
}

vector<char> result;
int count = 0;

void updateIndex(int &index, const vector<foo> &Frequency) {
    for (int i = index; i < Frequency.size(); i++) {
        if (Frequency[i].m_enable && Frequency[i].m_times > 0) {
            index = i;
            return;
        }
    }
    index = -1;
    return;
}

void func(int index, vector<foo> &Frequency) {
    updateIndex(index, Frequency);
    if (index == -1) {
        count++;
        output(result);
    } else {
        result.push_back(Frequency[index].m_ch);
        Frequency[index].m_enable = true;
        Frequency[index].m_times -= 1;
        
        func(index, Frequency);
        
        result.pop_back();
        Frequency[index].m_enable = false;
        func(index, Frequency);
        Frequency[index].m_times += 1;
        Frequency[index].m_enable = true;
    }
}



int main() {

    // 输入
    vector<char> str;
    input(str);

    // 第一步: 获取各字符出现频次
    vector<foo> Frequency(10);
    GetFrequency(str, Frequency);

    printf("output:\n");
    func(-1, Frequency);

    printf("%d\n", count);

    return 0;
}