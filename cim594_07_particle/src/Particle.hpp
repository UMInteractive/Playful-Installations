//
//  Particle.hpp
//  cim594_06_particle
//
//  Created by Clay Ewing on 1/24/17.
//
// Example from Zach Lieberman, http://github.com/ofZach/algo2012
// https://github.com/ofZach/algo2012/tree/master/week4/drawingWithParticles


#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class Particle{
    
public:
    
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
    
    Particle();
    virtual ~Particle(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    
    float damping;
    
protected:
private:
};

#endif // PARTICLE_H
