#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    xPos = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    xPos++;
    if(xPos > ofGetWidth()) {
        xPos = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    redStrokeRectangle(xPos, ofGetHeight()/2);
}

void ofApp::redStrokeRectangle(int x, int y) {
    ofFill();
    ofSetColor(255, 255, 255); //fill color
    ofDrawRectangle(x, y, 50, 50);
    ofNoFill();
    ofSetColor(255, 0, 0);//stroke color
    ofDrawRectangle(x, y, 50, 50);
    
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
