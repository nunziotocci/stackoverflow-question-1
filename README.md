# stackoverflow-question-1
this is for a stackoverflow question @ http://stackoverflow.com/questions/32343272/why-can-i-have-an-opengl-shader-class-but-not-a-vao-class

The problem is solved, at GSMesh.cpp:27
It is supposed to be sizeof(GLfloat) * intNumVertex * 3 instead of sizeof(arrFVertex)
