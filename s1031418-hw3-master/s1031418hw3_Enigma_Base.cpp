#include "s1031418hw3_Enigma_Base.h"
using namespace std;

void Enigma_Files::Read_file ( std::string file )
{
    ifstream in(file, std::ios::in);
    in >> data;
}

void Enigma_Files::Write_file ( std::string file )
{
    ofstream out(file, std::ios::out);
    out << data;
}
    
void Enigma_Files::Push ( char const& c )
{
    data.push_back(c);
}
    
char const& Enigma_Files::operator [] ( size_t const& i  )
{
    return data[i];
}
    
std::string Enigma_Files::Data ()
{
    return data;
}

size_t Enigma_Files::Length ()
{
    return data.size();
}




Enigma_Component::Enigma_Component( std::string table_file )
{
    link_next = link_previous = NULL;
    Read_table(table_file);
}

void Enigma_Component::Link( Enigma_Component& next )
{
    link_next = &next;
    next.link_previous = this;
}

char Enigma_Component::Input_signal ( char c )
{
    this->link_next->Spin();
	return this->Encoding(table[c-'A']) + 'A';
}

void Enigma_Component::Read_table ( std::string table_file )
{
    ifstream in( table_file, ios::in);
    std::string tmp;
    in >> tmp;
    for (size_t i = 0; i < tmp.size(); i++) {
        table[i] = tmp[i] - 'A';
        small_table[tmp[i] - 'A'] = i;
    }
}
