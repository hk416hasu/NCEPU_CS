#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <ctime>
        
#define ElemType int

void GetinputFromFile(std::vector<ElemType> &arr);
void InputK(const std::vector<ElemType> &arr, int &k);
int FindKthMinElem_by_Sort(std::vector<ElemType> arr, int k, double &used_time);
int FindKthMinElem_by_Heap(std::vector<ElemType> arr, int k, double &used_time);
int FindKthMinElem_by_partition(std::vector<ElemType> arr, int k, double &used_time);

int main()
{

std::vector<ElemType> arr;
    GetinputFromFile(arr);

int k = 0, kth_min = 0;
    InputK(arr, k);

int op = 0;
    printf("    We are going to find the Kth-min-elem, and here are some choices for u:)\n");
    printf("    1 => by Sort() : After sorting the array, then we AT the arr[k-1].    \n");
    printf("    2 => by Heap() : In the beginning, we suppose the first k elems are generally minimal,  \n");
    printf("                            then we update them by Heap step by step.    \n");
    printf("    3 => by partition() : every time we find the pivot's pos, then choose a range to find. \n");
    printf("    4 => change the value of K.\n");
    printf("other => exit.\n");
    printf("    plz input your choice : ");
    scanf("%d", &op);

double used_time = 0.0;
    do {
        switch (op)
        {
        case 1:
            kth_min = FindKthMinElem_by_Sort(arr, k, used_time);
            break;
        case 2:
            kth_min = FindKthMinElem_by_Heap(arr, k, used_time);
            break;
        case 3:
            kth_min = FindKthMinElem_by_partition(arr, k, used_time);
            break;
        case 4:
            InputK(arr, k);
            break;
        default:
            break;
        }

        if (op != 4) {
            printf("the %dth_min elem is: %d\n", k, kth_min);
            printf("timecost: %lfs\n", used_time);
        }
        printf("    plz input your choice again : ");
        scanf("%d", &op);
    } while (op == 1 || op == 2 || op == 3 || op == 4);

    return 0;
}

void GetinputFromFile(std::vector<ElemType> &arr) {
    printf("trying to open file and get input-num.\n");
    std::ifstream file("RandomNum.txt");
    if (!file.is_open()) {
        printf("Error: Failed to open file.\n");
        exit(0);
    }

    std::string line;
    while(std::getline(file, line)) {
        arr.push_back(std::stoi(line));
    }
    printf("over.\n");
    file.close();
}

void InputK(const std::vector<ElemType> &arr, int &k) {
    printf("plz input the value of K: ");
    scanf("%d", &k);

    while (k < 1 || k > (int)arr.size()) {
        printf("Invalid K value, plz enter again.\n");
        printf("(the size of Sequence is %zu , it maybe an useful information :)\n", arr.size());
        printf("plz input the value of K: ");
        scanf("%d", &k);
    }
}

/**
 * @brief 对数组arr中前len部分，从root下标开始大根堆化
 * @param root是“选定堆顶”的索引index
 * @attention root, largest, left, right 均为数组索引(index)
 * @attention heap 默认为大根堆
*/
void heapify(std::vector<ElemType> &arr, int len, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < len && arr[left] > arr[largest]) largest = left;
    if (right < len && arr[right] > arr[largest]) largest = right;

    if (largest != root) {
        std::swap(arr[largest], arr[root]);
        heapify(arr, len, largest);
    }
}

/**
 * @brief 对数组arr的全部元素建立大根堆
*/
void BuildHeap(std::vector<ElemType> &arr) {
    int len = static_cast<int>arr.size();
    for (int i = len/2; i >= 0; --i) {
        heapify(arr, len, i);
    }
}

/**
 * @brief 对数组arr的前len部分建立大根堆
*/
void BuildHeap(std::vector<ElemType> &arr, int len) {
    for (int i = len/2; i >= 0; --i) {
        heapify(arr, len, i);
    }
}

int partition(std::vector<ElemType> &arr, int low, int high) {
    ElemType pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) high--;
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) low++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

int FindKthMinElem_by_partition(std::vector<ElemType> &arr, int k, int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int pivotpos = partition(arr, low, high);
    int j = pivotpos - low + 1; // 将pivotpos转换为相对次序
    if (k == j) {
        return arr[pivotpos];
    } else if (k < j) {
        return FindKthMinElem_by_partition(arr, k, low, pivotpos - 1);
    } else {
        return FindKthMinElem_by_partition(arr, k - j, pivotpos + 1, high); // k-j是目标元素在新序列的相对次序
    }
}

int FindKthMinElem_by_Sort(std::vector<ElemType> arr, int k, double &used_time) {
    printf("1 : FindKthMinElem_by_Sort() begin now.\n");
    clock_t timestart = clock();    // 记录算法开始时间
    std::sort(arr.begin(), arr.end());
    used_time = (double)(clock() - timestart)/(CLOCKS_PER_SEC);
    return arr[k-1];
}

int FindKthMinElem_by_Heap(std::vector<ElemType> arr, int k, double &used_time) {
    printf("2 : FindKthMinElem_by_Heap() begin now.\n");
    clock_t timestart = clock();    // 记录算法开始时间
    BuildHeap(arr, k);   // 对arr的前k个元素进行大根堆化
    for (int i = k; i < (int)arr.size(); i++) {
        if (arr[i] < arr[0]) {
            // std::swap(arr[i], arr[0]);  // 如果需要保留大根堆顶元素，则使用std::swap()
            arr[0] = arr[i];    // 如果不需要保留，直接替换即可
            heapify(arr, k, 0); // 重新对前k个元素堆化，以找到新的最大值
        }
    }
    used_time = (double)(clock() - timestart)/(CLOCKS_PER_SEC);
    return arr[0];
}

int FindKthMinElem_by_partition(std::vector<ElemType> arr, int k, double &used_time) {
    printf("3 : FindKthMinElem_by_partition() begin now.\n");
    clock_t timestart = clock();    // 记录算法开始时间
    int kth_num = FindKthMinElem_by_partition(arr, k, 0, (int)arr.size() - 1);
    used_time = (double)(clock() - timestart)/(CLOCKS_PER_SEC);
    return kth_num;
}