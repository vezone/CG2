#include "graphics_vertex_buffer.h"

#include <stdlib.h>

#include <Glad/glad.h>

graphics_vertex_buffer* graphics_vertex_buffer_create(float* vertices, uint32_t size)
{
	graphics_vertex_buffer* vertex_buffer = (graphics_vertex_buffer*) malloc(sizeof(graphics_vertex_buffer));
	vertex_buffer->vertices = vertices;
	glGenBuffers(1, &(vertex_buffer->rendererID));
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer->rendererID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	return vertex_buffer;
}

void graphics_vertex_buffer_bind(graphics_vertex_buffer* vertex_buffer)
{
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer->rendererID);
}

void graphics_vertex_buffer_unbind(graphics_vertex_buffer* vertex_buffer)
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

graphics_index_buffer* graphics_index_buffer_create(uint32_t* indices, uint32_t count)
{
	graphics_index_buffer* index_buffer = (graphics_index_buffer*)malloc(sizeof(graphics_index_buffer));
	index_buffer->count = count;
	index_buffer->indices = indices;
	glGenBuffers(1, &(index_buffer->rendererID));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer->rendererID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(indices), indices, GL_STATIC_DRAW);
	return index_buffer;
}

void graphics_index_buffer_bind(graphics_index_buffer* index_buffer)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer->rendererID);
}

void graphics_index_buffer_unbind(graphics_index_buffer* index_buffer)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
