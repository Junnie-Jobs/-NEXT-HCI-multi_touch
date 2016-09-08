//
//  Stage_3.h
//  HCI_Final
//
//  Created by 임동준 on 2016. 8. 30..
//
//

#ifndef Stage_3_h
#define Stage_3_h
#include "ofMain.h"
//#include "Ball.h"

class Stage_3 {
public:
    Stage_3();
    ~Stage_3();
    void setup();
    void update();
    void draw();
    void keyPressed  (int key);
    void touchDown(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    
    ofImage     srcImg;
    ofImage     dstImg;
    ofImage     brushImg;
    
    ofFbo       maskFbo;
    ofFbo       fbo;
    
    ofShader    shader;
    
    bool        bBrushDown;
};


#endif /* Stage_3_h */
