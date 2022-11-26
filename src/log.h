#ifndef LOG_H
#define LOG_H

#include <stdio.h>

#define PPM_VIEW_DEBUG_LOG(x, ...) printf("[DEBUG] " x "\n", __VA_ARGS__);

#endif // !LOG_H
