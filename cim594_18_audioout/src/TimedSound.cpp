//
//  TimedSound.cpp
//  cim594_18_audioout
//
//  Created by Clay Ewing on 2/8/17.
//
//

#include "TimedSound.hpp"

TimedSound::TimedSound(){
}

void TimedSound::draw() {
    ofSetColor(255, 0, 0);
    ofDrawCircle(a, 20);
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(ofToString(timeBetweenPlays - ofGetElapsedTimef()), a);
}

void TimedSound::update() {
    
    if(timeBetweenPlays <= ofGetElapsedTimef()) {
        sound->play();
        timeBetweenPlays += timer;
    }
}

void TimedSound::setInitialConditions(int x, int y, float t) {
    sound->setMultiPlay(true);
    sound->play();
    a.set(x,y);
    timer = t;
    timeBetweenPlays = t + ofGetElapsedTimef();
}
