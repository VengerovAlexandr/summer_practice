#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long omega;
    cin >> n >> omega;

    vector<pair<long long, int>> holes(n);
    for (int i = 0; i < n; i++) {
        cin >> holes[i].first;
        holes[i].second = i + 1;
    }

    sort(holes.begin(), holes.end());

    vector<int> ans;
    long long current = omega;
    int i = 0;

    while (i < n) {
        if (holes[i].first < current) {
            current += holes[i].first;
            ans.push_back(holes[i].second);
            i++;
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (int idx : ans) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}