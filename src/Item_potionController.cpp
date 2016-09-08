//
//  Item_potionController.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 20..
//
//

#include <stdio.h>
#include "Item_potionController.h"

void Item_potionController::setup(float s) {
    start_time = s;
    interval_time = 5000;
}
bool Item_potionController::should_spawn() {
    if (ofGetElapsedTimeMillis() - start_time > interval_time) {
        start_time = ofGetElapsedTimeMillis();
        return true;
    }
    return false;
}
