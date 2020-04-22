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

#include "Bitboard.h"
#include "Chess.h"

namespace chessEngine
{
    /**
     @class          Position
     
     @brief          Position of a piece
     */
    struct Position
    {
        static constexpr uint8_t    kRemoved = 0xFF;
        
        uint8_t                     row;
        uint8_t                     col;
        
        Position() :
        row(kRemoved), col(kRemoved)
        { }
        
        Position(uint8_t inRowNum, uint8_t inColNum) :
        row(inRowNum), col(inColNum)
        { assert((row < 8) || (row == kRemoved)); assert((col < 8) || (col == kRemoved)); }
        
        static Position             getPositionByRankFile(uint8_t file, char rank)
        { return Position(file - 1, rank - 'a'); }
        
        /**
         @brief             get file number
         */
        uint8_t                     getFile() const { return row + 1; }
        
        /**
         @brief             get rank number
         */
        char                        getRank() const { return col + 'a'; }
        
        /**
         @brief             check if the position indicate that the piece is removed
         */
        bool                        isRemoved() const
        { return (row == kRemoved) || (col == kRemoved); }
        
        /**
         @brief             check if the position indicate that the piece is removed
         */
        Square                     getSquare() const
        { return Square(row, col); }
    };
    
    /**
     @class          Piece
     
     @brief          The piece name
     */
    struct Piece
    {
        attributes::ChessColor      color;
        attributes::ChessPieceName  piece;
        
        Piece() :
        color(attributes::ChessColor::kNone)
        { }
        
        Piece(attributes::ChessColor      inColor,
              attributes::ChessPieceName  inPiece) :
        color(inColor), piece(inPiece)
        { }
        
        bool                        isValid() const
        { return (color != attributes::ChessColor::kNone); }
    };
    
    /**
     @class          PieceAtPosition
     
     @brief          A unique piece at a position
     */
    struct PieceAtPosition
    {
        Piece                       pieceType;
        Position                    position;
        
        PieceAtPosition()
        { }
        
        PieceAtPosition(Piece       inPieceType,
                        Position    inPosition) :
        pieceType(inPieceType), position(inPosition)
        { }
        
        bool                        isValid() const
        { return pieceType.isValid(); }
    };
    
    /**
     @class          Move
     
     @brief          A move for a PieceAtPosition to a new position
     */
    struct Move
    {
        PieceAtPosition             piece;
        Position                    dest;
        
        Move()
        { }
        
        Move(Piece inPiece, Position inSrc, Position inDest) :
        piece(inPiece, inSrc), dest(inDest)
        { }
        
        Move(PieceAtPosition inPiece, Position inDest) :
        piece(inPiece), dest(inDest)
        { }
        
        bool                        isValid() const
        { return piece.pieceType.isValid(); }
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
