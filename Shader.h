#pragma once

#include <GL/glew.h>
#include "Defines.h"
#include <string>

struct Shader {
	Shader(const char* vertexShaderFilenme, const char* fragmentShaderFilenme);
	virtual ~Shader();
	void bind();
	void unbind();

private:
	GLuint compile(std::string shaderSource, GLenum type); //type beschreibt ob fs oder vs
	std::string parse(const char* filename);
	GLuint createSheder(const char* vertexShaderFilename,const char* fragmentShaderFilename);
	GLuint shaderId;
};
