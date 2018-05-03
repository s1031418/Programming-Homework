#pragma once

#include "s1031418hw3_Enigma_Base.h"

//a derived class for plugboard
class Plugboard : public Enigma_Component
{
    public:
        Plugboard( std::string table_file );
    protected:
		size_t Decoding ( size_t const& i );
        size_t Encoding ( size_t const& i );
};

//a derived class for the ordinary wheel (Rotor I and III)
class Wheel : public Enigma_Component
{
    public:
        Wheel(std::string table_file, char start, char arrow);
		virtual void Spin ();
    protected:
        char arrow;
		static bool check ;
		char wheel[26];
		void genWheel(char ch);
        virtual size_t Encoding ( size_t const& i );
		virtual size_t Decoding ( size_t const& i );
};

//a derived class for the special version of wheel (Rotor II)
class Special_Wheel : public Wheel
{
    public:
        Special_Wheel(std::string table_file, char start, char arrow);
		virtual void Spin ();
    protected:
        size_t Encoding ( size_t const& i );
		size_t Decoding ( size_t const& i );
};

//a derived class for reflector
class Reflector : public Enigma_Component
{
    public:
        Reflector( std::string table_file );
    protected:
        size_t Encoding ( size_t const& i );
		size_t Decoding ( size_t const& i ) { return 0;}
};