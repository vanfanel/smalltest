#include <iostream>
#include <stdio.h>

#include "video.hpp"

#include "rendergles.hpp"
    
Video video;

Video::Video(void)
{
    renderer	 = new RenderGLES();
}

Video::~Video(void)
{
    printf ("Video destructor runs.\n");
    //renderer->disable();
    delete renderer;
}

void Video::disable()
{
    //renderer->disable();
}

int Video::set_video_mode(void)
{
    renderer->init(320, 200, 1, 1, 0);

    return 1;
}
