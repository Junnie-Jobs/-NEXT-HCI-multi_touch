//
//  WorldMap.cpp
//  HCI_Final
//
//  Created by 임동준 on 2016. 8. 30..
//
//

#include <stdio.h>
#include "WorldMap.h"

//--------------------------------------------------------------
WorldMap::WorldMap() {}
WorldMap::~WorldMap() {}

void WorldMap::setup(){
    
    map_background.load("treasuremap.png");
    island_a.load("island_a.png");
    island_b.load("island_b.png");
    island_c.load("island_c.png");
    island_d.load("island_d.png");
    island_e.load("island_e.png");
    
    boat_image.load("boat.png");
    boat_drawing_finished = false;
    boat = new Boat();
    boat->setup(boat_image);
    
    island_A = new Island();
    island_A->setup(island_a, "island_A");
    island_A_Pressed = false;
    island_A_Complete = false;
    
    island_B = new Island();
    island_B->setup(island_b, "island_B");
    island_B_Pressed = false;
    island_B_Complete = false;
    
    island_C = new Island();
    island_C->setup(island_c, "island_C");
    island_C_Pressed = false;
    island_C_Complete = false;
    
    island_D = new Island();
    island_D->setup(island_d, "island_D");
    island_D_Pressed = false;
    island_D_Complete = false;
    
    island_E = new Island();
    island_E->setup(island_e, "island_E");
    island_E_Pressed = false;
    island_E_Complete = false;
    
    all_island_Completed = false;
    boat_step = "zero";
    
    game_status = "before_first_island";
    
}

void WorldMap::setup_again(){
    
    boat_drawing_finished = true;
    island_A_Pressed = false;
    island_A_Complete = true;
    island_B_Pressed = false;
    island_B_Complete = true;
    island_C_Pressed = false;
    island_C_Complete = true;
    island_D_Pressed = false;
    island_D_Complete = true;
    island_E_Pressed = false;
    island_E_Complete = true;
    
    all_island_Completed = true;
    boat_step = "first";
    
}


//--------------------------------------------------------------
void WorldMap::draw(){
    map_background.draw(0, 0, ofGetWidth(), ofGetHeight());
    island_A->img.draw(ofGetWidth()-200,ofGetHeight()-100,100,100);
    island_B->img.draw(ofGetWidth()-300,ofGetHeight()-100,100,100);
    island_C->img.draw(ofGetWidth()-400,ofGetHeight()-100,100,100);
    island_D->img.draw(ofGetWidth()-500,ofGetHeight()-100,100,100);
    island_E->img.draw(ofGetWidth()-600,ofGetHeight()-100,100,100);
    
    if(game_status == "before_first_island"){
        if(island_A_Pressed){
            island_A->draw(island_a);
        }
        if(island_A_Complete){
            island_A->draw(island_a);
        }
        
        if(island_B_Pressed){
            island_B->draw(island_b);
        }
        if(island_B_Complete){
            island_B->draw(island_b);
        }
        
        if(island_C_Pressed){
            island_C->draw(island_c);
        }
        if(island_C_Complete){
            island_C->draw(island_c);
        }
        
        if(island_D_Pressed){
            island_D->draw(island_d);
        }
        if(island_D_Complete){
            island_D->draw(island_d);
        }
        
        if(island_E_Pressed){
            island_E->draw(island_e);
        }
        if(island_E_Complete){
            island_E->draw(island_e);
        }
        
        if(all_island_Completed){
            boat->draw();
        }
        
        if(island_A_Complete && island_B_Complete){
            if(island_C_Complete && island_D_Complete){
                if(island_E_Complete){
                    all_island_Completed = true;
                }
            }
        }
    
    }
    
    if(game_status == "after_first_island"){
        island_A->draw(island_a);
        island_B->draw(island_b);
        island_C->draw(island_c);
        island_D->draw(island_d);
        island_E->draw(island_e);
    }

}

//--------------------------------------------------------------
void WorldMap::update(){
    ofBackground(255);
    
    if(game_status == "before_first_island"){
        if(all_island_Completed && boat->pos.x <= island_A->pos.x){
            boat->x_update();
        }
        
        if(all_island_Completed && boat->pos.x >= island_A->pos.y){
            boat->y_update();
        }
        
        if(all_island_Completed && boat->pos.x >= island_A->pos.x - 5){
            boat_step = "first";
        }
        
        if(island_A_Complete){
            island_A_Pressed = false;
        }
        
        if(island_B_Complete){
            island_B_Pressed = false;
        }
        
        if(island_C_Complete){
            island_C_Pressed = false;
        }
        
        if(island_D_Complete){
            island_D_Pressed = false;
        }
        
        if(island_E_Complete){
            island_E_Pressed = false;
        }
    }
    
    }


//마우스를 클릭할 때 발생하는 이벤트
//--------------------------------------------------------------
void WorldMap::mousePressed(int x, int y, int button){
    
    
    if(island_A->inside(x, y, "island_A")){
        island_A_Pressed = true;
    }else if(island_B->inside(x, y, "island_B")){
        island_B_Pressed = true;
    }else if(island_C->inside(x, y, "island_C")){
        island_C_Pressed = true;
    }else if(island_D->inside(x, y, "island_D")){
        island_D_Pressed = true;
    }else if(island_E->inside(x, y, "island_E")){
        island_E_Pressed = true;
    }else{
        return;
    }
}

//마우스로 드래그 할 때--------------------------------------------------------------
void WorldMap::mouseDragged(int x, int y, int button){
    if(island_A_Pressed){
        island_A->add(x, y);
    }
    
    if(island_B_Pressed){
        island_B->add(x, y);
    }
    
    if(island_C_Pressed){
        island_C->add(x, y);
    }
    
    if(island_D_Pressed){
        island_D->add(x, y);
    }
    
    if(island_E_Pressed){
        island_E->add(x, y);
    }
    
}


//마우스를 떼었을 때 발생하는 이벤트
//--------------------------------------------------------------
void WorldMap::mouseReleased(int x, int y, int button){
    
    if(island_A_Pressed){
        island_A_Pressed  = false;
        island_A_Complete = true;
    }
    
    if(island_B_Pressed){
        island_B_Pressed  = false;
        island_B_Complete = true;
    }
    
    if(island_C_Pressed){
        island_C_Pressed  = false;
        island_C_Complete = true;
    }
    
    if(island_D_Pressed){
        island_D_Pressed  = false;
        island_D_Complete = true;
    }
    
    if(island_E_Pressed){
        island_E_Pressed  = false;
        island_E_Complete = true;
    }
}

void WorldMap::load(ofPoint a, ofPoint b, ofPoint c, ofPoint d, ofPoint e){

    island_A->add(a.x+100, a.y+100);
    island_B->add(b.x+100, b.y+100);
    island_C->add(c.x+100, c.y+100);
    island_D->add(d.x+100, d.y+100);
    island_E->add(e.x+100, e.y+100);
}

//--------------------------------------------------------------
void WorldMap::keyPressed(int key){
    
}



//--------------------------------------------------------------
void WorldMap::keyReleased(int key){
    
    
}

//마우스를 움직일 때
//--------------------------------------------------------------
void WorldMap::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void WorldMap::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void WorldMap::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void WorldMap::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void WorldMap::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void WorldMap::dragEvent(ofDragInfo dragInfo){
    
}

