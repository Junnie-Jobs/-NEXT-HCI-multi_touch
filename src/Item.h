//
//  Item.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 8..
//
//

#include "ofMain.h"
#ifndef Item_h
#define Item_h

class Item {
public:
    void setup(bool f_p, float max_item_amplitude, ofImage * item_image);
    void update();
    void draw();
public:
    ofPoint pos;
    float speed;
    float amplitude;
    float width;
    float start_shoot;
    float shoot_interval;
    ofImage * img;
    bool from_player;
};


#endif /* Item_h */
