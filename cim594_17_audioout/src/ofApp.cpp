#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    beat.load("drumloop.wav");
    beat.setLoop(true);
    beat.play();
    yPos = ofGetHeight();
    changingVolume = false;

}

//--------------------------------------------------------------
void ofApp::update(){
    float vol = ofMap(yPos, ofGetHeight(), 0, 0, 1);
    beat.setVolume(vol);

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawCircle(ofGetWidth()/2, yPos, 20);

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
    if(changingVolume) {
        //make sure we're not out of bounds
        if(y > 20 && y < ofGetHeight() - 20) {
            yPos = y;
        }
    }

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(ofDist(x, y, ofGetWidth()/2, yPos) <= 20) {
        //touching our circle
        changingVolume = true;
        cout << "changing volume" << endl;
    }

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
