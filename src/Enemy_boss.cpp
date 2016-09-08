//
//  Enemy_boss.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 21..
//
//

#include <stdio.h>
#include "Enemy_boss.h"

void Enemy_boss::setup(float max_enemy_boss_amplitude, ofImage * enemy_boss_image) {
    pos.x = ofRandom(ofGetWidth());
    pos.y = 0;
    img = enemy_boss_image;
    width = 700;
    speed = ofRandom(0, 2);
    amplitude = ofRandom(max_enemy_boss_amplitude);
    life = 15;
}

void Enemy_boss::update() {
    pos.y += speed;
    pos.x += amplitude * sin(ofGetElapsedTimef()); }

void Enemy_boss::draw() {
    img->draw(pos.x - width/2, pos.y - width/2, width, width); }

