//
//  LineRectangle.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 7. 19..
//
//

#include "LineRectangle.h"

LineRectangle::LineRectangle() {
}

LineRectangle::~LineRectangle() {
}

void LineRectangle::setup()
{
    position.clear();
    color.clear();
}

void LineRectangle::add(ofRectangle rectangle, ofColor c)
{
    position.push_back(rectangle);
    color.push_back(c);
}

void LineRectangle::clear()
{
    position.clear();
    color.clear();
}

void LineRectangle::draw()
{
    for(int i=0;i<position.size();i++) {
        ofSetColor(color[i]);
        ofSetRectMode(OF_RECTMODE_CORNER);
        ofDrawRectangle(position[i]);
    }
}

void LineRectangle::drawLines(){
      for (auto line : lines) {
          ofDrawLine(line.a, line.b);
       }
}

void LineRectangle::drawingBranchs(int x, int y){
    for (auto point : drawnPoints){
        ofPoint mouse;
        mouse.set(x,y);
        float dist = (mouse - point).length();
        if (dist < 30){
            Line lineTemp;
            lineTemp.a = mouse;
            lineTemp.b = point;
            lineTemp.color = ofColor(255,255,255);
            lines.push_back(lineTemp);
        }
    }
    drawnPoints.push_back(ofPoint(x,y));
}
