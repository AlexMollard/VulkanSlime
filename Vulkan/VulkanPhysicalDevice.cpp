#include "VulkanPhysicalDevice.h"

VulkanPhysicalDevice::~VulkanPhysicalDevice()
{
}

VkPhysicalDevice& VulkanPhysicalDevice::GetPhysicalDevice()
{
	return device;
}

QueueFamilyIndices& VulkanPhysicalDevice::GetQueueFamilyIndices()
{
	return familyIndices;
}

VkPhysicalDeviceProperties& VulkanPhysicalDevice::GetPhysicalDeviceProperties()
{
	return physicalDeviceProperties;
}

VkPhysicalDeviceFeatures& VulkanPhysicalDevice::GetPhysicalDeviceFeatures()
{
	return physicalDeviceFeatures;
}

VkPhysicalDeviceMemoryProperties& VulkanPhysicalDevice::GetPhysicalDeviceMemoryProperties()
{
	return physicalDeviceMemoryProperties;
}

VulkanPhysicalDevice* VulkanPhysicalDevice::GetPhysicalDevice(VulkanInstance* instance)
{
	std::vector<VkPhysicalDevice> devices = GetAvailablePhysicalDevices(instance);

	VkPhysicalDevice secondaryDevice = VK_NULL_HANDLE;
	QueueFamilyIndices secondaryQueue;

	for (auto& device : devices)
	{
		QueueFamilyIndices queueFamily;
		if (PhysicalDeviceSupported(device,queueFamily))
		{
			VkPhysicalDeviceProperties physicalDeviceProperties;
			vkGetPhysicalDeviceProperties
			(
				device,
				&physicalDeviceProperties
			);

			if (physicalDeviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
			{
				return new VulkanPhysicalDevice(instance,device,queueFamily);
			}
			else
			{
				secondaryDevice = device;
				secondaryQueue = queueFamily;
			}
		}
	}

	if (secondaryDevice == VK_NULL_HANDLE) return nullptr;
	else
		return new VulkanPhysicalDevice(instance,secondaryDevice,secondaryQueue);
}

VulkanPhysicalDevice::VulkanPhysicalDevice(VulkanInstance* instance, VkPhysicalDevice device, QueueFamilyIndices indices)
{
	this->instance = instance;
	this->device = device;
	this->familyIndices = indices;

	vkGetPhysicalDeviceProperties
	(
		this->device,
		&physicalDeviceProperties
	);

	vkGetPhysicalDeviceFeatures
	(
		this->device,
		&physicalDeviceFeatures
	);

	vkGetPhysicalDeviceMemoryProperties
	(
		this->device,
		&physicalDeviceMemoryProperties
	);
}

std::vector<VkPhysicalDevice> VulkanPhysicalDevice::GetAvailablePhysicalDevices(VulkanInstance* instance)
{
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices
	(
		instance->GetInstance(),
		&deviceCount,
		nullptr
	);

	std::vector<VkPhysicalDevice> devices(deviceCount);

	vkEnumeratePhysicalDevices
	(
		instance->GetInstance(),
		&deviceCount,
		devices.data()
	);

	return devices;
}

bool VulkanPhysicalDevice::PhysicalDeviceSupported(VkPhysicalDevice& device, QueueFamilyIndices& familyIndices)
{
	bool supportsQueueFamily = SupportsQueueFamily(device,familyIndices);

	return supportsQueueFamily;
}

bool VulkanPhysicalDevice::SupportsQueueFamily(VkPhysicalDevice& device, QueueFamilyIndices& familyIndices)
{
	uint32_t queueFamilyCount = 0;
	
	vkGetPhysicalDeviceQueueFamilyProperties
	(
		device,
		&queueFamilyCount,
		nullptr
	);

	std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);

	vkGetPhysicalDeviceQueueFamilyProperties
	(
		device,
		&queueFamilyCount,
		queueFamilies.data()
	);

	uint32_t i = 0;
	for (auto& queueFamily : queueFamilies)
	{
		if (queueFamily.queueCount > 0)
		{
			if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
				familyIndices.graphicsIndices = i;
			if (queueFamily.queueFlags & VK_QUEUE_COMPUTE_BIT)
				familyIndices.computeIndices = i;
		}
		if (familyIndices.graphicsIndices < UINT32_MAX && familyIndices.computeIndices < UINT32_MAX) return true;
		i++;
	}

	return false;
}
