#include <string>
#include <vector>

namespace Game{
    // Return next iteration of the game of life
    std::string game_off_life_next(std::string input);

    int north(int i,const std::string& board, const size_t board_width);
    int north_east(int i,const std::string& board, const size_t board_width);
    int east(int i,const std::string& board, const size_t board_width);
    int south_east(int i,const std::string& board, const size_t board_width);
    int south(int i,const std::string& board, const size_t board_width);
    int south_west(int i,const std::string& board, const size_t board_width);
    int west(int i, const std::string& board, const size_t board_width);
    int north_west(int i,const std::string& board, const size_t board_width);

    int is_cell(int index,const std::string &board);
    size_t get_board_width(const std::string& board);
    std::string strim(std::string input);
}