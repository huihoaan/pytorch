#pragma once

#include <ATen/core/Generator.h>
#include <c10/core/Device.h>
#include <c10/util/Exception.h>
namespace at {

struct TORCH_API PrivateUse1HooksInterface {
  virtual ~PrivateUse1HooksInterface() = default;
  virtual void lazyInitPrivateUse1() const {}
  virtual const at::Generator& getDefaultGenerator(c10::DeviceIndex device_index) const {
    TORCH_CHECK_NOT_IMPLEMENTED(
        false,
        "You should register `PrivateUse1HooksInterface` for PrivateUse1 before call `getDefaultGenerator`.");
  }

  virtual at::Device getDeviceFromPtr(void* data) const {
    TORCH_CHECK_NOT_IMPLEMENTED(
        false,
        "You should register `PrivateUse1HooksInterface` for PrivateUse1 before call `getDeviceFromPtr`.");
  }
};

struct TORCH_API PrivateUse1HooksArgs {};

C10_DECLARE_REGISTRY(PrivateUse1HooksRegistry, PrivateUse1HooksInterface, PrivateUse1HooksArgs);
#define REGISTER_PRIVATEUSE1_HOOKS(clsname) \
  C10_REGISTER_CLASS(PrivateUse1HooksRegistry, clsname, clsname)

namespace detail {
TORCH_API const PrivateUse1HooksInterface& getPrivateUse1Hooks();
} // namespace detail

}
