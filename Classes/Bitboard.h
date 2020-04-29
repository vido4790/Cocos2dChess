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
        
        bool                        isOutside() const
        { return index == kRemoved; }
        
        uint8_t                     getRow() const
        { return (isOutside() ? kRemoved : _getRowNoValidation()); }
        
        uint8_t                     getCol() const
        { return (isOutside() ? kRemoved : _getColNoValidation()); }
        
        Position                    getPosition() const;
        
    private:
        uint8_t                     _getRowNoValidation() const
        { return index / 8; }
        
        uint8_t                     _getColNoValidation() const
        { return index % 8; }
    };
    
    //
    
    using BitboardMask = uint64_t;
    
    namespace BitboardLUT
    {
        extern const Bitboard       kRowMasks[8];
        extern const Bitboard       kColMasks[8];
        extern const Bitboard       kDiagMasks[15];
        extern const Bitboard       kADiagMasks[15];
        extern const Bitboard       kSquareMasks[64];
        
        extern const Bitboard       kStartWhitePawns;
        extern const Bitboard       kStartBlackPawns;
        
        extern const Bitboard       kStartWhiteKnights;
        extern const Bitboard       kStartBlackKnights;
        
        extern const Bitboard       kStartWhiteBishops;
        extern const Bitboard       kStartBlackBishops;
        
        extern const Bitboard       kStartWhiteRooks;
        extern const Bitboard       kStartBlackRooks;
        
        extern const Bitboard       kStartWhiteQueen;
        extern const Bitboard       kStartBlackQueen;
        
        extern const Bitboard       kStartWhiteKing;
        extern const Bitboard       kStartBlackKing;
        
        extern const Bitboard       kFull;
        
        extern Bitboard             kRowOccupiedMasks[8][256];
        extern Bitboard             kColOccupiedMasks[8][256];
        extern Bitboard             kDiagOccupiedMasks[8][256];
        extern Bitboard             kADiagOccupiedMasks[8][256];
        
        void                        init();
    }
    
    struct Bitboard
    {
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

        bool                            operator== (BitboardMask inOtherMask)
        { return mask == inOtherMask; }
        
        bool                            operator!= (BitboardMask inOtherMask)
        { return mask != inOtherMask; }
        
        bool                            operator== (Bitboard inOther)
        { return mask == inOther.mask; }
        
        bool                            operator!= (Bitboard inOther)
        { return mask != inOther.mask; }
        
        void                            print() const;
        
        static Bitboard                 getForSquare(Square inSq)
        { return BitboardLUT::kSquareMasks[inSq.index]; }
        
        static Bitboard                 getForRow(uint8_t inRowNum)
        { return BitboardLUT::kRowMasks[inRowNum]; }
        
        static Bitboard                 getForRowWith(Square inSq)
        { return getForRow(inSq._getRowNoValidation()); }
        
        static Bitboard                 getForCol(uint8_t inColNum)
        { return BitboardLUT::kColMasks[inColNum]; }
        
        static Bitboard                 getForColWith(Square inSq)
        { return getForCol(inSq._getColNoValidation()); }
        
        static uint8_t                  getDiagNum(Square inSq)
        { return inSq._getRowNoValidation() - inSq._getColNoValidation() + 7; }
        
        static uint8_t                  getADiagNum(Square inSq)
        { return inSq._getRowNoValidation() + inSq._getColNoValidation(); }
        
        static Bitboard                 getForDiag(uint8_t inDiagNum)
        { return BitboardLUT::kDiagMasks[inDiagNum]; }
        
        static Bitboard                 getForADiag(uint8_t inADiagNum)
        { return BitboardLUT::kADiagMasks[inADiagNum]; }
        
        static Bitboard                 getForDiagWith(Square inSq)
        { return getForDiag(getDiagNum(inSq)); }
        
        static Bitboard                 getForADiagWith(Square inSq)
        { return getForADiag(getADiagNum(inSq)); }
        
        static Bitboard                 getRowAttacks(Square inSq, Bitboard inBoard);
        static Bitboard                 getRowAttacks(Bitboard inAttackers, Bitboard inBoard);
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
