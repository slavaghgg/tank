#pragma once 
#include <SFML/Graphics.hpp> 

const float WINDOW_WIDTH = 1200;
const float WINDOW_HEIGHT = 900;
const std::string WINDOW_TITLE = "SFML Asteroids P53122";
const size_t FPS = 60;

const double PI = 3.141592653589793;
const std::string PLAYER_FILE_NAME = "tank.png";
const int CHAR_SIZE = 48;
const std::string FONT_FILE_NAME = "ds-digib.ttf";
sf::Vector2f HP_TEXT_POS(0.f, 0.f);
const int MAX_PLAYER_LIVES = 3;
const int MAX_PLAYER_HP = 100;

const float TOP_BORDER = -300.f;
const float BOTTOM_BORDER = 1200.f;
const float LEFT_BORDER = -300.f;
const float RIGHT_BORDER = 1500.f;

const float LASER_SPEED = 15.f;
const std::string LASER_FILE_NAME = "laserRed03.png";
const int FIRE_COOLDOWN = 200;
const std::string SAND_FILE_NAME = "sand.jpg";
const sf::Vector2f SAND_START_POS{ 0.f,0.f };

const float FRAME_WIDTH = 150.f;
const float FRAME_HEIGHT = 30.f;
const std::string LIFE_ICON_FILE_NAME = "heart.png";
const sf::Vector2f TEXT_START_POS{ WINDOW_WIDTH / 2 - 180.f, WINDOW_HEIGHT / 2 - 80.f };
const std::string LET_FILE_NAME = "pngeg.png";
const sf::Vector2f LET_POS{ 200.f, 300.f };
const sf::Vector2f LET1_POS { 500.f,300.f };
const sf::Vector2f LET2_POS { 400.f,700.f };
const sf::Vector2f LET3_POS { 1000.f,500.f };
const sf::Vector2f LET4_POS { 800.f,400.f };
const sf::Vector2f LET5_POS{ 1000.f,600.f };
const sf::Vector2f LET6_POS{ 300.f,600.f };
const sf::Vector2f LET7_POS{ 200.f,800.f };
const sf::Vector2f LET8_POS{ 1000.f,800.f };
const sf::Vector2f LET9_POS{ 300.f,300.f };
const sf::Vector2f LET10_POS{ 200.f,100.f };