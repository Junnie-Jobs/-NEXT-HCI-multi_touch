//
//  NoiseLineRectangle.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 7. 20..
//
//

#include "NoiseLineRectangle.h"


NoiseLineRectangle::NoiseLineRectangle() {
}

NoiseLineRectangle::~NoiseLineRectangle() {
}

void NoiseLineRectangle::setup()
{
    position.clear();
    color.clear();
}


void NoiseLineRectangle::update(){
    for (auto &vert : line.getVertices()){
        vert.x += ofRandom(-1,1);
        vert.y += ofRandom(-1,1);
    }
}

void NoiseLineRectangle::add(int x, int y)
{
    ofPoint pt;
    pt.set(x,y);
    line.addVertex(pt);
}

void NoiseLineRectangle::clear()
{
    position.clear();
    color.clear();
}

void NoiseLineRectangle::draw()
{
    for(int i=0;i<position.size();i++) {
        ofSetColor(color[i]);
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofDrawRectangle(position[i]);
    }
}


