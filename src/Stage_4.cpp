//
//  Stage_4.cpp
//  HCI_Final ver4
//
//  Created by 임동준 on 2016. 9. 7..
//
//

#include <stdio.h>
#include "Stage_4.h"

Stage_4::Stage_4() {}
Stage_4::~Stage_4() {}
//--------------------------------------------------------------
void Stage_4::setup(){
//    ofBackground(100, 100, 100);
    ofSetVerticalSync(true);
    fishMap.clear();
    underwater.load("underwater3.png");
    fishImage.load("jellyfish.png");

}

//--------------------------------------------------------------
void Stage_4::update(){
    
    map<int, Fish>::iterator iter_Pos;
    for(iter_Pos = fishMap.begin(); iter_Pos != fishMap.end(); ++iter_Pos) {
        iter_Pos->second.checkBoundary();
        iter_Pos->second.update();
    }
}

//--------------------------------------------------------------
void Stage_4::draw(){
    
    underwater.draw(0,0, ofGetWidth(),ofGetHeight());
    
    map<int, Fish>::iterator iter_Pos;
    for(iter_Pos = fishMap.begin(); iter_Pos != fishMap.end(); ++iter_Pos) {
        iter_Pos->second.draw();
    }
}

void Stage_4::touchDown(ofTouchEventArgs & touch){
    
    fishMap.insert(make_pair((int)touch.id, Fish(touch.x,touch.y)));
    fishMap.find(touch.id)->second.init(&fishImage);
    
}

void Stage_4::touchUp(ofTouchEventArgs & touch){
    
    fishMap.find(touch.id)->second.stopIncreasing();
    fishMap.find(touch.id)->second.setVelocity();
    
}

void Stage_4::touchMoved(ofTouchEventArgs & touch){
    
}

