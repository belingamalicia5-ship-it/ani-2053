#include <bits/stdc++.h>
using namespace std;

int main() {
    long long v, n;
    cin >> v >> n;

    bool spacePressed = false, leftPressed = false, rightPressed = false;
    long long xe = 0, xi = 0;
    long long sautsE = 0, sautsI = 0, manques = 0;

    for (long long img = 1; img <= n; img++) {
        long long k;
        cin >> k;
        long long plusSpaceThisImage = 0;

        for (long long j = 0; j < k; j++) {
            string ev;
            cin >> ev;
            bool isPress = (ev[0] == '+');
            string name = ev.substr(1);

            if (name == "SPACE") {
                if (isPress) {
                    sautsE++;
                    plusSpaceThisImage++;
                    spacePressed = true;
                } else {
                    spacePressed = false;
                }
            } else if (name == "LEFT") {
                if (isPress) { leftPressed = true; xe -= v; }
                else { leftPressed = false; }
            } else if (name == "RIGHT") {
                if (isPress) { rightPressed = true; xe += v; }
                else { rightPressed = false; }
            }
        }

        if (spacePressed) sautsI++;
        if (rightPressed) xi += v;
        if (leftPressed) xi -= v;
        if (plusSpaceThisImage > 0 && !spacePressed) manques += plusSpaceThisImage;

        cout << img << " " << xe << " " << xi << "\n";
    }

    cout << "SAUTS EVENEMENTS " << sautsE << "\n";
    cout << "SAUTS INTERROGATION " << sautsI << "\n";
    cout << "MANQUES " << manques << "\n";
    return 0;
}
