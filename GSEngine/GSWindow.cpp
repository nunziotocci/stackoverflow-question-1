//
//  GSWindow.cpp
//  GSEngine
//
//  Created by nunzio on 8/5/15.
//  Copyright (c) 2015 greyspots. All rights reserved.
//

#include "GSWindow.h"

GSWindow::GSWindow() {
	
}

void GSWindow::open(int intWidth, int intHeight) {
	window = SDL_CreateWindow("GSEngine",
							  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							  intWidth, intHeight,
							  SDL_WINDOW_OPENGL);
	
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	
	if (window == NULL) {
		printf("Could not create window: %s\n", SDL_GetError());
		exit(1);
	}
	
	openGLRenderer = SDL_GL_CreateContext(window);
}

void GSWindow::makeCurrent() {
	SDL_GL_MakeCurrent(window, openGLRenderer);
}

void GSWindow::clear(GLfloat fRed, GLfloat fGreen, GLfloat fBlue, GLfloat fAlpha) {
	glClearColor(fRed, fGreen, fBlue, fAlpha);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GSWindow::swapBuffers() {
	SDL_GL_SwapWindow(window);
}

void GSWindow::close() {
	SDL_GL_DeleteContext(openGLRenderer);
	SDL_DestroyWindow(window);
}

GSWindow::~GSWindow() {
	
}
