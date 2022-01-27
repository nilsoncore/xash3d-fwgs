#pragma once

#include "vk_rtx.h"
#include "vk_const.h"
#include "shaders/ray_interop.h"

typedef struct vk_ray_resources_s {
	uint32_t width, height;

	struct {
		VkAccelerationStructureKHR tlas;

		vk_buffer_region_t ubo;
		vk_buffer_region_t kusochki, indices, vertices;
		VkDescriptorImageInfo *all_textures; // [MAX_TEXTURES]

		vk_buffer_region_t lights;
		vk_buffer_region_t light_clusters;
	} scene;

#define X(index, name, ...) VkImageView name;
	RAY_PRIMARY_OUTPUTS(X)
	RAY_LIGHT_DIRECT_OUTPUTS(X)
	X(-1, denoised)
#undef X
} vk_ray_resources_t;

