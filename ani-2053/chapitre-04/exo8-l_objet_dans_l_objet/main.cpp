#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long x, y, angle, scale;
    int level;
};

int main() {
    int n;
    cin >> n;
    map<string, Node> world;
    int maxLevel = 0;
    vector<tuple<string, long long, long long, long long, long long>> order;

    for (int i = 0; i < n; i++) {
        string nom, parent;
        long long tx, ty, angle, echelle;
        cin >> nom >> parent >> tx >> ty >> angle >> echelle;

        long long wx, wy, wangle, wscale;
        int level;

        if (parent == "-") {
            wx = tx; wy = ty;
            wangle = ((angle % 360) + 360) % 360;
            wscale = echelle;
            level = 1;
        } else {
            Node &p = world[parent];
            long long ax = tx * p.scale;
            long long ay = ty * p.scale;
            long long norm = ((p.angle % 360) + 360) % 360;
            long long c, s;
            if (norm == 0)        { c = 1;  s = 0;  }
            else if (norm == 90)  { c = 0;  s = 1;  }
            else if (norm == 180) { c = -1; s = 0;  }
            else                  { c = 0;  s = -1; }
            long long rx = ax * c - ay * s;
            long long ry = ax * s + ay * c;
            wx = p.x + rx;
            wy = p.y + ry;
            wangle = ((p.angle + angle) % 360 + 360) % 360;
            wscale = p.scale * echelle;
            level = p.level + 1;
        }

        world[nom] = {wx, wy, wangle, wscale, level};
        maxLevel = max(maxLevel, level);
        order.push_back({nom, wx, wy, wangle, wscale});
    }

    for (auto &[nom, x, y, a, e] : order) {
        cout << nom << " " << x << " " << y << " " << a << " " << e << "\n";
    }
    cout << "PROFONDEUR " << maxLevel << "\n";
    return 0;
}
