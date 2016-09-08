//
//  Item_potion.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 20..
//
//

#include <stdio.h>
#include <Item_potion.h>

void Item_potion::setup(bool f_p, float max_potion_amplitude, ofImage * potion_image) {
    from_player = f_p;
    pos.x = ofRandom(ofGetWidth());
    pos.y = 0;
    img = potion_image;
    width = 60;
    speed = ofRandom(1, 3);
    amplitude = ofRandom(max_potion_amplitude);
}


void Item_potion::update() {
    if (from_player) {
        pos.y -= speed;
    } else {
        pos.y += speed;
    }
}

void Item_potion::draw() {
    img->draw(pos.x - width/2, pos.y - width/2, width, width);
}

