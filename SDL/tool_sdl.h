#ifndef TOOL_SDL_H
#define TOOL_SDL_H

#include <SDL2\SDL.h>
#include "OSDL.h"

void crazyRenderer(OSDL_Window &win)
{
	SDL_Renderer * ren=SDL_GetRenderer(win.GetWin());
	SDL_SetRenderDrawColor(ren,0,0,0,255);
	SDL_RenderClear(ren);
	SDL_SetRenderDrawColor(ren,rand()%256,rand()%256,rand()%256,100);
	for(int i=0;i<3000;i++)
	{
		int winWidth,winHeight;
		SDL_GetWindowSize(win.GetWin(),&winWidth,&winHeight);
		int x1=rand()%winWidth;
		int y1=rand()%winHeight;
		int x2=rand()%winWidth;
		int y2=rand()%winHeight;
		//int x2=x1*1.7;
		//int y2=y1*1.1;
		SDL_RenderDrawLine(ren,x1,y1,x2,y2);
	}
	SDL_RenderPresent(ren);
}


#endif