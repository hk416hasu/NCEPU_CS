#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using std::vector;

#define InstucSize 320
// #define PMSize 4 // PhysicalMemorySize
#define VMSize 32   // VirtualMemorySize(0 ~ n (int)) for every process



class PTE {   // PageTableElem
public:
    bool m_existence;   // 存在位
    bool m_visit; // 访问位, 实现近似LRU
    // bool dirty; // 脏位
    int m_VPN;    // virtual page num
    int m_PPN;    // physical page num

    PTE() {
        m_existence = 0;
        m_visit = 0;
        // m_dirty = 0;
        m_VPN = 0;
        m_PPN = 0;
    }
    ~PTE() {}
};

class Process {
public:
    int VPagePointer;  // 虚页指针
    vector<int> m_VPageCurrent;   // 存储虚拟页流
    vector<PTE> m_PageTable; // 页表, 存储虚页放到了哪个实页中

    Process() {
        VPagePointer = 0;
        CreateInstructions(m_VPageCurrent);
        TransToPage(m_VPageCurrent);
        m_PageTable = vector<PTE> (VMSize);
    }
    ~Process() {}

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



int main(int argc, char *argv[]) {
    static int PMSize = 4;  // 可以循环修改PMSize 以改变物理内存大小
    vector<bool> MemoryMap(PMSize);


    Process a;



    return 0;
}