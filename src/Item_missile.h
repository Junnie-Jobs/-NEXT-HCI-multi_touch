//
//  Item_missile.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 21..
//
//

#ifndef Item_missile_h
#define Item_missile_h
#include "ofMain.h"

class Item_missile {
public:
    void setup(bool f_p, float max_missile_amplitude, ofImage * missile_image);
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


#endif /* Item_missile_h */
