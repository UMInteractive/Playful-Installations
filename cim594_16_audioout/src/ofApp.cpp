#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    beat.load("drumloop.wav");
    beat.setLoop(true);
    beat.play();
    xPos = ofGetWidth()/2;
    changingSpeed = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    float speed = ofMap(xPos, 0, ofGetWidth(), -2, 2);
    beat.setSpeed(speed);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawCircle(xPos, ofGetHeight()/2, 20);
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
    if(changingSpeed) {
        //make sure we're not out of bounds
        if(x > 20 && x < ofGetWidth() - 20) {
            xPos = x;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(ofDist(x, y, xPos, ofGetHeight()/2) <= 20) {
        //touching our circle
        changingSpeed = true;
        cout << "changing speed" << endl;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    changingSpeed = false;
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
