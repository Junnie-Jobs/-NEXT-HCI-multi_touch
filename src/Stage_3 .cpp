//
//  Stage_3.cpp
//  HCI_Final ver4
//
//  Created by 임동준 on 2016. 9. 7..
//
//

#include <stdio.h>
#include "Stage_3 .h"

Stage_3::Stage_3() {}
Stage_3::~Stage_3() {}
//--------------------------------------------------------------
void Stage_3::setup(){
    ofEnableAlphaBlending();
    
    srcImg.load("underwater2.png");
    dstImg.load("underwater_cover.png");
    brushImg.load("brush.png");
    
    int width = ofGetWidth();
    int height = ofGetHeight();
    
    maskFbo.allocate(ofGetWidth(),ofGetHeight());
    fbo.allocate(ofGetWidth(),ofGetHeight());
    
#ifdef TARGET_OPENGLES
    shader.load("shaders_gles/alphamask.vert","shaders_gles/alphamask.frag");
#else
    if(ofIsGLProgrammableRenderer()){
        string vertex = "#version 150\n\
        \n\
        uniform mat4 projectionMatrix;\n\
        uniform mat4 modelViewMatrix;\n\
        uniform mat4 modelViewProjectionMatrix;\n\
        \n\
        \n\
        in vec4  position;\n\
        in vec2  texcoord;\n\
        \n\
        out vec2 texCoordVarying;\n\
        \n\
        void main()\n\
        {\n\
        texCoordVarying = texcoord;\
        gl_Position = modelViewProjectionMatrix * position;\n\
        }";
        string fragment = "#version 150\n\
        \n\
        uniform sampler2DRect tex0;\
        uniform sampler2DRect maskTex;\
        in vec2 texCoordVarying;\n\
        \
        out vec4 fragColor;\n\
        void main (void){\
        vec2 pos = texCoordVarying;\
        \
        vec3 src = texture(tex0, pos).rgb;\
        float mask = texture(maskTex, pos).r;\
        \
        fragColor = vec4( src , mask);\
        }";
        shader.setupShaderFromSource(GL_VERTEX_SHADER, vertex);
        shader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragment);
        shader.bindDefaults();
        shader.linkProgram();
    }else{
        string shaderProgram = "#version 120\n \
        #extension GL_ARB_texture_rectangle : enable\n \
        \
        uniform sampler2DRect tex0;\
        uniform sampler2DRect maskTex;\
        \
        void main (void){\
        vec2 pos = gl_TexCoord[0].st;\
        \
        vec3 src = texture2DRect(tex0, pos).rgb;\
        float mask = texture2DRect(maskTex, pos).r;\
        \
        gl_FragColor = vec4( src , mask);\
        }";
        shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
        shader.linkProgram();
    }
#endif
    
    maskFbo.begin();
    ofClear(0,0,0,255);
    maskFbo.end();
    
    fbo.begin();
    ofClear(0,0,0,255);
    fbo.end();
    
    bBrushDown = false;
}

//--------------------------------------------------------------
void Stage_3::update(){
    
    // MASK (frame buffer object)
    maskFbo.begin();
    if (bBrushDown){
        brushImg.draw(ofGetMouseX(), ofGetMouseY(),60,60);
    }
    maskFbo.end();
    
    // HERE the shader-masking happends
    fbo.begin();
    // Cleaning everthing with alpha mask on 0 in order to make it transparent for default
    ofClear(0, 0, 0, 0);
    
    shader.begin();
    shader.setUniformTexture("maskTex", maskFbo.getTexture(), 1 );
    
    srcImg.draw(0,0);
    
    shader.end();
    fbo.end();
    
}

//--------------------------------------------------------------
void Stage_3::draw(){
    ofSetColor(255,255);
    srcImg.draw(0,0, ofGetWidth(),ofGetHeight());
    dstImg.draw(0,0, ofGetWidth(),ofGetHeight());
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void Stage_3::keyPressed(int key){
    maskFbo.begin();
    ofClear(0,0,0,255);
    maskFbo.end();
}

void Stage_3::touchDown(ofTouchEventArgs & touch){
     bBrushDown = true;
}

void Stage_3::touchUp(ofTouchEventArgs & touch){
     bBrushDown = false;
}

void Stage_3::touchMoved(ofTouchEventArgs & touch){
}
