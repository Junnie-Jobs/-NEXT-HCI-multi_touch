//
//  Item_potionController.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 20..
//
//

#ifndef Item_potionController_h
#define Item_potionController_h
#include "ofMain.h"

class Item_potionController {
public:
    float start_time;
    float interval_time;
    void setup(float e);
    bool should_spawn();
};

#endif /* Item_potionController_h */
