//
//  GSShader.cpp
//  GSEngine
//
//  Created by nunzio on 8/9/15.
//  Copyright (c) 2015 greyspots. All rights reserved.
//

#include "GSShader.h"

GSShader::GSShader() {
	
}

void GSShader::load(const char *strVertexShaderPath, const char *strFragmentShaderPath) {
	char *strVertexShaderSource;
	char *strFragmentShaderSource;
	long intLength;
	FILE *fp;
	
	if ((fp = fopen(strVertexShaderPath, "r")) == NULL) {
		printf("Failed to open %s", strVertexShaderPath);
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END);
	intLength = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	strVertexShaderSource = (char *)malloc(intLength);
	fread(strVertexShaderSource, 1, intLength, fp);
	
	fclose(fp);
	
	if ((fp = fopen(strFragmentShaderPath, "r")) == NULL) {
		printf("Failed to open %s", strFragmentShaderPath);
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END);
	intLength = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	strFragmentShaderSource = (char *)malloc(intLength);
	fread(strFragmentShaderSource, 1, intLength, fp);
	
	fclose(fp);
	
	intShaderProgram = glCreateProgram();
	
	GLuint intVertexShader;
	intVertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(intVertexShader, 1, &strVertexShaderSource, NULL);
	glCompileShader(intVertexShader);
	GLint intVertexShaderSuccess;
	GLchar strVertexShaderInfoLog[512];
	glGetShaderiv(intVertexShader, GL_COMPILE_STATUS, &intVertexShaderSuccess);
	if(!intVertexShaderSuccess) {
		glGetShaderInfoLog(intVertexShader, 512, NULL, strVertexShaderInfoLog);
		printf("Vertex shader failed:\n%s\n", strVertexShaderInfoLog);
		exit(1);
	}
	
	GLuint intFragmentShader;
	intFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(intFragmentShader, 1, &strFragmentShaderSource, NULL);
	glCompileShader(intFragmentShader);
	GLint intFragmentShaderSuccess;
	GLchar strFragmentShaderInfoLog[512];
	glGetShaderiv(intFragmentShader, GL_COMPILE_STATUS, &intFragmentShaderSuccess);
	if(!intFragmentShaderSuccess) {
		glGetShaderInfoLog(intFragmentShader, 512, NULL, strFragmentShaderInfoLog);
		printf("Fragment shader failed:\n%s\n", strFragmentShaderInfoLog);
		exit(1);
	}
	
	glAttachShader(intShaderProgram, intVertexShader);
	glAttachShader(intShaderProgram, intFragmentShader);
	glLinkProgram(intShaderProgram);
	
	GLint intShaderProgramSuccess;
	GLchar strShaderProgramInfoLog[512];
	glGetProgramiv(intShaderProgram, GL_LINK_STATUS, &intShaderProgramSuccess);
	if(!intShaderProgramSuccess) {
		glGetProgramInfoLog(intShaderProgram, 512, NULL, strShaderProgramInfoLog);
		printf("Shader linking failed:\n%s\n", strShaderProgramInfoLog);
		exit(1);
	}
	
	glDeleteShader(intVertexShader);
	glDeleteShader(intFragmentShader);
	
	free(strVertexShaderSource);
	free(strFragmentShaderSource);
}

void GSShader::use() {
	glUseProgram(intShaderProgram);
}

GSShader::~GSShader() {
	glDeleteProgram(intShaderProgram);
}