//
//  Particle.cpp
//  cim594_06_particle
//

// Example from Zach Lieberman, http://github.com/ofZach/algo2012
// https://github.com/ofZach/algo2012/tree/master/week4/drawingWithParticles

#include "Particle.hpp"


//------------------------------------------------------------
Particle::Particle(){
    setInitialCondition(0,0,0,0);
    damping = 0.01f;
    radius = 10.0f;
}

//------------------------------------------------------------
void Particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void Particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void Particle::addDampingForce(){
    
    // the usual way to write this is  vel *= 0.99
    // basically, subtract some part of the velocity
    // damping is a force operating in the oposite direction of the
    // velocity vector
    
    //frc = frc - vel * damping;
    
    frc.x -= vel.x * damping;
    frc.y -= vel.y * damping;
}

//------------------------------------------------------------
void Particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
    vel.set(vx,vy);
}

//------------------------------------------------------------
void Particle::update(){
    vel = vel + frc;
    pos = pos + vel;
    radius *= .95f;
}

//------------------------------------------------------------
void Particle::draw(){
    ofDrawCircle(pos.x, pos.y, radius);
}
