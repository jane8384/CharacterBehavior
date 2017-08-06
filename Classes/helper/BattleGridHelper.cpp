//
//  BattleGridHelper.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/6.
//
//

#include "BattleGridHelper.hpp"

#include <math.h>

int BattleGridHelper::_groundBaseZOrder = 100;
int BattleGridHelper::_skyBaseZOReder   = 500;

cocos2d::Vec2 BattleGridHelper::dealPositionOffsetInTile(BattleTileFocus focus, const cocos2d::Vec2 &positionLeftBottom){
    cocos2d::Vec2 newPosition = positionLeftBottom;
    float tileWidth = static_cast<float>(MapConfig::tileWidth);
    switch (focus) {
        case BattleTileFocus::LeftTop:{
            newPosition.y += tileWidth;
            break;
        }
        case BattleTileFocus::CentreTop:{
            newPosition.x += tileWidth / 2;
            newPosition.y += tileWidth;
            
            break;
        }
        case BattleTileFocus::RightTop:{
            newPosition.x += tileWidth;
            newPosition.y += tileWidth;
            break;
        }
        case BattleTileFocus::LeftMiddle:{
            newPosition.y += tileWidth / 2;
            break;
        }
        case BattleTileFocus::CentreMiddle:{
            newPosition.x += tileWidth / 2;
            newPosition.y += tileWidth / 2;
            break;
        }
        case BattleTileFocus::RightMiddle:{
            newPosition.x += tileWidth;
            newPosition.y += tileWidth / 2;
            break;
        }
            
        case BattleTileFocus::LeftBottom:{
            break;
        }
        case BattleTileFocus::CentreBottom:{
            newPosition.x += tileWidth / 2;
            break;
        }
        case BattleTileFocus::RightBottom:{
            newPosition.x += tileWidth;
            break;
        }
        default:
            break;
    }
    return newPosition;
}

cocos2d::Vec2 BattleGridHelper::getPositionByBattleTile(const BattleTile &battleTile){
    float x = battleTile.column * MapConfig::tileWidth;
    float y = battleTile.row * MapConfig::tileWidth;
    cocos2d::Vec2 position(x, y);
    return BattleGridHelper::dealPositionOffsetInTile(battleTile.focus, position);
}

BattleTile BattleGridHelper::getBattleTileByPosition(const cocos2d::Vec2 &position){
    int column = static_cast<int>(floorf(position.x / MapConfig::tileWidth));
    int row    = static_cast<int>(floorf(position.y / MapConfig::tileWidth));
    return BattleTile(column, row);
}

int BattleGridHelper::getGronudZOrderByPosition(const cocos2d::Vec2 &position){
    float tileWidth = static_cast<float>(MapConfig::tileWidth);
    int offset = static_cast<int>(floorf(position.y / (tileWidth / 2)));
    return _groundBaseZOrder + offset;
}

int BattleGridHelper::getGroundZOrderByBattleTile(const BattleTile &battleTile){
    int offset = battleTile.row * 2;
    return _groundBaseZOrder + offset;
}

int BattleGridHelper::getSkyZOrderByPosition(const cocos2d::Vec2 &position){
    float tileWidth = static_cast<float>(MapConfig::tileWidth);
    int offset = static_cast<int>(floorf(position.y / (tileWidth / 2)));
    return _skyBaseZOReder + offset;
}

int BattleGridHelper::getSkyZOrderByBattleTile(const BattleTile &battleTile){
    int offset = battleTile.row * 2;
    return _skyBaseZOReder + offset;
}

































