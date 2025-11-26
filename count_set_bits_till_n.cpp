#include <bits/stdc++.h>
using namespace std;

int countBits(long long n) {
    long long count = 0;

    for (long long i = 1; i <= n; i <<= 1) {
        long long completeCycles = (n + 1) / (i << 1);
        count += completeCycles * i;

        long long remainder = (n + 1) % (i << 1);
        if (remainder > i) count += remainder - i;
    }
    return count;
}

int main() {
    long long n;
    cin >> n;
    cout << countBits(n);
}
