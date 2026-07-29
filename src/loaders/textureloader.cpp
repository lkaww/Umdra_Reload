#include <memory.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <psputils.h>

#include "loaders/textureloader.h"

Texture* TextureLoader::LoadTexture(const char* filename) 
{
    Texture* texture = (Texture *) calloc(1, sizeof(Texture));

    texture->data = (uint32_t *) stbi_load(filename, &(texture->width), &(texture->height), NULL, STBI_rgb_alpha);
    
    sceKernelDcacheWritebackInvalidateAll();

    return texture;
}

void TextureLoader::UnloadTexture(const Texture* texture)
{
    stbi_image_free(texture->data);
}