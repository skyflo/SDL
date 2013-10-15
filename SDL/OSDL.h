#ifndef OSDL_H
#define OSDL_H

#include <SDL2\SDL.h>

class OSDL_Window
{
private:
	SDL_Window * win;
public:
	OSDL_Window(const char * title,int x, int y, int w,int h, Uint32 flags) {win=SDL_CreateWindow(title,x,y,w,h,flags);}
	SDL_Window * GetWin() {return win;}

	const char * GetTitle() {return SDL_GetWindowTitle(win);}
	int GetWidth() {
		int width;
		SDL_GetWindowSize(win,&width,NULL);
		return width;
	}
	int GetHeight() {
		int height;
		SDL_GetWindowSize(win,NULL,&height);
		return height;
	}
	int GetPosX() {
		int posx;
		SDL_GetWindowPosition(win,&posx,NULL);
		return posx;
	}
	int GetPosY() {
		int posy;
		SDL_GetWindowPosition(win,NULL,&posy);
		return posy;
	}

	void SetTitle(const char * title) {SDL_SetWindowTitle(win,title);}
	void SetSize(int width, int height) {SDL_SetWindowSize(win,width,height);}
	void SetPosition(int posx, int posy) {SDL_SetWindowPosition(win,posx,posy);}

	void Show() {SDL_ShowWindow(win);}
	void Hide() {SDL_HideWindow(win);}

	void ErrorManage(){
		if(win==NULL) SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Error",SDL_GetError(),NULL);
	}
};

class OSDL_Renderer
{
private:
	SDL_Renderer * ren;
public:
	OSDL_Renderer(OSDL_Window &win,Uint32 flags) {ren=SDL_CreateRenderer(win.GetWin(),-1,flags);}
	SDL_Renderer * GetRenderer() {return ren;}

	void Update() {SDL_RenderPresent(ren);}
	void Clear() {SDL_RenderClear(ren);}
	void SetDrawColor(Uint8 r,Uint8 g,Uint8 b,Uint8 a) {SDL_SetRenderDrawColor(ren,r,g,b,a);}
	void SetDrawBlendMode(SDL_BlendMode BlendMode) {SDL_SetRenderDrawBlendMode(ren,BlendMode);}

	void ErrorManage(){
		if(ren==NULL) SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Error",SDL_GetError(),NULL);
	}
};

class OSDL_ImageBMP
{
private:
	SDL_Texture * tex;
public:
	OSDL_ImageBMP(const char * file,OSDL_Renderer &ren){
		SDL_Surface * loadSurface;
		loadSurface=SDL_LoadBMP(file);
		if (loadSurface!=NULL){
			tex=SDL_CreateTextureFromSurface(ren.GetRenderer(),loadSurface);
		}
		else tex=NULL;
		SDL_FreeSurface(loadSurface);
	}

	void Load(const char * file,OSDL_Renderer &ren){
		SDL_Surface * loadSurface;
		loadSurface=SDL_LoadBMP(file);
		if (loadSurface!=NULL){
			tex=SDL_CreateTextureFromSurface(ren.GetRenderer(),loadSurface);
		}
		else tex=NULL;
		SDL_FreeSurface(loadSurface);
	}

	void Apply(int posx,int posy,OSDL_Renderer &ren){
		SDL_Rect pos;
		pos.x = posx;
		pos.y = posy;
		SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
		SDL_RenderCopy(ren.GetRenderer(), tex, NULL, &pos);
	}

	void ErrorManage(){
		if(tex==NULL) SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Error",SDL_GetError(),NULL);
	}
};

class OSDL_Joystick
{
private:
	SDL_Joystick * joy;
public:
	OSDL_Joystick(int index) {joy=SDL_JoystickOpen(index);}
	SDL_Joystick * Getjoystick() {return joy;}

	void ErrorManage(){
		if(joy==NULL) SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Error",SDL_GetError(),NULL);
	}
};

#endif