//
//  GSMesh.h
//  GSEngine
//
//  Created by nunzio on 8/9/15.
//  Copyright (c) 2015 greyspots. All rights reserved.
//

#ifndef __GSEngine__GSMesh__
#define __GSEngine__GSMesh__

#include <OpenGL/gl3.h>
#include <stdio.h>
#include <stdlib.h>
#include "GSShader.h"

struct GSMesh {
	GLuint intVAO;
	GLuint intVBO;
	GLuint intShaderAttribPosition;
	int intNumVertex;
	
	GSMesh();
	
	void build(GLfloat *arrFVertex, GSShader *shader, int intNumVertex);
	void draw();
	
	~GSMesh();
};

#endif // __GSEngine__GSMesh__
