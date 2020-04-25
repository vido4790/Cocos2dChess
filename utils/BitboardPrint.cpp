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

		// Bitboard::getForSquare(i).print();		

		assert(1ULL << i == Bitboard::getForSquare(i).mask);
		assert((wholeMask & Bitboard::getForSquare(i).mask) == 0);

		wholeMask |= Bitboard::getForSquare(i).mask;
	}

	assert(wholeMask == Bitboard::kFull.mask);
	wholeMask = 0;

	LOG("\nRows\n");

	for (auto i = 0; i < 8; i++)
	{
		LOG("%d ", i);
		
		// Bitboard::getForRow(i).print();

		assert(__builtin_popcountll(Bitboard::getForRow(i).mask) == 8);
		assert(Bitboard::getForRow(i).mask == (0xFFULL << (8 * i)));
		assert((wholeMask & Bitboard::getForRow(i).mask) == 0);

		wholeMask |= Bitboard::getForRow(i).mask;
	}

	assert(wholeMask == Bitboard::kFull.mask);
	wholeMask = 0;

	LOG("\nCols\n");

	for (auto i = 0; i < 8; i++)
	{
		LOG("%d ", i);
		
		// Bitboard::getForCol(i).print();

		assert(__builtin_popcountll(Bitboard::getForCol(i).mask) == 8);
		assert(Bitboard::getForCol(i).mask == (0x0101010101010101 << (7 - i)));
		assert((wholeMask & Bitboard::getForCol(i).mask) == 0);

		wholeMask |= Bitboard::getForCol(i).mask;
	}

	assert(wholeMask == Bitboard::kFull.mask);
	wholeMask = 0;

	BitboardMask aWholeMask = 0;

	LOG("\nDiags and adiags\n");

	for (auto i = 0; i < 15; i++)
	{
		auto diagMask  = Bitboard::getForDiag(i).mask;
		auto aDiagMask = Bitboard::getForADiag(i).mask;
		
		LOG("%d ", i);

		auto numBits = (i > 7) ? 15 - i : i + 1;
		assert(__builtin_popcountll(Bitboard::getForDiag(i).mask) == numBits);
		assert(__builtin_popcountll(Bitboard::getForADiag(i).mask) == numBits);

		//LOG("\n");
		//Bitboard::getForADiag(i).print();
		//Bitboard::getForDiag(i).print();

		for (auto row = 7; row >= 0; row--)
		{
			for (auto col = 0; col < 8; col++)
			{
				auto currMask = Bitboard::getForSquare(Square(row, col)).mask;
				bool isOnDiag = ((row - col + 7) == i);
				bool isOnADiag = ((row + col) == i);

				// LOG("%d%d,", isOnDiag, ((currMask & diagMask) == currMask));
				// LOG("%d%d ", isOnADiag, ((currMask & aDiagMask) == currMask));

				assert(row - col + 7 == Bitboard::getDiagNum(Square(row, col)));
				assert(row + col == Bitboard::getADiagNum(Square(row, col)));
				assert(((currMask & diagMask) == currMask) == isOnDiag);
				assert(((currMask & aDiagMask) == currMask) == isOnADiag);
			}

			// LOG("\n");
		}
		assert((wholeMask & Bitboard::getForDiag(i).mask) == 0);
		assert((aWholeMask & Bitboard::getForADiag(i).mask) == 0);

		wholeMask  |= Bitboard::getForDiag(i).mask;
		aWholeMask |= Bitboard::getForADiag(i).mask;
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