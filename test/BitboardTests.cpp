/***************************************************************************************************
 *
 *  @file       BitboardTests.cpp  
 *
 *  @author     Virag Doshi
 *
 *  @brief
 *
 **************************************************************************************************/

#include "Test.h"

#include "Bitboard.h"
#include <inttypes.h>

using namespace chessEngine;

#define countof(x) (sizeof(x)/sizeof(x[0]))

TEST_CASE( "Test Bitboards", "[Bitboard]")
{
	BitboardMask wholeMask = 0;

	for (auto i = 0; i < 64; i++)
	{
		// Bitboard::getForSquare(i).print();
        
        INFO("Failed for index " << i);
		CHECK(1ULL << i == Bitboard::getForSquare(i).mask);
		CHECK((wholeMask & Bitboard::getForSquare(i).mask) == 0);
        
		wholeMask |= Bitboard::getForSquare(i).mask;
	}

	CHECK(wholeMask == Bitboard::kFull.mask);
	wholeMask = 0;

	for (auto i = 0; i < 8; i++)
	{
		// Bitboard::getForRow(i).print();

        INFO("Failed for index " << i);
		CHECK(__builtin_popcountll(Bitboard::getForRow(i).mask) == 8);
		CHECK(Bitboard::getForRow(i).mask == (0xFFULL << (8 * i)));
		CHECK((wholeMask & Bitboard::getForRow(i).mask) == 0);

		wholeMask |= Bitboard::getForRow(i).mask;
	}

	CHECK(wholeMask == Bitboard::kFull.mask);
	wholeMask = 0;

	for (auto i = 0; i < 8; i++)
	{
		// Bitboard::getForCol(i).print();

        INFO("Failed for index " << i);
		CHECK(__builtin_popcountll(Bitboard::getForCol(i).mask) == 8);
		CHECK(Bitboard::getForCol(i).mask == (0x0101010101010101 << (7 - i)));
		CHECK((wholeMask & Bitboard::getForCol(i).mask) == 0);

		wholeMask |= Bitboard::getForCol(i).mask;
	}

	CHECK(wholeMask == Bitboard::kFull.mask);
	wholeMask = 0;

	BitboardMask aWholeMask = 0;

	for (auto i = 0; i < 15; i++)
	{
		auto diagMask  = Bitboard::getForDiag(i).mask;
		auto aDiagMask = Bitboard::getForADiag(i).mask;
		
		auto numBits = (i > 7) ? 15 - i : i + 1;
        
        INFO("Failed for index " << i);
		CHECK(__builtin_popcountll(Bitboard::getForDiag(i).mask) == numBits);
		CHECK(__builtin_popcountll(Bitboard::getForADiag(i).mask) == numBits);

		//Bitboard::getForADiag(i).print();
		//Bitboard::getForDiag(i).print();

		for (auto row = 7; row >= 0; row--)
		{
			for (auto col = 0; col < 8; col++)
			{
				auto currMask = Bitboard::getForSquare(Square(row, col)).mask;
				bool isOnDiag = ((row - col + 7) == i);
				bool isOnADiag = ((row + col) == i);

                INFO("Failed for cell " << row << ", "<< col);
				CHECK(row - col + 7 == Bitboard::getDiagNum(Square(row, col)));
				CHECK(row + col == Bitboard::getADiagNum(Square(row, col)));
				CHECK(((currMask & diagMask) == currMask) == isOnDiag);
				CHECK(((currMask & aDiagMask) == currMask) == isOnADiag);
			}
		}
		
		CHECK((wholeMask & Bitboard::getForDiag(i).mask) == 0);
		CHECK((aWholeMask & Bitboard::getForADiag(i).mask) == 0);

		wholeMask  |= Bitboard::getForDiag(i).mask;
		aWholeMask |= Bitboard::getForADiag(i).mask;
	}

	CHECK(wholeMask == Bitboard::kFull.mask);
	CHECK(aWholeMask == Bitboard::kFull.mask);
	wholeMask = 0;
}
