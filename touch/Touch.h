#pragma once

#include <aidl/vendor/xiaomi/hw/touchfeature/BnTouchFeature.h>

namespace aidl {
namespace vendor {
namespace xiaomi {
namespace hw {
namespace touchfeature {

class Touch : public BnTouchFeature {
public:
    ndk::ScopedAStatus setTouchMode(int displayId, int mode, int value) override;
    ndk::ScopedAStatus setEdgeMode(int displayId, int mode, const std::vector<int32_t>& value, int len) override;
};

}  // namespace touchfeature
}  // namespace hw
}  // namespace xiaomi
}  // namespace vendor
}  // namespace aidl
