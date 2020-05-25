#pragma once

#include "BUILD_ORDER.h"

class VulkanInstance;

class VulkanPhysicalDevice
{
public:
	~VulkanPhysicalDevice();
	VkPhysicalDevice& GetPhysicalDevice();
	QueueFamilyIndices& GetQueueFamilyIndices();
	VkPhysicalDeviceProperties& GetPhysicalDeviceProperties();
	VkPhysicalDeviceFeatures& GetPhysicalDeviceFeatures();
	VkPhysicalDeviceMemoryProperties& GetPhysicalDeviceMemoryProperties();


	static VulkanPhysicalDevice* GetPhysicalDevice(VulkanInstance* instance);
private:
	VulkanPhysicalDevice(VulkanInstance* instance, VkPhysicalDevice device, QueueFamilyIndices indices);
	static std::vector<VkPhysicalDevice> GetAvailablePhysicalDevices(VulkanInstance* instance);
	static bool PhysicalDeviceSupported(VkPhysicalDevice& device, QueueFamilyIndices& familyIndices);
	static bool SupportsQueueFamily(VkPhysicalDevice& device, QueueFamilyIndices& familyIndices);
	VulkanInstance* instance;
	VkPhysicalDevice device;
	QueueFamilyIndices familyIndices;
	VkPhysicalDeviceProperties physicalDeviceProperties;
	VkPhysicalDeviceFeatures physicalDeviceFeatures;
	VkPhysicalDeviceMemoryProperties physicalDeviceMemoryProperties;
};
