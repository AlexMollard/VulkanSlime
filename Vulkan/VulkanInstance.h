#pragma once
#include "BUILD_ORDER.h"

class VulkanInstance
{
public:
	VulkanInstance(VulkanConfiguration& vulkanConfig);
	~VulkanInstance();

	VkInstance& GetInstance();

private:
	VkInstance instance;
	std::vector<const char*> layers;
	std::vector<const char*> extensions;
};