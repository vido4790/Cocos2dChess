/***************************************************************************************************
 *
 *  @file       ChessEngine.h
 *
 *  @author     Virag Doshi
 *
 *  @brief      Chess engine
 *
 **************************************************************************************************/

#pragma once

#include "Chess.h"

namespace chessEngine
{
    /**
     @class          Position
     
     @brief          Position of a piece
     */
    struct Position
    {
        uint8_t                     row;
        uint8_t                     col;
        
        Position(uint8_t inRowNum, uint8_t inColNum) :
        row(inRowNum), col(inColNum)
        { assert(row < 8); assert(col < 8); }
        
        static Position             getPositionByRankFile(uint8_t file, char rank)
        { return Position(file - 1, rank - 'a'); }
        
        uint8_t                     getFile() { return row + 1; }
        char                        getRank() { return col + 'a'; }
    };
    
    /**
     @class          Piece
     
     @brief          The piece name
     */
    struct Piece
    {
        attributes::ChessColor      color;
        attributes::ChessPieceName  piece;
    };
    
    /**
     @class          PieceAtPosition
     
     @brief          A unique piece at a position
     */
    struct PieceAtPosition
    {
        Piece                       piece;
        Position                    position;
    };
    
    /**
     @class          Move
     
     @brief          A move for a PieceAtPosition to a new position
     */
    struct Move
    {
        PieceAtPosition             piece;
        Position                    dest;
    };
    
    /**
     @class          ChessEngine
     
     @brief          A chess engine that processes moves
     */
    class ChessEngine
    {
    public:
        ChessEngine() = default;
        
        /**
         @brief         Attempt movement of a piece from one to another
         
         @param     inMove          move structure
         @param     outSideEffect   side effect of the movement
         */
        bool                        attemptMove(const Move & inMove, Move * outSideEffect);
    };
}
