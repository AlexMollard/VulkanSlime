#include "BUILD_ORDER.h"

VulkanInstance* instance;
VulkanPhysicalDevice* physicalDevice;
VulkanDevice* device;

int main()
{
    VulkanConfiguration vulkanConfig;
    vulkanConfig.applicationName = "Vulkan Slime";
    vulkanConfig.applicationVersion = VK_MAKE_VERSION(1, 0, 0);

    instance = new VulkanInstance(vulkanConfig);
    physicalDevice = VulkanPhysicalDevice::GetPhysicalDevice(instance);
    device = new VulkanDevice(instance, physicalDevice);


    std::cout << "Your GPU: " << physicalDevice->GetPhysicalDeviceProperties().deviceName << std::endl;
    delete device;
    delete physicalDevice;
    delete instance;

    return 0;
}
