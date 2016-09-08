//
//  Item_potion.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 20..
//
//
#include "ofMain.h"
#ifndef Item_potion_h
#define Item_potion_h

class Item_potion {
public:
    void setup(bool f_p, float max_potion_amplitude, ofImage * potion_image);
    void update();
    void draw();
public:
    ofPoint pos;
    float speed;
    float amplitude;
    float width;
    float shoot_interval;
    ofImage * img;
    bool from_player;
};

#endif /* Item_potion_h */
