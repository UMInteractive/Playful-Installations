#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < sounds.size(); i++) {
        if(sounds[i].isPlaying()) {
            ofFill();
            ofSetColor(0,255,0);
        }
        else {
            ofNoFill();
        }
        ofDrawRectangle(i + (i * ofGetWidth()/sounds.size()), 0, ofGetWidth()/sounds.size(), ofGetHeight());
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
    for(int i = 0; i < sounds.size(); i++) {
        if(x > i + (i * ofGetWidth()/sounds.size()) && x < i + (i * ofGetWidth()/sounds.size()) + ofGetWidth()/sounds.size()) {
            sounds[i].play();
        }
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
    for(int i = 0; i < dragInfo.files.size(); i++) {
        ofSoundPlayer snd;
        snd.load(dragInfo.files[i]);
        sounds.push_back(snd);
    }
}
