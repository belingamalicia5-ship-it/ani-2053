#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long totalPoints = 0, totalSegments = 0, totalTriangles = 0, refuses = 0;

    for (int i = 0; i < n; i++) {
        string type;
        long long s;
        cin >> type >> s;

        if (type == "POINTS") {
            cout << type << " " << s << " " << s << " POINTS 0\n";
            totalPoints += s;
        } else if (type == "LINES") {
            long long seg = s / 2, rest = s % 2;
            cout << type << " " << s << " " << seg << " SEGMENTS " << rest << "\n";
            totalSegments += seg;
        } else if (type == "LINE_STRIP") {
            long long seg, rest;
            if (s >= 2) { seg = s - 1; rest = 0; } else { seg = 0; rest = s; }
            cout << type << " " << s << " " << seg << " SEGMENTS " << rest << "\n";
            totalSegments += seg;
        } else if (type == "TRIANGLES") {
            long long tri = s / 3, rest = s % 3;
            cout << type << " " << s << " " << tri << " TRIANGLES " << rest << "\n";
            totalTriangles += tri;
        } else if (type == "TRIANGLE_STRIP" || type == "TRIANGLE_FAN") {
            long long tri, rest;
            if (s >= 3) { tri = s - 2; rest = 0; } else { tri = 0; rest = s; }
            cout << type << " " << s << " " << tri << " TRIANGLES " << rest << "\n";
            totalTriangles += tri;
        } else {
            cout << type << " " << s << " REFUSE\n";
            refuses++;
        }
    }

    cout << "POINTS " << totalPoints << "\n";
    cout << "SEGMENTS " << totalSegments << "\n";
    cout << "TRIANGLES " << totalTriangles << "\n";
    cout << "REFUSES " << refuses << "\n";
    return 0;
}
