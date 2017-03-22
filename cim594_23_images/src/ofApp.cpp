#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    elijah.load("elijah.jpg");
    ofEnableAlphaBlending();
    for(int y = 0; y < elijah.getHeight(); y+=2) {
        for(int x = 0; x < elijah.getWidth(); x+=2) {
            ofColor cur = elijah.getColor(x, y);
            //getBrightness will return a number between 0 and 255 for ofColor
            //max brightness = 1 - (255 / 255) = 0
            //min brightness = 1 - (0 / 255) = 1
            
            if(cur.getBrightness() > 10) {
                Particle p;
                p.setInitialCondition(x, y, 0, 0);
                p.radius = 2;
                p.a = cur.getBrightness();
                particles.push_back(p);
            }
        }
    }
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
    for(int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for(int i = 0; i < particles.size(); i++) {
        particles[i].vel.set(ofRandom(-2,2), ofRandom(1,5));
    }
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
