//
//  Stage_2.h
//  HCI_Final
//
//  Created by 임동준 on 2016. 8. 30..
//
//

#ifndef Stage_2_h
#define Stage_2_h

#include "ofMain.h"
#include "ofEvents.h"
#include "RectButton.h"
#include "PenRectangle.h"
#include "LineRectangle.h"
#include "NoiseLineRectangle.h"
#include "AutoLineRectangle.h"

class Stage_2{
    
public:
    Stage_2();
    ~Stage_2();
    void setup();
    void update();
    void draw();
    
    void touchDown(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    
    vector<ofRectangle> position;
    vector<ofColor> color;
    
    bool bDrawButton;
    bool bClearButton;
    bool bLineButton;
    bool bNoiseLineButton;
    bool bAutoLineButton;
    
    RectButton drawButton;
    RectButton clearButton;
    RectButton lineButton;
    RectButton noiseLineButton;
    RectButton autoLineButton;
    
    PenRectangle *penRectangle;
    LineRectangle *lineRectangle;
    NoiseLineRectangle *noiseLineRectangle;
    AutoLineRectangle *autoLineRectangle;
    
};


#endif /* Stage_2_h */
