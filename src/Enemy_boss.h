//
//  Enemy_boss.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 21..
//
//

#ifndef Enemy_boss_h
#define Enemy_boss_h
#include "ofMain.h"

class Enemy_boss {
public:
    void setup(float max_enemy_boss_amplitude, ofImage * enemy_image);
    void update();
    void draw();
public:
    ofPoint pos;
    float speed;
    float amplitude;
    float width;
    ofImage * img;
    int life;
};


#endif /* Enemy_boss_h */
