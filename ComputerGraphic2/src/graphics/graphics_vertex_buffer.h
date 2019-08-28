#pragma once

#include "vtypes.h"

typedef struct
{
	float* vertices;
	uint32_t rendererID;
} graphics_vertex_buffer;

graphics_vertex_buffer* graphics_vertex_buffer_create(float* vertices, uint32_t size);
void graphics_vertex_buffer_bind(graphics_vertex_buffer* vertex_buffer);
void graphics_vertex_buffer_unbind(graphics_vertex_buffer* vertex_buffer);

typedef struct
{
	uint32_t* indices;
	uint32_t rendererID;
	uint32_t count;
} graphics_index_buffer;

graphics_index_buffer* graphics_index_buffer_create(uint32_t* indices, uint32_t size);
void graphics_index_buffer_bind(graphics_index_buffer* index_buffer);
void graphics_index_buffer_unbind(graphics_index_buffer* index_buffer);
