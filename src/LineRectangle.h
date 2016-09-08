//
//  LineRectangle.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 7. 19..
//
//

#ifndef LineRectangle_h
#define LineRectangle_h
#include "ofMain.h"

class Line {
public:
    ofPoint a;
    ofPoint b;
    ofColor color;
};

class LineRectangle {
public:
    LineRectangle();
    ~LineRectangle();
    void setup();
    void add(ofRectangle rect, ofColor c);
    void draw();
    void clear();
    void drawLines();
    void drawingBranchs(int x, int y);
    
    vector<ofRectangle> position;
    vector<ofColor> color;
    vector<ofPoint> drawnPoints;
    vector<Line> lines;
};

#endif /* LineRectangle_h */
