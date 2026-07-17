#pragma once

#include <PlaystationUiBridgeSpecJSI.h>

#include <memory>

namespace facebook::react {

class PlaystationUiBridgeImpl
  : public NativePlaystationUiBridgeCxxSpec<PlaystationUiBridgeImpl> {
public:
  PlaystationUiBridgeImpl(std::shared_ptr<CallInvoker> jsInvoker);

  double multiply(jsi::Runtime& rt, double a, double b);
};

}
