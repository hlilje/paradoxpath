#include "test.hpp"


void TestEdgeCases() {
    unsigned char pMap[] = {1}; // Single node
    int pOutBuffer[10];

    int nRes = FindPath(0, 0, 0, 0, pMap, 1, 1, pOutBuffer, 10);
    assert(nRes == 0); // Question of definition

    unsigned char pMap2[] = {
        1, 1, 1,
        1, 1, 1
    };
    int pOutBuffer2[2]; // Too small buffer

    nRes = FindPath(0, 0, 2, 1, pMap2, 3, 2, pOutBuffer2, 2);
    assert(nRes == 3);

    assert(pOutBuffer2[0] == 1);
    assert(pOutBuffer2[1] == 2);
}

void TestInvalidLongPath() {
    unsigned char pMap[] = {
        1, 0, 0, 1, 1, 1,
        1, 0, 1, 1, 1, 1,
        1, 0, 0, 1, 1, 0,
        1, 0, 1, 1, 0, 1,
        1, 1, 1, 0, 1, 1,
        0, 0, 0, 0, 0, 1
    };
    int pOutBuffer[100];

    int nRes = FindPath(0, 0, 5, 5, pMap, 6, 6, pOutBuffer, 100);
    assert(nRes == -1);
}

void TestInvalidPath() {
    unsigned char pMap[] = {
        0, 0, 1,
        0, 1, 1,
        1, 0, 1
    };
    int pOutBuffer[7];

    int nRes = FindPath(2, 0, 0, 2, pMap, 3, 3, pOutBuffer, 7);
    assert(nRes == -1);
}

void TestValidLongPath() {
    unsigned char pMap[] = {
        1, 1, 0, 1, 1, 1,
        1, 1, 1, 1, 0, 1,
        1, 1, 0, 1, 0, 1,
        1, 0, 1, 1, 1, 1,
        1, 1, 1, 0, 1, 1,
        0, 0, 0, 0, 1, 1
    };
    int pOutBuffer[100];

    int nRes = FindPath(0, 0, 5, 5, pMap, 6, 6, pOutBuffer, 100);
    assert(nRes == 10);
}

void TestValidOnePath() {
    unsigned char pMap[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 1, 1, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
    };
    int pOutBuffer[100];

    int nRes = FindPath(4, 4, 3, 9, pMap, 10, 10, pOutBuffer, 100);
    assert(nRes == 22);

    assert(pOutBuffer[0] == 45);
    assert(pOutBuffer[9] == 77);
    assert(pOutBuffer[21] == 93);
}

void TestValidPath() {
    unsigned char pMap[] = {
        1, 1, 1, 1,
        0, 1, 0, 1,
        0, 1, 1, 1
    };
    int pOutBuffer[12];

    int nRes = FindPath(0, 0, 1, 2, pMap, 4, 3, pOutBuffer, 12);
    assert(nRes == 3);

    assert(pOutBuffer[0] == 1);
    assert(pOutBuffer[1] == 5);
    assert(pOutBuffer[2] == 9);
}
