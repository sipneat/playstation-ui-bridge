#include "PlaystationUiBridgeImpl.h"
#include <string>
#include <algorithm>

namespace facebook::react
{

  PlaystationUiBridgeImpl::PlaystationUiBridgeImpl(
      std::shared_ptr<CallInvoker> jsInvoker)
      : NativePlaystationUiBridgeCxxSpec(std::move(jsInvoker)) {}

  std::string PlaystationUiBridgeImpl::processEngineState(jsi::Runtime &rt, std::string payload)
  {
    std::transform(payload.begin(), payload.end(), payload.begin(), [](unsigned char c)
                   { return std::toupper(c); });
    return "[SIE_RUNTIME_OK] " + payload;
  }

}
