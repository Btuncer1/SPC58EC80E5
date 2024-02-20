##############################################################################
# References to the component library (./component/lib) locations.

LIB_C_SRC       += \
	./components/spc5_freertos_component_rla/lib/src/croutine.c \
	./components/spc5_freertos_component_rla/lib/src/list.c \
	./components/spc5_freertos_component_rla/lib/src/event_groups.c \
	./components/spc5_freertos_component_rla/lib/src/queue.c \
	./components/spc5_freertos_component_rla/lib/src/stream_buffer.c \
	./components/spc5_freertos_component_rla/lib/src/tasks.c \
	./components/spc5_freertos_component_rla/lib/src/timers.c \
	\
	./components/spc5_freertos_component_rla/lib/portable/port.c \
	\
	./components/spc5_freertos_component_rla/lib/MemMang/heap_4.c


LIB_CPP_SRC     +=

LIB_ASM_SRC     += \
	./components/spc5_freertos_component_rla/lib/portable/portasm.s

LIB_INCLUDES    += \
	./components/spc5_freertos_component_rla/lib/include \
	./components/spc5_freertos_component_rla/lib/portable

##############################################################################
# References to the application locations.

APP_C_SRC       +=

APP_CPP_SRC     +=

APP_ASM_SRC     +=

APP_INCLUDES    += ./components/spc5_freertos_component_rla/cfg

##############################################################################
# Default directories, definitions and libraries.

# C/C++ definitions (-D....).
DDEFS   +=

# Assembled definitions (-D....).
DADEFS  +=

# Include files search directories separated by spaces.
DINCDIR +=

# Library files search directories separated by spaces.
DLIBDIR +=

# Libraries (-l...).
DLIBS   +=
