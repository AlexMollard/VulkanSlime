#include "VulkanDevice.h"

VulkanDevice::VulkanDevice(VulkanInstance* instance, VulkanPhysicalDevice* physicalDevice)
{
	this->instance = instance;
	this->physicalDevice = physicalDevice;

	std::vector<VkDeviceQueueCreateInfo> queueCreateInfo;


	float priority = 1.0f;
	queueCreateInfo.push_back(Initilizers::DeviceQueueCreate(this->physicalDevice->GetQueueFamilyIndices().computeIndices, priority));

	VkDeviceCreateInfo createInfo = Initilizers::DeviceCreateInfo(queueCreateInfo, physicalDevice->GetPhysicalDeviceFeatures());

	ErrorCheck(vkCreateDevice
	(
		physicalDevice->GetPhysicalDevice(),
		&createInfo,
		nullptr,
		&device
	));

	vkGetDeviceQueue
	(
		device,
		physicalDevice->GetQueueFamilyIndices().computeIndices,
		0,
		&computeQueue
	);
}

VulkanInstance* VulkanDevice::GetInstance()
{
	return instance;
}

VkDevice* VulkanDevice::GetDevice()
{
	return &device;
}

VkQueue* VulkanDevice::GetQueue()
{
	return &computeQueue;
}

VulkanDevice::~VulkanDevice()
{
	vkDestroyDevice(device, nullptr);
}
