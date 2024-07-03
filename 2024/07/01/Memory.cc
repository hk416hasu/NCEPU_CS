#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using std::vector;

#define InstucSize 320
#define PMSize 4 // PhysicalMemorySize
#define VMSize 32   // VirtualMemorySize for every process

vector<bool> MemoryMap(PMSize);

// class PageTableMember

class Process {
public:
    vector<int> m_Instuc;   // 存储页面流
    vector<int> m_PageTable; // 页表

    Process() {
        CreateInstructions(m_Instuc);
        TransToPage(m_Instuc);
        m_PageTable = vector<int> (VMSize);
    }

    // 生成指令流
    void CreateInstructions(vector<int> &instructions) {
        std::srand(std::time(0)); // 用当前时间作为随机数种子
        instructions.clear();
        int count = 0;
        while (count < InstucSize) {
            int m = std::rand() % InstucSize;
            // instructions.push_back(m);   count++;
            instructions.push_back(m + 1);  count++;
            int m1 = std::rand() % (m + 2);
            instructions.push_back(m1);     count++;
            instructions.push_back(m1 + 1); count++;
            int m2 = (std::rand() % (318 - m1)) + (m1 + 2);
            instructions.push_back(m2);     count++;
        }
    }

    // 转换为虚页流（10个指令占一页，每个进程的虚存共32页）
    void TransToPage(vector<int> &instuctions) {
        for (int &elem : instuctions) {
            elem /= 10;
        }
    }

};



int main() {
    Process a;



    return 0;
}