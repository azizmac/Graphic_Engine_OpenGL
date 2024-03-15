#include "CubeMesh.h"

std::vector<bbe::Vertex> bbe::CubeMesh::vertices = std::vector<Vertex>{
        {glm::vec3{ -1.0, -1.0, 1.0 }},
        {glm::vec3{ 1.0, -1.0, 1.0 }},
        {glm::vec3{ -1.0, 1.0, 1.0 }},
        {glm::vec3{ 1.0, 1.0, 1.0 }},
        {glm::vec3{ -1.0, -1.0, -1.0}},
        {glm::vec3{ 1.0, -1.0, -1.0}},
        {glm::vec3{ -1.0, 1.0, -1.0}},
        {glm::vec3{ 1.0, 1.0, -1.0}}
};

std::vector<GLuint> bbe::CubeMesh::indices = std::vector<GLuint>{
        0, 1, 2, 1, 3, 2, // передн€€ грань
        1, 5, 3, 5, 7, 3, // права€ грань
        5, 4, 7, 4, 6, 7, // задн€€ грань
        4, 0, 6, 0, 2, 6, // лева€ грань
        4, 5, 0, 5, 1, 0, // нижн€€ грань
        2, 3, 6, 3, 7, 6  // верхн€€ грань
};
