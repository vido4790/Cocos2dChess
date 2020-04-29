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
#include "Bitboard.h"

#include <array>

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
        
        static Position             outside() { return Position(); }
        
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
        bool                        isOutside() const
        { return (row == kRemoved) || (col == kRemoved); }
        
        /**
         @brief             check if the position indicate that the piece is removed
         */
        Square                      getSquare() const
        { return Square(row, col); }
        
        Bitboard                    getBitboard() const
        { return Bitboard::getForSquare(getSquare()); }
    };
    
    /**
     @class          Move
     
     @brief          A move for a PieceAtPosition to a new position
     */
    struct Move
    {
        Position                    src;
        Position                    dest;
        
        static Move                 invalid()
        { return Move(); }
        
        Move() :
        src(), dest()
        { }
        
        Move(Position inSrc, Position inDest) :
        src(inSrc), dest(inDest)
        { }
        
        bool                        isValid()
        { return src.isOutside() && dest.isOutside(); }
    };
    
    /**
     @class          ChessEngine
     
     @brief          A chess engine that processes moves
     */
    class ChessEngine
    {
        struct BitboardCollection
        {
            enum PieceIndex
            {
                kPawns   = static_cast<uint8_t>(attributes::ChessPieceName::kPawn),
                kKnights = static_cast<uint8_t>(attributes::ChessPieceName::kKnight),
                kBishops = static_cast<uint8_t>(attributes::ChessPieceName::kBishop),
                kRooks   = static_cast<uint8_t>(attributes::ChessPieceName::kRook),
                kQueens  = static_cast<uint8_t>(attributes::ChessPieceName::kQueen),
                kKing    = static_cast<uint8_t>(attributes::ChessPieceName::kKing),
                kSize
            };
            
        private:
            using PositionBitboardArray = std::array<Bitboard, PieceIndex::kSize>;
            
            PositionBitboardArray   _pos;
            
        public:
            Bitboard &              pawnsPos()   { return _pos[PieceIndex::kPawns]; }
            Bitboard &              knightsPos() { return _pos[PieceIndex::kKnights]; }
            Bitboard &              bishopsPos() { return _pos[PieceIndex::kBishops]; }
            Bitboard &              rooksPos()   { return _pos[PieceIndex::kRooks]; }
            Bitboard &              queensPos()  { return _pos[PieceIndex::kQueens]; }
            Bitboard &              kingPos()    { return _pos[PieceIndex::kKing]; }
            
            Bitboard &              board(attributes::ChessPieceName inPiece)
            { return _pos[static_cast<uint8_t>(inPiece)]; }
            
            BitboardCollection(Bitboard inPawnsPos, Bitboard inKnightsPos,
                               Bitboard inBishopsPos, Bitboard inRooksPos,
                               Bitboard inQueensPos, Bitboard inKingPos) :
            _pos({ inPawnsPos, inKnightsPos, inBishopsPos, inRooksPos, inQueensPos, inKingPos })
            { }
            
            Bitboard                getAll()
            { Bitboard b; for (auto i : _pos) b &= i; return b; }
            
            bool                    getPieceAt(const Position & inPos,
                                               attributes::ChessPieceName * outPiece);
        };
        
        BitboardCollection          _whitePieces;
        BitboardCollection          _blackPieces;
        
        attributes::ChessColor      _currTurn;
        
        static bool                 _sIsInit;
        
    public:
        ChessEngine();
        
        /**
         @brief         Attempt movement of a piece from one to another
         
         @param     inMove          move structure
         @param     outSideEffect   side effect of the movement
         @param     outPromotion    indicate that there was a promotion
         */
        bool                        attemptMove(const Move & inMove, Move * outSideEffect,
                                                bool * outPromotion);
        
        attributes::ChessColor      getCurrMove() const { return _currTurn; }
        
        static void                 init();
        
    private:
        bool                        _attemptPawnMove(attributes::ChessColor inColor,
                                                     const Move & inMove, Move * outSideEffect,
                                                     bool * outPromotion);
        bool                        _attemptKnightMove(attributes::ChessColor inColor,
                                                       const Move & inMove, Move * outSideEffect);
        bool                        _attemptBishopMove(attributes::ChessColor inColor,
                                                       const Move & inMove, Move * outSideEffect);
        bool                        _attemptRookMove(attributes::ChessColor inColor,
                                                     const Move & inMove, Move * outSideEffect);
        bool                        _attemptQueenMove(attributes::ChessColor inColor,
                                                      const Move & inMove, Move * outSideEffect);
        bool                        _attemptKingMove(attributes::ChessColor inColor,
                                                     const Move & inMove, Move * outSideEffect);
        
        bool                        _simpleMoveAndKill(attributes::ChessPieceName inPiece,
                                                       attributes::ChessColor inColor,
                                                       const Move & inMove, Move * outSideEffect);
    };
}
