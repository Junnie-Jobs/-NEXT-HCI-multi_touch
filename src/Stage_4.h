//
//  Stage_4.h
//  HCI_Final ver4
//
//  Created by 임동준 on 2016. 9. 7..
//
//

#ifndef Stage_4_h
#define Stage_4_h
#include "Fish.h"
#include "ofMain.h"
class Stage_4 {
public:
    Stage_4();
    ~Stage_4();
    void setup();
    void update();
    void draw();

    void touchDown(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    
    map<int, Fish> fishMap;
    ofImage fishImage;
    ofImage underwater;
};

#endif /* Stage_4_h */
