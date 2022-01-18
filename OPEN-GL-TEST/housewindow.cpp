/*
 * housewindow.cpp
 *
 *  Created on: 1 дек. 2021 г.
 *      Author: Семен Беляев
 */


#include "housewindow.h"
#include <memory>

housewindow::housewindow(): Window(WINDOW_WIDTH, WINDOW_HEIGHT),
		_house_model("house_model.txt") {
SDL_SetRelativeMouseMode(SDL_TRUE);
SDL_SetWindowTitle(_window.get(), "House");
}

void housewindow::update() {
	_angle+=0.05f;

}

void housewindow::render() {
	auto eye=_player.position();
	auto center=_player.center();
	glm::vec3 moon_pos{12.f,12.f,90.f};
	glm::vec3 light_pos{0.f,0.f,0.f};

	glLightfv(GL_LIGHT0, GL_POSITION, &moon_pos[0]);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(eye.x,eye.y,eye.z,center.x,center.y,center.z,0.0,0.0,1.0);
	glPushMatrix();
	glTranslated(eye.x,eye.y,eye.z);

	glDisable(GL_LIGHTING);
	glDisable(GL_FOG);
	Texture::enable();
	_sky.bind();
	draw_sphere(64,32,100);

	glEnable(GL_LIGHTING);
	GLfloat white[4]{1.f,1.f,1.f,1.f};
	GLfloat black[4]{0.f,0.f,0.f,1.f};
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, white);
	glTranslated(moon_pos.x,moon_pos.y,moon_pos.z);
	glLightfv(GL_LIGHT0, GL_POSITION, &light_pos[0]);

    glRotated(-80.0,0.f,1.f,0.f);
	_moon.bind();
	draw_sphere(32,16,2.5);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, black);

	glPopMatrix();

	Texture::disable();
	glEnable(GL_FOG);

	glBegin(GL_QUADS);
	glNormal3d(0,0,1);
	for(int i=-150;i<150;++i)
		for(int j=-150;j<150;++j){
			glVertex3d(i+0,j+0,0);
			glVertex3d(i+1,j+0,0);
			glVertex3d(i+1,j+1,0);
			glVertex3d(i+0,j+1,0);
		}
	glEnd();
	Texture::enable();

//тело снеговика
	glPushMatrix();
	glRotated(_angle,0,0,1);
	_snow.bind();
	glTranslated(0.0,0.0,0.75);
	draw_sphere(12,8,1);
	glTranslated(0.0,0.0,1.25);
	draw_sphere(12,8,0.7);
	glTranslated(0.0,0.0,0.9);
	draw_sphere(12,8,0.4);
	_carrot.bind();
	glRotated(90.0,0,1,0);
	draw_cone(12,0.08,1.0);
	glPopMatrix();
	glPushMatrix();
		glRotated(_angle,0,0,1);
		_bark.bind();
		glTranslated(0,0,2);
		glRotated(90.0,0,1,0);
		glRotated(45.0,1,0,0);
		draw_cylinder(12,0.025,1.2);
		glRotated(-90.0,1,0,0);
		draw_cylinder(12,0.025,1.2);
		glPopMatrix();
		glPushMatrix();
			glRotated(_angle,0,0,1);
			_bark.bind();
			glTranslated(0.28,0.2,3.1);
			draw_sphere(12,8,0.04);
			glTranslated(0,-0.4,0);
			draw_sphere(12,8,0.04);
			glPopMatrix();

	glTranslated(-3.0,-3,0);

	glPushMatrix();
	glRotated(_angle,0,0,1);
	_snow.bind();
	glTranslated(0.0,0.0,0.75);
	draw_sphere(12,8,1);
	glTranslated(0.0,0.0,1.25);
	draw_sphere(12,8,0.7);
	glTranslated(0.0,0.0,0.9);
	draw_sphere(12,8,0.4);
	_carrot.bind();
	glRotated(90.0,0,1,0);
	draw_cone(12,0.08,1.0);
	glPopMatrix();

	glPushMatrix();
		glRotated(_angle,0,0,1);
		_bark.bind();
		glTranslated(0,0,2);
		glRotated(90.0,0,1,0);
		glRotated(45.0,1,0,0);
		draw_cylinder(12,0.025,1.2);
		glRotated(-90.0,1,0,0);
		draw_cylinder(12,0.025,1.2);
		glPopMatrix();
		glPushMatrix();
			glRotated(_angle,0,0,1);
			_bark.bind();
			glTranslated(0.28,0.2,3.1);
			draw_sphere(12,8,0.04);
			glTranslated(0,-0.4,0);
			draw_sphere(12,8,0.04);
			glPopMatrix();

	glTranslated(-2.5,-1.5,0);

	glPushMatrix();
	glRotated(_angle,0,0,1);
	_snow.bind();
	glTranslated(0.0,0.0,0.75);
	draw_sphere(12,8,1);
	glTranslated(0.0,0.0,1.25);
	draw_sphere(12,8,0.7);
	glTranslated(0.0,0.0,0.9);
	draw_sphere(12,8,0.4);
	_carrot.bind();
	glRotated(90.0,0,1,0);
	draw_cone(12,0.08,1.0);
	glPopMatrix();

	glPushMatrix();
		glRotated(_angle,0,0,1);
		_bark.bind();
		glTranslated(0,0,2);
		glRotated(90.0,0,1,0);
		glRotated(45.0,1,0,0);
		draw_cylinder(12,0.025,1.2);
		glRotated(-90.0,1,0,0);
		draw_cylinder(12,0.025,1.2);
		glPopMatrix();
		glPushMatrix();
			glRotated(_angle,0,0,1);
			_bark.bind();
			glTranslated(0.28,0.2,3.1);
			draw_sphere(12,8,0.04);
			glTranslated(0,-0.4,0);
			draw_sphere(12,8,0.04);
			glPopMatrix();
	Texture::enable();

//елка
	glPushMatrix();
	_bark.bind();
	glTranslated(-4,-4,0);
	draw_cylinder(12,0.6,1.0);
	_tree.bind();
	glTranslated(0,0,0.75);
	draw_cone(12,3,5);
	glTranslated(0,0,3.0);
	draw_cone(12,2,3);
	glTranslated(0,0,2.25);
	draw_cone(12,1,1.5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-10,0,0);
	_house_texture.bind();
	_house_model.draw();
	glTranslated(-5,0,0);
	_house_model.draw();
	glTranslated(-5,0,0);
	_house_model.draw();
	glPopMatrix();
Texture::disable();

//фонарь
	glPushMatrix();
	glTranslated(-10,8,0);
	draw_cylinder(20,0.05,5);
	glTranslated(0,0,5);
	glRotated(90.0,1,0,0);
	draw_cylinder(20,0.05,1);
	draw_sphere(12,8,0.06);
	glTranslated(0,-0.5,0.95);
	glRotated(-90.0,1,0,0);
	draw_cylinder(20,0.05,0.5);
	draw_cone(20,0.3,0.5);

	glPopMatrix();
	glTranslated(-10.0,7.0,4.5);
	Texture::enable();
	_lamp.bind();
	draw_sphere(12,8,0.18);
	Texture::disable();

	/*glPushMatrix();
	glm::vec3 lamp_pos{-10.f,7.f,4.5f};
	GLfloat yellow[4]{1.f, 1.f, 0.f, 1.f};
	glLightfv(GL_LIGHT1, GL_POSITION, &lamp_pos[0]);
	//GLfloat lamp_pos[]={-10.0,7.0,4.5};
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, yellow);
	glTranslated(lamp_pos.x,lamp_pos.y,lamp_pos.z);
	glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
	GLfloat spot_direction [] = {-10.0, 7.0, 0.0};
	glLightfv (GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);

	glEnable(GL_LIGHT1);
	glPopMatrix();
	*/
	glPushMatrix();
	glm::vec3 lamp_pos{-10.f,7.f,4.3f};
	GLfloat light1_ambient[] = {1.0, 1.0, 0.0, 1.0};
	GLfloat light1_diffuse[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat light1_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat spot_direction[] = {lamp_pos.x, lamp_pos.y, -1.0};

	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, &lamp_pos[0]);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);


	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 180.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
	glLightfv(GL_LIGHT1, GL_POSITION, &light_pos[0]);

	glEnable(GL_LIGHT1);
	glPopMatrix();

	//_house_texture.bind();
	//_house_model.draw();
	//draw_pyramid(3,1,2);
	//draw_cone(12,1,2);
	//_sphere_tex.bind();
	//draw_disco_ball(16,8,1.0);
//	draw_sphere(16,8,1.0);
	//_cylinder_texture.bind();
	//draw_prism(5,2,1);
	//draw_cylinder(12,1,2);
}

void housewindow::setupGL() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_FOG);

	glFogf(GL_FOG_END,70.f);
	glFogf(GL_FOG_DENSITY, 0.2f);
	glFogi(GL_FOG_MODE,GL_LINEAR);

	glClearColor(0.1f,0.25f,0.45f,1.0f);
	double aspect_ratio=double(width())/double(height());
	glMatrixMode(GL_PROJECTION);
	gluPerspective (45.0, aspect_ratio, 0.1,120.0);
	glMatrixMode(GL_MODELVIEW);
}

void housewindow::handle_event(const SDL_Event &event) {
	switch(event.type){
	case SDL_MOUSEMOTION:
		_player.turn_phi(-event.motion.xrel*player::TURN_ANGLE);
		_player.turn_theta(event.motion.yrel*player::TURN_ANGLE);
		break;
	case SDL_KEYDOWN:
		if(event.key.keysym.scancode==SDL_SCANCODE_F)
			_player.toggle_fly();
		break;
	}
}

void housewindow::handle_keys(const Uint8 *keys) {
	if(keys[SDL_SCANCODE_W]) _player.move_forward();
	if(keys[SDL_SCANCODE_S]) _player.move_backward();
	if(keys[SDL_SCANCODE_A]) _player.move_left();
	if(keys[SDL_SCANCODE_D]) _player.move_right();

}
