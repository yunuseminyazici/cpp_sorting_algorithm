#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
#include <chrono>

using namespace std;

int main() {

auto start = chrono::steady_clock::now(); //timer start

vector<string> myVector; //create vector container
string line; //create line string
ifstream myfile ("testfile.txt"); //open the text file

if (myfile.is_open()) // if my file is open
  {
    while ( !myfile.eof() ) //till the end of the line
    {
      getline (myfile,line);
      myVector.push_back(line); // push the lines into vector container
    }
    cout << "Inside of the text file: "<<"\n***********"<<endl;
    //print each index of vector 
    for (auto i = myVector.begin(); i != myVector.end(); ++i) 
        cout << *i<<endl; 
    cout <<"***********"<<endl;
    
    for (size_t i = 0; i < myVector.size(); i++)
    {   
        //using sort function sort each line
        sort(myVector[i].begin(),myVector[i].end());
        
    }
    cout<<"Sorted vector:"<<"\n***********"<<endl;
    for (auto c : myVector)
	    cout << c<<endl;

    myfile.close();
  

    ofstream Sortfile("sortedfile2.txt");
    for (size_t i = 0; i < myVector.size(); i++)
    {
        //write sorted text into text file
        Sortfile<<myVector[i]<<endl;

    }
    
    auto end = chrono::steady_clock::now(); //timer end

    cout << "Elapsed time in microseconds: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " µs" << endl;
  }


else cout << "Unable to open file";


	return 0;
}
