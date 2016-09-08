//
//  PenRectangle.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 7. 18..
//
//

#ifndef PenRectangle_h
#define PenRectangle_h
#include "ofMain.h"

class PenRectangle {
public:
    PenRectangle();
    ~PenRectangle();
    void setup();
    void add(ofRectangle rect, ofColor c);
    void draw();
    void clear();
    
    vector<ofRectangle> position;
    vector<ofColor> color;

};

#endif /* PenRectangle_h */
