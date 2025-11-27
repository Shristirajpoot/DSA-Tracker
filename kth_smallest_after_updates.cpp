#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q, K;
    cin >> N >> Q >> K;

    vector<long long> A(N), diff(N+1, 0);
    for(int i = 0; i < N; i++) cin >> A[i];

    while(Q--) {
        int L, R;
        long long X;
        cin >> L >> R >> X;
        L--, R--;
        diff[L] += X;
        diff[R+1] -= X;
    }

    long long add = 0;
    for(int i = 0; i < N; i++) {
        add += diff[i];
        A[i] += add;
    }

    nth_element(A.begin(), A.begin() + K - 1, A.end());
    cout << A[K-1] << "\n";
}
