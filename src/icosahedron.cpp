#include "icosahedron.h"

//--------------------------------------------------------------
void icosahedron::setup(){
    ofSetVerticalSync(true);

    
    myPhoto.load("gradient.png"); //get color
    
    for (int i=0; i<12; ++i) {
        mesh.addVertex(ofVec3f(vdata[i][0], vdata[i][1], vdata[i][2]));
        int ii = ofMap(i, 0, 12, 0, myPhoto.getWidth());
        ofColor myc = readBackground(ii, ii);
        myc.a = ofRandom(150);
        mesh.addColor(myc);
    }
        
    for (int i=0; i<20; ++i) {
        mesh.addIndex(indices[i][0]);
        mesh.addIndex(indices[i][1]);
        mesh.addIndex(indices[i][2]);
    }
}

//--------------------------------------------------------------
void icosahedron::update(){
    ang+=0.5;
    
    if ((ofGetFrameNum()%5) == 0) {
        for (int i = 60; i < 120; i++) {
            mesh.removeIndex(i);
        }
     
        for (int i=0; i<20; ++i) {
            int r = ofRandom(20);
            int r2 = ofRandom(20);
            int r3 = ofRandom(20);
            mesh.addIndex(indices[r][0]);
            mesh.addIndex(indices[r2][1]);
            mesh.addIndex(indices[r3][2]);
        }
    }
    
}

//--------------------------------------------------------------
void icosahedron::draw(){
    ofBackground(241, 240, 238);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
    ofScale(1.2);
    ofRotateDeg(ang, 1.0, 1.0, 1.0);
    mesh.drawFaces();
    ofPopMatrix();
    
    myImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
}
//--------------------------------------------------------------
void icosahedron::keyReleased(int key){
    if (key == 'S' || key == 's') {
        myImage.save(ofGetTimestampString("%Y%m%d%H%M%S")+"##.png");
    }
}

//--------------------------------------------------------------
ofColor icosahedron::readBackground(float x, float y){
    ofPixels pixels = myPhoto.getPixels();
    ofColor c = pixels.getColor(x, y);
    return c;
    
}
