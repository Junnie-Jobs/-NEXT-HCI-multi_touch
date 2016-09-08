//
//  PenRectangle.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 7. 18..
//
//

//#include <stdio.h>
#include "PenRectangle.h"
PenRectangle::PenRectangle() {
}
PenRectangle::~PenRectangle() {
}

void PenRectangle::setup()
{
    position.clear();
    color.clear();
}

void PenRectangle::add(ofRectangle rectangle, ofColor c)
{
    position.push_back(rectangle);
    color.push_back(c);
}

void PenRectangle::clear()
{
    position.clear();
    color.clear();
}

void PenRectangle::draw()
{
    for(int i=0;i<position.size();i++) {
        ofSetColor(color[i]);
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofDrawRectangle(position[i]);
    }
}

