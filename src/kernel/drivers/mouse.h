#pragma once

#include <lib/asmUtils.h>

#define MOUSE_SENSITIVITY 3

namespace kernel {

void mouseHandler(regs_t *regs);

void initMouse();

inline uint8_t mouseSensitivity = 3;

}