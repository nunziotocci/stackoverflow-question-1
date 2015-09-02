#version 330 core

in vec3 f3Position;

void main() {
	gl_Position = vec4(f3Position, 1.0);
}