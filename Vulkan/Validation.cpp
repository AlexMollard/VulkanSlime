#include "Validation.h"

void ErrorCheck(VkResult res)
{
	if (res != VK_SUCCESS)
	{
		std::cout << "Error" << std::endl;
		assert(0 && "There was a error");
	}
}
