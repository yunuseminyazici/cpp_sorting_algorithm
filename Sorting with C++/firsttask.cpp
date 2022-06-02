#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;


#define _TANK_HEIGHT 128
#define _TANK_WIDTH 100

void swap(char* xp, char* yp) //swap function
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}
/*simple sorting algorithm created,
swapping the adjacent elements 
if they are in the wrong order.*/
void bubbleSort(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int myStrlen(char arr[]) //calculate size of the string
{
    int size = 0; //initialize size counter
    register char* p=arr;//create pointer to point each index
    //for each char of line
    for (size_t i = 0; i < _TANK_WIDTH; i++)
    {
        
        if((*p++) =='\0')
            break;
        size++;
    }
    
    return size;
}


int main() {
auto start = chrono::steady_clock::now();
char delevery_man[_TANK_WIDTH]; //temporary array
char* tank[_TANK_HEIGHT];//number of the lines

for (size_t i = 0; i < _TANK_HEIGHT; i++)
{
  //create linewidth for each line number  
  tank[i]=new char[_TANK_WIDTH];  
}
//open file in rb mode(read binary)
FILE* myfile = fopen("testfile.txt","rb"); 

size_t size = _TANK_WIDTH;
char* p;

if (myfile) //if file is open
  {
    for (size_t i = 0; i < _TANK_HEIGHT; i++)
    {
        //fgets return null value when goes the end of the file
        //if fgets func returns null break 
        if (!fgets(tank[i],_TANK_WIDTH,myfile)) 
            break;
            
        else
        {
            p=tank[i];
            for (size_t i = 0; i < _TANK_WIDTH; i++)
            {
                if((*p) =='\n')
                *p = '\0';
                p++;
            }
            
            cout<<"Original text:  "<<tank[i]<<endl;
            bubbleSort(tank[i],myStrlen(tank[i]));
            cout<<"Sorted text:  "<<tank[i]<<endl;

        }

    }
    //create a txt file 
    ofstream Sortfile("sortedfile.txt");
    for (size_t i = 0; i < _TANK_HEIGHT; i++)
    {
        //write sorted text into text file
        Sortfile<<tank[i]<<endl;
    }
    
    Sortfile.close(); //close the file
    fclose(myfile); //close the file
    auto end = chrono::steady_clock::now();
    
     cout << "Elapsed time in microseconds: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " µs" << endl;
  }
  return 0;
}