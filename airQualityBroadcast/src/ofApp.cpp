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
    timeBetweenBroadcasts = 5;
    timer = ofGetElapsedTimef() + timeBetweenBroadcasts;
    receiver.setup(12345);
}

//--------------------------------------------------------------
void ofApp::update(){
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        ofxOscSender s;
        s.setup(m.getRemoteIp(), 23456);
        ofxOscMessage hello;
        hello.setAddress("/welcome");
        s.sendMessage(hello);
        ofLog(OF_LOG_NOTICE, "New Client " + m.getRemoteIp());

        clients.push_back(s);
    }
    
    
    if(timer < ofGetElapsedTimef()) {
        timer = ofGetElapsedTimef() + timeBetweenBroadcasts;
        if(currentRow > csv.getNumRows()) {
            currentRow = 1;
            ofLog(OF_LOG_NOTICE, "Returning to row 0");
        }
        ofxCsvRow row;
        row = csv.at(currentRow);
        ofLog(OF_LOG_NOTICE, "Broadcasting /pm/" + row.at(2));

        ofxOscMessage pm;
        pm.setAddress("/pm");
        pm.addFloatArg(ofToFloat(row.at(2)));
        for(int i = 0; i < clients.size(); i++) {
            clients[i].sendMessage(pm);

            ofLog(OF_LOG_NOTICE, "Sent to Client " + i);

        }
        currentRow++;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

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
