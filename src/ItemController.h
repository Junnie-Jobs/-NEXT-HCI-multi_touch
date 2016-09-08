//
//  ItemController.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 17..
//
//

#ifndef ItemController_h
#define ItemController_h
#include "ofMain.h"

class ItemController {
public:
    float start_time;
    float interval_time;
    void setup(float e);
    bool should_spawn();
};
#endif /* ItemController_h */
