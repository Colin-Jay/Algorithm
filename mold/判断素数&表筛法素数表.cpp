//�ж�����&��ɸ��������
#include <iostream>
#include <cmath>
#include <algorithm>

// #define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

const int maxn = 101;
bool pTable[maxn] = {0};              //��־��Ӧ�±��Ƿ�Ϊ����

bool isPrime(int x) {                 //�ж�����
    bool flag = 1;                    //��־�Ƿ�Ϊ����
    int sqr = sqrt(x);                //��Ҫ�����ķ�Χ��2-sqrt(x)
    for (int i = 2; i <= sqr; i++) {
        if (!(x % i)) {
            flag = 0;
            break;
        }
    }
    return flag;
}

void primeTable() {                   //��ɸ��������
    fill(pTable + 2, pTable + maxn, 1);
    for (int i = 2; i < maxn; i++) {  //����������ÿ��ɸȥ��ǰ�����ı���
        if (pTable[i]) {              //û�б�����ɸ���ĵ�һ����Ϊ����
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