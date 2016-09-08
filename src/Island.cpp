//
//  Island.cpp
//  HCI_Final
//
//  Created by 임동준 on 2016. 8. 24..
//

#include <stdio.h>
#include <Island.h>

Island::Island() {}
Island::~Island() {}

void Island::setup(ofImage _img, string _name)
{
    img = _img;
    name = _name;
}

bool Island::inside(int x, int y, string name) {
    if(name == "island_A"){
        if(x > ofGetWidth()-200 && x < ofGetWidth()-100){
            if(y > ofGetHeight()-100 && y <ofGetHeight()){
                return true;
            }
        }
        return false;
    }else if(name == "island_B"){
        
        if(x > ofGetWidth()-300 && x < ofGetWidth()-200){
            if(y > ofGetHeight()-100 && y <ofGetHeight()){
                return true;
            }
        }
        return false;
    }else if(name == "island_C"){
        
        if(x > ofGetWidth()-400 && x < ofGetWidth()-300){
            if(y > ofGetHeight()-100 && y <ofGetHeight()){
                return true;
            }
        }
         return false;
    }else if(name == "island_D"){
        
        if(x > ofGetWidth()-500 && x < ofGetWidth()-400){
            if(y > ofGetHeight()-100 && y <ofGetHeight()){
                return true;
            }
        }
        return false;

    }else if(name == "island_E"){
        
        if(x > ofGetWidth()-600 && x < ofGetWidth()-500){
            if(y > ofGetHeight()-100 && y <ofGetHeight()){
                return true;
            }
        }
        return false;
    }else{
        return;
    }
}

void Island::draw(ofImage img){
    img.draw(pos.x, pos.y, 220, 158);
}

void Island::add(int x, int y){
    pos.x = x-100;
    pos.y = y-100;
}


string Island::getName() {
    return name;
}