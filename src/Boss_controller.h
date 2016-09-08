//
//  Boss_controller.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 21..
//
//

#ifndef Boss_controller_h
#define Boss_controller_h
#include "ofMain.h"

class Boss_controller {
public:
    float start_time;
    float interval_time;
    void setup(float e);
    bool should_spawn();
};

#endif /* Boss_controller_h */
