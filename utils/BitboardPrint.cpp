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
#include <assert.h>

using namespace chessEngine;

#define countof(x) (sizeof(x)/sizeof(x[0]))

void testMasks()
{
	LOG("Square\n");

	for (auto i = 0; i < 64; i++)
	{
		LOG("%d ", i);
		assert(1ULL << i == Bitboard::kSquareMasks[i].mask);
	}

	LOG("\nRows\n");

	for (auto i = 0; i < countof(Bitboard::kRowMasks); i++)
	{
		LOG("%d ", i);
		
		assert(__builtin_popcountll(Bitboard::kRowMasks[i].mask) == 8);
		assert(Bitboard::kRowMasks[i].mask == (0xFFULL << (8 * i)));
	}

	LOG("\nCols\n");

	for (auto i = 0; i < countof(Bitboard::kColMasks); i++)
	{
		LOG("%d ", i);
		
		assert(__builtin_popcountll(Bitboard::kRowMasks[i].mask) == 8);
		assert(Bitboard::kColMasks[i].mask == (0x0101010101010101 << (7 - i)));
	}

	LOG("\nDiags\n");

	for (auto i = 0; i < countof(Bitboard::kColMasks); i++)
	{
		LOG("%d ", i);
		
		assert(__builtin_popcountll(Bitboard::kRowMasks[i].mask) == 8);
		assert(Bitboard::kColMasks[i].mask == (0x0101010101010101 << (7 - i)));
	}	
}

int main()
{
	testMasks();

	LOG("Diags\n");

	for (auto i = 0; i < countof(Bitboard::kDiagMasks); i++)
	{
		LOG("%d", i);
		Bitboard::kDiagMasks[i].print();
		LOG("\n");
	}

	return 0;
}