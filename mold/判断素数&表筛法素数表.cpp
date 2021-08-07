//判断素数&表筛法素数表
#include <iostream>
#include <cmath>
#include <algorithm>

// #define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

const int maxn = 101;
bool pTable[maxn] = {0};              //标志对应下标是否为素数

bool isPrime(int x) {                 //判断素数
    bool flag = 1;                    //标志是否为素数
    int sqr = sqrt(x);                //需要检索的范围是2-sqrt(x)
    for (int i = 2; i <= sqr; i++) {
        if (!(x % i)) {
            flag = 0;
            break;
        }
    }
    return flag;
}

void primeTable() {                   //表筛法素数表
    fill(pTable + 2, pTable + maxn, 1);
    for (int i = 2; i < maxn; i++) {  //遍历素数表，每轮筛去当前素数的倍数
        if (pTable[i]) {              //没有被上轮筛区的第一个数为素数
            for (int j = i + i; j < maxn; j += i) {
                pTable[j] = 0;
            }
        }

    }

}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
    int a;
    scanf("%d", &a);
    printf("%d\n", isPrime(a));
    primeTable();
    for(int i = 0; i < maxn; i++) {
        if (pTable[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}