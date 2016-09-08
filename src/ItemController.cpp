//
//  ItemController.cpp
//  DrawingCircle
//
//  Created by 임동준 on 2016. 8. 17..
//
//

#include <stdio.h>
#include "ItemController.h"

void ItemController::setup(float s) {
    start_time = s;
    interval_time = 3000;
}
bool ItemController::should_spawn() {
    if (ofGetElapsedTimeMillis() - start_time > interval_time) {
        start_time = ofGetElapsedTimeMillis();
        return true;
    }
    return false;
}