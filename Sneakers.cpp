// Sprinkler

#include<bits/stdc++.h>
using namespace std;

long long solution( vector<int> a) {
    vector<int> have(32);
    const int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int x = a[i], j = 0; x; ++j, x >>= 1) {
            have[j] += x & 1;
        }
    }
    long long r = 0;
    for (int i = n >> 1; i; --i) {
        long long v = 0;
        for (int j = 31; j >= 0; --j) {
            if (have[j]) {
                v |= 1LL << j;
                --have[j];
            }
        }
        r += v * v;
    }
    return r;
}

int main() {
    cout << solution({3, 6, 7, 5, 3}) << endl;
}
