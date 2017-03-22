#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    terry.load("terry.jpg");
    diameter = 1;
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    
    for(int y = 0; y < terry.getHeight(); y++) {
        for(int x = 0; x < terry.getWidth(); x++) {
            ofColor cur = terry.getColor(x, y);
            //getBrightness will return a number between 0 and 255 for ofColor
            //max brightness = 1 - (255 / 255) = 0
            //min brightness = 1 - (0 / 255) = 1
//            float size = 1 - (cur.getBrightness() / 255);
            float size = 1 - (cur.getHue() / 255);
//            float size = 1 - (cur.getSaturation() / 255);
//            float size = 1 - (cur.getLightness() / 255);

            //as we move the mouse and diameter gets larger, the amount of size (0-1) * (1-10) gets larger/more pronounced
            ofDrawCircle(x * diameter, y * diameter, 1 + size * diameter / 2);
        }
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
    diameter = ofMap(x, 0, ofGetWidth(), 1, 10);
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
