//
//  main.cpp
//  GSEngine
//
//  Created by nunzio on 8/5/15.
//  Copyright (c) 2015 greyspots. All rights reserved.
//

#include <OpenGL/gl3.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GSShader.h"
#include "GSMesh.h"

SDL_Window *window = NULL;
SDL_GLContext openGLRenderer;
bool bolRunning = true;
int intGLVersionMajor, intGLVersionMinor;

GLfloat arrFVertex[] = {
	 0.5f,  0.5f, 0.0f,  // Top Right
	 0.5f, -0.5f, 0.0f,  // Bottom Right
	-0.5f,  0.5f, 0.0f,  // Top Left 
	
	 0.5f, -0.5f, 0.0f,  // Bottom Right
	-0.5f, -0.5f, 0.0f,  // Bottom Left
	-0.5f,  0.5f, 0.0f   // Top Left 
};
GSShader *shader;
GSMesh *mesh;
GLuint intVAO;
GLuint intVBO;
GLuint intShaderAttribPosition;

int main(int argc, char **argv) {
	SDL_Init(SDL_INIT_EVERYTHING);
	
	window = SDL_CreateWindow("GSEngine",
							  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							  640, 480,
							  SDL_WINDOW_OPENGL);
	
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	
	if (window == NULL) {
		printf("Could not create window: %s\n", SDL_GetError());
		exit(1);
	}
	
	openGLRenderer = SDL_GL_CreateContext(window);
	
	SDL_GL_MakeCurrent(window, openGLRenderer);
	glViewport(0, 0, 640, 480);
	
	glGetIntegerv(GL_MAJOR_VERSION, &intGLVersionMajor);
	glGetIntegerv(GL_MINOR_VERSION, &intGLVersionMinor);
	printf("OpenGL version: %i.%i\n", intGLVersionMajor, intGLVersionMinor);
	
	shader = new GSShader();
	shader->load("shader.vs", "shader.fs");
	
	mesh = new GSMesh();
	mesh->build(arrFVertex, shader, 6);
	
	while (bolRunning) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				bolRunning = false;
			}
		}
		
		SDL_GL_MakeCurrent(window, openGLRenderer);
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		shader->use();
		mesh->draw();
		
		SDL_GL_SwapWindow(window);
	}
	
	delete shader;
	delete mesh;
	
	SDL_GL_DeleteContext(openGLRenderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
    return 0;
}
