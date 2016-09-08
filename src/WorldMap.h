//
//  WorldMap.h
//  HCI_Final
//
//  Created by 임동준 on 2016. 8. 30..
//
//
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofEvents.h"
#include "Island.h"
#include "Boat.h"
//#include "Stage_1.h"
#ifndef WorldMap_h
#define WorldMap_h
class WorldMap {
public:
    WorldMap();
    ~WorldMap();
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void load(ofPoint a, ofPoint b, ofPoint c, ofPoint d, ofPoint e);
    void setup_again();
public:
    ofImage map_background;
    
    Island *island_A;
    ofImage island_a;
    ofImage island_a_copy;
    bool island_A_Pressed;
    bool island_A_Complete;
    
    Island *island_B;
    ofImage island_b;
    bool island_B_Pressed;
    bool island_B_Complete;
    
    Island *island_C;
    ofImage island_c;
    bool island_C_Pressed;
    bool island_C_Complete;
    
    Island *island_D;
    ofImage island_d;
    bool island_D_Pressed;
    bool island_D_Complete;
    
    Island *island_E;
    ofImage island_e;
    bool island_E_Pressed;
    bool island_E_Complete;
    
    Boat *boat;
    ofImage boat_image;
    bool boat_drawing_finished;
    
    bool all_island_Completed;
    
    string boat_step;
    string game_status;
};

#endif /* WorldMap_h */
