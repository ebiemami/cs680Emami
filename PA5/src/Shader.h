#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h> // glew must be included before the main gl libs
#include <GL/glut.h> // doing otherwise causes compiler shouting
#include <iostream>
#include <fstream>

class Shader
{

	public:
		Shader();		
		virtual ~Shader();

		static  GLuint	 getShader(const char* shaderFileName, GLenum shaderType);
	private:
		static  void	 loadShader(GLuint	&shaderObj, const char* fileName);
		static  bool 	 readFile(const char* fileName, char* output);
};

#endif
