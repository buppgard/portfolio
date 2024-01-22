#pragma once

class TestStats {
    unsigned int _passedTests;
    unsigned int _testsRun;

public:

    TestStats();

    void Run(unsigned int result);
    void Print();
};


