#include "s1031418hw3_Enigma.h"

Plugboard::Plugboard( std::string table_file )
    :Enigma_Component( table_file )
{
}

size_t Plugboard::Encoding( size_t const& i )
{
    return link_next->Encoding( table[i] );
}

size_t Plugboard::Decoding( size_t const& i )
{
    return small_table[i];
}
bool Wheel::check=false;
Wheel::Wheel( std::string table_file, char start, char arrow )
    :Enigma_Component( table_file )
{
     this->arrow = arrow;
    genWheel( start );
}

void Wheel::genWheel( char ch )
{
    for (int i = 0; i < 26; i++) {
        wheel[i] = (i + ch) <= 'Z' ? i + ch : i + ch - 26;
    }
}

void Wheel::Spin()
{
    char head = wheel[0];
    for (int i = 0; i < 25; i++)
        wheel[i] = wheel[i + 1];
    wheel[25] = head;
    if (wheel[0] == arrow)
        link_next->Spin();
	else if (check==true)
	{
		check=false;
		link_next->Spin();
	}
}

size_t Wheel::Encoding( size_t const& i )
{
    int n = table[wheel[i] - 'A'];
    for (int j = 0; j < 26; j++) {
        if (n == wheel[j] - 'A')
            return link_next->Encoding( j );
    }
}

size_t Wheel::Decoding( size_t const& i )
{
    int n = small_table[wheel[i] - 'A'];
    for (int j = 0; j < 26; j++) {
        if (n == wheel[j] - 'A')
            return link_previous->Decoding( j );
    }
}

Special_Wheel::Special_Wheel( std::string table_file, char start, char arrow )
    :Wheel( table_file, start, arrow )
{
}

void Special_Wheel::Spin()
{
    Wheel::Spin();
    if (wheel[1]==arrow)
        check=true;
}

size_t Special_Wheel::Encoding( size_t const& i )
{
    int n = table[wheel[i] - 'A'];
    for (int j = 0; j < 26; j++) {
        if (n == wheel[j] - 'A')
            return link_next->Encoding( j );
    }
}

size_t Special_Wheel::Decoding( size_t const& i )
{
    int n = small_table[wheel[i] - 'A'];
    for (int j = 0; j < 26; j++) {
        if (n == wheel[j] - 'A')
            return link_previous->Decoding( j );
    }
}

Reflector::Reflector( std::string table_file )
    :Enigma_Component( table_file )
{
}

size_t Reflector::Encoding( size_t const& i )
{
    return link_previous->Decoding( table[i] );
}