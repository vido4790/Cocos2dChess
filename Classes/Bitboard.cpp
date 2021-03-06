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

#include <inttypes.h>
#include <limits>

using namespace chessEngine;

////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Square
////////////////////////////////////////////////////////////////////////////////////////////////////

Position
Square::getPosition() const
{
    return (isOutside() ? Position::outside() :
            Position(_getRowNoValidation(), _getColNoValidation()));
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark BitboardLUT
////////////////////////////////////////////////////////////////////////////////////////////////////

static constexpr BitboardMask kRowMaskBase = 0xFFULL;
const Bitboard   BitboardLUT::kRowMasks[8] = {
    (kRowMaskBase <<  0), (kRowMaskBase <<  8), (kRowMaskBase << 16), (kRowMaskBase << 24),
    (kRowMaskBase << 32), (kRowMaskBase << 40), (kRowMaskBase << 48), (kRowMaskBase << 56)
};

static constexpr BitboardMask kColMasksBase = 0x0101010101010101ULL;
const Bitboard   BitboardLUT::kColMasks[8] = {
    (kColMasksBase << 7), (kColMasksBase << 6),
    (kColMasksBase << 5), (kColMasksBase << 4),
    (kColMasksBase << 3), (kColMasksBase << 2),
    (kColMasksBase << 1), (kColMasksBase << 0)
};

static constexpr BitboardMask kSquareMaskBase = 0x01ULL;
const Bitboard   BitboardLUT::kSquareMasks[64] = {
    (kSquareMaskBase << 0x00), (kSquareMaskBase << 0x01),
    (kSquareMaskBase << 0x02), (kSquareMaskBase << 0x03),
    (kSquareMaskBase << 0x04), (kSquareMaskBase << 0x05),
    (kSquareMaskBase << 0x06), (kSquareMaskBase << 0x07),
    (kSquareMaskBase << 0x08), (kSquareMaskBase << 0x09),
    (kSquareMaskBase << 0x0A), (kSquareMaskBase << 0x0B),
    (kSquareMaskBase << 0x0C), (kSquareMaskBase << 0x0D),
    (kSquareMaskBase << 0x0E), (kSquareMaskBase << 0x0F),
    (kSquareMaskBase << 0x10), (kSquareMaskBase << 0x11),
    (kSquareMaskBase << 0x12), (kSquareMaskBase << 0x13),
    (kSquareMaskBase << 0x14), (kSquareMaskBase << 0x15),
    (kSquareMaskBase << 0x16), (kSquareMaskBase << 0x17),
    (kSquareMaskBase << 0x18), (kSquareMaskBase << 0x19),
    (kSquareMaskBase << 0x1A), (kSquareMaskBase << 0x1B),
    (kSquareMaskBase << 0x1C), (kSquareMaskBase << 0x1D),
    (kSquareMaskBase << 0x1E), (kSquareMaskBase << 0x1F),
    (kSquareMaskBase << 0x20), (kSquareMaskBase << 0x21),
    (kSquareMaskBase << 0x22), (kSquareMaskBase << 0x23),
    (kSquareMaskBase << 0x24), (kSquareMaskBase << 0x25),
    (kSquareMaskBase << 0x26), (kSquareMaskBase << 0x27),
    (kSquareMaskBase << 0x28), (kSquareMaskBase << 0x29),
    (kSquareMaskBase << 0x2A), (kSquareMaskBase << 0x2B),
    (kSquareMaskBase << 0x2C), (kSquareMaskBase << 0x2D),
    (kSquareMaskBase << 0x2E), (kSquareMaskBase << 0x2F),
    (kSquareMaskBase << 0x30), (kSquareMaskBase << 0x31),
    (kSquareMaskBase << 0x32), (kSquareMaskBase << 0x33),
    (kSquareMaskBase << 0x34), (kSquareMaskBase << 0x35),
    (kSquareMaskBase << 0x36), (kSquareMaskBase << 0x37),
    (kSquareMaskBase << 0x38), (kSquareMaskBase << 0x39),
    (kSquareMaskBase << 0x3A), (kSquareMaskBase << 0x3B),
    (kSquareMaskBase << 0x3C), (kSquareMaskBase << 0x3D),
    (kSquareMaskBase << 0x3E), (kSquareMaskBase << 0x3F)
};

// Diagonal going north east
//
// line eqn: y = x + c or r = c + i - 7 where i is the index that goes from 0-14
// index such that a point (r, c) is on the diagonal i = r - c + 7
//
static constexpr BitboardMask kDiagMaskBase = 0x8040201008040201ULL;
const Bitboard   BitboardLUT::kDiagMasks[15] = {  // start (r, c) on the board
    (kDiagMaskBase >> 56),                      //  0 or (0, 7)
    (kDiagMaskBase >> 48),                      //  1 or (0, 6)
    (kDiagMaskBase >> 40),                      //  2 or (0, 5)
    (kDiagMaskBase >> 32),                      //  3 or (0, 4)
    (kDiagMaskBase >> 24),                      //  4 or (0, 3)
    (kDiagMaskBase >> 16),                      //  5 or (0, 2)
    (kDiagMaskBase >>  8),                      //  6 or (0, 1)
    (kDiagMaskBase),                            //  7 or (0, 0)
    (kDiagMaskBase <<  8),                      //  8 or (1, 0)
    (kDiagMaskBase << 16),                      //  9 or (2, 0)
    (kDiagMaskBase << 24),                      // 10 or (3, 0)
    (kDiagMaskBase << 32),                      // 11 or (4, 0)
    (kDiagMaskBase << 40),                      // 12 or (5, 0)
    (kDiagMaskBase << 48),                      // 13 or (6, 0)
    (kDiagMaskBase << 56)                       // 14 or (7, 0)
};

// Diagonal going north west
//
// line eqn: y = -x + c or r = -c + i where i is the index that goes from 0-14
// index such that a point (r, c) is on the diagonal i = r + c
//
static constexpr BitboardMask kADiagMaskBase = 0x0102040810204080ULL;
const Bitboard   BitboardLUT::kADiagMasks[15] = { //  i     r  c
    (kADiagMaskBase >> 56),                     //  0 or (0, 0)
    (kADiagMaskBase >> 48),                     //  1 or (0, 1)
    (kADiagMaskBase >> 40),                     //  2 or (0, 2)
    (kADiagMaskBase >> 32),                     //  3 or (0, 3)
    (kADiagMaskBase >> 24),                     //  4 or (0, 4)
    (kADiagMaskBase >> 16),                     //  5 or (0, 5)
    (kADiagMaskBase >>  8),                     //  6 or (0, 6)
    (kADiagMaskBase),                           //  7 or (0, 7)
    (kADiagMaskBase <<  8),                     //  8 or (1, 7)
    (kADiagMaskBase << 16),                     //  9 or (2, 7)
    (kADiagMaskBase << 24),                     // 10 or (3, 7)
    (kADiagMaskBase << 32),                     // 11 or (4, 7)
    (kADiagMaskBase << 40),                     // 12 or (5, 7)
    (kADiagMaskBase << 48),                     // 13 or (6, 7)
    (kADiagMaskBase << 56)                      // 14 or (7, 7)
};

const Bitboard    BitboardLUT::kStartWhitePawns    = BitboardLUT::kRowMasks[1];
const Bitboard    BitboardLUT::kStartBlackPawns    = BitboardLUT::kRowMasks[6];

const Bitboard    BitboardLUT::kStartWhiteKnights  = (BitboardLUT::kSquareMasks[1] |
                                                   BitboardLUT::kSquareMasks[6]);
const Bitboard    BitboardLUT::kStartBlackKnights  = (BitboardLUT::kSquareMasks[56 + 1] |
                                                   BitboardLUT::kSquareMasks[56 + 6]);

const Bitboard    BitboardLUT::kStartWhiteBishops  = (BitboardLUT::kSquareMasks[2] |
                                                   BitboardLUT::kSquareMasks[5]);
const Bitboard    BitboardLUT::kStartBlackBishops  = (BitboardLUT::kSquareMasks[56 + 2] |
                                                   BitboardLUT::kSquareMasks[56 + 5]);

const Bitboard    BitboardLUT::kStartWhiteRooks    = (BitboardLUT::kSquareMasks[0] |
                                                   BitboardLUT::kSquareMasks[7]);
const Bitboard    BitboardLUT::kStartBlackRooks    = (BitboardLUT::kSquareMasks[56 + 0] |
                                                   BitboardLUT::kSquareMasks[56 + 7]);

const Bitboard    BitboardLUT::kStartWhiteQueen    = BitboardLUT::kSquareMasks[3];
const Bitboard    BitboardLUT::kStartBlackQueen    = BitboardLUT::kSquareMasks[56 + 3];

const Bitboard    BitboardLUT::kStartWhiteKing     = BitboardLUT::kSquareMasks[4];
const Bitboard    BitboardLUT::kStartBlackKing     = BitboardLUT::kSquareMasks[56 + 4];

const Bitboard    BitboardLUT::kFull               = std::numeric_limits<BitboardMask>::max();

Bitboard          BitboardLUT::kRowOccupiedMasks[8][256];
Bitboard          BitboardLUT::kColOccupiedMasks[8][256];
Bitboard          BitboardLUT::kDiagOccupiedMasks[8][256];
Bitboard          BitboardLUT::kADiagOccupiedMasks[8][256];

void
BitboardLUT::init()
{
    for (auto i = 0; i < 8; i++)
    {
        for (auto others = 0; others < 256; others++)
        {
            uint8_t allPieces    = others | (1 << i);
            int8_t  closestBelow = -1;
            uint8_t closestAbove = 8;
            
            for (int8_t bitPos = i - 1; bitPos >= 0; bitPos--)
            {
                if ((1 << bitPos) & allPieces)
                {
                    closestBelow = bitPos;
                    break;
                }
            }
            
            for (uint8_t bitPos = i + 1; bitPos < 8; bitPos++)
            {
                if ((1 << bitPos) & allPieces)
                {
                    closestAbove = bitPos;
                    break;
                }
            }
            
            assert(closestBelow < i);
            assert(closestAbove > i);
            
            auto rowIt   = kRowMasks[0].begin();
            auto colIt   = kColMasks[0].begin();
            auto diagIt  = kDiagMasks[7].begin();
            auto aDiagIt = kADiagMasks[7].begin();
            
            for (auto bitPos = 0; bitPos <= closestBelow; bitPos++)
            {
                ++rowIt;
                ++colIt;
                ++diagIt;
                ++aDiagIt;
            }
            
            for (auto bitPos = closestBelow + 1; bitPos < closestAbove; bitPos++)
            {
                kRowOccupiedMasks[i][others]   |= Bitboard::getForSquare(*rowIt);
                kColOccupiedMasks[i][others]   |= Bitboard::getForSquare(*colIt);
                kDiagOccupiedMasks[i][others]  |= Bitboard::getForSquare(*diagIt);
                kADiagOccupiedMasks[i][others] |= Bitboard::getForSquare(*aDiagIt);
                
                ++rowIt;
                ++colIt;
                ++diagIt;
                ++aDiagIt;
            }
            
            assert((kRowOccupiedMasks[i][others] | kRowMasks[0])     == kRowMasks[0]);
            assert((kColOccupiedMasks[i][others] | kColMasks[0])     == kColMasks[0]);
            assert((kDiagOccupiedMasks[i][others] | kDiagMasks[7])   == kDiagMasks[7]);
            assert((kADiagOccupiedMasks[i][others] | kADiagMasks[7]) == kADiagMasks[7]);
            
            assert(kRowOccupiedMasks[i][others].mask   <= kRowMasks[0].mask);
            assert(kColOccupiedMasks[i][others].mask   <= kColMasks[0].mask);
            assert(kDiagOccupiedMasks[i][others].mask  <= kDiagMasks[7].mask);
            assert(kADiagOccupiedMasks[i][others].mask <= kADiagMasks[7].mask);
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Bitboard
////////////////////////////////////////////////////////////////////////////////////////////////////

Bitboard
Bitboard::getRowAttacks(Square inSq, Bitboard inBoard)
{
    
}

Bitboard
Bitboard::getRowAttacks(Bitboard inAttackers, Bitboard inBoard)
{
    
}

void
Bitboard::print() const
{
    LOG("0x%" PRIx64 "\n", mask);
    
    for (auto row = 7; row >= 0; row--)
    {
        for (auto col = 0; col < 8; col++)
        {
            unsigned int val = (getForSquare(Square(row, col)).mask & mask) > 0;
            
            LOG("%d ", val);
        }
        
        LOG("\n");
    }
    
    LOG("\n");
}
