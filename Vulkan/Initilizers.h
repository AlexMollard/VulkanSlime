#pragma once
#include "BUILD_ORDER.h"

namespace Initilizers
{
	VkApplicationInfo ApplicationInfo(VulkanConfiguration& config);

	VkInstanceCreateInfo InstanceCreateInfo(VkApplicationInfo& app_info, std::vector<const char*>& layers, std::vector<const char*>& extensions);

	VkDeviceQueueCreateInfo DeviceQueueCreate(uint32_t queueFamilyIndices, float& priority);

	VkDeviceCreateInfo DeviceCreateInfo(std::vector<VkDeviceQueueCreateInfo>& queueCreateInfo, VkPhysicalDeviceFeatures& deviceFeatures);
}