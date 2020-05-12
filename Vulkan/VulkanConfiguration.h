#pragma once

#include "BUILD_ORDER.h"

struct VulkanConfiguration
{
	const char* applicationName = "";
	uint32_t applicationVersion = VK_MAKE_VERSION(0,0,0);
	const char* engineName = "VulkanSlime";
	const uint32_t engineVersion = VK_MAKE_VERSION(0,0,0);
	const uint32_t api_version = VK_MAKE_VERSION(1,1,114);

};