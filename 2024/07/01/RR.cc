#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <unistd.h>

using std::vector;

#define ProcessNum 5

enum ProcessState { R, E };

class Process {
public:
    int m_id;
    int m_next;
    int m_NeedServeTime;
    int m_ServedTime;
    ProcessState m_stat;

    Process(int id, int NeedServeTime) : m_id(id), m_ServedTime(0), m_stat(R) {
        m_next = id % ProcessNum + 1;
        m_NeedServeTime = NeedServeTime;
    }

    void Print() {
        printf("Process %d:\n\tnext -> %d,\n\tNeedServeTime: %d,\n\tServedTime: %d,\n\tstate: %c\n", \
            m_id, m_next, m_NeedServeTime, m_ServedTime, ((m_stat == 0) ? 'R' : 'E') );
    }

    void Execute() {
        m_ServedTime++;
        if (m_ServedTime == m_NeedServeTime) {
            m_stat = E;
        }
    }

};

void CreateProcessArray(vector<Process> &ProcessArray, int num) {
    assert(num >= 1);
    std::srand(std::time(0) + std::rand()); // 设置随机数种子
    for (int i = 1; i <= num; i++) {
        ProcessArray.emplace_back( i, ((std::rand() % 5) + 1) );
    }
}

// 若所有进程均End, 则返回true, 否则返回false
bool isAllEnd(const vector<Process> &PArr) {
    for (Process elem : PArr) {
        if (elem.m_stat == R) {
            return false;
        }
    }
    return true;
}

void Print(const vector<Process> &PArr) {
    for (Process elem : PArr) {
        elem.Print();
    }
}

void RR(vector<Process> &PArr) {

    int RP = 1; // RunningPointer


    while (!isAllEnd(PArr)) {   // RR结束条件

        if (PArr[RP-1].m_stat == R) {
            printf("\n\n\nselected Process: %d\n\n", PArr[RP-1].m_id);
            Print(PArr);    // 输出状态
            PArr[RP-1].Execute();
        }

        RP = PArr[RP-1].m_next;
        sleep(5);
    }

    printf("\n\n\n");
    Print(PArr);    // 输出结束状态

}

int main() {

    assert(ProcessNum > 0);
    
    vector<Process> ProcessArray;
    CreateProcessArray(ProcessArray, ProcessNum);

    printf("enum ProcessState { R, E }");
    RR(ProcessArray);

    return 0;
}