/*
 * Model.h
 *
 *  Created on: 1 ���. 2021 �.
 *      Author: ����� ������
 */

#ifndef MODEL_H_
#define MODEL_H_
#include <vector>
#include <memory>
#include <GL/gl.h>
#include <glm/glm.hpp>


class Model {
public:
	using VerticesType= std::vector< glm::vec3>;
	using FacesType=std::vector< std::vector<unsigned>>;
	using NormalsType=std::vector< glm::vec3>;
	using TexCoordsType=	 std::vector< std::vector< glm::vec2>>;

	using AmbientColorType = std::vector<glm::vec4>;
	using DiffuseColorType = std::vector<glm::vec4>;
	using SpecularColorType = std::vector<glm::vec4>;
	using EmissionColorType = std::vector<glm::vec4>;
	using ShininessType = std::vector<GLfloat>;

	using VerticesTypePtr=std::shared_ptr<VerticesType>;
	using FacesTypePtr=std::shared_ptr<FacesType>;
	using NormalsTypePtr=std::shared_ptr<NormalsType>;
	using TexCoordsTypePtr=std::shared_ptr<TexCoordsType>;


protected:
	VerticesTypePtr _vertices;
	FacesTypePtr _faces;
	NormalsTypePtr _normals;
    TexCoordsTypePtr _texcoords;




public:
	Model(VerticesTypePtr vertices, FacesTypePtr faces, NormalsTypePtr normals, TexCoordsTypePtr tex_coords);
	Model (const char *filename);
	virtual ~Model() = default;
	void draw();

private:
	void read_model_line(std::ifstream &file, std::string &buffer);
};

#endif /* MODEL_H_ */
