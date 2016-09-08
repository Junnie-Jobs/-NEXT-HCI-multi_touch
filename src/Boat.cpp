//
//  Boat.cpp
//  HCI_Final
//
//  Created by 임동준 on 2016. 8. 28..
//
//

#include <stdio.h>
#include "Boat.h"

Boat::Boat() {}
Boat::~Boat() {}

void Boat::setup(ofImage _img) {
    pos.x = 0;
    pos.y = ofGetHeight()-200;
    img = _img;
    width = 200;
    height = 105;
    speed = ofRandom(1,2);
}

void Boat::update() {
    
}

void Boat::x_update(){
    pos.x += speed;
}

void Boat::y_update(){
    pos.y -= speed;
}

void Boat::draw() {
    img.draw(pos.x, pos.y, width, height);
}
