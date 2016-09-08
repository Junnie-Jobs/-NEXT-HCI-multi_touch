//
//  Stage_5.h
//  HCI_Final
//
//  Created by 임동준 on 2016. 8. 30..
//
//

#ifndef Stage_5_h
#define Stage_5_h
#include "ofMain.h"

class Stage_5 {
public:
    Stage_5();
    ~Stage_5();
    void setup();
    void update();
    void draw();
    void addPoint(float x, float y) {
        points.push_back(ofVec2f(x, y));
        speeds.push_back(ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1)));
    }
    void touchDown(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);

    
    ofImage galaxy;
    
    vector <ofVec2f> points;
    vector <ofVec2f> speeds;

};


#endif /* Stage_5_h */
