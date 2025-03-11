#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> iVector = {1, 2, 3, 4, 5, 6};

//  for_each(begin(iVector), end(iVector), [](int n) {
//      if (n % 2 == 0) cout << n << endl;
//  });

    [&]() -> void { for (auto &elem : iVector) cout << elem << " "; }();

    {
       int count = 0;
       [=]() mutable { cout << (count++) << " "; }();
    }
    cout << '\n';

    return 0;
}

