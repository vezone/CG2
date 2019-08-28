#pragma once

#include <stdlib.h>

typedef struct
{

} application;

application* application_create()
{
	application* app = (application*) malloc(sizeof(application));
	return app;
}
