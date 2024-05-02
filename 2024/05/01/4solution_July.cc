#include <iostream>
#include <list>
using namespace std;

list<int>list1;
int count = 0;

// sum 是目标和，n是当前的数
void SumOfkNumber(int sum, int n)
{
	// 递归出口
	if (n <= 0 || sum <= 0)
		return;

	// 当当前数字n正好等于目标和sum时，就输出找到的结果
	if (sum == n)
	{
        count++;
		// 反转list
		list1.reverse();
		for (list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)
			cout << *iter << " ";
		cout << n << endl;
		list1.reverse();  //此处还需反转回来
	}

	list1.push_front(n);      //典型的01背包问题
	SumOfkNumber(sum - n, n - 1);   //“放”n，前n-1个数“填满”sum-n
	list1.pop_front();
	SumOfkNumber(sum, n - 1);     //不“放”n，n-1个数“填满”sum
}

int main() {
    int n = 0, target = 0;
    scanf("%d %d", &n, &target);
    SumOfkNumber(target, n);
    cout << "Here are " << count << " solutions." << endl;
    return 0;
}