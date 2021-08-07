//最大公约数&最小公倍数
#include <iostream>
#include <algorithm>

// #define LOCAL
#define SEE(x) cout << #x << ":" << x << endl;

using namespace std;

int gcd(int a, int b) {
    if(a < b) {
        swap(a, b);
    }
    return !b ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
    int d = gcd(a, b);
    return a / d * b;
}

int main() {
#ifdef LOCAL
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d与%d的最大公约数为：%d\n", a, b, gcd(a, b));
    printf("%d与%d的最小公倍数为：%d\n", a, b, lcm(a, b));
    return 0;
}