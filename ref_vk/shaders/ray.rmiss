#version 460 core
#extension GL_GOOGLE_include_directive : require
#include "ray_common.glsl"

layout(location = 0) rayPayloadInEXT RayPayload payload;

void main() {
    payload.hit_pos_t = vec4(-1.);
    payload.roughness = 0.;
    payload.normal = vec3(0., 1., 0.);
    payload.albedo = vec3(1., 0., 1.);
    payload.kusok_index = -1;
}