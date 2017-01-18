//
//  ball.cpp
//  cim594_01_classes
//
//  Created by Clay Ewing on 1/13/17.
//
//

#include "Ball.h"

Ball::Ball(){
}

void Ball::setup(){
    x = ofRandom(0, ofGetWidth());      // give some random positioning
    y = ofRandom(0, ofGetHeight());
    
    speedX = 2;          // and random speed and direction
    speedY = 2;
    
    diameter = 20;

    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
}

void Ball::update(){
    if(x < 0 ){
        x = 0;
        speedX *= -1;
    } else if(x > ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
    }
    
    if(y < 0 ){
        y = 0;
        speedY *= -1;
    } else if(y > ofGetHeight()){
        y = ofGetHeight();
        speedY *= -1;
    }
    
    x+=speedX;
    y+=speedY;
}

void Ball::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, diameter);
}
