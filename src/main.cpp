#include <iostream>
#include <fstream>
#include <string>

#include "args.hpp"
#include "game.hpp"

std::string out_file_name(const std::string & input_file_name, int iterations){
    std::string file_path = input_file_name.substr(0, input_file_name.find_last_of('.'));
    std::string extension = input_file_name.substr(input_file_name.find_last_of('.') + 1);;
    std::ostringstream output_file_name;
    output_file_name << file_path << "_" << iterations << "." << extension;
    std::cout << output_file_name.str() << std::endl;
    return output_file_name.str();
}

int main(int argc, char **argv) {
    args::ArgumentParser parser("Game of life");
    args::ValueFlag<std::string> input(parser, "input", "path", {"input"});
    args::ValueFlag<int> iteration(parser, "iterations", "nb iteration", {"iterations"});
    args::Flag all(parser, "all", "all", {"all"});
    try
    {
        parser.ParseCLI(argc, argv);
    }
    catch (args::Help)
    {
        std::cout << parser;
        return 0;
    }
    catch (args::ParseError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    catch (args::ValidationError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }

    if(!input || !iteration){
        std::cerr << "Wrong formating --input and --iteration are mandatory" << std::endl;
        return 1;
    }
    const std::string input_file_name = args::get(input);
    const int interations = args::get(iteration);

    std::cout << input_file_name << " "<< interations << " " << all << std::endl;


    std::ifstream inFile(input_file_name);
    if (!inFile) {
        std::cerr << "Error: Unable to open the file " << input_file_name  << std::endl;
        return 1;
    }
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string file_content = buffer.str();
    inFile.close();
    std::string next = file_content;
    for(int i=0;i< interations; i++){
        next=Game::game_off_life_next(next);

        if(all){
            std::ofstream outFile(out_file_name(input_file_name,i));
            if (!outFile) {
                std::cerr << "Error: Unable to open the file for writing." << std::endl;
            return 1;
            }
            outFile << next;
            outFile.close();
        }

    }
    std::ofstream outFile(out_file_name(input_file_name,iteration));
    if (!outFile) {
        std::cerr << "Error: Unable to open the file for writing." << std::endl;
        return 1;
    }
    outFile << next;
    outFile.close();

    return 0;
}