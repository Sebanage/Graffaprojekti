#include "GLSL.h"
#include <GL\glew.h>

#include <fstream>
#include <vector>

GLSL::GLSL() :  _programID(0), _vertShaderID(0), _fragShaderID(0), __numAttributes(0){
	
}

GLSL::~GLSL()
{

}

void GLSL::compileShader(const std::string & vertShaderPath, const std::string & fragShaderPath)
{
	//Vertex and fragment shaders are successfully compiled.
	//Now time to link them together into a program.
	//Get a program object.
	_programID = glCreateProgram();

	_vertShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (_vertShaderID == 0) {
		fatalError("Vertex shader failed to be created!");
	}

	_fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_fragShaderID == 0) {
		fatalError("Fragment shader failed to be created!");
	}

	compileShader(vertShaderPath, _vertShaderID);
	compileShader(fragShaderPath, _fragShaderID);
}

void GLSL::compileShader(const std::string & filePath, GLuint id)
{
	//Vertex and fragment shaders are successfully compiled.
	//Now time to link them together into a program.
	//Get a program object.
	_programID = glCreateProgram();

	//load shader code
	std::ifstream vertexFile(filePath);
	if (vertexFile.fail()) {
		fatalError("Failed to open " + filePath);
	}

	std::string fileContent = "";
	std::string line;

	while (std::getline(vertexFile, line)) {
		fileContent += line + "\n";
	}

	vertexFile.close();

	const char* contentsPtr = fileContent.c_str();
	glShaderSource(id, 1, &contentsPtr, nullptr);

	glCompileShader(id);

	//error checking of shader code
	GLint success = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);


	GLint maxLength = 0;
	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

	// The maxLength includes the NULL character
	std::vector<char> errorLog(maxLength);
	glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);


	

	// Exit with failure.
	glDeleteShader(id); // Don't leak the shader.

	std::printf("%s\n", &(errorLog[0]));

	//Provide the infolog in whatever manor you deem best.
	fatalError("Shader "+ filePath+" failed to compile!");
}

void GLSL::linkShaders()
{
	//Attach our shaders to our program
	glAttachShader(_programID, _vertShaderID);
	glAttachShader(_programID, _fragShaderID);

	//Link our program
	glLinkProgram(_programID);

	//Note the different functions here: glGetProgram* instead of glGetShader*.
	GLint isLinked = 0;
	glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorLog[0]);

		//We don't need the program anymore.
		glDeleteProgram(_programID);
		//Don't leak shaders either.
		glDeleteShader(_vertShaderID);
		glDeleteShader(_fragShaderID);

		//Use the infoLog as you see fit.
		std::printf("%s\n", &(errorLog[0]));
		fatalError("Shaders failed to link!");

		//In this simple program, we'll just leave
		return;
	}

	//Always detach shaders after a successful link.
	glDetachShader(_programID, _vertShaderID);
	glDetachShader(_programID, _fragShaderID);

	//Delete shaders
	glDeleteShader(_vertShaderID);
	glDeleteShader(_fragShaderID);

}

void GLSL::addAttribute(const std::string& attrName)
{
	glBindAttribLocation(_programID, __numAttributes++, attrName.c_str());
}

void GLSL::use()
{
	glUseProgram(_programID);
	for (int i = 0; i < __numAttributes;i++) {
		glEnableVertexAttribArray(i);
	}
}

void GLSL::unuse()
{
	glUseProgram(0);
	for (int i = 0; i < __numAttributes; i++) {
		glDisableVertexAttribArray(i);
	}
}
