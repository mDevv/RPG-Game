//
//  Game.hpp
//  RPG-Game
//
//  Created by Michał Dziewulski on 10.05.2017.
//  Copyright © 2017 Michał Dziewulski. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <fstream>
#include "json.hpp"
#include "ResourcePath.hpp"
#include "Entity.hpp"
#include "ArcherEntity.hpp"
#include "WarriorEntity.hpp"
#include "KnightEntity.hpp"
#include "MageEntity.hpp"
#include "CavalierEntity.hpp"

namespace global
{
    extern const float W_HEIGHT; // 800 map + 200 bar
    extern const float W_WIDTH;
    extern unsigned size;
    extern const bool GREEN;
    extern const bool ORANGE;
    extern unsigned greenAmount;
    extern unsigned orangeAmount;
    extern int errorFlag;
}

class Game
{
public:
    Game();
    ~Game();
    void run();
    void save();
    void load(std::string fileName);
private:
    void render(sf::RenderWindow &window);
    void renderWinner(sf::RenderWindow &window, bool winner);
    void renderErrorLoad(sf::RenderWindow &window);
    void renderErrorSave(sf::RenderWindow &window);
    
    void drawBackground(sf::RenderWindow &window);
    void drawFields(sf::RenderWindow &window);
    void drawMenu(sf::RenderWindow &window);
    void drawMap(sf::RenderWindow &window);
    
    sf::Texture backgroundTile;
    sf::RectangleShape bar;
    sf::Texture nextTurnButton;
    sf::Texture saveButton;
    sf::RectangleShape lineY;
    sf::RectangleShape lineX;
    sf::RectangleShape playerTurn;
    sf::Texture army;
    
    bool m_turn;
    bool m_hasAttacked;
    bool m_hasMoved;
    Entity*** map;
    
    Entity* selected;
    int selectedPosX;
    int selectedPosY;
};

#endif /* Game_hpp */
