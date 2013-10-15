#include <SDL2\SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tool_sdl.h"
#include "OSDL.h"

using namespace std;

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	OSDL_Window win1("SDL",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_FULLSCREEN_DESKTOP|SDL_WINDOW_HIDDEN);
	win1.ErrorManage();

	OSDL_Renderer ren1(win1,SDL_RENDERER_ACCELERATED);
	ren1.ErrorManage();
	ren1.SetDrawBlendMode(SDL_BLENDMODE_BLEND);

	OSDL_ImageBMP img1("chat.bmp",ren1);
	img1.ErrorManage();

	OSDL_Joystick joy(0);
	joy.ErrorManage();

	SDL_Event event;
	srand(int(time(NULL)));

	win1.Show();
	SDL_ShowCursor(0);

	bool stop=0;
	while(!stop)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.key.keysym.sym==SDLK_ESCAPE)
			{
				//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Au revoir","La fenetre va se fermer",NULL);
				SDL_Quit();
				stop=1;
			}
			if(event.type==SDL_MOUSEBUTTONDOWN) crazyRenderer(win1);
		}
		ren1.SetDrawColor(255,255,255,255);
		ren1.Clear();
		img1.Apply(event.motion.x-400,event.motion.y-400,ren1);
		ren1.Update();
	}
	return 0;
}