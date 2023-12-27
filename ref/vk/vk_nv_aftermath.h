#pragma once

#include "vk_module.h"

#include "xash3d_types.h"

#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>

extern RVkModule g_module_nv_aftermath;

void R_Vk_NV_CheckpointF(VkCommandBuffer cmdbuf, const char *fmt, ...);
void R_Vk_NV_Checkpoint_Dump(void);

#define DEBUG_NV_CHECKPOINTF(cmdbuf, fmt, ...) \
	do { \
		if (vk_core.nv_checkpoint) { \
			R_Vk_NV_CheckpointF(cmdbuf, fmt, ##__VA_ARGS__); \
		} \
	} while(0)

#define DEBUG_NV_CHECKPOINT_DUMP() \
	do { \
		if (vk_core.nv_checkpoint) { \
			R_Vk_NV_Checkpoint_Dump(); \
		} \
	} while(0)
