//
//  NoiseLineRectangle.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 7. 20..
//
//

#ifndef NoiseLineRectangle_h
#define NoiseLineRectangle_h

#include "ofMain.h"
class NoiseLineRectangle {
public:
    NoiseLineRectangle();
    ~NoiseLineRectangle();
    void setup();
    void add(int x, int y);
    void draw();
    void clear();
    void update();
    void drawLines();
    void drawingBranchs(int x, int y);
    
    vector<ofRectangle> position;
    vector<ofColor> color;
    
    ofPolyline line;

};

#endif /* NoiseLineRectangle_h */
