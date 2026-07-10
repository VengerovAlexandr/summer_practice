#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int minX1 = min(x1, x2);
    int maxX1 = max(x1, x2);
    int minY1 = min(y1, y2);
    int maxY1 = max(y1, y2);

    int minX2 = min(x3, x4);
    int maxX2 = max(x3, x4);
    int minY2 = min(y3, y4);
    int maxY2 = max(y3, y4);

    long long s1 = (long long)(maxX1 - minX1) * (maxY1 - minY1);

    long long s2 = (long long)(maxX2 - minX2) * (maxY2 - minY2);

    int overlapX = max(0, min(maxX1, maxX2) - max(minX1, minX2));
    int overlapY = max(0, min(maxY1, maxY2) - max(minY1, minY2));
    long long overlap = (long long)overlapX * overlapY;

    long long ans = s1 + s2 - overlap;

    cout << ans << endl;

    return 0;
}