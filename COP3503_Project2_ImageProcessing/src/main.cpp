#include <fstream>
#include <iostream>
#include <string>
#include "TGA.h"
#include "TestStats.h"
#include "leaker.h"
using namespace std;

#define carFile           "input/car.tga"
#define circlesFile       "input/circles.tga"
#define layer1File        "input/layer1.tga"
#define layer2File        "input/layer2.tga"
#define layerBlueFile     "input/layer_blue.tga"
#define layerGreenFile    "input/layer_green.tga"
#define layerRedFile      "input/layer_red.tga"
#define pattern1File      "input/pattern1.tga"
#define pattern2File      "input/pattern2.tga"
#define textFile          "input/text.tga"
#define text2File         "input/text2.tga"

#define example1File      "examples/example_part1.tga"
#define example2File      "examples/example_part2.tga"
#define example3File      "examples/example_part3.tga"
#define example4File      "examples/example_part4.tga"
#define example5File      "examples/example_part5.tga"
#define example6File      "examples/example_part6.tga"
#define example7File      "examples/example_part7.tga"
#define example8_rFile    "examples/example_part8_r.tga"
#define example8_gFile    "examples/example_part8_g.tga"
#define example8_bFile    "examples/example_part8_b.tga"
#define example9File      "examples/example_part9.tga"
#define example10File     "examples/example_part10.tga"
#define exampleECFile     "examples/example_extracredit.tga"

#define outputFile1       "output/test1.tga"
#define outputFile2       "output/test2.tga"
#define outputFile3       "output/test3.tga"
#define outputFile4       "output/test4.tga"
#define outputFile5       "output/test5.tga"
#define outputFile6       "output/test6.tga"
#define outputFile7       "output/test7.tga"
#define outputFile8_r     "output/test8_r.tga"
#define outputFile8_g     "output/test8_g.tga"
#define outputFile8_b     "output/test8_b.tga"
#define outputFile9       "output/test9.tga"
#define outputFile10      "output/test10.tga"
#define outputECFile   "output/extracredit.tga"

int part1(bool debug = false);
int part2(bool debug = false);
int part3(bool debug = false);
int part4(bool debug = false);
int part5(bool debug = false);
int part6(bool debug = false);
int part7(bool debug = false);
int part8(bool debug = false);
int part9(bool debug = false);
int part10(bool debug = false);
int extraCredit(bool debug = false);

bool CompareFiles(string file1, string file2, bool debug = false);

int main(int argc, const char* argv[]) {

    TestStats tests;

    bool debug = false;

    if (argc > 1) {
        string argument = argv[1];
        if (argument == "d") {
            debug = true;
        }
    }

    tests.Run(part1(debug));
    tests.Run(part2(debug));
    tests.Run(part3(debug));
    tests.Run(part4(debug));
    tests.Run(part5(debug));
    tests.Run(part6(debug));
    tests.Run(part7(debug));
    tests.Run(part8(debug));
    tests.Run(part9(debug));
    tests.Run(part10(debug));
    tests.Run(extraCredit(debug));

    tests.Print();

    return 0;
}

int part1(bool debug) {

    if (debug)
        cout << "Part 1: Multiplying " << pattern1File << " and " << layer1File << "..." << endl;

    TGA topLayer(layer1File);
    TGA bottomLayer(pattern1File);
    bottomLayer *= topLayer;
    bottomLayer.WriteTGA(outputFile1);

    if (debug)
        cout << "DONE" << endl;

    if (!CompareFiles(outputFile1, example1File, debug)) {
        cout << "Part one FAILED. :-(" << endl;
        if (debug)
            cout << endl;
        return 0;
    }

    cout << "Part one complete." << endl;
    if (debug)
        cout << endl;
    return 1;
}

int part2(bool debug) {

    if (debug)
        cout << "Part 2: Subtracting " << layer2File << " from " << carFile << "..." << endl;
    
    TGA topLayer(layer2File);
    TGA bottomLayer(carFile);
    bottomLayer -= topLayer;
    bottomLayer.WriteTGA(outputFile2);

    if (debug)
        cout << "DONE" << endl;

    if (!CompareFiles(outputFile2, example2File, debug)){
        cout << "Part two FAILED. :-(" << endl;
        if (debug)
            cout << endl;
        return 0;
    }

    cout << "Part two complete." << endl;
    if (debug)
        cout << endl;
    return 1;
}

int part3(bool debug) {

    if (debug)
        cout << "Part 3: Multiplying " << layer1File << " and " << pattern2File
             << ", then Screening " << textFile << "..." << endl;

    TGA topLayer(pattern2File);
    TGA bottomLayer(layer1File);
    bottomLayer *= topLayer;
    topLayer.LoadTGA(textFile);
    bottomLayer.Screen(topLayer);
    bottomLayer.WriteTGA(outputFile3);

    if (debug)
        cout << "DONE" << endl;

    if (!CompareFiles(outputFile3, example3File, debug)) {
            cout << "Part three FAILED. :-(" << endl;
            if (debug)
                cout << endl;
            return 0;
        }

        cout << "Part three complete." << endl;
        if (debug)
            cout << endl;
        return 1;
}

int part4(bool debug) {

    if (debug)
        cout << "Part 4: Multiplying " << layer2File << " and " << circlesFile
             << ", then Subtracting " << pattern2File << "..." << endl;

    TGA topLayer(layer2File);
    TGA bottomLayer(circlesFile);
    bottomLayer *= topLayer;
    topLayer.LoadTGA(pattern2File);
    bottomLayer -= topLayer;
    bottomLayer.WriteTGA(outputFile4);

    if (debug)
        cout << "DONE" << endl;

    if (!CompareFiles(outputFile4, example4File, debug)) {
        cout << "Part four FAILED. :-(" << endl;
        if (debug)
            cout << endl;
        return 0;
    }

    cout << "Part four complete." << endl;
    if (debug)
        cout << endl;
    return 1;
}

int part5(bool debug) {

    if (debug)
        cout << "Part 5: Overlaying " << pattern1File << " with " << layer1File << "..." << endl;

    TGA topLayer(layer1File);
    TGA bottomLayer(pattern1File);
    bottomLayer.Overlay(topLayer);
    bottomLayer.WriteTGA(outputFile5);

    if (debug)
        cout << "DONE" << endl;

    if (!CompareFiles(outputFile5, example5File, debug)) {
        cout << "Part five FAILED. :-(" << endl;
        if (debug)
            cout << endl;
        return 0;
    }

    cout << "Part five complete." << endl;
    if (debug)
        cout << endl;
    return 1;
}

int part6(bool debug) {

    if (debug)
        cout << "Part 6: Adding 200 to " << carFile << " green channel..." << endl;

    TGA bottomLayer(carFile);
    bottomLayer.AddColor('G', 200);
    bottomLayer.WriteTGA(outputFile6);
    CompareFiles(outputFile6, example6File);

    if (debug)
        cout << "DONE" << endl;

    if (!CompareFiles(outputFile6, example6File, debug)) {
        cout << "Part six FAILED. :-(" << endl;
        if (debug)
            cout << endl;
        return 0;
    }

    cout << "Part six complete." << endl;
    if (debug)
        cout << endl;
    return 1;
}

int part7(bool debug) {

    if (debug)
        cout << "Part 7: Scaling " << carFile << " red channel by 4 and blue channel by 0..." << endl;

    TGA bottomLayer(carFile);
    bottomLayer.ScaleColor('R', 4);
    bottomLayer.ScaleColor('B', 0);
    bottomLayer.WriteTGA(outputFile7);

    if (debug)
        cout << "DONE" << endl;

    if (!CompareFiles(outputFile7, example7File, debug)) {
        cout << "Part seven FAILED. :-(" << endl;
        if (debug)
            cout << endl;
        return 0;
    }

    cout << "Part seven complete." << endl;
    if (debug)
        cout << endl;
    return 1;
}

int part8(bool debug) {

    if (debug)
        cout << "Part 8a: Isolating " << carFile << " red channel..." << endl;

    TGA bottomLayer(carFile);
    bottomLayer.SingleChannel('R');
    bottomLayer.WriteTGA(outputFile8_r);

    if (debug) {
        cout << "DONE" << endl;
        cout << "Part 8b: Isolating " << carFile << " green channel..." << endl;
    }

    bottomLayer.LoadTGA(carFile);
    bottomLayer.SingleChannel('G');
    bottomLayer.WriteTGA(outputFile8_g);

    if (debug) {
        cout << "DONE" << endl;
        cout << "Part 8c: Isolating " << carFile << " blue channel..." << endl;
    }

    bottomLayer.LoadTGA(carFile);
    bottomLayer.SingleChannel('B');
    bottomLayer.WriteTGA(outputFile8_b);

    if (debug)
        cout << "DONE" << endl;

    if (!(CompareFiles(outputFile8_r, example8_rFile, debug) &&
          CompareFiles(outputFile8_g, example8_gFile, debug)&&
          CompareFiles(outputFile8_b, example8_bFile, debug))) {
        cout << "Part eight FAILED. :-(" << endl;
        if (debug)
            cout << endl;
        return 0;
    }

    cout << "Part eight complete." << endl;
    if (debug)
        cout << endl;
    return 1;
}

int part9(bool debug) {

    if (debug)
        cout << "Part 9: Combining " << layerRedFile << ", " << layerBlueFile << " and "
             << layerGreenFile << "..." << endl;

    TGA bottomLayer(layerRedFile);
    TGA topLayer(layerGreenFile);
    bottomLayer.Combine('G', topLayer);
    topLayer.LoadTGA(layerBlueFile);
    bottomLayer.Combine('B', topLayer);
    bottomLayer.WriteTGA(outputFile9);

    if (debug)
        cout << "DONE" << endl;

    if (!CompareFiles(outputFile9, example9File, debug)) {
        cout << "Part nine FAILED. :-(" << endl;
        if (debug)
            cout << endl;
        return 0;
    }

    cout << "Part nine complete." << endl;
    if (debug)
        cout << endl;
    return 1;
}

int part10(bool debug) {

    if (debug)
        cout << "Part 10: Rotating " << text2File << " 180 degrees... " << endl;

    TGA bottomLayer(text2File);
    bottomLayer.Rotate180();
    bottomLayer.WriteTGA(outputFile10);

    if (debug)
        cout << "DONE" << endl;

    if (!CompareFiles(outputFile10, example10File, debug)) {
        cout << "Part ten FAILED. :-(" << endl;
        if (debug)
            cout << endl;
        return 0;
    }

    cout << "Part ten complete." << endl;
    if (debug)
        cout << endl;
    return 1;
}

int extraCredit(bool debug) {

    if (debug)
        cout << "Extra Credit: Forming a collage with " << carFile << ", "
             << circlesFile << ", " << pattern1File << " and " << textFile << endl;

    TGA output;
    TGA car(carFile);
    TGA circles(circlesFile);
    TGA pattern1(pattern1File);
    TGA text(textFile);
    output.Collage(text, pattern1, car, circles);
    output.WriteTGA(outputECFile);

    if (debug)
        cout << "DONE" << endl;

    if (!CompareFiles(outputECFile, exampleECFile, debug)) {
        cout << "Extra credit FAILED. :-(" << endl;
        if (debug)
            cout << endl;
        return 0;
    }

    cout << "Extra credit complete." << endl;
    if (debug)
        cout << endl;
    return 1;
}

bool CompareFiles(string file1, string file2, bool debug) {
    ifstream data1(file1, ios_base::binary);
    ifstream data2(file2, ios_base::binary);

    if (debug)
        cout << "Comparing " << file1 << " with " << file2 << ";" << endl;

    int charsChecked = 0;
    while(! data1.eof()) {
        char testChar1 = data1.get();
        char testChar2 = data2.get();
        if (testChar1 != testChar2) {

            if (debug) {
                cout << int(testChar1) << " does not equal " << int(testChar2) << endl;
                cout << "Failed after checking " << charsChecked << " characters" << endl;
                cout << "The files are not identical" << endl;
            }

            return false;
        }
        charsChecked ++;
    }

    if (debug)
        cout << "The files are identical." << endl;

    return true;
}
