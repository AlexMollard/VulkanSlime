#include "VulkanInstance.h"

VulkanInstance::VulkanInstance(VulkanConfiguration& vulkanConfig)
{
	VkApplicationInfo applicationInfo = Initilizers::ApplicationInfo(vulkanConfig);

	VkInstanceCreateInfo instance_info = Initilizers::InstanceCreateInfo(applicationInfo, layers, extensions);

	ErrorCheck(vkCreateInstance(&instance_info, NULL, &instance));
}

VulkanInstance::~VulkanInstance()
{
	vkDestroyInstance(instance, NULL);
}

VkInstance& VulkanInstance::GetInstance()
{
	return instance;
}
