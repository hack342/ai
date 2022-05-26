    #include <iostream>
    #include <fstream>
    #include <string>
    #include <stdint.h>
    #include <sstream>
    #include <typeinfo>
    #include <algorithm>    

using namespace std;
    
	
	void showMessage() {
	  std::cout << "*** Hi, I am polly, How Can I Help You? ****\n";
	}

    


	int getPhrase(string userInput) {
	 ifstream brainFile ( "abc.txt" );
	 
	 string phrase="";
	 string response="";
	 
	 while (getline(brainFile, phrase, '|')) {
	getline(brainFile, response);
		
	 

	   if(userInput == phrase) {
	    cout << "[Tejas]: " << response<<endl;
	    brainFile.close();
	    return 1;
	   }
	 
	 }
	 //quit if user types Quit
	 if(userInput == "Quit") {
	  std::exit(0);
	 }
	 
	 //we couldn't find the phrase, so we'll need to go to the other function
	 // After you are done with the file always close it.
	 brainFile.close();
	 return 0;
	}


    
    void learner(string inputPhrase) {
     string storePhrase = inputPhrase;
     std::cout << "Not Found! Tell me what to enter for " << storePhrase << " : ";
     std::string learningResponse;
     getline(std::cin, learningResponse);
     std::cout << learningResponse << endl;
     
     //open file for writing: parameters indicate that you will APPEND to end
     std::ofstream saveBrain;
     saveBrain.open("abc.txt", std::ios::out | std::ios::app);
     if(!saveBrain.is_open()) {
      std::cout << "error on file open" << endl;
     } else {
      saveBrain << endl << storePhrase << "|" << learningResponse;
      saveBrain.close();
     }
     return;
    }


    int main () {
      showMessage();
      std::string userInput;
      do {
       std::cout << "[You] : ";
       getline(std::cin, userInput);
       //x or X will close out the program
       if(userInput != "x" && userInput != "X") {
        if(getPhrase(userInput)) {;
         //keep going
        } else {
         //need to learn this phrase and response
         learner(userInput);
        }
       }
     } while (userInput != "x" && userInput != "X");
      return 0;
    }
