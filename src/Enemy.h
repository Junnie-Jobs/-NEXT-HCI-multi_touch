//
//  Enemy.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 1..
//
//
#include "ofMain.h"
#ifndef Enemy_h
#define Enemy_h

class Enemy {
public:
    void setup(float max_enemy_amplitude, float max_enemy_shoot_interval, ofImage * enemy_image);
    void update();
    void draw();
    bool time_to_shoot();
public:
    ofPoint pos;
    float speed;
    float amplitude;
    float width;
    float start_shoot;
    float shoot_interval;
    ofImage * img;
};

#endif /* Enemy_h */
