#pragma once
#include "rendergles.hpp"

class RenderGLES;

class Video
{
public:
    Video();
    ~Video();
    int set_video_mode(void);
    void disable();
private:
    RenderGLES *renderer;
};

extern Video video;
