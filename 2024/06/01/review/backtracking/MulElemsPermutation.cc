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

vector<char> vec;
int count = 0;

void func(size_t t, vector<foo> &CharFrequency, int limit) {
    if (t == limit) {
        count++;
        output(vec);
    } else {
        // 遍历CharFrequency, 取一个频次为>=1的字符
        // for (size_t i = t; i < 10; i++) {
        for (size_t i = 0; i < 10; i++) {
            if (CharFrequency[i].m_times >= 1) { // 剪枝
                // 状态更新
                vec.push_back(CharFrequency[i].m_ch);
                CharFrequency[i].m_times -= 1;

                // 回溯遍历解空间排列树
                func((t + 1), CharFrequency, limit);
                
                // 状态回滚
                vec.pop_back();
                CharFrequency[i].m_times += 1;
            }
        }
    }
}



int main() {

    // 输入
    vector<char> str;
    input(str);

    // 第一步: 获取各字符出现频次
    vector<foo> Frequency(10);
    GetFrequency(str, Frequency);

    // 第二步: 每次取一个频次大于0的字符, 每个字符仅一次
    //          然后回溯遍历解空间排列树即可
    printf("output:\n");
    func(0, Frequency, str.size());

    printf("%d\n", count);

    return 0;
}