//
//  CharacterStateIdle.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/10.
//
//

#ifndef CharacterStateIdle_hpp
#define CharacterStateIdle_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Singleton.hpp"
#include "EntityState.hpp"
#include "Character.hpp"

class CharacterStateIdle: public EntityState<Character>, public Singleton<CharacterStateIdle>{
private:
    float _timeCounter = 0.0;
    float _turnInterval = 0.0;
public:
    virtual void enter(Character* charater);
    virtual void execute(Character* charater, float dt);
    virtual void exit(Character* charater);
};

#endif /* CharacterStateIdle_hpp */
