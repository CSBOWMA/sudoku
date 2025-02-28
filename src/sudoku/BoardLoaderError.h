#ifndef SUDOKU_BOARD_LOADER_ERROR_H
#define SUDOKU_BOARD_LOADER_ERROR_H
#include <stdexcept>


class BoardLoaderError : public std::runtime_error {
    public:
        BoardLoaderError(const std::string& message) : std::runtime_error(message) {}
};


#endif
