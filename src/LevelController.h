//
//  LevelController.h
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 1..
//
//

#ifndef LevelController_h
#define LevelController_h
#include "ofMain.h"

class LevelController {
public:
    float start_time;
    float interval_time;
    void setup(float e);
    bool should_spawn();
};

#endif /* LevelController_h */
