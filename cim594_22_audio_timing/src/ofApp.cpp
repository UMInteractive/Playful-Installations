#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mySound.load("impact.wav");
    mySound.setMultiPlay(true);
    mySound.setLoop(false);
    loopReturnLength = 100;
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < sounds.size(); i++) {
        sounds[i].play(currentPosition);
    }
    currentPosition++;
    if(currentPosition >= loopReturnLength) {
        currentPosition = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float currentXPositionOnScreen = ofMap(currentPosition, 0, loopReturnLength, 0, ofGetWidth());
    ofDrawCircle(currentXPositionOnScreen, ofGetHeight()/2, 20);

    for(int i = 0; i < sounds.size(); i++) {
        sounds[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_UP) {
        loopReturnLength--;
    }
    if(key == OF_KEY_DOWN) {
        loopReturnLength++;
    }
    if(loopReturnLength < 10) {
        loopReturnLength == 10;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    TimedSound tmpSound;
    tmpSound.sound = &mySound;
    float xPos = ofMap(x, 0, ofGetWidth(), 0, loopReturnLength);

    tmpSound.setInitialConditions(x,ofGetHeight()/2, xPos);
    sounds.push_back(tmpSound);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
