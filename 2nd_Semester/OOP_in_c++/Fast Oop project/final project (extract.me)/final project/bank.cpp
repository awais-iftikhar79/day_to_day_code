#include "Stronghold.h"
Bank::Bank() : loanAmount(0.0), interestRate(5.0), treasuryBalance(5000.0), fraudDetected(false) {}
void Bank::issueLoan(double amount) {
    if (amount <= 0 || amount > treasuryBalance) {
        return;
    }
    loanAmount += amount;
    treasuryBalance -= amount;
    if (amount > treasuryBalance * 0.5) {
        corruptionLevel += 0.1;
        if (corruptionLevel > 1.0) {
            corruptionLevel = 1.0;
        }
    }
}
void Bank::repayLoan(double amount) {
    if (amount <= 0) {
        return;
    }
    double repayment = (amount > loanAmount) ? loanAmount : amount;
    loanAmount -= repayment;
    treasuryBalance += repayment;
    if (repayment >= loanAmount * 0.2) {
        corruptionLevel -= 0.05;
        if (corruptionLevel < 0.0) {
            corruptionLevel = 0.0;
        }
    }
}
void Bank::detectFraud() {
    if (fraudDetected) {
        treasuryBalance -= 1000.0;
        fraudDetected = false;
    }
    if (loanAmount > treasuryBalance * 0.5) {
        fraudDetected = true;
    }
}
void Bank::update(Kingdom& kingdom) {
    if (fraudDetected) {
        treasuryBalance -= 1000.0;
        fraudDetected = false;
    }
    applyInterest();
    auditTreasury();
    if (corruptionLevel > 0.5) {
        treasuryBalance -= 500.0;
    }
    detectFraud();
}
void Bank::auditTreasury() {
    double detectionThreshold = 1000.0 - (corruptionLevel * 400);
    if (treasuryBalance < detectionThreshold) {
        fraudDetected = true;
        corruptionLevel *= 0.6;
    }
    if ((rand() % 100) < (10 + (corruptionLevel * 15))) {
        fraudDetected = true;
    }
}
void Bank::applyInterest() {
    loanAmount += loanAmount * (interestRate / 100.0);
}
void Bank::deductGold(double amount) {
    if (amount <= 0 || amount > treasuryBalance) {
        return;
    }
    treasuryBalance -= amount;
    if (treasuryBalance < 0) {
        treasuryBalance = 0;
    }
}