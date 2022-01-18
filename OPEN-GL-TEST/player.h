/*
 * player.h
 *
 *  Created on: 15 дек. 2021 г.
 *      Author: Семен Беляев
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <glm/glm.hpp>
#include "primitive.h"

class player {
public:
	static constexpr  float DEFAULT_DISTANCE=0.05;
	static constexpr float TURN_ANGLE=0.0025;
protected:
	glm::vec3 _position;
	float _phi;
	float _theta;
	bool _fly;

public:
	player(const glm::vec3 start, float phi, float theta):_position(start), _phi(phi),_theta(),_fly(false){}
	virtual ~player() = default;

	inline auto &position() const {return _position;}
	inline auto center() const {return position()+sph2cart(glm::vec3(1.0f,_phi,_theta));}

	bool fly_enabled() const {return _fly;}
	void set_fly(bool mode){_fly=mode;}
	void toggle_fly() {_fly=not _fly;}
	void move_forward(float dist=DEFAULT_DISTANCE);
	void move_backward(float dist=DEFAULT_DISTANCE);
	void move_left(float dist=DEFAULT_DISTANCE);
	void move_right(float dist=DEFAULT_DISTANCE);
	void turn_phi(float angle);
	void turn_theta(float angle);

};

#endif /* PLAYER_H_ */

