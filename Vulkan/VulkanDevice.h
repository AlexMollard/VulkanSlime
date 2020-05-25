#pragma once

#include "BUILD_ORDER.h"

class VulkanPhysicalDevice;

class VulkanDevice
{
public:
	VulkanDevice(VulkanInstance* instance, VulkanPhysicalDevice* physicalDevice);
	VulkanInstance* GetInstance();
	VkDevice* GetDevice();
	VkQueue* GetQueue();
	~VulkanDevice();
private:
	VulkanInstance* instance;
	VkDevice device;
	VulkanPhysicalDevice* physicalDevice;
	VkQueue computeQueue;
};