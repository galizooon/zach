/*
 * housewindow.h
 *
 *  Created on: 1 дек. 2021 г.
 *      Author: Семен Беляев
 */

#ifndef HOUSEWINDOW_H_
#define HOUSEWINDOW_H_
#include "Window.h"
#include "Model.h"
#include "Texture.h"
#include "primitive.h"
#include "player.h"


class housewindow: public Window {
private:
	Model _house_model{"house_model.txt"};
	Texture _house_texture{"house_tex.png"};
	//Texture _cylinder_texture{"tex.png"};
	//Texture _cone_texture{"tex.png"};
	//Texture _sphere_tex{"8K.jpg"};
	Texture _sky{"stars.jpg"};
	Texture _snow{"snow.jpg"};
	Texture _moon{"moon.jpg"};
	Texture _tree{"tree.jpg"};
	Texture _bark{"bark.jpg"};
	Texture _carrot{"carrot.jpg"};
	Texture _lamp{"lamp.png"};
	double _angle=0.0;
	player _player{glm::vec3(3.f,3.f,1.5f),0.f,1.6f};
public:
		static constexpr int WINDOW_WIDTH=1024;
		static constexpr int WINDOW_HEIGHT=720;

	virtual void handle_keys(const Uint8 *keys);
	virtual void handle_event(const SDL_Event &event);
	virtual void update();
	virtual void render();
	virtual void setupGL();

public:
	housewindow();
	virtual ~housewindow() = default;
};

#endif /* HOUSEWINDOW_H_ */
