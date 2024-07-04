#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using std::vector, std::string;

#define InstucSize 320
#define PMSize 4 // PhysicalMemorySize
#define VMSize 32   // VirtualMemorySize(0 ~ n (int)) for every process
#define ProcessNum 5

/**************************Physical Memory**************************/
class PMPFAE { // PhysicalMemoryPageFrameAllocationElem
public:
    bool m_isOwned;
    int m_owner;

    PMPFAE() : m_isOwned(false), m_owner(-1) {}
    ~PMPFAE() {}
};

vector<PMPFAE> MemoryVector(PMSize);   // 主存物理块管理向量


/**************************Virtual Memory**************************/
class PTE {   // PageTableElem
public:
    bool m_existence;   // 存在位
    bool m_visit; // 访问位, 实现近似LRU
    // bool dirty; // 脏位
    // int m_VPN;    // virtual page num
    int m_PPN;    // physical page num

    PTE() : m_existence(0), m_visit(0), m_PPN(0) {}
    ~PTE() {}
};

class PageTable {
public:
    vector<PTE> m_PageTable; // 页表, 存储虚页放到了哪个实页中

    PageTable() {
        m_PageTable = vector<PTE> (VMSize);
    }

    int findPPN (int id, int VPN) {
        // 页表有效位有效 且 实页owner与当前进程id号相同
        if (m_PageTable[VPN].m_existence == true && MemoryVector[m_PageTable[VPN].m_PPN].m_owner == id) {
            m_PageTable[VPN].m_visit = 1;   // 更新访问位


            return m_PageTable[VPN].m_PPN;
        }
    }
};

class Process {
public:
    int m_id;
    int VPagePointer;  // 虚页指针
    vector<int> m_VPageCurrent;   // 存储虚拟页流
    PageTable m_PT;

    Process(int id) : m_id(id), VPagePointer(0) {
        CreateInstructions(m_VPageCurrent);
        TransToPage(m_VPageCurrent);
    }
    ~Process() {}

    // 生成指令流
    void CreateInstructions(vector<int> &instructions) {
        std::srand(std::time(0) + std::rand()); // 设置随机数种子
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

    // int Execute() {
    //     for (int VPage : m_VPageCurrent) {
    //         // AskOSFor(VPage);
    //         // PrintMem(MemoryVector);
    //     }
    // }

    void AskOSFor(int VPage, int) {

    }

    void OSDealWithPageLack() {}

    void PrintMem() {
        
    }

};

void CreateProcessArray(vector<Process> &ProcessArray, int num) {
    for (int i = 1; i <= num; i++) {
        ProcessArray.emplace_back(i);
    }
}

int main(int argc, char *argv[]) {
    // int PMSize = 4;  // 可以循环修改PMSize 以改变物理内存大小
    
    vector<Process> ProcessArray;
    CreateProcessArray(ProcessArray, ProcessNum);


    return 0;
}