#pragma once

/* Choose context manager*/ 
//#include "eglcontextkms.hpp"

#include <EGL/egl.h>

// KMS/DRM includes
// This hacky define is needed since there is an struct member called "virtual" in drm.h
#define virtual __virtual
#include <xf86drm.h>
#undef virtual
#include <xf86drmMode.h>
#include <gbm.h>
#include <fcntl.h>

struct __gbm{
	struct gbm_device *dev;
	struct gbm_surface *surface;
};

struct __drm{
	int fd;
	drmModeModeInfo *mode;
	uint32_t crtc_id;
	uint32_t connector_id;

	drmModeCrtcPtr orig_crtc;
};

struct __drm_fb {
	struct gbm_bo *bo;
	uint32_t fb_id;
};

struct __eglInfo {
	EGLDisplay display;
	EGLConfig config;
	EGLContext context;
	EGLSurface surface;
	int width, height, refresh;
};


class RenderGLES
{
public:
    RenderGLES();
    ~RenderGLES();
    bool init(int src_width, int src_height, 
              int scale,
              int video_mode,
              int scanlines);
    void disable();

    bool context_init();
    void context_deinit();
    void pageflip();

private:
    struct gbm_bo *bo;
    struct __drm_fb *fb;

    struct __gbm gbm;
    struct __drm drm;
    struct __eglInfo eglInfo;
    
    drmEventContext eventContext;

    bool initDRM();
    bool initGBM();
    void drmPageFlip();
    struct __drm_fb *drmFBGetFromBO(struct gbm_bo *bo);

};
