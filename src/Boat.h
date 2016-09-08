//
//  Boat.h
//  HCI_Final
//
//  Created by 임동준 on 2016. 8. 28..
//
//
#include "ofMain.h"
#ifndef Boat_h
#define Boat_h
class Boat {
public:
    Boat();
    ~Boat();
    void setup(ofImage boat_image);
    void update();
    void draw();
    void x_update();
    void y_update();
public:
    ofPoint pos;
    float speed;
    float width;
    float height;
    ofImage img;
};


#endif /* Boat_h */
