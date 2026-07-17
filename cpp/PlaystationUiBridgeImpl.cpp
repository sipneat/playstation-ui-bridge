#include "PlaystationUiBridgeImpl.h"

namespace facebook::react {

PlaystationUiBridgeImpl::PlaystationUiBridgeImpl(
  std::shared_ptr<CallInvoker> jsInvoker
)
  : NativePlaystationUiBridgeCxxSpec(std::move(jsInvoker)) {}

double PlaystationUiBridgeImpl::multiply(
  jsi::Runtime& rt,
  double a,
  double b
) {
  return a * b;
}

}
