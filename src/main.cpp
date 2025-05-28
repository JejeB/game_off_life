#include <iostream>
#include "args.hpp"

int main(int argc, char **argv) {
    args::ArgumentParser parser("Game of life");
    args::ValueFlag<std::string> input(parser, "path", "path", {"input"});
    args::ValueFlag<int> iteration(parser, "iteration", "nb iteration", {"iteration"});
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
    std::cout << args::get(input) << " "<< args::get(iteration) << " " << all << std::endl;

    return 0;
}