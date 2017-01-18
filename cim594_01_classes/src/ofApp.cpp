#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(false);
    baseSpeed = 0;
    for (int i = 0; i < 10; i++) {
        myBall[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < 10; i++) {
        myBall[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < 10; i++) {
        myBall[i].draw();
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
    baseSpeed = ofMap(mouseX, 0, ofGetWidth(), -10, 10);
    for (int i = 0; i < 10; i++) {
        myBall[i].speedX = myBall[i].speedX + baseSpeed;
        myBall[i].speedY = myBall[i].speedY + baseSpeed;
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    baseSpeed = 0;
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
