#define LOG_TAG "XiaomiTouchService"

#include "Touch.h"
#include <android-base/logging.h>
#include <fstream>

// Confirmed DT2W path for sm8450-common
#define TOUCH_DOUBLE_TAP_NODE "/sys/devices/platform/goodix_ts.0/goodix_ts_double_tap"
#define DOUBLE_TAP_TO_WAKE_MODE 14

namespace aidl {
namespace vendor {
namespace xiaomi {
namespace hw {
namespace touchfeature {

ndk::ScopedAStatus Touch::setTouchMode(int, int mode, int value) {
    LOG(DEBUG) << "setTouchMode: mode=" << mode << ", value=" << value;

    if (mode == DOUBLE_TAP_TO_WAKE_MODE) {
        std::ofstream file(TOUCH_DOUBLE_TAP_NODE);
        if (!file.is_open()) {
            LOG(ERROR) << "Failed to open " << TOUCH_DOUBLE_TAP_NODE;
            return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
        }
        file << (value ? "1" : "0");
        LOG(INFO) << "Set Double Tap to Wake to " << (value ? "1" : "0");
    }

    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus Touch::setEdgeMode(int, int, const std::vector<int32_t>&, int) {
    // This is required by the interface but not needed for DT2W.
    return ndk::ScopedAStatus::ok();
}

}  // namespace touchfeature
}  // namespace hw
}  // namespace xiaomi
}  // namespace vendor
}  // namespace aidl
