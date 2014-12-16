#define LOG_TAG "su"

#include <binder/AppOpsManager.h>
#include <utils/Log.h>

using namespace android;

extern "C" {

int check_appops(int uid, const char *pkgName) {
    ALOGD("Checking whether app [uid:%d, pkgName: %s] is allowed to be root", uid, pkgName);
    AppOpsManager *ops = new AppOpsManager();

    int mode = ops->noteOp(61, uid, String16(pkgName));

    switch (mode) {
        case AppOpsManager::MODE_ALLOWED:
          ALOGD("Privillege elevation allowed by appops");
          return 0;
        default:
          ALOGD("Privillege elevation denied by appops");
          return 1;
    }

    free(ops);
}

}
