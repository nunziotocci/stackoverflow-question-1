//
//  GSWindow.h
//  GSEngine
//
//  Created by nunzio on 8/5/15.
//  Copyright (c) 2015 greyspots. All rights reserved.
//

#ifndef __GSEngine__GSWindow__
#define __GSEngine__GSWindow__

#include <SDL2/SDL.h>
#include <OpenGL/gl3.h>
#include <stdio.h>

struct GSWindow {
	SDL_Window *window = NULL;
	SDL_GLContext openGLRenderer;
	
	GSWindow();
	
	void open(int intWidth, int intHeight);
	void makeCurrent();
	void clear(GLfloat fRed, GLfloat fGreen, GLfloat fBlue, GLfloat fAlpha);
	void swapBuffers();
	void close();
	
	~GSWindow();
};

#endif // __GSEngine__GSWindow__
