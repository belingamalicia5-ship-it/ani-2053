#include <bits/stdc++.h>
using namespace std;

int main() {
    long long C, R, W, H, F, D, P;
    cin >> C >> R >> W >> H >> F >> D >> P;
    long long n;
    cin >> n;

    long long cur = 0, acc = 0;
    long long avances = 0, plafonnes = 0;

    for (long long i = 0; i < n; i++) {
        long long dt;
        cin >> dt;

        if (dt > P) { dt = P; plafonnes++; }
        acc += dt;

        while (acc >= D) {
            acc -= D;
            cur = (cur + 1) % F;
            avances++;
        }

        long long x = (cur % C) * W;
        long long y = (cur / C) * H;
        cout << cur << " " << x << " " << y << " " << W << " " << H << "\n";
    }

    cout << "AVANCES " << avances << "\n";
    cout << "PLAFONNES " << plafonnes << "\n";
    return 0;
}
