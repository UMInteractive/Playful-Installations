#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < particles.size(); i++) {
        particles[i].resetForce();
        particles[i].bounceOffWalls();
        particles[i].addDampingForce();
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for (int i = 0; i < particles.size(); i++){
        particles[i].returning = true;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    for (int i = 0; i < particles.size(); i++){
        particles[i].setInitialCondition(particles[i].o_pos.x, particles[i].o_pos.y, ofRandom(-1,1), ofRandom(-1,1));
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    Particle p;
    p.setInitialCondition(x, y, ofRandom(-1,1), ofRandom(-1,1));
    particles.push_back(p);

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
