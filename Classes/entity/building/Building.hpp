//
//  Building.hpp
//  CharacterBehavior
//
//  Created by weilove-jiajiaju on 2017/8/15.
//
//

#ifndef Building_hpp
#define Building_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "setting.hpp"
#include "import.hpp"

#include "BaseEntity.hpp"

#include "StateMachine.hpp"

#include "BuildingConfig.hpp"

#ifdef FSM

class Building: public BaseEntity{
private:
    Building(int id, const BuildingConfig& config);
    ~Building();
public:
    
    BuildingConfig buildingConfig;
    
    StateMachine<Building> *stateMachine;
    
    static Building* createBuilding(int id, const BuildingConfig& config);
    static Building* createBuilding(int id, const std::string& buildingTypeName);
    
    virtual void destory();
    virtual void update(float dt);
    
    
    void setPosition(const cocos2d::Vec2& position);
    void setPosition(float x, float y);
//    void setPosition(const BattleTile& battleTile);
    cocos2d::Vec2 getPosition(){ return avatar->getPosition(); }
    
    
};

#endif

#endif /* Building_hpp */
