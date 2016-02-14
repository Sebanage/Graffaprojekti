#pragma once

#include <string>
#include <GL\glew.h>
#include "Errors.h"

class GLSL
{
public:
	GLSL();
	~GLSL();

	void compileShader(const std::string& vertShaderPath, const std::string& fragShaderPath);
	void linkShaders();
	void addAttribute(const std::string& attrName);
	void use();
	void unuse();

private:
	
	GLuint _programID;
	GLuint _vertShaderID;
	GLuint _fragShaderID;
	int __numAttributes;

	void compileShader(const std::string& filePath, GLuint id);
};

