//
//  GSMesh.cpp
//  GSEngine
//
//  Created by nunzio on 8/9/15.
//  Copyright (c) 2015 greyspots. All rights reserved.
//

#include "GSMesh.h"

GSMesh::GSMesh() {
	
}

void GSMesh::build(GLfloat *arrFVertex, GSShader *shader, int _intNumVertex) {
	intNumVertex = _intNumVertex;
	intShaderAttribPosition = glGetAttribLocation(shader->intShaderProgram, "f3Position");
	
	glGenVertexArrays(1, &intVAO);
	glBindVertexArray(intVAO);
	
	glGenBuffers(1, &intVBO);
	glBindBuffer(GL_ARRAY_BUFFER, intVBO);
	
	glVertexAttribPointer(intShaderAttribPosition, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(intShaderAttribPosition);
	glBufferData(GL_ARRAY_BUFFER, sizeof(arrFVertex), arrFVertex, GL_STATIC_DRAW);
	
	glBindVertexArray(0);
}

void GSMesh::draw() {
	glBindVertexArray(intVAO);
	
	glDrawArrays(GL_TRIANGLES, 0, intNumVertex);
	
	glBindVertexArray(0);
}

GSMesh::~GSMesh() {
	glDeleteBuffers(1, &intVBO);
	glDeleteVertexArrays(1, &intVAO);
}