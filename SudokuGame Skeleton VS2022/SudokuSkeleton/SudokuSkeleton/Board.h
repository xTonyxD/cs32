//
//  Board.h
//  SudokuGame
//
//

#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include "NumberSet.h"

#include <string>

namespace cs32
{
    // a Board represents a full SudokuBoard
    // it holds an array of Cell.  To make everything simpler,
    //    row 0 and column 0 is completely ignored
    // a Board can be stringified which gets called whenever the
    //      Game is printed
    //      0 values stringify as      .
    // for a particular position on the Board, a NumberSet
    //      representing the row, column or bounding box can be
    //      created
    // for testing purposes, a Board can be cheated to allow
    //      for direct testing of any particular Board configuration
    class Board
    {
    public:
        Board( );
        
        // A Board can be stringified which gets called when the
        //      Game is printed
        //      0 values stringify as   .
        //      uses |s and -s between groups of three rows and columns
        std::string stringify( ) const;
        
        // called whenever the Game wants to change the value of
        // a Board's cell.  The [ row ][ column ] cell is
        // trying to be changed to the parameter value.
        // returns false if the move is illegal
        // sets the immutability of the cell
        bool acceptValue( int value, int row, int column, bool immutable=false );
        // acquire the value from any given cell
        Cell getValue( int row, int column );
        
        // CS 32 TODO : CS 32 Students need to implement this operation
        bool completed() const;    /* is this Board done fully?     */
        
        void cheat();              /* for testing purposes          */
        void cheat( std::string boardstring );
        
        // CS 32 TODO : CS 32 Students need to implement this operation
        int evaluate( ) const;     /* the Board evaluation function */
    private:
        Cell mCells[ 10 ][ 10 ];  // 9x9, ignoring row and column 0
        
        // called by acceptValue(...) to
        // create a NumberSet for the box that encloses
        // the position [row][column] on the Board
        NumberSet buildBox( int row, int column ) const;
        // called by acceptValue(...) to
        // create a NumberSet for the column that encloses
        // the position [row][column] on the Board
        NumberSet buildColumn( int row, int column ) const;
        // called by acceptValue(...) to
        // create a NumberSet for the row that encloses
        // the position [row][column] on the Board
        NumberSet buildRow( int row, int column ) const;
    };
}

#endif
