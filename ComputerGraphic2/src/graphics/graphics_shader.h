#pragma once 

#include <Glad/glad.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vtypes.h"

static void write_string_file(char* file_path, char* data, int len)
{
	FILE* file;
	file = fopen(file_path, "w");
	fwrite(data, 1, len, file);
	fclose(file);
}

static char* read_string_file(const char* file_path)
{
	FILE* file;
	file = fopen(file_path, "r");

	if (file)
	{
		fseek(file, 0, SEEK_END);
		long file_length = (ftell(file));
		fseek(file, 0, SEEK_SET);
		char* result = (char*)malloc((file_length + 1) * sizeof(char));
		memset(result, '\0', (file_length + 1));
		fread(result, sizeof(char), (file_length - 1), file);
		result[file_length] = '\0';

		fclose(file);

		return(result);
	}

	return("file_open_error");
}

typedef struct {
	char* VertexShader;
	char* FragmentShader;
} graphics_shader_source;


graphics_shader_source graphics_shader_load(
	const char* vertex_shader_path,
	const char* fragment_shader_path)
{
	graphics_shader_source source;
	source.VertexShader = read_string_file(vertex_shader_path);
	source.FragmentShader = read_string_file(fragment_shader_path);

	if (strcmp(source.VertexShader, "file_open_error") == 0)
	{
		printf(RED5("vertex shader: open error\n"));
	}
	
	if (strcmp(source.FragmentShader, "file_open_error") == 0)
	{
		printf(RED5("fragment shader: open error\n"));
	}

	return source;
}

uint32 graphics_shader_compile(graphics_shader_source source)
{
	uint32 vertex_shader_id;
	vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);

	printf("Compiling vertex shader\n");
	glShaderSource(vertex_shader_id, 1, &source.VertexShader, 0);
	glCompileShader(vertex_shader_id);

	int32 result = GL_FALSE;
	int32 info_log_length;
	glGetShaderiv(vertex_shader_id,
		GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertex_shader_id,
		GL_INFO_LOG_LENGTH, &info_log_length);
	if (info_log_length > 0)
	{
		char* shader_error_message =
			(char*)malloc(info_log_length + 1);
		glGetShaderInfoLog(vertex_shader_id,
			info_log_length, 0, shader_error_message);
		printf(RED5("compiling error %s\n"), shader_error_message);
	}

	printf("Compiling fragment shader\n");
	uint32 fragment_shader_id;
	fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader_id, 1, &source.FragmentShader, 0);
	glCompileShader(fragment_shader_id);

	glGetShaderiv(fragment_shader_id,
		GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragment_shader_id,
		GL_INFO_LOG_LENGTH, &info_log_length);
	if (info_log_length > 0)
	{
		char* shader_error_message =
			(char*)malloc(info_log_length + 1);
		glGetShaderInfoLog(fragment_shader_id,
			info_log_length, 0, shader_error_message);
		printf(RED5("compiling error %s\n"), shader_error_message);
		if (shader_error_message)
		{
			free(shader_error_message);
		}
	}

	printf("Linking program\n");
	uint32 shader_program_id = glCreateProgram();
	glAttachShader(shader_program_id, vertex_shader_id);
	glAttachShader(shader_program_id, fragment_shader_id);
	glLinkProgram(shader_program_id);

	glGetProgramiv(shader_program_id, GL_LINK_STATUS, &result);
	glGetProgramiv(shader_program_id, GL_INFO_LOG_LENGTH, &info_log_length);
	if (info_log_length > 0)
	{
		char* shader_error_message =
			(char*)malloc(info_log_length + 1);
		glGetProgramInfoLog(shader_program_id,
			info_log_length, 0, shader_error_message);
		printf(RED5("linking error %s\n"), shader_error_message);
		if (shader_error_message)
		{
			free(shader_error_message);
		}
	}

	glDetachShader(shader_program_id, vertex_shader_id);
	glDetachShader(shader_program_id, fragment_shader_id);

	glDeleteShader(vertex_shader_id);
	glDeleteShader(fragment_shader_id);

	return shader_program_id;
}

void graphics_shader_delete(uint32_t renderId)
{
	glDeleteProgram(renderId);
}

void graphics_shader_bind(uint32_t renderId)
{
	glUseProgram(renderId);
}

void graphics_shader_unbind()
{
	glUseProgram(0);
}