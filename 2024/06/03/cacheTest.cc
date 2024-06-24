#include <iostream>
#include <vector>
#include <algorithm>

#define n 50000

using std::vector;

int main(int argc, char* argv[]) {
        
    int sum = 0;
    vector<vector<int>> arr(n, vector<int>(n, 1));
    
    //std::string str = argv[1];
    //int op = std::atoi(str) - 48;

    switch(argc) {
    case 1 : 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += arr[i][j];
            }
        }
        break;

    case 2 :
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                sum += arr[i][j];
            }
        }
        break;
    default:
        printf("error\n");
        break;

    }        

    return 0;
}
