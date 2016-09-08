//
//  Item_missile.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 21..
//
//

#include <stdio.h>
#include "Item_missile.h"

void Item_missile::setup(bool f_p, float max_missile_amplitude, ofImage * missile_image) {
    from_player = f_p;
    pos.x = ofRandom(ofGetWidth());
    pos.y = 0;
    img = missile_image;
    width = 60;
    speed = ofRandom(1, 3);
    amplitude = ofRandom(max_missile_amplitude);
}


void Item_missile::update() {
    if (from_player) {
        pos.y -= speed;
    } else {
        pos.y += speed;
    }
}

void Item_missile::draw() {
    img->draw(pos.x - width/2, pos.y - width/2, width, width);
}

