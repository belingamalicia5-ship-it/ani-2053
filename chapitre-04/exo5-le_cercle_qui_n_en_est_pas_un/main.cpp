#include <bits/stdc++.h>
using namespace std;

int main() {
    const double PI = 3.141592653589793;
    int n;
    cin >> n;
    long long visibles = 0, refuses = 0;

    for (int i = 0; i < n; i++) {
        long long r, segs;
        cin >> r >> segs;

        if (segs < 3) {
            cout << r << " " << segs << " REFUSE\n";
            refuses++;
            continue;
        }

        double g = (double)r * (1.0 - cos(PI / (double)segs));
        long long ecart = (long long)floor(g * 1000.0);

        if (g == 0.0) {
            cout << r << " " << segs << " " << ecart << " JAMAIS\n";
            continue;
        }

        long long zoom = (long long)ceil(100.0 / g);
        bool visible = (zoom <= 100);
        cout << r << " " << segs << " " << ecart << " " << zoom << " "
             << (visible ? "VISIBLE" : "INVISIBLE") << "\n";
        if (visible) visibles++;
    }

    cout << "VISIBLES " << visibles << "\n";
    cout << "REFUSES " << refuses << "\n";
    return 0;
}
