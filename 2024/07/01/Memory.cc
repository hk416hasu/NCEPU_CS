#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cassert>

using std::vector, std::string;

#define InstucSize 80
#define PMSize 2 // PhysicalMemorySize
static int VMSize = InstucSize / 10;   // VirtualMemorySize(0 ~ n (int)) for every process
#define ProcessNum 1
#define Step 80 // 一步执行80条指令

/**************************Physical Memory**************************/
class PMPFAE { // PhysicalMemoryPageFrameAllocationElem
public:
    bool m_isOwned;
    int m_owner;    // 存储id号
    bool m_visit;

    PMPFAE() : m_isOwned(false), m_owner(-1), m_visit(false) {}
    ~PMPFAE() {}
    // void Print(int PPid) {  // Physical Page id
    //     printf("usage ...\n");
    // }
};

class PhysicalMemory {
public:
    vector<PMPFAE> m_MemoryVector;   // 主存物理块管理向量
    int ClockPointer = 0;
    
    PhysicalMemory() : ClockPointer(0) {
        m_MemoryVector = vector<PMPFAE>(PMSize);
    }

    // 查找储存中是否有空闲块, 有则返回索引, 没有则返回-1
    int hasAvailablePPage() {
        for (int i = 0; i < PMSize; i++) {
            if (m_MemoryVector[i].m_isOwned == false) {
                return i;
            }
        }
        return -1;
    }

    // 判断主存是否已满
    bool isNotFull() {
        if (hasAvailablePPage() != -1) {
            return true;    // 有块没人占, 确实没满
        }
        return false;   // 满了
    }

    // 申请一空闲物理块, 返回物理块号PPN
    int ApplyPPage(int id) {
        int index = hasAvailablePPage();    // 取一块空闲物理块
        assert(index != -1);
        AllocatePPage(id, index);   // 调入主存
        return index;
    }

    /**
     * @brief: 为进程号为id的进程 分配 主存中索引为index(PPN)的块
     */
    void AllocatePPage(int id, int index) {
        m_MemoryVector[index].m_isOwned = true;
        m_MemoryVector[index].m_owner = id;
        m_MemoryVector[index].m_visit = 1;
    }

    // 
    void ReleasePPage(int id) {
        for (PMPFAE elem : m_MemoryVector) {
            if (elem.m_owner == id) {
                elem.m_isOwned = false;
            }
        }
    }

    // 按照近似LRU算法“分配”(置换)一物理块, 并要记录被换出的VPN(如果是同owner), 非同一进程的页表不太好改，还是用主存owner辨别就可以 不需要特别去修改
    // 如果换掉的是同一进程的页, 仅有主存owner位不够
    // 因此需要更新当前进程的页表, 将被换出去的页的页表项存在位置为false
    int ApplyPPageWithLRU(int id, bool &SwapOutSameProcess) {
        // 找一个最近最不常访问的物理页
        while (m_MemoryVector[ClockPointer].m_visit) {
            m_MemoryVector[ClockPointer].m_visit = false;
            ClockPointer = (ClockPointer + 1) % PMSize;
        }

        SwapOutSameProcess = (m_MemoryVector[ClockPointer].m_owner == id);

        AllocatePPage(id, ClockPointer);   // 调入主存
        return ClockPointer;
    }

};

PhysicalMemory Memory;   // 主存物理块 们


/**************************Virtual Memory**************************/
class PTE {   // PageTableElem
public:
    bool m_existence;   // 存在位
    // bool m_visit; // 页表项访问位 暂时不需要
    // bool dirty; // 脏位
    // int m_VPN;    // virtual page num
    int m_PPN;    // physical page num

    PTE() : m_existence(0), m_PPN(0) {}
    ~PTE() {}
};

class PageTable {
public:
    vector<PTE> m_PageTable; // 页表, 存储虚页放到了哪个实页中

    PageTable() {
        m_PageTable = vector<PTE> (VMSize);
    }

    // is in Physical Memory
    // 注意！！本实验中，有效位有效不代表虚页一定在主存中，还需要对比owner
    bool isInPM (int id, int VPN) {
        // 页表有效位有效 且 对应实页owner与当前进程id号相同
        if (m_PageTable[VPN].m_existence == true &&
            Memory.m_MemoryVector[m_PageTable[VPN].m_PPN].m_owner == id )
        {
            Memory.m_MemoryVector[m_PageTable[VPN].m_PPN].m_visit = 1;   // 更新对应主存访问位
            return true;
        }
        return false;
    }

    void OneVPNisNotExistInThisPPNnow(int PPN) {
        for (PTE &elem : m_PageTable) {
            if (elem.m_PPN == PPN) {
                elem.m_existence = false;
            }
        }
    }
};

class Process {
public:
    int m_id;
    int VPagePointer;  // 虚页指针
    vector<int> m_VPageCurrent;   // 存储虚拟页流
    PageTable m_PT; // ProcessAddressSpace

    Process(int id) : m_id(id), VPagePointer(0) {
        CreateInstructions(m_VPageCurrent);
        TransToPage(m_VPageCurrent);
    }
    ~Process() {
        m_id = -1;
        VPagePointer = -1;
        m_VPageCurrent.clear();
        m_PT.m_PageTable.clear();

        // this = nullptr;
    }

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
            int m2 = (std::rand() % (InstucSize - 2 - m1)) + (m1 + 2);
            instructions.push_back(m2);     count++;
        }
    }

    // 转换为虚页流（10个指令占一页，每个进程的虚存共32页）
    void TransToPage(vector<int> &instuctions) {
        for (int &elem : instuctions) {
            elem /= 10;
        }
    }

    void Execute() {
        // for (int i = ; i < Step??; i++) {

        // }
        for (int VPN : m_VPageCurrent) {
            AskOSFor(VPN);
            // PrintMem();
        }
    }

    void AskOSFor(int VPN) {
        while(!m_PT.isInPM(m_id, VPN)) { // 如果主存中没有对应实页 
            CallOStoDealWithPageLack(VPN);
        }
        // then okay, page is in Phycical Memory now!
    }

    // 页面调入算法/页面置换算法, 以从虚存调入页面进入主存
    // 模拟调入, 其实就是修改主存标志位和页表项.
    //     这个放到Memory class里会不会更适合？
    void CallOStoDealWithPageLack(int VPN) {
        int PPN = -1;
        bool SwapOutAPageInSameProcess = false;
        if (Memory.isNotFull()) { // 检查主存是否满了
            // 没满, 则申请一个空闲块
            PPN = Memory.ApplyPPage(m_id);
        } else { // 如果满了
            // LRU算法选择一个最近最不常访问块，遍历过程中要更新visit
            PPN = Memory.ApplyPPageWithLRU(m_id, SwapOutAPageInSameProcess);
        }
        
        // 更新页表
        // 首先取消在此PPN的页表项(旧的那个)
        if (SwapOutAPageInSameProcess) {
            m_PT.OneVPNisNotExistInThisPPNnow(PPN);
        }
        // 再更新页表表示:此VPN位于PPN
        assert(PPN >= 0);
        m_PT.m_PageTable[VPN].m_PPN = PPN;
        m_PT.m_PageTable[VPN].m_existence = true;


    }

    void PrintMem() {
        // 先直接调试吧
    }

    void Exit() {
        // OS遍历主存, 取消所有此进程的实页分配() : owner对的上的主存全部 改标志位
        Memory.ReleasePPage(m_id);

        // 撤销所有东西 ~() ?
        this->~Process();
    }

};

void CreateProcessArray(vector<Process> &ProcessArray, int num) {
    assert(num >= 1);
    for (int i = 1; i <= num; i++) {
        ProcessArray.emplace_back(i);
    }
}

int main(int argc, char *argv[]) {
    // int PMSize = 4;  // 可以循环修改PMSize 以改变物理内存大小
    
    vector<Process> ProcessArray;
    CreateProcessArray(ProcessArray, ProcessNum);
    ProcessArray[0].Execute();

    // ProcessArray[0].Exit(); // 

    return 0;
}