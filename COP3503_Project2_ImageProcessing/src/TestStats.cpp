#include <iostream>
#include "TestStats.h"

TestStats::TestStats() : _passedTests(0), _testsRun(0) {}

void TestStats::Run(unsigned int result) {
    _testsRun++;
    _passedTests += result;
}

void TestStats::Print() {
    std::cout << _passedTests << "/" << _testsRun << " tasks completed successfully." << std::endl;
}


