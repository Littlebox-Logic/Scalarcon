// Scalar Console (Scalarcon) - display/driver.h

#ifndef DRIVER_H
#define DRIVER_H

#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <fcntl.h>
//#include <unistd.h>

#include <sys/ioctl.h>
#include <sys/mman.h>
//#include <sys/stat.h>
//#include <sys/types.h>

#include <drm/drm.h>
#include <drm/drm_mode.h>
#include <xf86drm.h>
#include <xf86drmMode.h>
#include <ft2build.h>

#define MALLOC_FAIL			-1
#define DRM_FD_FAIL			-2
#define DRM_MODE_RES_FAIL	-3

typedef struct
{
	drmModeRes				*mode_res;
	drmModeConnector		*connector;
	uint32_t				*framebuffer;
	drm_mode_create_dumb	create_dumb;
	int fd;
} _display_driver, *display_deiver;

extern display_driver driver;

int driver_init(display_driver);
void driver_destroy(display_driver);
int font_init(const char *);

#endif
