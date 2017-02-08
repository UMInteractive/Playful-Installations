#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sounds[0].load("beast.wav");
    sounds[1].load("synth.wav");
    sounds[2].load("reverse.wav");
    sounds[0].setMultiPlay(true);
    sounds[1].setMultiPlay(true);
    sounds[2].setMultiPlay(true);
    currentSound = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < 3; i++) {
        if(sounds[i].isPlaying()) {
            ofSetColor(0,255,0);
            ofSetColor(0);
            float curPos = i + (i * (ofGetWidth()/10));
            
            ofDrawCircle(curPos + ofMap(sounds[i].getPosition(), 0, 1, 0, ofGetWidth()/10), ofGetWidth()/10, 3);
        }
        else {
            ofSetColor(255, 0, 0);
        }
        ofDrawRectangle(i + (i * (ofGetWidth()/10)), 20, ofGetWidth()/10, 20);
        ofSetColor(255,255,255);
        ofDrawBitmapString(ofToString(i), i + (i * (ofGetWidth()/10)), 20);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '0') {
        sounds[0].play();
    }
    
    if(key == '1') {
        sounds[1].play();
    }
    
    if(key == '2') {
        sounds[2].play();
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
