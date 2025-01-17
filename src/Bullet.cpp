//
//  Bullet.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 1..
//
//

#include <stdio.h>
#include <Bullet.h>

void Bullet::setup(bool f_p, ofPoint p, float s, ofImage * bullet_image) {
    from_player = f_p;
    pos = p;
    speed = s + 3;
    img = bullet_image;
    width = 50;
}


void Bullet::update() {
    if (from_player) {
        pos.y -= speed;
    } else {
        pos.y += speed;
    }
}

void Bullet::draw() {
    img->draw(pos.x - width/2, pos.y - width/2, width, width);
}