//
//  Bullet.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 1..
//
//

#include "ofMain.h"

#ifndef Bullet_h
#define Bullet_h

class Bullet {
public:
void setup(
    bool f_p, ofPoint p,
    float s, ofImage * bullet_image
);

void update();
void draw();
ofPoint pos;
float speed;
float width;
bool from_player;
ofImage * img;
    
};

#endif /* Bullet_h */
