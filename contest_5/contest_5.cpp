#include <iostream>
using namespace std;

const int MOD = 1000000007;

long long modPow(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long b1, q, n;
        cin >> b1 >> q >> n;

        if (n == 0) {
            cout << 0 << '\n';
            continue;
        }

        b1 %= MOD;
        q %= MOD;

        if (q == 0) {
            cout << b1 << '\n';
            continue;
        }

        if (q == 1) {
            cout << (b1 * (n % MOD)) % MOD << '\n';
            continue;
        }

        long long qn = modPow(q, n);
        long long numerator = (qn - 1 + MOD) % MOD;
        long long denominator = (q - 1 + MOD) % MOD;

        long long ans = b1 * numerator % MOD * modPow(denominator, MOD - 2) % MOD;
        cout << ans << '\n';
    }

    return 0;
}