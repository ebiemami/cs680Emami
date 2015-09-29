#ifndef MODEL_LOADER_H 
#define MODEL_LOADER_H

#include <GL/glew.h> // glew must be included before the main gl libs
#include <GL/glut.h> // doing otherwise causes compiler shouting

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> //Makes passing matrices to shaders easier

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
struct Vertex
{
    GLfloat position[3];
    GLfloat color[3];
};

class ModelLoader
{

	public :

		static bool 		loadModel( const char* fileName, std::vector<Vertex>& vertices);

};

#endif
