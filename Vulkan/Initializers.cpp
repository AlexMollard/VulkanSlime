#include "Initilizers.h"

VkApplicationInfo Initilizers::ApplicationInfo(VulkanConfiguration& config)
{
	VkApplicationInfo info = {};
	info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	info.pApplicationName = config.applicationName;
	info.pEngineName = config.engineName;
	info.applicationVersion = config.applicationVersion;
	info.engineVersion = config.engineVersion;
	info.apiVersion = config.api_version;

	return info;
}

VkInstanceCreateInfo Initilizers::InstanceCreateInfo(VkApplicationInfo& app_info, std::vector<const char*>& layers, std::vector<const char*>& extensions)
{
	VkInstanceCreateInfo info = {};
	info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	info.pApplicationInfo = &app_info;
	info.enabledExtensionCount = extensions.size();
	info.enabledLayerCount = layers.size();
	info.ppEnabledExtensionNames = extensions.data();
	info.ppEnabledLayerNames = layers.data();

	return info;
}

VkDeviceQueueCreateInfo Initilizers::DeviceQueueCreate(uint32_t queueFamilyIndices, float& priority)
{
	VkDeviceQueueCreateInfo queueCreateInfo{};
	queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	queueCreateInfo.queueFamilyIndex = queueFamilyIndices;
	queueCreateInfo.queueCount = 1;
	queueCreateInfo.pQueuePriorities = &priority;

	return queueCreateInfo;
}

VkDeviceCreateInfo Initilizers::DeviceCreateInfo(std::vector<VkDeviceQueueCreateInfo>& queueCreateInfo, VkPhysicalDeviceFeatures& deviceFeatures)
{
	VkDeviceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	createInfo.pQueueCreateInfos = queueCreateInfo.data();
	createInfo.queueCreateInfoCount = (uint32_t)queueCreateInfo.size();
	createInfo.pEnabledFeatures = &deviceFeatures;

	return createInfo;
}
