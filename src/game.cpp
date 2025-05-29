#include "game.hpp"

#include <algorithm>
#include <iostream>

const static char DEAD = '_';
const static char CELL = '*';

std::string Game::game_off_life_next(std::string input)
{
    std::vector<std::string> iterations;
    size_t board_width = get_board_width(input);
    std::string formated = strim(input);
    std::string new_ite;
    for (int i=0;i < formated.size();i++){
        int total = north(i,formated,board_width) +
                    north_east(i,formated,board_width) +
                    east(i,formated,board_width) +
                    south_east(i,formated,board_width) +
                    south(i,formated,board_width) +
                    south_west(i,formated,board_width) +
                    west(i,formated, board_width) +
                    north_west(i,formated, board_width);
        if(formated[i]==CELL){
            if(total==3 || total==2){
                new_ite.push_back(CELL);
            }else{
                new_ite.push_back(DEAD);
            }
        }
        else if(formated[i]==DEAD){
            if(total==3){
                new_ite.push_back(CELL);
            }else{
                new_ite.push_back(DEAD);
            }
        }else{
            std::cerr << "Unknow cell "<< formated[i];
        }

        if(board_width!=0 && (i+1)%board_width==0){
            new_ite.push_back('\n');
        }

    }
    return new_ite;
}

size_t Game::get_board_width(const std::string& board){
    const auto it = std::find(board.begin(),board.end(),'\n');
    if(it == board.end()){
        return 0;
    }
    return std::distance(board.begin(), it);
}

int Game::north(int i,const std::string& board, const size_t board_width){
    if(i<board_width){
        return 0;
    }
    return is_cell(i - board_width, board);
}

int Game::north_east(int i, const std::string &board, const size_t board_width)
{
    if(i<board_width || board_width==0 || (i+1)%board_width==0){
        return 0;
    }
    return is_cell(i + 1 - board_width, board);
}

int Game::east(int i,const std::string& board, const size_t board_width){
    if(board_width==0 ||(i+1)%board_width==0){
        return 0;
    }
    return is_cell(i+1, board);
}

int Game::south_east(int i, const std::string &board, const size_t board_width)
{
    if(i + board_width >= board.size() || board_width==0 ||(i+1)%board_width==0){
        return 0;
    }
    return is_cell(i + 1 + board_width, board);
}

int Game::south(int i,const std::string& board, const size_t board_width){
    if(i + board_width >= board.size()){
        return 0;
    }
    return is_cell(i+board_width, board);
}

int Game::south_west(int i, const std::string &board, const size_t board_width)
{
    if(i + board_width >= board.size() || board_width==0 || i%board_width==0){
        return 0;
    }
    return is_cell(i-1+board_width, board);
}

int Game::west(int i, const std::string& board,const size_t board_width){
    if( board_width==0 || i%board_width==0){
        return 0;
    }
    return is_cell(i-1,board);
}

int Game::north_west(int i, const std::string &board, const size_t board_width)
{
    if(board_width==0 || i%board_width==0 || i<board_width){
        return 0;
    }
    return is_cell(i-1-board_width, board);
}

int Game::is_cell(int index,const std::string &board){
    if(index >= board.size()){
        return 0;
    }
    return board[index]==CELL?1:0;
}

std::string Game::strim(std::string input){
    std::string buffer;
    for(auto const c:input){
        if(c!='\n'){
            buffer.push_back(c);
        }
    }
    return buffer;
}