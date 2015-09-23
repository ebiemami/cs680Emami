#include "ModelLoader.h"

#define DEBUG_MODE 0

using namespace std;
using namespace glm;

bool ModelLoader::loadObjModel( const char* fileName, vector<Vertex>& vertices)
{

	ifstream modelFile;
	modelFile.open(fileName);	

	vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	vector< glm::vec3 > tVertices;
	vector< glm::vec2 > tUvs;
	vector< glm::vec3 > tNormals;

	GLfloat		 	rgbColor[3] = {1.0, 0.0, 1.0};
	string 			line;	

	while (!modelFile.eof())
	{
		getline(modelFile, line);
		
		stringstream 	lineStream(line);
		string 			lineType;

		lineStream >> lineType;
		
		if (lineType == "v")
		{	
			vec3	tVector;
			lineStream >> tVector.x >> tVector.y >> tVector.z;
			
			#if DEBUG_MODE
				cout << "vertex added : " << tVector.x << " " << tVector.y << " " << tVector.z << " " << endl; 
			#endif

			tVertices.push_back(tVector);
			
		}
		else if (lineType =="vt")
		{	
			vec2	tUV;
			lineStream >> tUV.x >> tUV.y;
			tUvs.push_back(tUV);
		}
		else if(lineType == "vn")
		{
			vec3 	tNorm;
			lineStream >> tNorm.x >> tNorm.y >> tNorm.z;
			tNormals.push_back(tNorm);
		}
		else if (lineType == "f")
		{
			string vertex1, vertex2, vertex3;
		    unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];

			//char dum;
//	lineStream >> vertexIndex[0] >> dum >> uvIndex[0] >> dum >> normalIndex[0] >> vertexIndex[1] >> dum >> uvIndex[1] >> dum >> normalIndex[1] >> vertexIndex[2] >> dum >> uvIndex[2] >>dum >> normalIndex[2];
			
			lineStream >> vertexIndex[0] >> vertexIndex[1] >> vertexIndex[2];

			vertexIndices.push_back(vertexIndex[0]);
		    vertexIndices.push_back(vertexIndex[1]);
		    vertexIndices.push_back(vertexIndex[2]);
		    
			#if DEBUG_MODE
				cout << "Trainlge face read: {" << vertexIndex[0] << ", " << vertexIndex[1] << ", " << vertexIndex[2] << "}" << endl; 
			#endif

			/*uvIndices    .push_back(uvIndex[0]);
		    uvIndices    .push_back(uvIndex[1]);
		    uvIndices    .push_back(uvIndex[2]);
		    normalIndices.push_back(normalIndex[0]);
		    normalIndices.push_back(normalIndex[1]);
		    normalIndices.push_back(normalIndex[2]);*/				
		}
		/*else if (lineType == "mtllib")	
		{
			string mtFile;
			lineStream >> mtFile;
		}
		else if (lineType == "usemtl")	
		{
			
		}*/
		else 
			continue;	
	} 

	int triangleCount=0;
// For each vertex of each triangle
	for( unsigned int i=0; i<vertexIndices.size(); i++ ){

		// Get the indices of its attributes
		unsigned int vertexIndex = vertexIndices[i];
		
		// Get the attributes thanks to the index
		glm::vec3 vertex = tVertices[ vertexIndex-1 ];

		// Put the attributes in buffers
		Vertex v;
		v.position[0] = vertex.x;		
		v.position[1] = vertex.y;
		v.position[2] = vertex.z;

		v.color[0] = rgbColor[0];
		v.color[1] = rgbColor[1];
		v.color[2] = rgbColor[2];


		#if DEBUG_MODE
		if(triangleCount %3 ==0)
			cout << "Trainlge: " << triangleCount/3 << " face added" << endl;
			cout << "Vertext: Position {" << v.position[0] << ", " << v.position[1] << ", " << v.position[0] << "} Color: {" << v.color[0] << ", " << v.color[1] << ", " << v.color[0] << "}" << endl; 
		triangleCount ++;
		#endif

		vertices.push_back(v);
		//out_uvs     .push_back(uv);

		//out_normals .push_bacccck(normal);
	
	}

}

bool ModelLoader::loadMaterial(const string mtlFilePath, map<string, vector<GLfloat>> &nameMaterialMap)
{
		ifstream mtlFile;
		mtlFile.open(mtlFilePath);
		string line;
		string material;
		vector<float> rgb;
		string lineType; 
		stringstream lineStream;

		while(!mtlFile.eof())
		{
			getline(mtlFile, line);
			lineStream.str() = line;

			lineStream >> lineType;
			
			if(lineType == "newmtl")
			{
				lineStream >> material;
				getline(mtlFile, line);
				getline(mtlFile, line);			
				getline(mtlFile, line);
				lineStream.str() = line; 
				lineStream >> rgb[0] >> rgb[1] >> rgb[2];
				nameMaterialMap.insert(std::pair<string, vector<GLfloat>>(material, rgb));
			}	
		}

		mtlFile.close();

		return true;

}

