#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mySound.load("impact.wav");
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < sounds.size(); i++) {
        sounds[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < sounds.size(); i++) {
        sounds[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    startTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    TimedSound tmpSound;
    tmpSound.sound = &mySound;
    tmpSound.setInitialConditions(x,y, ofGetElapsedTimef() - startTime);
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
