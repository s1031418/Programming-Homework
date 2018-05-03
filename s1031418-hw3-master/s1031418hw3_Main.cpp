#include <conio.h>
#include "s1031418hw3_Enigma.h"

//*This main function is only a example
//You might modified this program to fit your design
int main ()
{
    Enigma_Files wheel_start_file;
    Enigma_Files wheel_arrow_file;
    Enigma_Files original_message_file;
    Enigma_Files encoded_message_file;

    std::cout << "Read original message: \"original_data.txt\"" << std::endl;
    original_message_file.Read_file("original_data.txt");

    std::cout << "Read arrows position of [Rotor]: \"wheel_web_arrow.txt\"" << std::endl;
    wheel_arrow_file.Read_file("wheel_web_arrow.txt");
    char wheel_0_arrows = wheel_arrow_file[0];
    char wheel_1_arrows = wheel_arrow_file[1];
    char wheel_2_arrows = wheel_arrow_file[2];

    std::cout << "Read start position of [Rotor]: \"wheel_web_start.txt\"" << std::endl;
    wheel_start_file.Read_file("wheel_web_start.txt");

    std::cout << "Read [Plugboard]: \"plugboard_web.txt\"" << std::endl;
    Plugboard plugboard("plugboard_web.txt");

    std::cout << "Read [Rotor III]: \"wheel_web_0.txt\"" << std::endl;
    Wheel wheel_0("wheel_web_0.txt", wheel_start_file[0], wheel_0_arrows);

    std::cout << "Read [Rotor II]: \"wheel_web_1.txt\"" << std::endl;
    Special_Wheel wheel_1("wheel_web_1.txt", wheel_start_file[1], wheel_1_arrows);

    std::cout << "Read [Rotor I]: \"wheel_web_2.txt\"" << std::endl;
    Wheel wheel_2("wheel_web_2.txt", wheel_start_file[2], wheel_2_arrows);

    std::cout << "Read [Reflector]: \"reflector_web.txt\"" << std::endl;
    Reflector reflector ( "reflector_web.txt" ) ;

    plugboard.Link ( wheel_0 ) ;
    wheel_0.Link ( wheel_1 ) ;
    wheel_1.Link ( wheel_2 ) ;
    wheel_2.Link ( reflector ) ;

    std::cout << "Original message: " << std::endl << original_message_file.Data() << std::endl;

    for (size_t i = 0; i < original_message_file.Length(); i++)
        encoded_message_file.Push(plugboard.Input_signal(original_message_file[i]));

    std::cout << "Output encoded data to \"encoded_data.txt\"" << std::endl;
    encoded_message_file.Write_file("encoded_data.txt");

    std::cout << "Eecoded message: " << std::endl << encoded_message_file.Data() << std::endl;

    std::cout << "Press any key to exit...";
    std::getchar();
    return EXIT_SUCCESS ;
}
