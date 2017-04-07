#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    if(csv.load("airmote.csv")) {
        ofLog(OF_LOG_NOTICE, "Data file loaded");
    }
    else {
        ofLog(OF_LOG_ERROR, "Unable to load data file");
    }
    //SKIP HEADER
    currentRow = 1;
    currentPM = 0;
    timeBetweenBroadcasts = 5;
    timer = ofGetElapsedTimef() + timeBetweenBroadcasts;
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    if(timer < ofGetElapsedTimef()) {
        timer = ofGetElapsedTimef() + timeBetweenBroadcasts;
        if(currentRow > csv.getNumRows()) {
            currentRow = 1;
            ofLog(OF_LOG_NOTICE, "Returning to row 0");
        }
        ofxCsvRow row;
        row = csv.at(currentRow);
        ofLog(OF_LOG_NOTICE, "Current PM: " + row.at(2));
        currentPM = ofToFloat(row.at(2));
        currentRow++;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //USE PM FOR VISUALIZATION
    ofSetColor(255, 255, 255);
    ofFill();
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, currentPM);
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
