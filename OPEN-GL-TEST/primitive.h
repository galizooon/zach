/*
 * primitive.h
 *
 *  Created on: 9 дек. 2021 г.
 *      Author: Семен Беляев
 */

#ifndef PRIMITIVE_H_
#define PRIMITIVE_H_

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <cmath>

glm::vec2 cart2pol(const glm::vec2 &cart);
glm::vec2 pol2cart(const glm::vec2 &pol);

glm::vec3 cart2cyl(const glm::vec3 &cart);
glm::vec3 cyl2cart(const glm::vec3 &cyl);
glm::vec3 cart2sph(const glm::vec3 &cart);
glm::vec3 sph2cart(const glm::vec3 &sph);

void draw_prism(unsigned sides, double radius, double height);

void draw_cylinder(unsigned sides,double radius, double height);
void draw_pyramid (unsigned sides, double radius, double height);
void draw_cone(unsigned sides, double radius, double height);

void draw_disco_ball(unsigned cols, unsigned rows, double radius);
void draw_sphere(unsigned cols, unsigned rows, double radius);

#endif /* PRIMITIVE_H_ */
