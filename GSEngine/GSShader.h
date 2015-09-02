//
//  GSShader.h
//  GSEngine
//
//  Created by nunzio on 8/9/15.
//  Copyright (c) 2015 greyspots. All rights reserved.
//

#ifndef __GSEngine__GSShader__
#define __GSEngine__GSShader__

#include <OpenGL/gl3.h>
#include <stdio.h>
#include <stdlib.h>

struct GSShader {
	int intShaderProgram;
	
	GSShader();
	
	void load(const char *strVertexShaderPath, const char *strFragmentShaderPath);
	void use();
	
	~GSShader();
};

#endif // __GSEngine__GSShader__
