//
//  Fish.h
//  HCI_Final ver4
//
//  Created by 임동준 on 2016. 9. 7..
//
//

#ifndef Fish_h
#define Fish_h
#include "ofMain.h"

#endif /* Fish_h */

class Fish
{
public:
    Fish(float x, float y);
    ~Fish(void);
    
    void init(ofImage * _img);
    void setVelocity();
//    void setup();
    void update();
    void draw();
    void checkBoundary();
    void changeFishProperties();
    void stopIncreasing();
    

    ofVec3f getPosition()				{ return m_Position; }
    ofVec3f getVelocity()				{ return m_Velocity; }
    void    setVelocity(ofVec3f change)	{ m_Velocity = change; }
    
public:
    
    ofImage *fish;
    bool m_IsChanging;
    ofVec3f m_Position;
    ofVec3f m_Velocity;
    float width, height;
};

