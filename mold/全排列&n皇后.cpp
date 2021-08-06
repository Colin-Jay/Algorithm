//按照字典序进行全排列&n皇后
#include <iostream>
#include <cstring>
#include <cmath>

// #define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

const int maxn = 11;
int n = 0, Fnum[maxn] = {}, num = 0;           //记录当前这组排列
int hashTable[maxn] = {};                      //记录当前这组排列中已经加入了哪些数字

void Fsort(int x) {                            //x表示已经加入该组排列的个数
    if (x == n+1) {                            //如果已经是一组排列了，那么直接打印该组
        for (int i = 1; i < n+1; i++) {
            printf("%d ", Fnum[i]);
        }
        printf("\n");
        // SEE(x);
        return ;
    }
    for (int i = 1; i < n+1; i++) {            //n个数字中已经加入当前排列的个数
        if (hashTable[i] == 0) {               //找到第一个没加入的数
            hashTable[i] = 1;                  //将其标志位修改并加入当前排列
            Fnum[x] = i;
            // SEE(Fnum[x]);
            Fsort(x+1);                        //加入下一个数字
            hashTable[i] = 0;                  //加入该数字后再还原，以便下一组排列中，可以继续加入该数字
        }
    }
}

void nQueen(int x) {
    if (x == n+1) {                            //递归边界，是一个合法的n皇后方案
        for (int i = 1; i < n+1; i++) {
            printf("%d ", Fnum[i]);
        }
        printf("\n");
        num++;                                 //合法方案个数
        // SEE(x);
        return ;
    }
    for (int i = 1; i < n+1; i++) {            //在第x行中，依次遍历每列，找到可以加皇后的列
        if (hashTable[i] == 0) {               //找到当前行第一个可以加入皇后的列
            bool flag = 1;                     //flag标志当前皇后方案可行
            for (int j = 1; j < x; j++) {      //若皇后存在对角线冲突，该方案后续不用继续判断，回溯
                if (abs(j - x) == abs(Fnum[j] - i)) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {                    //若目前方案可行，加入皇后
                hashTable[i] = 1;                  //将其标志位修改并加入行
                Fnum[x] = i;
                // SEE(Fnum[x]);
                nQueen(x+1);                        //在下一行（x+1行）加入皇后
                hashTable[i] = 0;                  //加入该数字后再还原，以便下一组排列中，可以继续加入该数字
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    hashTable[0] = 1;
    //全排列
    printf("%d的全排列：\n", n);
    Fsort(1);
    //n皇后
    printf("其中满足%d皇后的方案：\n", n);
    nQueen(1);
    printf("%d皇后的方案个数为：%d\n", n, num);
    return 0;
}