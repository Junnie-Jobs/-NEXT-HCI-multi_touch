//
//  Player.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 1..
//
//

#include <stdio.h>
#include <Player.h>

Player::Player() {
}

void Player::setup(ofImage * _img, float max_player_shoot_interval)
{
    img = _img;
    pos.x = 100;
    pos.y = ofGetHeight() - 100;
    width = 55;
    height= 100;
    speed = 5;
    lives = 5;
    shoot_interval = ofRandom(0.1, max_player_shoot_interval);
    start_shoot = ofGetElapsedTimef();
    
 
}

void Player::update(){

}

void Player::draw()
{
    img->draw(pos.x - width/2, pos.y - height/2 , width, height);
}
void Player::shoot() {
}
void Player::calculate_movement() {
}
bool Player::check_can_shoot() {
}

bool Player::time_to_shoot() {
    if (ofGetElapsedTimef() - start_shoot > shoot_interval) {
        start_shoot = ofGetElapsedTimef();
        return true;
    }
    return false;
}

