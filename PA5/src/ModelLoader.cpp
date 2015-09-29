#include "ModelLoader.h"

#define DEBUG_MODE 0

using namespace std;
using namespace glm;

bool ModelLoader::loadModel( const char* fileName, vector<Vertex>& vertices)
{

		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile( fileName, aiProcess_CalcTangentSpace |aiProcess_Triangulate |	aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);

		for( int meshI = 0; meshI < scene->mNumMeshes; meshI ++ )
		{
			for( int faceI = 0;  faceI < scene->mMeshes[meshI]->mNumFaces; faceI++ )
			{
				for( int i = 0; i < scene->mMeshes[meshI]->mFaces[faceI].mNumIndices; i++ )
				{
					int loc = scene->mMeshes[meshI]->mFaces[faceI].mIndices[i];
					int mat = scene->mMeshes[meshI]->mMaterialIndex;
					
					aiColor3D color;
					scene->mMaterials[mat]->Get( AI_MATKEY_COLOR_DIFFUSE, color );

					Vertex v;
					v.position[0] = scene->mMeshes[meshI]->mVertices[loc].x;
					v.position[1] = scene->mMeshes[meshI]->mVertices[loc].y;
					v.position[2] = scene->mMeshes[meshI]->mVertices[loc].z;
					v.color[0] = color.r;
					v.color[1] = color.g;
					v.color[2] = color.b;

					vertices.push_back( v ); 
				}
			}
		}

		return true;
}

