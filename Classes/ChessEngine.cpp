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
             Bitboard::kStartBlackQueen, Bitboard::kStartBlackKing),
_currTurn(attributes::ChessColor::kWhite)
{
    
}

bool
ChessEngine::attemptMove(const Move & inMove, Move * outSideEffect,
                         bool * outPromotion)
{
    bool ret = false;
    
    attributes::ChessPieceName piece;
    attributes::ChessColor color = getCurrMove();
    
    // Start with an invalid move
    *outSideEffect = Move::invalid();
    
    if (color == attributes::ChessColor::kWhite)
    {
        assert(_whitePieces.getPieceAt(inMove.src, &piece));
    }
    else if(color == attributes::ChessColor::kBlack)
    {
        assert(_blackPieces.getPieceAt(inMove.src, &piece));
    }
    else
    {
        assert(0);
    }
    
    switch (piece)
    {
        case attributes::ChessPieceName::kPawn:
        {
            ret = _attemptPawnMove(color, inMove, outSideEffect, outPromotion);
            break;
        }
        case attributes::ChessPieceName::kKnight:
        {
            ret = _attemptKnightMove(color, inMove, outSideEffect);
            break;
        }
        case attributes::ChessPieceName::kBishop:
        {
            ret = _attemptBishopMove(color, inMove, outSideEffect);
            break;
        }
        case attributes::ChessPieceName::kRook:
        {
            ret = _attemptRookMove(color, inMove, outSideEffect);
            break;
        }
        case attributes::ChessPieceName::kQueen:
        {
            ret = _attemptQueenMove(color, inMove, outSideEffect);
            break;
        }
        case attributes::ChessPieceName::kKing:
        {
            ret = _attemptKingMove(color, inMove, outSideEffect);
            break;
        }
    }
    
    if (ret)
    {
        _currTurn = ((color == attributes::ChessColor::kWhite) ?
                     attributes::ChessColor::kBlack :
                     attributes::ChessColor::kWhite);
    }
    
    return ret;
}

bool
ChessEngine::_attemptPawnMove(attributes::ChessColor inColor,
                              const Move & inMove, Move * outSideEffect,
                              bool * outPromotion)
{
    *outPromotion = false;
    return _simpleMoveAndKill(attributes::ChessPieceName::kPawn, inColor,
                              inMove, outSideEffect);
}

bool
ChessEngine::_attemptKnightMove(attributes::ChessColor inColor,
                                const Move & inMove, Move * outSideEffect)
{
    return _simpleMoveAndKill(attributes::ChessPieceName::kKnight, inColor,
                              inMove, outSideEffect);
}

bool
ChessEngine::_attemptBishopMove(attributes::ChessColor inColor,
                                const Move & inMove, Move * outSideEffect)
{
    return _simpleMoveAndKill(attributes::ChessPieceName::kBishop, inColor,
                              inMove, outSideEffect);
}

bool
ChessEngine::_attemptRookMove(attributes::ChessColor inColor,
                              const Move & inMove, Move * outSideEffect)
{
    return _simpleMoveAndKill(attributes::ChessPieceName::kRook, inColor,
                              inMove, outSideEffect);
}

bool
ChessEngine::_attemptQueenMove(attributes::ChessColor inColor,
                               const Move & inMove, Move * outSideEffect)
{
    return _simpleMoveAndKill(attributes::ChessPieceName::kQueen, inColor,
                              inMove, outSideEffect);
}

bool
ChessEngine::_attemptKingMove(attributes::ChessColor inColor,
                              const Move & inMove, Move * outSideEffect)
{
    return _simpleMoveAndKill(attributes::ChessPieceName::kKing, inColor,
                              inMove, outSideEffect);
}

bool
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
        if (capturedPiece == attributes::ChessPieceName::kKing)
        {
            return false;
        }
        
        own.board(capturedPiece) &= ~dest;
        
        outSideEffect->src  = (*dest.begin()).getPosition();
        outSideEffect->dest = Position::outside();
    }
    
    own.board(inPiece)  &= ~src;
    own.board(inPiece)  |= dest;
}
