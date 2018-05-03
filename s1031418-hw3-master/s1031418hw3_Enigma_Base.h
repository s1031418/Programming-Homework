#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
// *you might add another header file if necessary

class Plugboard;
class Wheel;
class Special_Wheel;
class Reflector;

//*A EXAMPLE class for read/write text data
//(You might modified this class to fit your design)
class Enigma_Files
{
    public:
        void Read_file ( std::string file ) ; //< Read from a file
        void Write_file ( std::string file ) ; //< Write the string into a file

        void Push ( char const& c ) ; //< push a character on the tail(end) of string
        char const& operator [] ( size_t const& i ) ; //< get specific character

        std::string Data (); //< get data
        size_t Length (); //< get length of data

        // *you might add another help function if necessary

    protected:
        std::string data ;
        // *you might add another data member if necessary
};

//*A REQUIRED base class of components in the Enigma
//(Please extend it to fit your design)
class Enigma_Component
{
    public:
        //Add suitable constructor if necessary
        Enigma_Component ( std::string table_file );

        //Input a character and return a encoded one (use this function to invoke "Encoding" function)
        char Input_signal ( char c );

        //[optional] This function is optional for Linked List
        void Link ( Enigma_Component& next );

		//Spin current component (It should be overrided by derived classes)
        virtual void Spin () {}

		//add decode function (reflection to plug)
		virtual size_t Decoding ( size_t const& i) = 0;
        //A function of encode messenge (It should be overrided by derived classes)(plug to reflection)
        virtual size_t Encoding ( size_t const& i) = 0;

        // *you might add another help function if necessary

    protected:
        //Add suitable data structure to store key-mapping
        int table[26];
        int small_table[26];

        //[optional] This two pointer is optional for Linked List
        Enigma_Component* link_next;
        Enigma_Component* link_previous;

        //Read a mapping table from file to setup current component (It should be overrided by derived classes)
        void Read_table ( std::string file );
};
