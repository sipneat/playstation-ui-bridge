#import <Foundation/Foundation.h>
#import "PlaystationUiBridgeImpl.h"
#import <ReactCommon/CxxTurboModuleUtils.h>

@interface PlaystationUiBridgeOnLoad : NSObject
@end

@implementation PlaystationUiBridgeOnLoad

using namespace facebook::react;

+ (void)load
{
  registerCxxModuleToGlobalModuleMap(
    std::string(PlaystationUiBridgeImpl::kModuleName),
    [](std::shared_ptr<CallInvoker> jsInvoker) {
      return std::make_shared<PlaystationUiBridgeImpl>(jsInvoker);
    }
  );
}

@end
