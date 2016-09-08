//
//  Item_misiileController.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 21..
//
//

#ifndef Item_misiileController_h
#define Item_misiileController_h

#include "ofMain.h"

class Item_misiileController {
public:
    float start_time;
    float interval_time;
    void setup(float e);
    bool should_spawn();
};

#endif /* Item_misiileController_h */
