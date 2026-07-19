#pragma once

#include <PlaystationUiBridgeSpecJSI.h>
#include <memory>
#include <string>

namespace facebook::react
{

  class PlaystationUiBridgeImpl
      : public NativePlaystationUiBridgeCxxSpec<PlaystationUiBridgeImpl>
  {
  public:
    PlaystationUiBridgeImpl(std::shared_ptr<CallInvoker> jsInvoker);

    std::string processEngineState(jsi::Runtime &rt, std::string payload);
  };

}
