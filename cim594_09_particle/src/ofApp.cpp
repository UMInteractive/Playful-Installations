
// Example from Zach Lieberman, http://github.com/ofZach/algo2012
// https://github.com/ofZach/algo2012/tree/master/week4/multiParticles


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    gem.load("gem.png");
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    // on every frame
    // we reset the forces
    // add in any forces on the particle
    // perfom damping and
    // then update
    
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        //particles[i].addForce(0,0.04);  // gravity
        particles[i].bounceOffWalls();
        particles[i].addDampingForce();
        particles[i].update();
    }
    if(ofGetFrameNum()%60 == 0) {
        ofColor tmpColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
        Particle myParticle;
        float vx = ofRandom(-1,1);
        float vy = ofRandom(-1,1);
        myParticle.setInitialCondition(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),vx, vy);
        myParticle.color = tmpColor;
        // more interesting with diversity :)
        // uncomment this:
        myParticle.damping = ofRandom(0.01, 0.05);
        myParticle.addImage(gem);
        particles.push_back(myParticle);
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

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
        ofColor tmpColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
        Particle myParticle;
        float vx = ofRandom(-1,1);
        float vy = ofRandom(-1,1);
        myParticle.setInitialCondition(x,y,vx, vy);
        myParticle.color = tmpColor;
        // more interesting with diversity :)
        // uncomment this:
        myParticle.damping = ofRandom(0.01, 0.05);
        myParticle.addImage(gem);
        particles.push_back(myParticle);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
/*
    ofColor tmpColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));

    for (int i = 0; i < particles.size(); i++){
        float vx = ofRandom(-10,10);
        float vy = ofRandom(5,10);
        particles[i].color = tmpColor;
        particles[i].a = 255;

        particles[i].setInitialCondition(mouseX,mouseY,vx, vy);
        
    }
*/
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
