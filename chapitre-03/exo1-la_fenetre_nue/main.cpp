#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkWindowEvent.h"

using namespace nkentseu;

NKENTSEU_DEFINE_APP_DATA(([]() {
    NkAppData d{};
    d.appName = "Fenetre nue";
    d.appVersion = "1.0.0";
    return d;
})());

int nkmain(const NkEntryState &state) {
    NkWindow window;
    NkWindowConfig cfg;
    cfg.title = "Fenetre nue";
    cfg.width = 800;
    cfg.height = 600;
    if (!window.Create(cfg))
        return -1;

    bool running = true;
    auto &events = NkEvents();
    events.AddEventCallback<NkWindowCloseEvent>([&](NkWindowCloseEvent *) { running = false; });

    while (running && window.IsOpen()) {
        while (NkEvent *ev = events.PollEvent()) {
            (void)ev;
        }
    }

    window.Close();
    return 0;
}
