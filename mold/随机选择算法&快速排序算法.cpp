//随机选择算法&快速排序算法
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

#define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

const int maxn = 100010;
int A[maxn];

int randPartition(int Snum[], int left, int right) {         //根据随机主元分割数组
    int pos = (int)round(1.0 * rand() / RAND_MAX * (right-left) + left);
    swap(Snum[left], Snum[pos]);
    int temp = Snum[left];
    while (left < right) {                                //保证结束的时候left=right
        while((left < right) && (Snum[right] > temp)) {
            right--;
        }
        Snum[left] = Snum[right];
        while((left < right) && (Snum[left] < temp)) {
            left++;
        }
        Snum[right] = Snum[left];
    }
    Snum[left] = temp;                                     //主元前面的数都比它小，后面的数都比它大
    return left;                                           //分割完成后将主元下标返回

}

void randSelect(int Snum[], int left, int right, int k) {  //随机选择算法，找出数组中第k小的数
    if (left == right) {                                   //边界条件，退出递归
        return ;
    }
    int pos = randPartition(Snum, left, right);
    int M = pos - left + 1;                               //主元为数组中第M小的数
    if(k == M) {
        return ;
    } else if (k > M) {
        randSelect(Snum, pos+1, right, k-M);
    } else {
        randSelect(Snum, left, pos-1, k);
    }

}

void QuickSort(int Snum[], int left, int right) {         //快排算法
    if (left >= right) {
        return ;
    }
    int pos = randPartition(Snum, left, right);
    QuickSort(Snum, left, pos-1);
    QuickSort(Snum, pos+1, right);
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
    //使用随机选择算法
    int n, sum = 0, sum1 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        sum += A[i];
    }
    srand((unsigned)time(NULL));                            //初始化随机数种子
    int left = 0, right = n-1;
    randSelect(A, left, right, n/2);
    for (int i = 0; i < n/2; i++) {
        sum1 += A[i];
    }
    printf("%d\n", (sum-sum1)-sum1);
    //使用快排
    QuickSort(A, left, right);
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}