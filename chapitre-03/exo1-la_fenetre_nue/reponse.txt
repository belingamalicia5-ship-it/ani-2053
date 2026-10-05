# La fenêtre nue — ani-2053-c3-exo1

## Programme (35 lignes)

```cpp
 1  #include "NKWindow/NKWindow.h"
 2  #include "NKWindow/NKMain.h"
 3  #include "NKEvent/NkWindowEvent.h"
 4
 5  using namespace nkentseu;
 6
 7  NKENTSEU_DEFINE_APP_DATA(([]() {
 8      NkAppData d{};
 9      d.appName = "Fenetre nue";
10      d.appVersion = "1.0.0";
11      return d;
12  })());
13
14  int nkmain(const NkEntryState &state) {
15      NkWindow window;
16      NkWindowConfig cfg;
17      cfg.title = "Fenetre nue";
18      cfg.width = 800;
19      cfg.height = 600;
20      if (!window.Create(cfg))
21          return -1;
22
23      bool running = true;
24      auto &events = NkEvents();
25      events.AddEventCallback<NkWindowCloseEvent>([&](NkWindowCloseEvent *) { running = false; });
26
27      while (running && window.IsOpen()) {
28          while (NkEvent *ev = events.PollEvent()) {
29              (void)ev;
30          }
31      }
32
33      window.Close();
34      return 0;
35  }
```

## Ligne par ligne

| Lignes | Contenu | Chapitre |
|---|---|---|
| 1-3 | Inclusions NKWindow, NKMain, NkWindowEvent | § 4.2, en-têtes après l'extrait `main.cpp:7-11` |
| 7-12 | `NKENTSEU_DEFINE_APP_DATA(...)` | § 0.6, extrait `NkCanvasDemo.cpp:29-33` |
| 14 | `int nkmain(const NkEntryState &state)` | § 0.6, extrait `NkCanvasDemo.cpp:36` et suivants |
| 15-19 | `NkWindow`, `NkWindowConfig`, `title`/`width`/`height` | § 1.2, extrait `NKGuiDemo/main.cpp:243-251` |
| 20-21 | `if (!window.Create(cfg)) return -1;` | § 1.2 et § 4.2 |
| 23-25 | `NkEvents()` et callback `NkWindowCloseEvent` | § 1.3, extrait `main.cpp:326-331` |
| 27-31 | Boucle `while (running && window.IsOpen())` + `PollEvent()` | § 1.3 ; boucle identique en § 2.14.3, `NkCanvasDemo.cpp:96` |
| 33 | `window.Close();` | § 2.3 et § 2.14.2, `NkCanvasDemo.cpp:75` |
| 34 | `return 0;` | § 0.6 |
