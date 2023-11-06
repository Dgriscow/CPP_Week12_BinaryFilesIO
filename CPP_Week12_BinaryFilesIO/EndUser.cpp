//This program uses the write and read functions to read and write data to and from binary files
#include <iostream> 
#include <fstream>
using namespace std;

int main()
{
    // File object used to access file
    fstream file("nums.dat", ios::out | ios::binary);   


    fstream charfile("chars.dat", ios::out | ios::binary);   

    //ios::out means we are writing TO nums.dat, and ios::binary is saying to output is in BINARY, not raw TXT  
    
    //output to write mode AND binary write mode
    
    //the file will open in the desired mode that is needed, so a BINARY OUTPUT

                                                      

    if (!file)
    {
        cout << "Error opening file.";
        return -1;
    }if (!charfile)
    {
        cout << "Error opening file.";
        return -1;
    }

    // Integer data to write to binary file
    int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(data) / sizeof(data[0]);  //this formula calculates the length of the array 
    
    char letterData[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    int charSize = sizeof(letterData) / sizeof(letterData[0]);
    //by taking the data size of the array(40) divided by the size of data type(4 for int) we get the 
    //length of the array(10)
    
    

    // Write the data and close the file
    cout << "Now writing the binary data to the file.\n";

    file.write(reinterpret_cast<char*>(data), sizeof(data));


    file.close();
    
    cout << "Now writing the char binary data to the file.\n";

    charfile.write(reinterpret_cast<char*>(letterData), sizeof(letterData));

    charfile.close();



   
    // Open the file and use a binary read to read
    // contents of the file into an array
    file.open("nums.dat", ios::in);
    if (!file)
    {
        cout << "Error opening file.";
        return -1;
    }
    
    
    charfile.open("chars.dat", ios::in);
    if (!charfile)
    {
        cout << "Error opening file.";
        return -1;
    }

    cout << "Now reading all data back into memorys.\n";

    int* inStorage = new int[size]; //this is a seperate array that file.read is going to READ INTO and display out
    
    char* inCharStorage = new char[charSize];

    file.read(reinterpret_cast<char*>(inStorage), sizeof(data)); //second parameter states how much data is being read into the variable from the .dat file
    //read 40 bytes from binary file into a memory location pointed to by buffer
    // Write out the array entries
    
    charfile.read(reinterpret_cast<char*>(inCharStorage), sizeof(letterData));

    for (int count = 0; count < size; count++) {
        cout << inStorage[count] << " ";

    }
        
    cout << endl;

    for (int count = 0; count < size; count++){
        cout << inCharStorage[count] << " ";
    }
    // Close the file	
    file.close();
    charfile.close();

    return 0;
}