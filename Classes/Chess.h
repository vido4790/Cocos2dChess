/***************************************************************************************************
 *
 *  @file       Chess.h  
 *
 *  @author     Virag Doshi
 *
 *  @brief      Attributes required for Chess
 *
 **************************************************************************************************/

#pragma once

#include <cstddef>
#include <assert.h>
#include <stdio.h>
#include <ctype.h>

#ifndef APP_UTILS
#define LOG      cocos2d::log
#else
#define LOG      printf
#endif

namespace attributes
{
	enum class ChessColor : uint8_t
	{
		kBlack,
		kWhite,
		kNone
	};

	enum class ChessPieceName : uint8_t
	{
		kPawn,
		kKnight,
		kBishop,
		kRook,
		kQueen,
		kKing
	};
    
    struct EnumClassHash
    {
        template <typename T>
        std::size_t operator()(T t) const
        {
            return static_cast<std::size_t>(t);
        }
    };
}
