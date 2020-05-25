#pragma once

#include "BUILD_ORDER.h"

struct QueueFamilyIndices
{
	uint32_t graphicsIndices = UINT32_MAX;
	uint32_t computeIndices = UINT32_MAX;
};