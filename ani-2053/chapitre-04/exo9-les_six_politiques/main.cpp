#include <bits/stdc++.h>
using namespace std;

long long roundDiv(long long a, long long b) {
    return (2 * a + b) / (2 * b);
}

int main() {
    long long RW, RH, AW, AH, W, H;
    cin >> RW >> RH >> AW >> AH >> W >> H;

    bool hasRef = (RW != 0 && RH != 0);
    long long bandes = 0;

    auto emit = [&](const string &name, long long vx, long long vy, long long vw, long long vh, long long mw, long long mh) {
        cout << name << " " << vx << " " << vy << " " << vw << " " << vh << " " << mw << " " << mh << "\n";
        if (vw < W || vh < H) bandes++;
    };

    emit("FOLLOW_WINDOW", 0, 0, W, H, W, H);

    if (!hasRef) emit("STRETCH", 0, 0, W, H, W, H);
    else emit("STRETCH", 0, 0, W, H, RW, RH);

    long long flVx, flVy, flVw, flVh;
    if (!hasRef) {
        flVx = 0; flVy = 0; flVw = W; flVh = H;
        emit("FIT_LETTERBOX", flVx, flVy, flVw, flVh, W, H);
    } else {
        if (W * RH <= H * RW) {
            flVw = W;
            flVh = roundDiv(RH * W, RW);
        } else {
            flVh = H;
            flVw = roundDiv(RW * H, RH);
        }
        flVx = (W - flVw) / 2;
        flVy = (H - flVh) / 2;
        emit("FIT_LETTERBOX", flVx, flVy, flVw, flVh, RW, RH);
    }

    if (!hasRef) {
        emit("INTEGER_SCALE", 0, 0, W, H, W, H);
    } else if (W >= RW && H >= RH) {
        long long k = min(W / RW, H / RH);
        long long vw = RW * k, vh = RH * k;
        long long vx = (W - vw) / 2, vy = (H - vh) / 2;
        emit("INTEGER_SCALE", vx, vy, vw, vh, RW, RH);
    } else {
        emit("INTEGER_SCALE", flVx, flVy, flVw, flVh, RW, RH);
    }

    if (!hasRef) {
        emit("FIT_CROP", 0, 0, W, H, W, H);
    } else {
        long long mw, mh;
        if (W * RH > H * RW) {
            mw = RW;
            mh = roundDiv(RW * H, W);
        } else {
            mw = roundDiv(RH * W, H);
            mh = RH;
        }
        emit("FIT_CROP", 0, 0, W, H, mw, mh);
    }

    emit("MANUAL", 0, 0, AW, AH, AW, AH);

    bool deformation = hasRef && (W * RH != H * RW);

    cout << "BANDES " << bandes << "\n";
    cout << "DEFORMATION " << (deformation ? "OUI" : "NON") << "\n";

    return 0;
}
