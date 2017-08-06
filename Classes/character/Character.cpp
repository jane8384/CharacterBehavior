//
//  Character.cpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/5.
//
//

#include "Character.hpp"

#include "GameManager.hpp"

Character::Character(){
    this->avatar = CharacterAvatar::createCharacterAvatar();
}

Character::~Character(){
}

Character* Character::createCharacter(){
    Character* newCharacter = new (std::nothrow) Character();
    if (newCharacter){
        return newCharacter;
    }
    
    delete newCharacter;
    newCharacter = nullptr;
    return nullptr;
}

void Character::destory(){
    this->avatar->destory();
    delete this;
}

void Character::setPosition(const BattleTile &battleTile){
    cocos2d::Vec2 position = BattleGridHelper::getPositionByBattleTile(battleTile);
    this->avatar->setPosition(position);
    this->avatar->setLocalZOrder(BattleGridHelper::getGroundZOrderByBattleTile(battleTile));
}

void Character::setPosition(const cocos2d::Vec2 &position){
    this->avatar->setPosition(position);
    this->avatar->setLocalZOrder(BattleGridHelper::getGronudZOrderByPosition(position));
}

void Character::setPosition(float x, float y){
    this->avatar->setPosition(x, y);
    this->avatar->setLocalZOrder(BattleGridHelper::getGronudZOrderByPosition(this->avatar->getPosition()));
}