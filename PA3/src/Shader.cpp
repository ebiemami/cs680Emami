
#include "Shader.h"

using namespace std;

Shader::Shader()
{

}


GLuint Shader::getShader(const char* shaderFileName, GLenum shaderType)
{	
	GLuint shader = glCreateShader(shaderType);
	 //compile the shaders
    GLint shader_status;

    // Vertex shader first
    loadShader(shader, shaderFileName);
    glCompileShader(shader);
    //check the compile status
    glGetShaderiv(shader, GL_COMPILE_STATUS, &shader_status);
    if(!shader_status)
    {
        std::cerr << "[F] FAILED TO COMPILE SHADER!" << std::endl;
    }

	return shader;

}


void Shader::loadShader(GLuint	&shaderObj, const char* fileName)
{	
    char outFile[1000];

    if(readFile(fileName, outFile))	
    {	
	const char *c = outFile;
		glShaderSource(shaderObj, 1, &c, NULL);		
    }
    else
	cout << "shader not loaded" << endl;
}


bool Shader::readFile(const char* fileName, char* output)
{
    ifstream iFile;
    iFile.open(fileName);	 

    if(iFile.is_open())
    {
        int i = 0;
        while(iFile.get(output[i]))
	    i++;
        iFile.close();
        return true;
    }
    else
	cout << "Problem opening the file" << endl;
    return false;

}

Shader::~Shader()
{

}


