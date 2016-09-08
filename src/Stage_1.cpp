//
//  Stage_1.cpp
//  HCI_Final
//
//  Created by ÏûÑÎèôÏ§Ä on 2016. 8. 30..
//
//

#include <stdio.h>
#include "Stage_1.h"

//--------------------------------------------------------------

Stage_1::Stage_1() {}
Stage_1::~Stage_1() {}

void Stage_1::setup(){
    
    game_state = "game";
    score = 0;
    
    start_screen.load("start_screen.png");
    end_screen.load("end_screen.png");
    score_font.load("Gota_Light.otf", 48);
    
    ocean.load("ocean.jpg");
    
    player_image.load("boat_for_shooting.png");
    max_player_shoot_interval = 0.5;
    player_1.setup(&player_image, max_player_shoot_interval);
    
    bullets.clear();
    player_bullet_image.load("player_bullet2.png");
    
    enemies.clear();
    max_enemy_amplitude = 5.0;
    max_enemy_shoot_interval = 1.5;
    enemy_image.load("enemy2.png");
    enemy_bullet_image.load("enemy_bullet2.png");
    
    enemy_bosses.clear();
    max_enemy_boss_amplitude = 0.5;
    enemy_boss_image.load("enemy_boss.png");
    
    items.clear();
    max_item_amplitude = 3.0;
    item_image.load("specialItem.png");
    
    potions.clear();
    max_item_potion_amplitude = 3.0;
    item_potion_image.load("potion.png");
    
    missiles.clear();
    max_item_missile_amplitude = 3.0;
    item_missile_image.load("potion2.png");
    
    level_controller.setup(ofGetElapsedTimeMillis());
    item_controller.setup(ofGetElapsedTimeMillis());
    item_potion_controller.setup(ofGetElapsedTimeMillis());
    item_missile_controller.setup(ofGetElapsedTimeMillis());
    boss_controller.setup(ofGetElapsedTimeMillis());
    
    
    ofSetVerticalSync(true);
    
 
    
}


//--------------------------------------------------------------
void Stage_1::draw(){
    
    ocean.draw(0,0, ofGetWidth(), ofGetHeight());
    
    if(game_state == "game"){
//        ofBackground(3, 101, 191);
        player_1.draw();

        for (int i=0;i<bullets.size();i++) {
            bullets[i].draw();
        }
        
        for(int i=0;i<enemies.size();i++) {
            enemies[i].draw();
        }
        
        for (int i=0;i<enemy_bosses.size();i++) {
            enemy_bosses[i].draw();
        }
        
        for (int i=0;i<items.size();i++) {
            items[i].draw();
        }
        
        for (int i=0;i<potions.size();i++) {
            potions[i].draw();
        }
        
        for (int i=0;i<missiles.size();i++) {
            missiles[i].draw();
        }

        draw_lives();
        draw_scores();
        
    } else if (game_state == "end") {
        end_screen.draw(0, 0, ofGetWidth(), ofGetHeight());
        draw_scores();
    }
}

void Stage_1::draw_scores() {
    if (game_state == "game") {
        score_font.drawString(ofToString(score), 30, 72);
    } else if (game_state == "end") {
        float w = score_font.stringWidth(ofToString(score));
        score_font.drawString(ofToString(score), ofGetWidth()/2 - w/2, 200);
    }
}


//--------------------------------------------------------------
void Stage_1::update(){
    
    if (game_state == "start") {
        
    } else if (game_state == "game") {
        player_1.update();
        update_bullets();
        update_items();
        update_potions();
        update_missiles();
        //        update_enemy_boss();
        
        for(int i=0;i<enemies.size();i++) {
            enemies[i].update();
            if (enemies[i].time_to_shoot()) {
                Bullet bullet;
                bullet.setup(false, enemies[i].pos, enemies[i].speed, &enemy_bullet_image);
                bullets.push_back(bullet);
            }
            
            if(player_1.time_to_shoot()){
                Bullet b;
                b.setup(true, player_1.pos, player_1.speed, &player_bullet_image);
                bullets.push_back(b);
            }
        }
        
        for(int i=0;i<enemy_bosses.size();i++) {
            enemy_bosses[i].update();
        }
        //
        
        if(level_controller.should_spawn()){
            Enemy e;
            e.setup(max_enemy_amplitude, max_enemy_shoot_interval, &enemy_image);
            enemies.push_back(e);
        }
        
        if(boss_controller.should_spawn()){
            Enemy_boss boss;
            boss.setup(max_enemy_boss_amplitude, &enemy_boss_image);
            enemy_bosses.push_back(boss);
        }
        
        if(item_controller.should_spawn()){
            Item item;
            item.setup(false, max_item_amplitude, &item_image);
            items.push_back(item);
        }
        
        if(item_potion_controller.should_spawn()){
            Item_potion potion;
            potion.setup(false, max_item_potion_amplitude, &item_potion_image);
            potions.push_back(potion);
        }
        
        if(item_missile_controller.should_spawn()){
            Item_missile missile;
            missile.setup(false, max_item_missile_amplitude, &item_missile_image);
            missiles.push_back(missile);
        }
        
        
    } else if (game_state == "end") {
        
    }
    
    
}

void Stage_1::mouseDragged(int x, int y, int button){
    
//        player_1.pos.x = x;
//        player_1.pos.y = y;
//        cout << player_1.pos.x << endl;
}



//--------------------------------------------------------------
void Stage_1::keyPressed(int key){
    
}

void Stage_1::update_bullets() {
    for(int i=0;i<bullets.size();i++) {
        bullets[i].update();
        if (bullets[i].pos.x - bullets[i].width/2 < 0 || bullets[i].pos.y + bullets[i].width/2 > ofGetHeight()) {
            bullets.erase(bullets.begin()+i);
        } }
    check_bullet_collision();
}

void Stage_1::update_items() {
    for(int i=0;i<items.size();i++) {
        items[i].update();
        if (items[i].pos.x - items[i].width/2 < 0 || items[i].pos.y + items[i].width/2 > ofGetHeight()) {
            items.erase(items.begin()+i);
        } }
    check_item_collision();
}

void Stage_1::update_potions() {
    for(int i=0;i<potions.size();i++) {
        potions[i].update();
        if (potions[i].pos.x - potions[i].width/2 < 0 || potions[i].pos.y + potions[i].width/2 > ofGetHeight()) {
            potions.erase(potions.begin()+i);
        } }
    check_potion_collision();
}

void Stage_1::update_missiles() {
    for(int i=0;i<missiles.size();i++) {
        missiles[i].update();
        if (missiles[i].pos.x - missiles[i].width/2 < 0 || missiles[i].pos.y + missiles[i].width/2 > ofGetHeight()) {
            missiles.erase(missiles.begin()+i);
        } }
    check_missile_item_collision();
}


//--------------------------------------------------------------
void Stage_1::keyReleased(int key){
//    
//    if (game_state == "start") {
//        //        game_state = "game";
//        //        level_controller.setup(ofGetElapsedTimeMillis());
//        //        item_controller.setup(ofGetElapsedTimeMillis());
//        //        item_potion_controller.setup(ofGetElapsedTimeMillis());
//        //        item_missile_controller.setup(ofGetElapsedTimeMillis());
//        //        boss_controller.setup(ofGetElapsedTimeMillis());
//    } else if (game_state == "game") {
//        if (key == OF_KEY_LEFT) {
//            player_1.is_left_pressed = false;
//        }
//        if (key == OF_KEY_RIGHT) {
//            player_1.is_right_pressed = false;
//        }
//        if (key == OF_KEY_UP) {
//            player_1.is_up_pressed = false;
//        }
//        if (key == OF_KEY_DOWN) {
//            player_1.is_down_pressed = false;
//        }
//    }
//    
    
}


void Stage_1::check_bullet_collision(void) { for (int i = 0; i < bullets.size(); i++) {
    if (bullets[i].from_player) {
        for (int e = enemies.size()-1; e >= 0; e--) {
            if (ofDist(bullets[i].pos.x, bullets[i].pos.y, enemies[e].pos.x, enemies[e].pos.y) < (enemies[e].width + bullets[i].width)/2) {
                enemies.erase(enemies.begin()+e);
                bullets.erase(bullets.begin()+i);
                score+=10;
            }
        }
        
        for (int b = enemy_bosses.size()-1; b >= 0; b--) {
            if (ofDist(bullets[i].pos.x, bullets[i].pos.y, enemy_bosses[b].pos.x, enemy_bosses[b].pos.y) < (enemy_bosses[b].width + bullets[i].width)/2) {
                bullets.erase(bullets.begin()+i);
                enemy_bosses[b].life--;
                if(enemy_bosses[b].life < 1){
                    enemy_bosses.erase(enemy_bosses.begin()+b);
                    score+=100;
                }
            }
        }
    } else {
        if (ofDist(bullets[i].pos.x, bullets[i].pos.y, player_1.pos.x, player_1.pos.y) <
            (bullets[i].width+player_1.width)/2) { bullets.erase(bullets.begin()+i);
            player_1.lives--;
            if (player_1.lives <= 0) {
                game_state = "end";
            }
        }
    }
}
}

void Stage_1::check_item_collision(void) {
    for (int i = 0; i < items.size(); i++) {
        if (ofDist(items[i].pos.x, items[i].pos.y, player_1.pos.x, player_1.pos.y) <
            (items[i].width+player_1.width)/2) {
            items.erase(items.begin()+i);
            score+=50;
        }
    }
}

void Stage_1::check_potion_collision(void) {
    for (int i = 0; i < potions.size(); i++) {
        if (ofDist(potions[i].pos.x, potions[i].pos.y, player_1.pos.x, player_1.pos.y) <
            (potions[i].width+player_1.width)/2) {
            potions.erase(potions.begin()+i);
            player_1.lives++;
        }
    }
}

void Stage_1::check_missile_item_collision(void) {
    for (int i = 0; i < missiles.size(); i++) {
        if (ofDist(missiles[i].pos.x, missiles[i].pos.y, player_1.pos.x, player_1.pos.y) <
            (missiles[i].width+player_1.width)/2) {
            missiles.erase(missiles.begin()+i);
            
            Bullet b1;
            b1.setup(true, player_1.pos, player_1.speed, &player_bullet_image);
            bullets.push_back(b1);
            
            Bullet b2;
            b2.setup(true, {player_1.pos.x+40, player_1.pos.y+20}, player_1.speed, &player_bullet_image);
            bullets.push_back(b2);
            
            Bullet b3;
            b3.setup(true, {player_1.pos.x+80, player_1.pos.y+40}, player_1.speed, &player_bullet_image);
            bullets.push_back(b3);
            
            Bullet b4;
            b4.setup(true, {player_1.pos.x+120, player_1.pos.y+60}, player_1.speed, &player_bullet_image);
            bullets.push_back(b4);
            
            Bullet b5;
            b5.setup(true, {player_1.pos.x+160, player_1.pos.y+80}, player_1.speed, &player_bullet_image);
            bullets.push_back(b5);
            
            Bullet b6;
            b6.setup(true, {player_1.pos.x+200, player_1.pos.y+100}, player_1.speed, &player_bullet_image);
            bullets.push_back(b6);
            
            Bullet b7;
            b7.setup(true, {player_1.pos.x+240, player_1.pos.y+120}, player_1.speed, &player_bullet_image);
            bullets.push_back(b7);
            
            ////////////////// ////////////////// ////////////////// //////////////////
            
            Bullet b8;
            b8.setup(true, {player_1.pos.x-40, player_1.pos.y+20}, player_1.speed, &player_bullet_image);
            bullets.push_back(b8);
            
            Bullet b9;
            b9.setup(true, {player_1.pos.x-80, player_1.pos.y+40}, player_1.speed, &player_bullet_image);
            bullets.push_back(b9);
            
            Bullet b10;
            b10.setup(true, {player_1.pos.x-120, player_1.pos.y+60}, player_1.speed, &player_bullet_image);
            bullets.push_back(b10);
            
            Bullet b11;
            b11.setup(true, {player_1.pos.x-160, player_1.pos.y+80}, player_1.speed, &player_bullet_image);
            bullets.push_back(b11);
            
            Bullet b12;
            b12.setup(true, {player_1.pos.x-200, player_1.pos.y+100}, player_1.speed, &player_bullet_image);
            bullets.push_back(b12);
            
            Bullet b13;
            b13.setup(true, {player_1.pos.x-240, player_1.pos.y+120}, player_1.speed, &player_bullet_image);
            bullets.push_back(b13);
            
        }
    }
}

void Stage_1::draw_lives() {
    for(int i=0;i<player_1.lives;i++) {
        player_image.draw(ofGetWidth()-(i * 50)-100,30,48,48); }
}

void Stage_1::touchDown(ofTouchEventArgs & touch){
    
    
}

void Stage_1::touchUp(ofTouchEventArgs & touch){
    
}

void Stage_1::touchMoved(ofTouchEventArgs & touch){
        
    player_1.pos.x = touch.x*1000;
    player_1.pos.y = touch.y*1000;
}




