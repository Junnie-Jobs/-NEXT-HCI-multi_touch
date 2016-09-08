#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    world_map = new WorldMap();
    world_map->setup();
    game_status = "map_init";
    
    //Connect to Port
    myTuio.connect(3333);
    
    //Assign Global TUIO Callback Functions
    ofAddListener(ofEvents().touchDown, this, &ofApp::touchDown);
    ofAddListener(ofEvents().touchUp, this, &ofApp::touchUp);
    ofAddListener(ofEvents().touchMoved, this, &ofApp::touchMoved);

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    myTuio.update();
//    
    if(game_status == "map_init"){
        world_map->update();
    }
//
    if(world_map->boat_step == "first"){
        pos_a = world_map->island_A->pos;
        pos_b = world_map->island_B->pos;
        pos_c = world_map->island_C->pos;
        pos_d = world_map->island_D->pos;
        pos_e = world_map->island_E->pos;

    }
//
    if(game_status == "first_island"){
        stage1->update();
    }
//
//    if(game_status == "after_first_island"){
//        world_map->update();
//    }
//
    if(game_status == "second_island"){
        stage2->update();
    }
//
    if(game_status == "third_island"){
        stage3->update();
    }
    
    if(game_status == "fourth_island"){
        stage4->update();
    }
    
    if(game_status == "fifth_island"){
        
        stage5->update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(game_status == "map_init"){
        world_map->draw();
    }
//
    if(game_status == "first_island"){
        stage1->draw();
    }
//
//    if(game_status == "after_first_island"){
//        world_map->draw();
//    }
//    
    if(game_status == "second_island"){
        stage2->draw();
    }
//
    if(game_status == "third_island"){
        stage3->draw();
    }
    
    if(game_status == "fourth_island"){
        stage4->draw();    }
    
    if(game_status == "fifth_island"){
        stage5->draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    
    if(game_status == "first_island"){
        stage1->keyPressed(key);
    }

    if(key == '1'){
        game_status = "first_island";
        stage1 = new Stage_1();
        stage1->setup();
        
    }else if(key == '2'){
        
        stage1->game_state = "start";
        game_status = "second_island";
        stage2 = new Stage_2();
        stage2->setup();
        
    }else if(key == '3'){
        
        stage1->game_state = "start";
        game_status = "third_island";
        stage3 = new Stage_3();
        stage3->setup();
        
    }else if(key == '4'){
        
        stage1->game_state = "start";
        game_status = "fourth_island";
        stage4 = new Stage_4();
        stage4->setup();
        
    }else if(key == '5'){
        
        stage1->game_state = "start";
        game_status = "fifth_island";
        stage5 = new Stage_5();
        stage5->setup();
        
    }else if(key == '0'){
        stage1->game_state = "start";
        game_status = "map_init";
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
//    if(game_status == "first_island"){
//        stage1->keyReleased(key);
//    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    
    if(game_status == "map_init"){
        world_map->mouseDragged(x, y, button);
    }

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    if(game_status == "map_init"){
        world_map->mousePressed(x, y, button);
    }
  
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    if(game_status == "map_init"){
        world_map->mouseReleased(x, y, button);
    }
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

void ofApp::touchDown(ofTouchEventArgs & touch){
    
//    if(game_status == "map_init"){
//        world_map->touchDown(touch);
//    }
    
    if(game_status == "first_island"){
        stage1->touchDown(touch);
    }
    
    if(game_status == "second_island"){
        stage2->touchDown(touch);
    }
    
    if(game_status == "third_island"){
        stage3->touchDown(touch);
    }
    
    if(game_status == "fourth_island"){
        stage4->touchDown(touch);
    }
    
    if(game_status == "fifth_island"){
        stage5->touchDown(touch);
    }
}

void ofApp::touchUp(ofTouchEventArgs & touch){

    if(game_status == "first_island"){
        stage1->touchUp(touch);
    }
    
    if(game_status == "second_island"){
        stage2->touchUp(touch);
    }
    
    if(game_status == "third_island"){
        stage3->touchUp(touch);
    }
    
    if(game_status == "fourth_island"){
        stage4->touchUp(touch);
    }
    
    if(game_status == "fifth_island"){
        stage5->touchUp(touch);
    }
    
}

void ofApp::touchMoved(ofTouchEventArgs & touch){

    if(game_status == "first_island"){
        stage1->touchMoved(touch);
    }
    
    if(game_status == "second_island"){
        stage2->touchMoved(touch);
    }
    
    if(game_status == "third_island"){
        stage3->touchMoved(touch);
    }
    
    if(game_status == "fourth_island"){
        stage4->touchMoved(touch);
    }
    
    if(game_status == "fifth_island"){
        stage5->touchMoved(touch);
    }
}



