#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
//#include "ofxAssimpModelLoader.h"
#include "WorldMap.h"
#include "Stage_1.h"
#include "Stage_2.h"
#include "Stage_3 .h"
#include "Stage_4.h"
#include "Stage_5.h"
#include "ofxTuioClient.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void touchDown(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    
    ofxTuioClient myTuio;
    
    bool all_island_Completed;
    
    Stage_1 *stage1;
    Stage_2 *stage2;
    Stage_3 *stage3;
    Stage_4 *stage4;
    Stage_5 *stage5;
    
    WorldMap *world_map;
    
    string game_status;
    
    ofPoint pos_a;
    ofPoint pos_b;
    ofPoint pos_c;
    ofPoint pos_d;
    ofPoint pos_e;
    
};

#endif
