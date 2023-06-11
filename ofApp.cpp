#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	for (int radius = 200; radius <= 300; radius += 10) {

		ofPushMatrix();
		ofRotateZ(ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.0005), 0, 1, -180, 180));
		ofRotateY(ofRandom(360) + ofGetFrameNum() * 3);

		this->draw_arrow(glm::vec3(0, 0, radius), glm::vec3(1, 0, radius), 30, ofColor(255), ofColor(0));

		ofNoFill();
		ofSetColor(0, 128);
		ofSetLineWidth(1);
		ofBeginShape();
		for (int deg = 0; deg < 360; deg += 3) {

			ofVertex(glm::vec3((radius - 3) * cos(deg * DEG_TO_RAD), 0, (radius - 3) * sin(deg * DEG_TO_RAD)));
		}
		ofEndShape(true);

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::draw_arrow(glm::vec3 location, glm::vec3 next_location, float size, ofColor fill_color, ofColor no_fill_color) {

	auto angle = std::atan2(next_location.y - location.y, next_location.x - location.x);

	ofSetColor(fill_color);
	ofFill();
	ofBeginShape();
	ofVertex(glm::vec3(size * 0.8 * cos(angle), size * 0.8 * sin(angle), 0) + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5), 0) + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5), 0) + location);
	ofEndShape(true);

	ofBeginShape();
	ofVertex(glm::vec3(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5), 0) * 0.25 + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5), 0) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5 + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5), 0) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5 + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5), 0) * 0.25 + location);
	ofEndShape(true);

	ofSetColor(no_fill_color);
	ofNoFill();
	ofSetLineWidth(3);
	ofBeginShape();
	ofVertex(glm::vec3(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5), 0) * 0.25 + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5), 0) + location);
	ofVertex(glm::vec3(size * 0.8 * cos(angle), size * 0.8 * sin(angle), 0) + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5), 0) + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5), 0) * 0.25 + location);
	ofEndShape();

	ofBeginShape();
	ofVertex(glm::vec3(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5), 0) * 0.25 + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5), 0) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5 + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5), 0) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5 + location);
	ofVertex(glm::vec3(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5), 0) * 0.25 + location);
	ofEndShape();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}