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
#include "GSWindow.h"
#include "GSShader.h"
#include "GSMesh.h"

GSWindow *mainWindow = NULL;
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
	
	mainWindow = new GSWindow();
	mainWindow->open(640, 480);
	mainWindow->makeCurrent();
	glViewport(0, 0, 640, 480);
	
	glGetIntegerv(GL_MAJOR_VERSION, &intGLVersionMajor);
	glGetIntegerv(GL_MINOR_VERSION, &intGLVersionMinor);
	printf("OpenGL version: %i.%i\n", intGLVersionMajor, intGLVersionMinor);
	
	shader = new GSShader();
	shader->load("shader.vs", "shader.fs");
	
	mesh = new GSMesh();
	mesh->build(arrFVertex, shader, 6);
	
	//intShaderAttribPosition = glGetAttribLocation(shader->intShaderProgram, "f3Position");
	
	//glGenVertexArrays(1, &intVAO);
	//glBindVertexArray(intVAO);
	
	//glGenBuffers(1, &intVBO);
	//glBindBuffer(GL_ARRAY_BUFFER, intVBO);
	
	//glVertexAttribPointer(intShaderAttribPosition, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);
	//glEnableVertexAttribArray(intShaderAttribPosition);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(arrFVertex), arrFVertex, GL_STATIC_DRAW);
	
	//glBindVertexArray(0);
	
	printf("glIsVertexArray(mesh->intVAO) = %s\n", glIsVertexArray(mesh->intVAO) == GL_TRUE ? "true" : "false");
	printf("glIsBuffer(mesh->intVBO) = %s\n", glIsBuffer(mesh->intVBO) == GL_TRUE ? "true" : "false");
	printf("glIsProgram(shader->intShaderProgram) = %s\n", glIsProgram(shader->intShaderProgram) == GL_TRUE ? "true" : "false");
	
	while (bolRunning) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				bolRunning = false;
			}
		}
		
		mainWindow->makeCurrent();
		mainWindow->clear(0.0f, 0.0f, 1.0f, 1.0f);
		
		shader->use();
		mesh->draw();
		//glBindVertexArray(intVAO);
		
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		
		//glBindVertexArray(0);
		
		mainWindow->swapBuffers();
		
		printf("0x%4x\n", glGetError());
	}
	
	delete shader;
	delete mesh;
	//glDeleteBuffers(1, &intVBO);
	//glDeleteVertexArrays(1, &intVAO);
	
	delete mainWindow;
	SDL_Quit();
	
    return 0;
}
