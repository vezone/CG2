#include <stdio.h>

#include "src/vtypes.h"
#include "src/graphics/graphics_vertex_buffer.h"
#include "src/graphics//graphics_shader.h"

#include <GLFW/glfw3.h>
#include <Glad/glad.h>

// WINDOW GLOBAL
static int8 g_is_cursor_position_visible = 0;
static int8 g_is_cursor_enabled = 1;
static int8 g_is_freqency_visible = 0;
static uint64 g_freqency;

//OPENGL FUNCTIONS
//void vertex_buffer_bind(uint32 vertex_buffer_id);
//void vertex_buffer_unbind();
//uint32 vertex_buffer_create(float* buffer_data, int32 length);
//void vertex_array_enable(int8 vertex_array_index);
//void vertex_array_disable(int8 vertex_array_index);
//int8 vertex_array_create(uint32 vertex_buffer_id, int32 size);

typedef struct { int8 handled; } event;

typedef void (*event_callback)(event e);

typedef struct {
	const char* title;
	uint32 width;
	uint32 height;
	uint8 vsync;
	event_callback event_handler;
} window_data;

void window_key_callback(GLFWwindow* window, int32 key, int32 scancode, int32 action, int32 mods)
{
	if (action == GLFW_PRESS)
	{
		switch (key)
		{
		case GLFW_KEY_Q:
			printf("Q is pressed\n");
			glfwSetWindowShouldClose(window, 1);
			break;
		case GLFW_KEY_W:
			printf("W is pressed\n");
			break;
		case GLFW_KEY_E:
			printf("E is pressed\n");
			break;
		case GLFW_KEY_R:
			printf("R is pressed\n");
			break;
		case GLFW_KEY_T:
			printf("T is pressed\n");
			break;
		case GLFW_KEY_Y:
			printf("Y is pressed\n");
			break;
		case GLFW_KEY_U:
			printf("U is pressed\n");
			break;
		case GLFW_KEY_I:
			printf("I is pressed\n");
			break;
		case GLFW_KEY_O:
			printf("O is pressed\n");
			break;
		case GLFW_KEY_P:
			printf("P is pressed\n");
			break;
		case GLFW_KEY_A:
			printf("A is pressed\n");
			break;
		case GLFW_KEY_S:
			if (!g_is_cursor_position_visible)
			{
				g_is_cursor_position_visible = 1;
			}
			else
			{
				g_is_cursor_position_visible = 0;
			}
			printf("S is pressed\n");
			break;
		case GLFW_KEY_D:
			if (!g_is_cursor_enabled)
			{
				g_is_cursor_enabled = 1;
				glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			}
			else
			{
				g_is_cursor_enabled = 0;
				glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
			}
			printf("D is pressed\n");
			break;
		case GLFW_KEY_F:
			if (g_is_freqency_visible)
			{
				g_is_freqency_visible = 0;
			}
			else
			{
				g_is_freqency_visible = 1;
			}
			printf("F is pressed\n");
			break;
		case GLFW_KEY_G:
			printf("G is pressed\n");
			break;
		case GLFW_KEY_H:
			printf("H is pressed\n");
			break;
		case GLFW_KEY_J:
			printf("J is pressed\n");
			break;
		case GLFW_KEY_K:
			printf("K is pressed\n");
			break;
		case GLFW_KEY_L:
			printf("L is pressed\n");
			break;
		case GLFW_KEY_Z:
			printf("Z is pressed\n");
			break;
		case GLFW_KEY_X:
			printf("X is pressed\n");
			break;
		case GLFW_KEY_C:
			printf("C is pressed\n");
			break;
		case GLFW_KEY_V:
			printf("V is pressed\n");
			break;
		case GLFW_KEY_B:
			printf("B is pressed\n");
			break;
		case GLFW_KEY_N:
			printf("N is pressed\n");
			break;
		case GLFW_KEY_M:
			printf("M is pressed\n");
			break;
		case GLFW_KEY_0:
			printf("0 is pressed\n");
			break;
		case GLFW_KEY_1:
			printf("1 is pressed\n");
			break;
		case GLFW_KEY_2:
			printf("2 is pressed\n");
			break;
		case GLFW_KEY_3:
			printf("3 is pressed\n");
			break;
		case GLFW_KEY_4:
			printf("4 is pressed\n");
			break;
		case GLFW_KEY_5:
			printf("5 is pressed\n");
			break;
		case GLFW_KEY_6:
			printf("6 is pressed\n");
			break;
		case GLFW_KEY_7:
			printf("7 is pressed\n");
			break;
		case GLFW_KEY_8:
			printf("8 is pressed\n");
			break;
		case GLFW_KEY_9:
			printf("9 is pressed\n");
			break;
		case GLFW_KEY_LEFT_SHIFT:
			printf("LShift is pressed\n");
			break;
		case GLFW_KEY_RIGHT_SHIFT:
			printf("RShift is pressed\n");
			break;
		case GLFW_KEY_UP:
			printf("Up is pressed\n");
			break;
		case GLFW_KEY_DOWN:
			printf("Down is pressed\n");
			break;
		case GLFW_KEY_LEFT:
			printf("Left is pressed\n");
			break;
		case GLFW_KEY_RIGHT:
			printf("Right is pressed\n");
			break;
		}
	}
}

void window_mouse_button_callback(GLFWwindow* window, int32 button, int32 action, int32 mods)
{
	if (action == GLFW_PRESS)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT)
		{
			printf("Left mouse button is pressed\n");
		}
		else if (button == GLFW_MOUSE_BUTTON_RIGHT)
		{
			printf("Right mouse button is pressed\n");
		}
		else if (button == GLFW_MOUSE_BUTTON_MIDDLE)
		{
			printf("Middle mouse button is pressed\n");
		}
	}
	else if (action == GLFW_RELEASE)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT)
		{
			printf("Left mouse button is released\n");
		}
		else if (button == GLFW_MOUSE_BUTTON_RIGHT)
		{
			printf("Right mouse button is released\n");
		}
		else if (button == GLFW_MOUSE_BUTTON_MIDDLE)
		{
			printf("Middle mouse button is released\n");
		}
	}
}

void window_mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	printf("Scroll mouse {%f, %f}\n", xoffset, yoffset);
}

void window_cursor_callback(GLFWwindow* window, double xpos, double ypos)
{
	//empty for now
}

void handle_dropped_file(const char* path)
{
	printf("Path of file = %s\n", path);
}

void window_drop_callback(GLFWwindow* window, int32 count, const char** paths)
{
	int32 i;
	for (i = 0; i < count; i++)
	{
		handle_dropped_file(paths[i]);
	}
}

#define to_string(x) #x

void on_event(event e)
{
	printf("event handled = %c\n", e.handled);
}

typedef struct
{
	int32 number_1;
	int32 number_2;
	int32 number_3;
} A;

int main()
{
#if 1

	A* a = malloc(sizeof(A));
	a->number_1 = 10;
	a->number_2 = 20;
	a->number_3 = 30;
	printf("a = %d\n", (int32) a);
	printf("number_1 = %d\n", ((A*)&a->number_1)->number_2);
	printf("number_2 = %d\n", (int32)&a->number_2);
	printf("number_3 = %d\n", (int32)&a->number_3);


#else

	GLFWwindow* window;
	window_data wdata;

	if (!glfwInit())
	{
		printf("GLFW is not initialized!\n");
		return(-1);
	}

	int32 major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("GLFW version: %d.%d.%d\n", major, minor, revision);

	wdata.title = "Demo";
	wdata.width = 1280;
	wdata.height = 720;
	wdata.vsync = 1;
	wdata.event_handler = on_event;

	window = glfwCreateWindow(wdata.width, wdata.height, wdata.title, 0, 0);
	if (!window)
	{
		glfwTerminate();
		return(-1);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(wdata.vsync);
	glfwSetWindowUserPointer(window, &wdata);

	glfwSetKeyCallback(window, window_key_callback);
	glfwSetMouseButtonCallback(window, window_mouse_button_callback);
	glfwSetScrollCallback(window, window_mouse_scroll_callback);
	glfwSetDropCallback(window, window_drop_callback);
	
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	if (status == 0)
	{
		printf("Failed to init GLAD\n");
	}

	printf("OpenGL version %s\n", glGetString(GL_VERSION));

	//opengl
	uint32_t m_VertexArray;
	glGenVertexArrays(1, &m_VertexArray);
	glBindVertexArray(m_VertexArray);

	float vertices[3 * 3] =
	{
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};
	graphics_vertex_buffer* vb = graphics_vertex_buffer_create(vertices, sizeof(vertices));
	graphics_vertex_buffer_bind(vb);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, 0, 3 * sizeof(float), 0);
	
	uint32_t indices[] = { 0, 1, 2 };
	graphics_index_buffer* ib = graphics_index_buffer_create(indices, 3);
	graphics_index_buffer_bind(ib);

	graphics_shader_source shader_source;
	shader_source = graphics_shader_load(
		"E://General//Programming//C//ComputerGraphic2//ComputerGraphic2//source//simple_vertex_shader.txt", 
		"E://General//Programming//C//ComputerGraphic2//ComputerGraphic2//source//simple_fragment_shader.txt");
	uint32 shader = graphics_shader_compile(shader_source);

	double mouse_x_pos, mouse_y_pos;
	while (!glfwWindowShouldClose(window))
	{
		g_freqency = glfwGetTimerFrequency();

		if (g_is_freqency_visible)
		{
			printf("%lld hz\n", g_freqency);
		}

		if (g_is_cursor_position_visible)
		{
			glfwGetCursorPos(window, &mouse_x_pos, &mouse_y_pos);
			printf("Mouse position: {%f,%f}\n", mouse_x_pos, mouse_y_pos);
		}

		glClearColor(0.1f, 0.1f, 0.1f, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		
		graphics_shader_bind(shader);

		glBindVertexArray(m_VertexArray);
		glDrawElements(GL_TRIANGLES, ib->count, GL_UNSIGNED_INT, NULL);

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	
	glfwTerminate();

#endif

	return 0;
}