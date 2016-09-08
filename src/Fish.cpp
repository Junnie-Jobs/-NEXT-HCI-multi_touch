//
//  Fish.cpp
//  multitouchTest
//
//  Created by 임동준 on 2016. 9. 7..
//
//

#include <stdio.h>
#include <stdio.h>
#include "ofMain.h"
#include "Fish.h"
#include <stdlib.h>
#include <math.h>

Fish::Fish(float x, float y)
{
    m_Position.x = x * ofGetWidth();
    m_Position.y = y * ofGetHeight();
    m_Velocity.x = 0.0f;
    m_Velocity.y = 0.0f;
    m_IsChanging = false;
}


Fish::~Fish(void)
{
}

void Fish::init(ofImage * _img)
{
    m_IsChanging = true;
    fish = _img;
    width = 20;
    height = 20;
    
}

void Fish::setVelocity()
{
    m_Velocity.x = static_cast<float>(rand() ) / (RAND_MAX / 2) - 1.0f;
    m_Velocity.y = static_cast<float>(rand() ) / (RAND_MAX / 2) - 1.0f;
}

void Fish::update()
{
    if (m_IsChanging)
        changeFishProperties();
    
    m_Position += m_Velocity;
}

void Fish::draw()
{
    //ofSetColor(m_colorList[static_cast<unsigned int>(m_ColorIdx) % COLOR_NUMBER]);
    fish->draw(m_Position.x, m_Position.y, width, height);
}

void Fish::changeFishProperties()
{
    fish->draw(m_Position.x, m_Position.y, width, height);
    width = width+0.5;
    height = height+0.5;
}

void Fish::stopIncreasing()
{
    m_IsChanging = false;
}

void Fish::checkBoundary()
{
    if (m_Position.x - width/2 < 0) {
        m_Velocity.x *= -1;
        m_Position.x = width/2;
    } else if (m_Position.x + width/2 > ofGetWidth()) {
        m_Velocity.x *= -1;
        m_Position.x = ofGetWidth() - width/2;
    }
    
    if (m_Position.y - height/2 < 0) {
        m_Velocity.y *= -1;
        m_Position.y = height/2;
    } else if (m_Position.y + height/2 > ofGetHeight()){
        m_Velocity.y *= -1;
        m_Position.y = ofGetHeight() - height/2;
    }
}