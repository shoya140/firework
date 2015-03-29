#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetCircleResolution(32);
    
    ofBackground(0,0,0);
    nBandsToGet = 512;
    
    mySound.loadSound("winter_rain.mp3");
    mySound.setLoop(true);
    mySound.play();
    ofSetLineWidth(4);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    fft = ofSoundGetSpectrum(nBandsToGet);
    angle ++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(float(ofGetWidth())/2, ofGetHeight()/2, -2000);
    ofRotateZ(-angle/10);
    float width = float(ofGetWidth())/float(nBandsToGet)/2.0f;
    for(int i=0;i<nBandsToGet;i++){
        ofSetColor(ofColor::fromHsb(i/2, 140, 255, 100+fft[0]*500));
        ofRotateZ(angle/10);
        ofLine(width*i*3,(ofGetHeight())/2,width*i*3+fft[i],(ofGetHeight()+fft[i]*-400)/2);
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}