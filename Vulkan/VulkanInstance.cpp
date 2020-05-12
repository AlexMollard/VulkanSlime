#include "VulkanInstance.h"

VulkanInstance::VulkanInstance(VulkanConfiguration& vulkanConfig)
{
	VkApplicationInfo applicationInfo = Initializers::ApplicationInfo(vulkanConfig);

	VkInstanceCreateInfo instance_info = Initializers::InstanceCreateInfo(applicationInfo, layers, extensions);

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
