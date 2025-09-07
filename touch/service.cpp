#define LOG_TAG "XiaomiTouchService"

#include <android-base/logging.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include "Touch.h"

using aidl::vendor::xiaomi::hw::touchfeature::Touch;

int main() {
    ABinderProcess_setThreadPoolMaxThreadCount(0);
    std::shared_ptr<Touch> touch = ndk::SharedRefBase::make<Touch>();
    const std::string instance = std::string() + Touch::descriptor + "/default";

    binder_status_t status = AServiceManager_addService(touch->asBinder().get(), instance.c_str());
    CHECK(status == STATUS_OK);
    LOG(INFO) << "Xiaomi Touch HAL service is ready.";

    ABinderProcess_joinThreadPool();
    return EXIT_FAILURE; // Should not be reached
}
