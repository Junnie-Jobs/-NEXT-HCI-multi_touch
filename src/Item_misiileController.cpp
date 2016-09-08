//
//  Item_misiileController.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 21..
//
//

#include <stdio.h>
#include "Item_misiileController.h"

void Item_misiileController::setup(float s) {
    start_time = s;
    interval_time = 2000;
}
bool Item_misiileController::should_spawn() {
    if (ofGetElapsedTimeMillis() - start_time > interval_time) {
        start_time = ofGetElapsedTimeMillis();
        return true;
    }
    return false;
}
