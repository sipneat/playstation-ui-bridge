# react-native-playstation-ui-bridge

A small, deliberately minimal React Native **C++ Cxx TurboModule** that demonstrates
how to push work off the JavaScript thread and into shared native code — the same
pattern used to bridge a UI framework to a native platform runtime.

The feature itself is intentionally trivial (uppercase a string and tag it) so the
focus stays on the **plumbing**: how a single native implementation written in
portable C++ is exposed to JavaScript/TypeScript across iOS and Android, with a
pure-JS fallback for web.

## Why this exists

React Native runs your app logic in a JavaScript engine (Hermes) on a single thread.
That's ideal for UI and product code, but it can't do two things:

1. **Reach the platform.** The JS engine is sandboxed — hardware, native SDKs, secure
   storage, sensors, and vendor runtimes are only reachable through native code.
2. **Do heavy work without janking the UI.** CPU-intensive work on the JS thread drops
   frames. Native code can run it on another thread and return only the result.

## Architecture

This is a **Cxx TurboModule** (New Architecture). The native logic is written **once**
in portable C++ and shared by both platforms — no per-platform Kotlin/Swift
reimplementation.

```
 JS / TS call
      │
      ▼
 src/index.tsx  ─────────────►  public API surface
      │
      ├─ (native)  src/processEngineState.native.tsx ─┐
      │                                                │  crosses the bridge
      └─ (web)     src/processEngineState.tsx          │
                                                       ▼
 src/NativePlaystationUiBridge.ts  ── codegen ──►  NativePlaystationUiBridgeCxxSpec (generated C++)
                                                       │
                                                       ▼
                              cpp/PlaystationUiBridgeImpl.{h,cpp}   ← the real native engine
                                                       ▲
                    registered by ios/OnLoad.mm  and  android/CMakeLists.txt
```

Key takeaway: **`cpp/` is the native side; `src/` is the JS side.** The `src/` TS does
not duplicate the C++ logic — it *declares the contract* (spec), *forwards* to native
(`.native.tsx`), and *provides a web fallback* (`.tsx`).

### Platform behavior

- **iOS / Android:** Metro picks `processEngineState.native.tsx`, which calls into the
  compiled **C++** in `cpp/PlaystationUiBridgeImpl.cpp`. The transformation runs in
  native code, off the JS thread.
- **Web:** there is no native binary, so Vite picks `processEngineState.tsx` — the pure
  **JavaScript** fallback that runs in the browser engine.

## Project layout

```
cpp/
  PlaystationUiBridgeImpl.h      # C++ class declaration (extends the codegen spec)
  PlaystationUiBridgeImpl.cpp    # C++ implementation (facebook::react)
src/
  NativePlaystationUiBridge.ts   # TurboModule spec (codegen source of truth)
  processEngineState.native.tsx  # native shim (iOS/Android)
  processEngineState.tsx         # web fallback (pure JS)
  index.tsx                      # public API
example/                         # example app (native + Vite web) used to run it
```

## Running it

Dependencies use Yarn workspaces; the runnable app lives in `example/`.

```sh
# from the repo root
yarn install
yarn prepare          # runs codegen + builds the library into lib/
yarn typecheck        # TS is type-checked against the native spec
yarn lint

# run the example app
yarn example android
cd example/ios && pod install && cd - && yarn example ios
yarn example web
```

---

Made with [create-react-native-library](https://github.com/callstack/react-native-builder-bob)
