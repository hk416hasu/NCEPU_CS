// 尝试使用打包重复元素的思路 解决重复元素子集问题, 成功！

#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

class foo {
public:
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

bool input(vector<char> &str) {
    size_t n = 0;
    scanf("%d", &n);
    assert(n > 0);
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
        assert(str[i] >= '0' && str[i] <= '9');
        index = str[i] - 48;
        bucket[index]++;
    }

    // step2: 将各数字字符及其出现频次打包成类数组
    for (size_t i = 0; i < 10; i++) {
        Frequency[i] = foo(i+48, bucket[i]);
    }

    return true;
}

vector<char> result;
int count = 0;

bool NoMore(int &index, const vector<foo> &Frequency) {
    for (int i = index; i < Frequency.size(); i++) {
        if (Frequency[i].m_times >= 1) {
            index = i;
            return false;
        }
    }
    return true;
}

void func(int index, vector<foo> &Frequency) {
    if (NoMore(index, Frequency)) {
        count++;
        output(result);
    } else {
        result.push_back(Frequency[index].m_ch);
        Frequency[index].m_times -= 1;
        
        func(index, Frequency);
        
        result.pop_back();
        func(index + 1, Frequency); // 妙笔! 强制跳过当前元素组, 就相当于剪枝
        Frequency[index].m_times += 1;
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
    func(0, Frequency);

    printf("%d\n", count);

    return 0;
}