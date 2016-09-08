//
//  Stage_2.cpp
//  HCI_Final
//
//  Created by 임동준 on 2016. 8. 30..
//
//

#include <stdio.h>
#include <Stage_2.h>

Stage_2::Stage_2() {}
Stage_2::~Stage_2() {}
//--------------------------------------------------------------
void Stage_2::setup(){
    
    position.clear();
    color.clear();
    
    drawButton.setup(ofRectangle(0,0,100,100),ofColor(81,167,249), "pen1");
    clearButton.setup(ofRectangle(100,0,100,100),ofColor(112,191,65), "clear");
    lineButton.setup(ofRectangle(200,0,100,100),ofColor(179,106,226), "line");
    noiseLineButton.setup(ofRectangle(300,0,100,100),ofColor(243,144,25), "noiseLine");
    autoLineButton.setup(ofRectangle(400,0,100,100),ofColor(245,211,40), "autoLine");
    
    penRectangle = new PenRectangle();
    penRectangle->setup();
    
    lineRectangle = new LineRectangle();
    lineRectangle->setup();
    
    noiseLineRectangle = new NoiseLineRectangle();
    noiseLineRectangle->setup();
    
    autoLineRectangle = new AutoLineRectangle();
    autoLineRectangle->setup();
    
    bDrawButton = false;
    bClearButton = false;
    bLineButton = false;
    bNoiseLineButton = false;
    bAutoLineButton = false;
}

//--------------------------------------------------------------
void Stage_2::draw(){
    ofEnableAlphaBlending();
    ofBackground(0, 0, 0);
    
    drawButton.draw();
    clearButton.draw();
    lineButton.draw();
    noiseLineButton.draw();
    autoLineButton.draw();
    
    if (bDrawButton) {
        penRectangle->draw();
    }
    
    if(bLineButton){
        lineRectangle->draw();
        lineRectangle->drawLines();
    }
    
    if(bNoiseLineButton){
        noiseLineRectangle->draw();
        noiseLineRectangle->line.draw();
    }
    
    if(bAutoLineButton){
        autoLineRectangle->draw();
        autoLineRectangle->autoDraw();
    }
}

void Stage_2::update() {
    
    if(bNoiseLineButton){
        noiseLineRectangle->update();
    }
    
    if(bAutoLineButton){
        autoLineRectangle->update();
    }
    
    if (bClearButton) {
        penRectangle->clear();
        lineRectangle->clear();
        noiseLineRectangle->clear();
        position.clear();
        color.clear();
        bClearButton = false;
    }
}

void Stage_2::touchDown(ofTouchEventArgs & touch){
    
    touch.x *= 1000;
    touch.y *= 1000;
    
    if (drawButton.inside(touch.x, touch.y)) {
        cout << "draw button" << endl;
        bDrawButton = true;
        bClearButton = false;
        bLineButton = false;
        bNoiseLineButton = false;
    }
    if (clearButton.inside(touch.x, touch.y)) {
        cout << "clear button" << endl;
        bClearButton = true;
        bDrawButton = false;
        bLineButton = false;
        bNoiseLineButton = false;
        bAutoLineButton = false;
    }
    
    if (lineButton.inside(touch.x, touch.y)){
        
        cout << "line button" << endl;
        bLineButton = true;
        bClearButton = false;
        bDrawButton = false;
        bNoiseLineButton = false;
        bAutoLineButton = false;
    }
    
    if(noiseLineButton.inside(touch.x, touch.y)){
        
        cout << "noiseLine button" << endl;
        bNoiseLineButton = true;
        bClearButton = false;
        bDrawButton = false;
        bLineButton = false;
        bAutoLineButton = false;
    }
    
    if(autoLineButton.inside(touch.x, touch.y)){
        
        cout << "autoLine button" << endl;
        bAutoLineButton = true;
        bNoiseLineButton = false;
        bClearButton = false;
        bDrawButton = false;
        bLineButton = false;
    }
}

void Stage_2::touchUp(ofTouchEventArgs & touch){
    
    touch.x *= 1000;
    touch.y *= 1000;
    
    drawButton.inside(touch.x, touch.y);
    clearButton.inside(touch.x, touch.y);
    lineButton.inside(touch.x, touch.y);
    noiseLineButton.inside(touch.x, touch.y);
    autoLineButton.inside(touch.x, touch.y);
}

void Stage_2::touchMoved(ofTouchEventArgs & touch){
    
    touch.x *= 1000;
    touch.y *= 1000;
    
    if (bDrawButton) {
        penRectangle->add(ofRectangle(touch.x, touch.y,ofRandom(30,50),ofRandom(30,50)),
                          ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
    }
    
    if(bLineButton){
        lineRectangle->drawingBranchs(touch.x, touch.y);
    }
    
    if(bNoiseLineButton){
        noiseLineRectangle->add(touch.x, touch.y);
    }
}
