/***************************************************************************************************
 *
 *  @file       BitboardPrint.cpp  
 *
 *  @author     Virag Doshi
 *
 *  @brief
 *
 **************************************************************************************************/

#include "Bitboard.h"
#include <inttypes.h>
#include <assert.h>

using namespace chessEngine;

#define countof(x) (sizeof(x)/sizeof(x[0]))

void testMasks()
{
	BitboardMask wholeMask = 0;

	LOG("Square\n");

	for (auto i = 0; i < 64; i++)
	{
		LOG("%d ", i);

		// Bitboard::kSquareMasks[i].print();		

		assert(1ULL << i == Bitboard::kSquareMasks[i].mask);
		assert((wholeMask & Bitboard::kSquareMasks[i].mask) == 0);

		wholeMask |= Bitboard::kSquareMasks[i].mask;
	}

	assert(wholeMask == Bitboard::kFull.mask);
	wholeMask = 0;

	LOG("\nRows\n");

	for (auto i = 0; i < countof(Bitboard::kRowMasks); i++)
	{
		LOG("%d ", i);
		
		// Bitboard::kRowMasks[i].print();

		assert(__builtin_popcountll(Bitboard::kRowMasks[i].mask) == 8);
		assert(Bitboard::kRowMasks[i].mask == (0xFFULL << (8 * i)));
		assert((wholeMask & Bitboard::kRowMasks[i].mask) == 0);

		wholeMask |= Bitboard::kRowMasks[i].mask;
	}

	assert(wholeMask == Bitboard::kFull.mask);
	wholeMask = 0;

	LOG("\nCols\n");

	for (auto i = 0; i < countof(Bitboard::kColMasks); i++)
	{
		LOG("%d ", i);
		
		// Bitboard::kColMasks[i].print();

		assert(__builtin_popcountll(Bitboard::kRowMasks[i].mask) == 8);
		assert(Bitboard::kColMasks[i].mask == (0x0101010101010101 << (7 - i)));
		assert((wholeMask & Bitboard::kColMasks[i].mask) == 0);

		wholeMask |= Bitboard::kColMasks[i].mask;
	}

	assert(wholeMask == Bitboard::kFull.mask);
	wholeMask = 0;

	BitboardMask aWholeMask = 0;

	LOG("\nDiags and adiags\n");

	assert(countof(Bitboard::kADiagMasks) == countof(Bitboard::kDiagMasks));

	for (auto i = 0; i < countof(Bitboard::kADiagMasks); i++)
	{
		auto diagMask  = Bitboard::kDiagMasks[i].mask;
		auto aDiagMask = Bitboard::kADiagMasks[i].mask;
		
		LOG("%d ", i);

		auto numBits = (i > 7) ? 15 - i : i + 1;
		assert(__builtin_popcountll(Bitboard::kDiagMasks[i].mask) == numBits);
		assert(__builtin_popcountll(Bitboard::kADiagMasks[i].mask) == numBits);

		//LOG("\n");
		//Bitboard::kADiagMasks[i].print();
		//Bitboard::kDiagMasks[i].print();

		for (auto row = 7; row >= 0; row--)
		{
			for (auto col = 0; col < 8; col++)
			{
				auto currMask = Square(row, col).getBitboard().mask;
				bool isOnDiag = ((row - col + 7) == i);
				bool isOnADiag = ((row + col) == i);

				// LOG("%d%d,", isOnDiag, ((currMask & diagMask) == currMask));
				// LOG("%d%d ", isOnADiag, ((currMask & aDiagMask) == currMask));

				assert(((currMask & diagMask) == currMask) == isOnDiag);
				assert(((currMask & aDiagMask) == currMask) == isOnADiag);
			}

			// LOG("\n");
		}
		assert((wholeMask & Bitboard::kDiagMasks[i].mask) == 0);
		assert((aWholeMask & Bitboard::kADiagMasks[i].mask) == 0);

		wholeMask  |= Bitboard::kDiagMasks[i].mask;
		aWholeMask |= Bitboard::kADiagMasks[i].mask;
	}

	assert(wholeMask == Bitboard::kFull.mask);
	assert(aWholeMask == Bitboard::kFull.mask);
	wholeMask = 0;
}

int main()
{
	testMasks();
	LOG("\nBitboard tests successful\n");
	return 0;
}