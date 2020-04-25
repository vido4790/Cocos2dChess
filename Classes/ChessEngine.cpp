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
#pragma mark ChessboardScene
////////////////////////////////////////////////////////////////////////////////////////////////////

ChessEngine::ChessEngine()
{
    _whitePieces.pawnsPos   = Bitboard::kStartWhitePawns;
    _blackPieces.pawnsPos   = Bitboard::kStartBlackPawns;
    _whitePieces.knightsPos = Bitboard::kStartWhiteKnights;
    _blackPieces.knightsPos = Bitboard::kStartBlackKnights;
    _whitePieces.bishopsPos = Bitboard::kStartWhiteBishops;
    _blackPieces.bishopsPos = Bitboard::kStartBlackBishops;
    _whitePieces.rooksPos   = Bitboard::kStartWhiteRooks;
    _blackPieces.rooksPos   = Bitboard::kStartBlackRooks;
    _whitePieces.queensPos  = Bitboard::kStartWhiteQueen;
    _blackPieces.queensPos  = Bitboard::kStartBlackQueen;
    _whitePieces.kingPos    = Bitboard::kStartWhiteKing;
    _blackPieces.kingPos    = Bitboard::kStartBlackKing;
}

bool
ChessEngine::attemptMove(const Move & inMove, Move * outSideEffect,
                         bool * outPromotion)
{
    bool ret = false;
    
    // Start with an invalid move
    *outSideEffect = Move();
    
    switch (inMove.piece.pieceType.piece)
    {
        case attributes::ChessPieceName::kPawn:
        {
            return _attemptPawnMove(inMove, outSideEffect, outPromotion);
        }
        case attributes::ChessPieceName::kKnight:
        {
            return _attemptKnightMove(inMove, outSideEffect);
        }
        case attributes::ChessPieceName::kBishop:
        {
            return _attemptBishopMove(inMove, outSideEffect);
        }
        case attributes::ChessPieceName::kRook:
        {
            return _attemptRookMove(inMove, outSideEffect);
        }
        case attributes::ChessPieceName::kQueen:
        {
            return _attemptQueenMove(inMove, outSideEffect);
        }
        case attributes::ChessPieceName::kKing:
        {
            return _attemptKingMove(inMove, outSideEffect);
        }
    }
    
    return false;
}

bool
ChessEngine::_attemptPawnMove(const Move & inMove, Move * outSideEffect,
                              bool * outPromotion)
{
    _simpleMoveAndKill(inMove, outSideEffect);
    *outPromotion = false;
    return true;
}

bool
ChessEngine::_attemptKnightMove(const Move & inMove, Move * outSideEffect)
{
    _simpleMoveAndKill(inMove, outSideEffect);
    
    return true;
}

bool
ChessEngine::_attemptBishopMove(const Move & inMove, Move * outSideEffect)
{
    _simpleMoveAndKill(inMove, outSideEffect);
    
    return true;
}

bool
ChessEngine::_attemptRookMove(const Move & inMove, Move * outSideEffect)
{
    _simpleMoveAndKill(inMove, outSideEffect);
    
    return true;
}

bool
ChessEngine::_attemptQueenMove(const Move & inMove, Move * outSideEffect)
{
    _simpleMoveAndKill(inMove, outSideEffect);
    
    return true;
}

bool
ChessEngine::_attemptKingMove(const Move & inMove, Move * outSideEffect)
{
    _simpleMoveAndKill(inMove, outSideEffect);
    
    return true;
}

void
ChessEngine::_simpleMoveAndKill(const Move & inMove, Move * outSideEffect)
{
    bool isWhite     = (inMove.piece.pieceType.color == attributes::ChessColor::kWhite);
    auto otherColor  = (isWhite ? attributes::ChessColor::kBlack :
                       attributes::ChessColor::kWhite);
    auto src         = Bitboard::getForSquare(inMove.piece.position.getSquare());
    auto dest        = Bitboard::getForSquare(inMove.dest.getSquare());
    auto & own       = isWhite ? _whitePieces : _blackPieces;
    auto & others    = isWhite ? _blackPieces : _whitePieces;
    
    auto pawnClash   = dest & others.pawnsPos;
    auto knightClash = dest & others.knightsPos;
    auto bishopClash = dest & others.bishopsPos;
    auto rookClash   = dest & others.rooksPos;
    auto queenClash  = dest & others.queensPos;
    auto allClash    = dest & others.getAll();
    
    if (allClash != 0)
    {
        outSideEffect->piece.pieceType.color = otherColor;
        outSideEffect->piece.position = inMove.dest;
        outSideEffect->dest = Position();
        
        if (pawnClash != 0)
        {
            others.pawnsPos &= ~dest;
            outSideEffect->piece.pieceType.piece = attributes::ChessPieceName::kPawn;
        }
        
        if (knightClash != 0)
        {
            others.knightsPos &= ~dest;
            outSideEffect->piece.pieceType.piece = attributes::ChessPieceName::kKnight;
        }
        
        if (bishopClash != 0)
        {
            others.bishopsPos &= ~dest;
            outSideEffect->piece.pieceType.piece = attributes::ChessPieceName::kBishop;
        }
        
        if (rookClash != 0)
        {
            others.rooksPos &= ~dest;
            outSideEffect->piece.pieceType.piece = attributes::ChessPieceName::kRook;
        }
        
        if (queenClash != 0)
        {
            others.queensPos &= ~dest;
            outSideEffect->piece.pieceType.piece = attributes::ChessPieceName::kQueen;
        }
    }
    
    own.pawnsPos   &= ~src;
    own.knightsPos &= ~src;
    own.bishopsPos &= ~src;
    own.rooksPos   &= ~src;
    own.queensPos  &= ~src;
    own.kingPos    &= ~src;
}
