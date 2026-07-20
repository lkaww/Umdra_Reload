#include <pspdisplay.h>
#include <pspgu.h>
#include <pspdebug.h>

#include "graphics/renderer.h"
#include "graphics/texture.h"
#include "graphics/vertex.h"

static unsigned int list[524288] __attribute__((aligned(16)));

void Renderer::Init()
{
    sceGuInit();

    sceGuStart(GU_DIRECT, list);

    sceGuDrawBuffer(GU_PSM_8888, (void*)0, 512);
    sceGuDispBuffer(480, 272, (void*)0x88000, 512);
    sceGuDepthBuffer((void*)0x110000, 512);

    //sceGuOffset(2048 - 240, 2048 - 136);
    sceGuViewport(2048, 2048, 480, 272);

    sceGuEnable(GU_SCISSOR_TEST);
    sceGuScissor(0, 0, 480, 272);

    sceGuFinish();
    sceGuSync(0, 0);

    pspDebugScreenInit();

    sceDisplayWaitVblankStart();
    sceGuDisplay(GU_TRUE);
}

void Renderer::BeginFrame()
{
    sceGuStart(GU_DIRECT, list);

    sceGuClearColor(0x000000);
    sceGuClear(
        GU_COLOR_BUFFER_BIT |
        GU_DEPTH_BUFFER_BIT
    );

    sceGuClearDepth(0x0000);
}

void Renderer::DrawText(const char* text)
{
    pspDebugScreenClear();
    pspDebugScreenPrintf(text);
}

void Renderer::DrawTexture(Texture * texture, float x, float y, float w, float h)
{
    static Vertex vertices[2];

    vertices[0].u = 0.0f;
    vertices[0].v = 0.0f;
    vertices[0].colour = 0xFFFFFFFF;
    vertices[0].x = x;
    vertices[0].y = y;
    vertices[0].z = 0.0f;

    vertices[1].u = w;
    vertices[1].v = h;
    vertices[1].colour = 0xFFFFFFFF;
    vertices[1].x = x + w;
    vertices[1].y = y + h;
    vertices[1].z = 0.0f;

    sceGuTexMode(GU_PSM_8888, 0, 0, GU_FALSE);
    sceGuTexFunc(GU_TFX_REPLACE, GU_TCC_RGB);
    sceGuTexImage(0, texture->width, texture->height, texture->width, texture->data);

    sceGuEnable(GU_TEXTURE_2D); 
    sceGuDrawArray(GU_SPRITES, GU_COLOR_8888 | GU_TEXTURE_32BITF | GU_VERTEX_32BITF | GU_TRANSFORM_2D, 2, 0, vertices);
    sceGuDisable(GU_TEXTURE_2D);
}

void Renderer::EndFrame()
{
    sceGuFinish();
    sceGuSync(0, 0);

    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}

void Renderer::Shutdown()
{
    sceGuTerm();
}