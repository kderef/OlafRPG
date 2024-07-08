#pragma once

#include "raylib-cpp.hpp"
#include "raygui.h"

namespace rl = raylib;

typedef rl::Vector2 vec2;
typedef rl::Rectangle rect;

rl::Texture load_texture_from_memory(const char* imgtype, const unsigned char* data, int data_size) {
    Image img = LoadImageFromMemory(imgtype, data, data_size);
    rl::Texture texture(img);
    UnloadImage(img);

    return texture;
}