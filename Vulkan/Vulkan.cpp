#include "BUILD_ORDER.h"

VulkanInstance* instance;

int main()
{
    VulkanConfiguration vulkanConfig;
    vulkanConfig.applicationName = "Vulkan Slime";
    vulkanConfig.applicationVersion = VK_MAKE_VERSION(1, 0, 0);

    instance = new VulkanInstance(vulkanConfig);

    delete instance;

    return 0;
}
