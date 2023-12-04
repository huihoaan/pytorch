#include <ATen/detail/PrivateUse1HooksInterface.h>

#include <c10/util/CallOnce.h>

#include <memory>

namespace at {
namespace detail {

const PrivateUse1HooksInterface& getPrivateUse1Hooks() {
  static PrivateUse1HooksInterface* privateuse1_hooks = nullptr;
  static c10::once_flag once;
  c10::call_once(once, [] {
    privateuse1_hooks =
        PrivateUse1HooksRegistry()->Create("PrivateUse1Hooks", PrivateUse1HooksArgs{}).release();
    if (!privateuse1_hooks) {
      privateuse1_hooks = new PrivateUse1HooksInterface();
    }
  });
  return *privateuse1_hooks;
}
} // namespace detail

C10_DEFINE_REGISTRY(PrivateUse1HooksRegistry, PrivateUse1HooksInterface, PrivateUse1HooksArgs)

} // namespace at
