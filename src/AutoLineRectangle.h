//
//  AutoLineRectangle.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 7. 20..
//
//

#ifndef AutoLineRectangle_h
#define AutoLineRectangle_h

#include "ofMain.h"
class AutoLineRectangle {
public:
    AutoLineRectangle();
    ~AutoLineRectangle();
    void setup();
    void add(int x, int y);
    void draw();
    void clear();
    void update();
    void autoDraw();
    
    vector<ofRectangle> position;
    vector<ofColor> color;
    
    ofNode baseNode;
    ofNode childNode;
    ofNode grandChildNode;
    ofPolyline line;
    ofEasyCam cam;
    
};


#endif /* AutoLineRectangle_h */
