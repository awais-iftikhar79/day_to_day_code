#include "Stronghold.h"
Leadership::Leadership() {
	leaderName = "Leader";
	leadershipStyle = 0;
	popularity = 50.0;
}
Leadership::Leadership(const string& name) {
	leaderName = name;
	leadershipStyle = 0;
	popularity = 50.0;
}
void Leadership::update(Kingdom& kingdom) {
	if (leadershipStyle == 0) {
		popularity -= 0.1;
	}
	else {
		popularity += 0.1;
	}
	if (popularity < 0) {
		popularity = 0;
	}
	if (popularity > 100) {
		popularity = 100;
	}
}
void Leadership::holdElection(Kingdom& kingdom) {
	if (leadershipStyle == 1) {
		if (popularity < 50) {
			changeLeader("New Elected Leader", 1);
		}
	}
}
void Leadership::initiateCoup(Kingdom& kingdom) {
	if (leadershipStyle == 0) {
		changeLeader("New Coup Leader", 0);
	}
}
void Leadership::changeLeader(const string& newName, int style) {
	leaderName = newName;
	leadershipStyle = style;
	popularity = 50.0;
}
void Leadership::affectPopularity(double amount) {
	popularity += amount;
	if (popularity < 0) {
		popularity = 0;
	}
	if (popularity > 100) {
		popularity = 100;
	}
}
string Leadership::getLeaderName() const {
	return leaderName;
}
int Leadership::getLeadershipStyle() const {
	return leadershipStyle;
}
double Leadership::getPopularity() const {
	return popularity;
}

int Leadership::getLeadershipLevel() const {
	return static_cast<int>(popularity / 20);
}