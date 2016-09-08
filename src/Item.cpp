//
//  Item.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 8..
//
//

#include <stdio.h>
#include <Item.h>

void Item::setup(bool f_p, float max_item_amplitude, ofImage * item_image) {
    from_player = f_p;
    pos.x = ofRandom(ofGetWidth());
    pos.y = 0;
    img = item_image;
    width = 60;
    speed = ofRandom(1, 3);
    amplitude = ofRandom(max_item_amplitude);
}

void Item::update() {
    if (from_player) {
                pos.y -= speed;
            } else {
                pos.y += speed;
            }

}

void Item::draw() {
    img->draw(pos.x - width/2, pos.y - width/2, width, width);
}

