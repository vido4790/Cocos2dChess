/***************************************************************************************************
 *
 *  @file       Bitboard.cpp  
 *
 *  @author     Virag Doshi
 *
 *  @brief      Bitboard implementation to represent pieces
 *
 **************************************************************************************************/

#include "ChessEngine.h"
#include "Bitboard.h"

#include "cocos2d.h"

using namespace chessEngine;
using namespace cocos2d;

////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Square
////////////////////////////////////////////////////////////////////////////////////////////////////

Position
Square::getPosition() const
{
    return (isRemoved() ? Position(index / 8, index % 8) : Position());
}

Bitboard
Square::getBitboard() const
{
    return (isRemoved() ? 0ULL : Bitboard::kSquareMasks[index]);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Bitboard
////////////////////////////////////////////////////////////////////////////////////////////////////

const Bitboard   Bitboard::kRowMasks[8] = {
    (0xFFULL <<  0), (0xFFULL <<  8), (0xFFULL << 16), (0xFFULL << 24),
    (0xFFULL << 32), (0xFFULL << 40), (0xFFULL << 48), (0xFFULL << 56)
};

const Bitboard   Bitboard::kColMasks[8] = {
    (0x0101010101010101ULL << 7), (0x0101010101010101ULL << 6),
    (0x0101010101010101ULL << 5), (0x0101010101010101ULL << 4),
    (0x0101010101010101ULL << 3), (0x0101010101010101ULL << 2),
    (0x0101010101010101ULL << 1), (0x0101010101010101ULL << 0)
};

const Bitboard   Bitboard::kSquareMasks[64] = {
    (0x1ULL << 0x00), (0x1ULL << 0x01), (0x1ULL << 0x02), (0x1ULL << 0x03),
    (0x1ULL << 0x04), (0x1ULL << 0x05), (0x1ULL << 0x06), (0x1ULL << 0x07),
    (0x1ULL << 0x08), (0x1ULL << 0x09), (0x1ULL << 0x0A), (0x1ULL << 0x0B),
    (0x1ULL << 0x0C), (0x1ULL << 0x0D), (0x1ULL << 0x0E), (0x1ULL << 0x0F),
    (0x1ULL << 0x10), (0x1ULL << 0x11), (0x1ULL << 0x12), (0x1ULL << 0x13),
    (0x1ULL << 0x14), (0x1ULL << 0x15), (0x1ULL << 0x16), (0x1ULL << 0x17),
    (0x1ULL << 0x18), (0x1ULL << 0x19), (0x1ULL << 0x1A), (0x1ULL << 0x1B),
    (0x1ULL << 0x1C), (0x1ULL << 0x1D), (0x1ULL << 0x1E), (0x1ULL << 0x1F),
    (0x2ULL << 0x20), (0x2ULL << 0x21), (0x2ULL << 0x22), (0x2ULL << 0x23),
    (0x2ULL << 0x24), (0x2ULL << 0x25), (0x2ULL << 0x26), (0x2ULL << 0x27),
    (0x2ULL << 0x28), (0x2ULL << 0x29), (0x2ULL << 0x2A), (0x2ULL << 0x2B),
    (0x2ULL << 0x2C), (0x2ULL << 0x2D), (0x2ULL << 0x2E), (0x2ULL << 0x2F),
    (0x3ULL << 0x30), (0x3ULL << 0x31), (0x3ULL << 0x32), (0x3ULL << 0x33),
    (0x3ULL << 0x34), (0x3ULL << 0x35), (0x3ULL << 0x36), (0x3ULL << 0x37),
    (0x3ULL << 0x38), (0x3ULL << 0x39), (0x3ULL << 0x3A), (0x3ULL << 0x3B),
    (0x3ULL << 0x3C), (0x3ULL << 0x3D), (0x3ULL << 0x3E), (0x3ULL << 0x3F)
};

// Diagonal going north east from the 0th column. There are 15 such diagonals. Each index represents
// diagonal originating from diffrent rows of the 0th column. First 8 indexes are negative rows, or
// they can be thought of as diagonals originating from the 0th row but different columns
const Bitboard    Bitboard::kDiagMasks[15] = {
    (0x8040201008040201ULL >> 56),              // -7 or 0, 7
    (0x8040201008040201ULL >> 48),              // -6 or 0, 6
    (0x8040201008040201ULL >> 40),              // -5 or 0, 5
    (0x8040201008040201ULL >> 32),              // -4 or 0, 4
    (0x8040201008040201ULL >> 24),              // -3 or 0, 3
    (0x8040201008040201ULL >> 16),              // -2 or 0, 2
    (0x8040201008040201ULL >>  8),              // -1 or 0, 1
    (0x8040201008040201ULL <<  0),              //  0 or 0, 0
    (0x8040201008040201ULL <<  8),              //  1 or 1, 0
    (0x8040201008040201ULL << 16),              //  2 or 2, 0
    (0x8040201008040201ULL << 24),              //  3 or 3, 0
    (0x8040201008040201ULL << 32),              //  4 or 4, 0
    (0x8040201008040201ULL << 40),              //  5 or 5, 0
    (0x8040201008040201ULL << 48),              //  6 or 6, 0
    (0x8040201008040201ULL << 56)               //  7 or 7, 0
};

// Diagonal going north west from the 0th column. There are 15 such diagonals. Each index represents
// diagonal originating from diffrent rows of the 0th column. First 8 indexes are negative rows, or
// they can be thought of as diagonals originating from the 0th row but different columns
const Bitboard    Bitboard::kADiagMasks[15] = {
    (0x8040201008040201ULL >> 56),              // -7 or 0, 7
    (0x8040201008040201ULL >> 48),              // -6 or 0, 6
    (0x8040201008040201ULL >> 40),              // -5 or 0, 5
    (0x8040201008040201ULL >> 32),              // -4 or 0, 4
    (0x8040201008040201ULL >> 24),              // -3 or 0, 3
    (0x8040201008040201ULL >> 16),              // -2 or 0, 2
    (0x8040201008040201ULL >>  8),              // -1 or 0, 1
    (0x8040201008040201ULL <<  0),              //  0 or 0, 0
    (0x8040201008040201ULL <<  8),              //  1 or 1, 0
    (0x8040201008040201ULL << 16),              //  2 or 2, 0
    (0x8040201008040201ULL << 24),              //  3 or 3, 0
    (0x8040201008040201ULL << 32),              //  4 or 4, 0
    (0x8040201008040201ULL << 40),              //  5 or 5, 0
    (0x8040201008040201ULL << 48),              //  6 or 6, 0
    (0x8040201008040201ULL << 56)               //  7 or 7, 0
};

const Bitboard    Bitboard::kStartWhitePawns    = Bitboard::kRowMasks[1];
const Bitboard    Bitboard::kStartBlackPawns    = Bitboard::kRowMasks[6];

const Bitboard    Bitboard::kStartWhiteKnights  = (Bitboard::kSquareMasks[1] |
                                                   Bitboard::kSquareMasks[6]);
const Bitboard    Bitboard::kStartBlackKnights  = (Bitboard::kSquareMasks[56 + 1] |
                                                   Bitboard::kSquareMasks[56 + 6]);

const Bitboard    Bitboard::kStartWhiteBishops  = (Bitboard::kSquareMasks[2] |
                                                   Bitboard::kSquareMasks[5]);
const Bitboard    Bitboard::kStartBlackBishops  = (Bitboard::kSquareMasks[56 + 2] |
                                                   Bitboard::kSquareMasks[56 + 5]);

const Bitboard    Bitboard::kStartWhiteRooks    = (Bitboard::kSquareMasks[0] |
                                                   Bitboard::kSquareMasks[7]);
const Bitboard    Bitboard::kStartBlackRooks    = (Bitboard::kSquareMasks[56 + 0] |
                                                   Bitboard::kSquareMasks[56 + 7]);

const Bitboard    Bitboard::kStartWhiteQueen    = Bitboard::kSquareMasks[3];
const Bitboard    Bitboard::kStartBlackQueen    = Bitboard::kSquareMasks[56 + 3];

const Bitboard    Bitboard::kStartWhiteKing     = Bitboard::kSquareMasks[4];
const Bitboard    Bitboard::kStartBlackKing     = Bitboard::kSquareMasks[56 + 4];


void
Bitboard::print()
{
    logger("\n");
    
    for (auto row = 0; row < 8; row++)
    {
        for (auto col = 0; col < 8; col++)
        {
            unsigned int val = (Square(row, col).getBitboard().mask & mask) > 0;
            
            logger("%d", val);
        }
        
        logger("\n");
    }
    
    logger("\n");
}
