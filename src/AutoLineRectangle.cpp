//
//  AutoLineRectangle.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 7. 20..
//
//

#include "AutoLineRectangle.h"


AutoLineRectangle::AutoLineRectangle() {
}

AutoLineRectangle::~AutoLineRectangle() {
}

void AutoLineRectangle::setup()
{
    position.clear();
    color.clear();
    
    baseNode.setPosition(0, 0, 0);
    childNode.setParent(baseNode);
    childNode.setPosition(0, 0, 200);
    grandChildNode.setParent(childNode);
    grandChildNode.setPosition(0,50,0);
}


void AutoLineRectangle::update(){
    baseNode.pan(1);
    childNode.tilt(3);
    
    line.addVertex(grandChildNode.getGlobalPosition());
    if (line.size() > 200){
        line.getVertices().
        erase(line.getVertices().begin());
    }
}

void AutoLineRectangle::add(int x, int y)
{
    ofPoint pt;
    pt.set(x,y);
    line.addVertex(pt);
}

void AutoLineRectangle::clear()
{
    position.clear();
    color.clear();
}

void AutoLineRectangle::draw()
{
    for(int i=0;i<position.size();i++) {
        ofSetColor(color[i]);
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofDrawRectangle(position[i]);
    }
}

void AutoLineRectangle::autoDraw()
{
    cam.begin();
    //uncomment these 3 lines to understand how nodes are moving
    //baseNode.draw();
    //childNode.draw();
    //grandChildNode.draw();
    line.draw();
    cam.end();
}

