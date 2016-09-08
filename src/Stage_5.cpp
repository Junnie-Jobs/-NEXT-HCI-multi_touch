//
//  Stage_5.cpp
//  HCI_Final
//
//  Created by 임동준 on 2016. 8. 30..
//
//

#include <Stage_5.h>

Stage_5::Stage_5() {}
Stage_5::~Stage_5() {}
//--------------------------------------------------------------
void Stage_5::setup() {
    
    galaxy.load("galaxy.jpg");
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void Stage_5::update() {
    
    
    // add points all the time
    if(points.size() < 50000) {
        for (int i=0; i<30; i++) {
            addPoint(ofGetWidth()/2, ofGetHeight()/2);
        }
    }
    
    // move all the points around
    for (unsigned int i=0; i<points.size(); i++) {
        
        speeds[i].y += 0.004; // some grav
        points[i]   += speeds[i];
        
        // move from the mouse
        ofVec2f mouseVec = ofVec2f(ofGetMouseX(), ofGetMouseY()) - points[i];
        if(mouseVec.length() < 100) {
            mouseVec.normalize();
            speeds[i] -= mouseVec;
        }
        
    }

}

//--------------------------------------------------------------
void Stage_5::draw() {
    
        galaxy.draw(0,0, ofGetWidth(), ofGetHeight());
        ofSetColor(255);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, &points[0].x);
        glDrawArrays(GL_POINTS, 0, (int)points.size());
        glDisableClientState(GL_VERTEX_ARRAY);
}

void Stage_5::touchDown(ofTouchEventArgs & touch){
    
}

void Stage_5::touchUp(ofTouchEventArgs & touch){
    points.clear();
    speeds.clear();
}

void Stage_5::touchMoved(ofTouchEventArgs & touch){
    
    touch.x *= 1000;
    touch.y *= 1000;
    
    for (int i=0; i<40; i++) {
        addPoint(touch.x, touch.y);
    }
  }


