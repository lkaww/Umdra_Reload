all: EBOOT.PBP
TARGET = engine
PSP_EBOOT_TITLE = Umdra_Reload

OBJS = \
src/main.o \
src/core/engine.o \
src/graphics/renderer.o \
src/graphics/animation.o \
src/loaders/textureloader.o \
src/input/input.o \
src/scene/scene_template.o \
src/scene/scene1.o \
src/scene/scene_manager.o

CFLAGS = -O2 -G0 -Wall -Iinclude
CXXFLAGS = $(CFLAGS)

LIBS = -lpspgu -lpspdisplay -lpspctrl -lpng -lz -lstdc++ -lm

include $(PSPSDK)/lib/build.mak