//
//  RectButton.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 7. 18..
//
//

#include "RectButton.h"

RectButton::RectButton() {}
RectButton::~RectButton() {}

void RectButton::setup(ofRectangle _rect, ofColor _color, string _name)
{
    rect = _rect;
    color = _color;
    name = _name;
    bPressed = false;
}

bool RectButton::inside(float x, float y) {
    if (rect.inside(x, y)) {
        bPressed = !bPressed;
        return true;
    }
    return false;
}

void RectButton::draw()
{
    if (!bPressed) {
        ofSetColor(color);
    } else {
        ofSetColor(30,30,30);
    }
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofDrawRectangle(rect);
}

string RectButton::getName() {
    return name;
}