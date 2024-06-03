
// 排列树
// 还没搞懂swap那块
void backtrack(int t) {     // t 表示在解空间树中所处的层次
    if(t > n) {             // n 表示问题的规模
        output(x);          // x 是当前解
    } 
    else {
        for(int i = t; i <= n; i++) {
            swap(x[t], x[i]);               //实现两个位置的交换
            if(constraint(t) && bound(t)) { //约束函数与限定函数
                backtrack(t+1);             //递归
            }
            swap(x[t], x[i]);               //恢复原状
        }
    }
}

// 子集树: 本质就是元素i选or不选
void backtrack() {
    if (okay) {
        x[i] = 0;
        backtrack(target);
        x[i] = 1;
        backtrack(target - i);
    }
}