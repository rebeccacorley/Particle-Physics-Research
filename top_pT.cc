//Just trying to make a damn histogram or something.
//This code is to generate data for a histogram plot of top quark pT distribution

#include "Pythia8/Pythia.h" // These are the pre-processor directive. It tells the compiler to locate the file that contains the code for libraries, "stuff." The libraries contain code that allows for input/output.
#include <iostream>
#include <cstdio>   // needed for io
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


using namespace Pythia8;
using namespace std; //using libraries (standard and Pythia8)



int main(int argc, char* argv[]) { // Declare main function. IDK what argc and argv[] are*****
    
    string outname=""; //Stores the output file name
    string filename_out=""; //Also declaring some variable
    ofstream outfile; // ofstream is class to write files on
    
    // outfile is an object of the ofstream class, which contains a bunch of functions I've never seen before so that we can even write output files. If you don't understand it, don't worry about it.
   
    outname="test-Output"; //This is to choose the name of the file
    outname = outname+".dat"; //This is always .dat DO NOT CHANGE
    filename_out=outname; //
           
       
    outfile.open(filename_out); //open output file. Just like pythia.event.id() had a pythia object calling on the event function to do the things..this is similar
       
      
    //int taco = 8; //Initalization of variable. aka identifier = value
       
    
    
    // Set up generation.

    Pythia pythia; // Declare pythia object of Pythia class

    pythia.readString("Top:qqbar2ttbar = on"); // Another switch on
    pythia.readString("Top:gg2ttbar = on");
    pythia.readString("Beams:eCM = 8000."); // 8 TeV CM energy.
    pythia.readString("Next:numberShowEvent = 1"); //List how many events

    pythia.init(); // Initialize; incoming pp beams is default.

    
    // Generate event(s).
    
        for (int iEvent = 0; iEvent < 1000000; ++iEvent) {
            pythia.next();
            //for loop repeats statement while condition is true. Format is: initialization -> condition -> statement -> increase
            
            for (int i = pythia.event.size(); i > 0; i--) {
            
                if (pythia.event[i].id() == 6){
        
                    outfile << pythia.event[i].pT() << endl;
                    //if the id = 6 then output the pT. 6 is top quark id
                    
                    break;
                }
                
            }

        }
    
    //outfile << taco << endl;
        //note, " outfile " is alsmost IDENTICAL to " cout " The only difference is that the output goes to a file instead of the terminal.
        
        outfile.close();    //close output file
        
        
    }

    
    

