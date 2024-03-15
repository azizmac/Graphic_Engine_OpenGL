#include "CubeMesh.h"

std::vector<bbe::Vertex> bbe::CubeMesh::vertices = std::vector<Vertex>{
        {glm::vec3{ -1.0, -1.0, 1.0 }, glm::vec3{1.0, 1.0, 1.0}, glm::vec2{0.0, 0.0}},
        {glm::vec3{ 1.0, -1.0, 1.0 }, glm::vec3{1.0, 1.0, 1.0}, glm::vec2{1.0, 0.0}},
        {glm::vec3{ -1.0, 1.0, 1.0 }, glm::vec3{1.0, 1.0, 1.0}, glm::vec2{0.0, 1.0}},
        {glm::vec3{ 1.0, 1.0, 1.0 }, glm::vec3{1.0, 1.0, 1.0}, glm::vec2{1.0, 1.0}},
        {glm::vec3{ -1.0, -1.0, -1.0}, glm::vec3{1.0, 1.0, 1.0}, glm::vec2{0.0, 0.0}},
        {glm::vec3{ 1.0, -1.0, -1.0}, glm::vec3{1.0, 1.0, 1.0}, glm::vec2{1.0, 0.0}},
        {glm::vec3{ -1.0, 1.0, -1.0}, glm::vec3{1.0, 1.0, 1.0}, glm::vec2{0.0, 1.0}},
        {glm::vec3{ 1.0, 1.0, -1.0}, glm::vec3{1.0, 1.0, 1.0}, glm::vec2{1.0, 1.0}}
};

std::vector<GLuint> bbe::CubeMesh::indices = std::vector<GLuint>{
        0, 1, 2, 1, 3, 2,
        1, 5, 3, 5, 7, 3,
        5, 4, 7, 4, 6, 7,
        4, 0, 6, 0, 2, 6,
        4, 5, 0, 5, 1, 0,
        2, 3, 6, 3, 7, 6
};
