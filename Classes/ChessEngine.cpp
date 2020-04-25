/***************************************************************************************************
 *
 *  @file       ChessEngine.cpp
 *
 *  @author     Virag Doshi
 *
 *  @brief      Chess engine
 *
 **************************************************************************************************/

#include "ChessEngine.h"

using namespace chessEngine;


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark ChessEngine::BitboardCollection
////////////////////////////////////////////////////////////////////////////////////////////////////

bool
ChessEngine::BitboardCollection::getPieceAt(const Position & inPos,
                                            attributes::ChessPieceName * outPiece)
{
    for (auto i = 0; i < _pos.size(); ++i)
    {
        if ((_pos[i] & inPos.getBitboard()) != 0)
        {
            *outPiece = static_cast<attributes::ChessPieceName>(i);
            return true;
        }
    }
    
    return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark ChessboardScene
////////////////////////////////////////////////////////////////////////////////////////////////////

ChessEngine::ChessEngine() :
_whitePieces(Bitboard::kStartWhitePawns, Bitboard::kStartWhiteKnights,
             Bitboard::kStartWhiteBishops, Bitboard::kStartWhiteRooks,
             Bitboard::kStartWhiteQueen, Bitboard::kStartWhiteKing),
_blackPieces(Bitboard::kStartBlackPawns, Bitboard::kStartBlackKnights,
             Bitboard::kStartBlackBishops, Bitboard::kStartBlackRooks,
             Bitboard::kStartBlackQueen, Bitboard::kStartBlackKing)
{
    
}

bool
ChessEngine::attemptMove(const Move & inMove, Move * outSideEffect,
                         bool * outPromotion)
{
    bool ret = false;
    
    attributes::ChessPieceName piece;
    attributes::ChessColor color;
    
    // Start with an invalid move
    *outSideEffect = Move();
    
    if (_whitePieces.getPieceAt(inMove.src, &piece))
    {
        color = attributes::ChessColor::kWhite;
    }
    else if(_blackPieces.getPieceAt(inMove.src, &piece))
    {
        color = attributes::ChessColor::kBlack;
    }
    else
    {
        assert(0);
    }
    
    switch (piece)
    {
        case attributes::ChessPieceName::kPawn:
        {
            return _attemptPawnMove(color, inMove, outSideEffect, outPromotion);
        }
        case attributes::ChessPieceName::kKnight:
        {
            return _attemptKnightMove(color, inMove, outSideEffect);
        }
        case attributes::ChessPieceName::kBishop:
        {
            return _attemptBishopMove(color, inMove, outSideEffect);
        }
        case attributes::ChessPieceName::kRook:
        {
            return _attemptRookMove(color, inMove, outSideEffect);
        }
        case attributes::ChessPieceName::kQueen:
        {
            return _attemptQueenMove(color, inMove, outSideEffect);
        }
        case attributes::ChessPieceName::kKing:
        {
            return _attemptKingMove(color, inMove, outSideEffect);
        }
    }
    
    return false;
}

bool
ChessEngine::_attemptPawnMove(attributes::ChessColor inColor,
                              const Move & inMove, Move * outSideEffect,
                              bool * outPromotion)
{
    _simpleMoveAndKill(attributes::ChessPieceName::kPawn, inColor, inMove, outSideEffect);
    *outPromotion = false;
    
    return true;
}

bool
ChessEngine::_attemptKnightMove(attributes::ChessColor inColor,
                                const Move & inMove, Move * outSideEffect)
{
    _simpleMoveAndKill(attributes::ChessPieceName::kKnight, inColor, inMove, outSideEffect);
    
    return true;
}

bool
ChessEngine::_attemptBishopMove(attributes::ChessColor inColor,
                                const Move & inMove, Move * outSideEffect)
{
    _simpleMoveAndKill(attributes::ChessPieceName::kBishop, inColor, inMove, outSideEffect);
    
    return true;
}

bool
ChessEngine::_attemptRookMove(attributes::ChessColor inColor,
                              const Move & inMove, Move * outSideEffect)
{
    _simpleMoveAndKill(attributes::ChessPieceName::kRook, inColor, inMove, outSideEffect);
    
    return true;
}

bool
ChessEngine::_attemptQueenMove(attributes::ChessColor inColor,
                               const Move & inMove, Move * outSideEffect)
{
    _simpleMoveAndKill(attributes::ChessPieceName::kQueen, inColor, inMove, outSideEffect);
    
    return true;
}

bool
ChessEngine::_attemptKingMove(attributes::ChessColor inColor,
                              const Move & inMove, Move * outSideEffect)
{
    _simpleMoveAndKill(attributes::ChessPieceName::kKing, inColor, inMove, outSideEffect);
    
    return true;
}

void
ChessEngine::_simpleMoveAndKill(attributes::ChessPieceName inPiece,
                                attributes::ChessColor inColor,
                                const Move & inMove, Move * outSideEffect)
{
    bool isWhite     = (inColor == attributes::ChessColor::kWhite);
    
    auto src         = inMove.src.getBitboard();
    auto dest        = inMove.dest.getBitboard();
    
    auto & own       = isWhite ? _whitePieces : _blackPieces;
    auto & others    = isWhite ? _blackPieces : _whitePieces;
    
    attributes::ChessPieceName capturedPiece;
    
    if (others.getPieceAt(inMove.dest, &capturedPiece))
    {
        own.board(capturedPiece) &= ~dest;
        
        outSideEffect->src  = (*dest.begin()).getPosition();
        outSideEffect->dest = Position();
    }
    
    own.board(inPiece)  &= ~src;
    own.board(inPiece)  |= dest;
}
