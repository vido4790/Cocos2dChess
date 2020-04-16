/***************************************************************************************************
 *
 *  @file       Chess.h  
 *
 *  @author     Virag Doshi
 *
 *  @brief
 *
 **************************************************************************************************/

#pragma once

#include <assert.h>
#include <stdio.h>
#include <ctype.h>


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
    
    class ChessboardPosition
    {
    public:
        static constexpr uint8_t    kOutside = 0xFF;
        
    private:
        uint8_t                     _rowIndex;
        uint8_t                     _colIndex;
        
        ChessboardPosition(uint8_t inRowIndex,
                           uint8_t inColIndex) :
        _rowIndex(inRowIndex), _colIndex(inColIndex)
        {
            assert((_rowIndex < kOutside) || (_rowIndex == kOutside));
            assert((_colIndex < kOutside) || (_colIndex == kOutside));
        }
        
    public:
        static ChessboardPosition   getChessboardPositionByIndex(uint8_t inRowIndex,
                                                                 uint8_t inColIndex)
        {
            return ChessboardPosition(inRowIndex, inColIndex);
        }
        
        static ChessboardPosition   getChessboardPositionByName(uint8_t inRowName,
                                                                char    inColName)
        {
            return ChessboardPosition(inRowName - 1, tolower(inColName) - 'a');
        }
        
        uint8_t                     getRowIndex() const { return _rowIndex; }
        uint8_t                     getColIndex() const { return _colIndex; }
        
        uint8_t                     getRowName() const  { return _rowIndex + 1; }
        uint8_t                     getColName() const  { return _colIndex + 'a'; }
        
        bool                        operator== (const ChessboardPosition & inOther) const
        {
            return (inOther._rowIndex == _rowIndex) && (inOther._colIndex == _colIndex);
        }
        
        bool                        operator!= (const ChessboardPosition & inOther) const
        {
            return (*this != inOther);
        }
        
        bool                        isOnBoard() const
        {
            return (_rowIndex == kOutside) || (_colIndex == kOutside);
        }
    };
}
