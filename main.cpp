#include <stdio.h>
#include "rendergles.hpp"
#include "video.hpp"

int main () {

	printf ("Initializing context..\n");	

/*	RenderGLES *renderer = new RenderGLES;	
	renderer->init(320, 200, 1, 1, 0);
	getchar();
	renderer->disable();
	delete(renderer);
*/

	video.set_video_mode();
	getchar();

	//video.disable();
	
	return 1;
}
