/***************************************************************************************************
 *
 *  @file       Bitboard.h  
 *
 *  @author     Virag Doshi
 *
 *  @brief      Bitboard implementation to represent pieces
 *
 **************************************************************************************************/

#pragma once

#include <cstdint>

#include "Chess.h"

namespace chessEngine
{
    struct Position;
    struct Bitboard;
    
    /**
     @class          Square
     
     @brief          Position of a piece represented by square index
     */
    struct Square
    {
        friend struct Bitboard;
        
        static constexpr uint8_t    kRemoved = 0xFF;
        
        uint8_t                     index;
        
        Square() :
        index(kRemoved)
        { }
        
        Square(uint8_t inIndex) :
        index(inIndex)
        { }
        
        Square(uint8_t inRowNum, uint8_t inColNum) :
        index(inRowNum * 8 + inColNum)
        { }
        
        bool                        isRemoved() const
        { return index == kRemoved; }
        
        uint8_t                     getRow() const
        { return (isRemoved() ? kRemoved : _getRowNoValidation()); }
        
        uint8_t                     getCol() const
        { return (isRemoved() ? kRemoved : _getColNoValidation()); }
        
        Position                    getPosition() const;
        
    private:
        uint8_t                     _getRowNoValidation() const
        { return index / 8; }
        
        uint8_t                     _getColNoValidation() const
        { return index % 8; }
    };
    
    //
    
    using BitboardMask = uint64_t;
    
    struct Bitboard
    {
    private:
        static const Bitboard       kRowMasks[8];
        static const Bitboard       kColMasks[8];
        static const Bitboard       kDiagMasks[15];
        static const Bitboard       kADiagMasks[15];
        static const Bitboard       kSquareMasks[64];
        
        static const Bitboard       kStartWhitePawns;
        static const Bitboard       kStartBlackPawns;
        
        static const Bitboard       kStartWhiteKnights;
        static const Bitboard       kStartBlackKnights;
        
        static const Bitboard       kStartWhiteBishops;
        static const Bitboard       kStartBlackBishops;
        
        static const Bitboard       kStartWhiteRooks;
        static const Bitboard       kStartBlackRooks;
        
        static const Bitboard       kStartWhiteQueen;
        static const Bitboard       kStartBlackQueen;
        
        static const Bitboard       kStartWhiteKing;
        static const Bitboard       kStartBlackKing;
        
        static const Bitboard       kFull;
        
    public:
        BitboardMask                mask;
        
        struct Iterator
        {
            BitboardMask            mask;
            
            Iterator(BitboardMask inMask) :
            mask(inMask)
            { }
            
            Square                  operator* () const
            { return Square(__builtin_ctzll(mask)); }
            
            Iterator &              operator++()
            { mask &= mask - 1; return *this; }
            
            bool                    operator== (Iterator inOther)
            { return mask == inOther.mask; }
            
            bool                    operator!= (Iterator inOther)
            { return mask != inOther.mask; }
        };
        
        Iterator                    begin() const
        { return Iterator(mask); }
        
        Iterator                    end() const
        { return Iterator(0x00ULL); }
        
        Bitboard(BitboardMask inMask = 0) :
        mask(inMask)
        { }
        
        void                            operator&= (Bitboard inB)
        { mask &= inB.mask; }
        
        void                            operator|= (Bitboard inB)
        { mask |= inB.mask; }
        
        void                            operator^= (Bitboard inB)
        { mask ^= inB.mask; }
        
        void                            operator>>= (uint8_t inNumShifts)
        { mask >>= inNumShifts; }
        
        void                            operator<<= (uint8_t inNumShifts)
        { mask <<= inNumShifts; }
        
        void                            print() const;
        
        static Bitboard                 getForSquare(Square inSq)
        { return kSquareMasks[inSq.index]; }
        
        static Bitboard                 getForRow(uint8_t inRowNum)
        { return kRowMasks[inRowNum]; }
        
        static Bitboard                 getForRowWith(Square inSq)
        { return getForRow(inSq._getRowNoValidation()); }
        
        static Bitboard                 getForCol(uint8_t inColNum)
        { return kColMasks[inColNum]; }
        
        static Bitboard                 getForColWith(Square inSq)
        { return getForCol(inSq._getColNoValidation()); }
        
        static uint8_t                  getDiagNum(Square inSq)
        { return inSq._getRowNoValidation() - inSq._getColNoValidation() + 7; }
        
        static uint8_t                  getADiagNum(Square inSq)
        { return inSq._getRowNoValidation() + inSq._getColNoValidation(); }
        
        static Bitboard                 getForDiag(uint8_t inDiagNum)
        { return kDiagMasks[inDiagNum]; }
        
        static Bitboard                 getForADiag(uint8_t inADiagNum)
        { return kADiagMasks[inADiagNum]; }
        
        static Bitboard                 getForDiagWith(Square inSq)
        { return getForDiag(getDiagNum(inSq)); }
        
        static Bitboard                 getForADiagWith(Square inSq)
        { return getForADiag(getADiagNum(inSq)); }
        
        static Bitboard                 getFull()
        { return kFull; }
    };
    
    static inline Bitboard              operator& (Bitboard inB1, Bitboard inB2)
    { return Bitboard(inB1.mask & inB2.mask); }
    
    static inline Bitboard              operator| (Bitboard inB1, Bitboard inB2)
    { return Bitboard(inB1.mask | inB2.mask); }
    
    static inline Bitboard              operator^ (Bitboard inB1, Bitboard inB2)
    { return Bitboard(inB1.mask ^ inB2.mask); }
    
    static inline Bitboard              operator~ (Bitboard inB)
    { return ~inB.mask; }
    
    static inline Bitboard              operator<< (Bitboard inB, uint8_t inNumShifts)
    { return inB.mask << inNumShifts; }
    
    static inline Bitboard              operator>> (Bitboard inB, uint8_t inNumShifts)
    { return inB.mask >> inNumShifts; }
};
