//
//  RectButton.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 7. 18..
//
//

#ifndef RectButton_h
#define RectButton_h
#include "ofMain.h"

class RectButton {
public:
    RectButton();
    ~RectButton();
    void setup(ofRectangle _rect, ofColor _color, string _name);
    void draw();
    bool inside(float x, float y);
    string getName();
    
public:
    string name;
    ofRectangle rect;
    ofColor color;
    bool bPressed;
};

#endif /* RectButton_h */
