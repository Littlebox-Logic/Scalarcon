// Scalar Console (Scalarcon) - display/driver.c

#include "driver.h"

#include <stdlib.h>

display_driver driver = NULL;

int driver_init(display_driver driver)
{
	if (!(driver = (display_driver)malloc(sizeof(_display_driver))))
		return MALLOC_FAIL;

	if ((driver->fd = open("/dev/dri/card1", 0_RDWR)) < 0)
	{
		free(driver);
		driver = NULL;
		return DRM_FD_FAIL;
	}

 	if (!(driver->mode_res= drmModeGetResources(driver->fd)))
	{
		close(driver->fd);
		free(driver);
		driver = NULL;

		return DRM_MODE_RES_FAIL;
	}

	if (!(driver->connector = drmModeGetConnector(driver->fd, driver->mode_res->connectors[0])))
	{
		close(driver->fd);
		free(driver);
		driver = NULL;

		return DRM_CONNECTOR_FAIL;
	}

	driver->create_dumb = {	.width = driver->connector->modes[0].vdisplay,
							.height = driver->connector->modes[0].vdisplay,
							.bpp = 32};
	ioctl(driver->fd, DRM_IOCTL_MODE_CREATE_DUMB, &driver->create_dumb);
	struct drm_mode_map_dumb map_dumb = {.handle = driver->create_dumb.handle};

	driver->framebuffer = mmap(0, driver->create_dumb.size, PROT_READ | PROT_WRITE, MAP_SHADED, driver->fd, map_dumb.offset);
	memset(driver->framebuffer, 0, driver->create_dumb.size);

	if (drmModeAddFB(driver->fd, driver->))
	driver->crtc = drmModeGetCrtc(driver->fd, driver->res)
	if (drmModeSetCrtc(driver->fd, driver->crtc->crtcid))

	return 0;
}

int font_init(const char *font_path, uint8_t, font_size)
{
	FT_Library library;
	FT_Face face;

	if (FT_Init_FreeType(&library))
		return FONT_INIT_FAIL;

	if (FT_New_Face(library, font_path, 0, &face))
	{
		FT_Done_FreeType(library);
		return FONT_IMPORT_FAIL;
	}

	FT_Set_Pixel_Sizes(face, 0, font_size);

	return 0;
}

void driver_destroy(display_driver driver)
{
	drmModeRmFB(driver->fd, fb_id);				// *
	munmap(driver->framebuffer, driver->create_dumb.size);
	drmModeFreeConnector(driver->connector);
	drmModeFreeResources(driver->mode_res);
	close(driver->fd);
	free(driver);
	driver = NULL;
}

void font_destroy(... font)
{
	;
}
