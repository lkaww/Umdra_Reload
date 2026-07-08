#include <pspkernel.h>

#include "core/engine.h"

PSP_MODULE_INFO("Umdra_Reload", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

int main()
{
    Engine engine;

    engine.Init();
    engine.Run();
    engine.Shutdown();

    return 0;
}