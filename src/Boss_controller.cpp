//
//  Boss_controller.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 21..
//
//

#include <stdio.h>
#include "Boss_controller.h"

void Boss_controller::setup(float s) {
    start_time = s;
    interval_time = 5000;
}
bool Boss_controller::should_spawn() {
    if (ofGetElapsedTimeMillis() - start_time > interval_time) {
        start_time = ofGetElapsedTimeMillis();
        return true;
    }
    return false;
}