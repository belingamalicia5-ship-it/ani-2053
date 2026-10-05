#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long refuses = 0;

    for (int i = 0; i < n; i++) {
        string nom;
        long long w, h, px, py, ox, oy, sx, sy, angle;
        cin >> nom >> w >> h >> px >> py >> ox >> oy >> sx >> sy >> angle;

        long long mod90 = ((angle % 90) + 90) % 90;
        if (mod90 != 0) {
            cout << nom << " ANGLE REFUSE\n";
            refuses++;
            continue;
        }

        long long norm = ((angle % 360) + 360) % 360;
        long long c, s;
        if (norm == 0)        { c = 1;  s = 0;  }
        else if (norm == 90)  { c = 0;  s = 1;  }
        else if (norm == 180) { c = -1; s = 0;  }
        else                  { c = 0;  s = -1; }

        long long lx[4] = {0, w, w, 0};
        long long ly[4] = {0, 0, h, h};
        long long wx[4], wy[4];
        long long minx = 0, miny = 0, maxx = 0, maxy = 0;

        for (int k = 0; k < 4; k++) {
            long long ax = (lx[k] - ox) * sx;
            long long ay = (ly[k] - oy) * sy;
            long long rx = ax * c - ay * s;
            long long ry = ax * s + ay * c;
            wx[k] = px + rx;
            wy[k] = py + ry;
            if (k == 0) { minx = maxx = wx[k]; miny = maxy = wy[k]; }
            else {
                minx = min(minx, wx[k]); maxx = max(maxx, wx[k]);
                miny = min(miny, wy[k]); maxy = max(maxy, wy[k]);
            }
        }

        cout << nom << " COINS " << wx[0] << " " << wy[0] << " "
             << wx[1] << " " << wy[1] << " " << wx[2] << " " << wy[2] << " "
             << wx[3] << " " << wy[3] << "\n";
        cout << nom << " BOITE " << minx << " " << miny << " " << maxx << " " << maxy << "\n";
    }

    cout << "REFUSES " << refuses << "\n";
    return 0;
}
