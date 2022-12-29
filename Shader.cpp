#include "Shader.h"
#include <fstream>
#include <iostream>


//Shader:: muss genannt werden da wir #inclde "shader.h" verwenden > die methoden liegen also so gesehen nicht in dieser klasse
Shader::Shader(const char* vertexShaderFilenme, const char* fragmentShaderFilenme){
	shaderId = createSheder(vertexShaderFilenme, fragmentShaderFilenme);
};


Shader::~Shader(){
	glDeleteProgram(shaderId);
};

void Shader::bind() {
	glUseProgram(shaderId);
};

void Shader::unbind(){
	glUseProgram(0);
};

GLuint Shader::compile(std::string shaderSource, GLenum type) { //type beschreibt ob fs oder vs
	GLuint id = glCreateShader(type);
	const char* src = shaderSource.c_str();
	glShaderSource(id, 1, &src, 0);
	glCompileShader(id);
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result != GL_TRUE) {
		int lenght = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
		char* message = new  char[lenght];
		glGetShaderInfoLog(id, lenght, &lenght, message);
		std::cout << "Compilation error:" << message << std::endl;
		delete[] message;
		return 0;
	}
	return id;
};


std::string Shader::parse(const char* filename){
	std::cout << "es ist noch kein Fehler aufgetreten" << std::endl;

	FILE* file;
	file = fopen(filename, "rb");		//rb = read binary

	/*
	if (file == nullptr) {
		std::cout << "File" << filename << "not found" << std::endl;
		};
	return 0;
	*/  //das hier ist BS und fuckt meinen code aber mein code ist sowiso gefuckt

	std::string contens;

	fseek(file, 0, SEEK_END);
	size_t filesize = ftell(file);
	rewind(file);					//Damit wir wieder von Forne Einlesen können
	contens.resize(filesize);
	fread(&contens[0], 1, filesize, file);
	fclose(file);
	return contens;
};


GLuint Shader::createSheder(const char* vertexShaderFilename, const char* fragmentShaderFilename){
	std::string verstexShaderSource = parse(vertexShaderFilename);
	std::string fragmentShaderSource = parse(fragmentShaderFilename);

	GLuint program = glCreateProgram();
	GLuint vs = compile(verstexShaderSource, GL_VERTEX_SHADER);
	GLuint fs = compile(fragmentShaderSource, GL_FRAGMENT_SHADER);
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);

	if(0)		//for the different day/night times
	{
		glDetachShader(program, fs);
		glDetachShader(program, vs);

	}

	return program;
	
};
