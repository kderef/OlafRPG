#pragma once

#include "raylib.h"
#include "raygui.h"

typedef Vector2 vec2;
typedef Rectangle rect;

Texture load_texture_from_memory(const char* imgtype, const unsigned char* data, int data_size) {
    Image img = LoadImageFromMemory(imgtype, data, data_size);
    Texture texture = LoadTextureFromImage(img);
    UnloadImage(img);

    return texture;
}