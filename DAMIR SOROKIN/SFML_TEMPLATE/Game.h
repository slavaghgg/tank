#pragma once
#include "gameObj.h" 
#include <vector> 
#include <list> 
#include "Player.h" 
#include "Player1.h" 
#include "sandObj.h" 
#include "HpBar.h"
#include "HP_BAR.h"
#include "Lives.h"
#include "textObj.h"
#include "let.h"


enum GameStatus { PLAY, GAME_OVER,GAME_OVER1 };
class Game {
private:
	sf::RenderWindow window;
	Player player;
	Player1 player1;
	SandObj sand;
	Hp_Bar hpbar;
	HpBar hpbar1;
	std::list<Lives*>lives;
	std::list<Lives*>lives1;
	TextObj bluegameovertext;
	TextObj redgameovertext;
	GameStatus game = PLAY;
	Let let;
	Let let1;
	Let let2;
	Let let3;
	Let let4;
	Let let5;
	Let let6;
	Let let7;
	Let let8;
	Let let9;
	Let let10;
	

public:

	Game() :bluegameovertext("GAME_OVER: Blue win ", TEXT_START_POS,sf::Color::Blue ), redgameovertext("GAME_OVER: Red win", TEXT_START_POS, sf::Color::Red),let(LET_POS),let1(LET1_POS),let2(LET2_POS),let3(LET3_POS),let4(LET4_POS),
		let5(LET5_POS),let6(LET6_POS), let7(LET7_POS), let8(LET8_POS), let9(LET9_POS), let10(LET10_POS) {
		window.create(sf::VideoMode{ (size_t)WINDOW_WIDTH, (size_t)WINDOW_HEIGHT }, WINDOW_TITLE);
		window.setFramerateLimit(FPS);
		for (size_t i = 0; i < MAX_PLAYER_LIVES; i++) {
			float xPos = 5.f;
			float yPos = 50.f;
			Lives* life = new Lives(sf::Vector2f{ xPos + i * 48.f, yPos });
			lives.push_back(life);
		}
		for (size_t i = 0; i < MAX_PLAYER_LIVES; i++) {
			float xPos = 1000.f;
			float yPos = 50.f;
			Lives* life1 = new Lives(sf::Vector2f{ xPos + i * 48.f, yPos });
			lives1.push_back(life1);
		}

	}

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}

	void update() {
		switch (game) {
		case PLAY: {
			player.update();
			player1.update();
			hpbar.update(player.getHp());
			hpbar1.update(player1.getHp());
		}
		}

	}

	void checkCollisions() {
		switch (game) {
		case PLAY: {
			auto laser1Sprites = player1.getLasers();
			for (auto laser1 : (*laser1Sprites)) {
				sf::FloatRect playerBounds = player.getHitBox();
				sf::FloatRect laser1Bounds = laser1->getHitBox();
				if (playerBounds.intersects(laser1Bounds)) {
					player.decreaseHp(laser1->getDamage());
					laser1->hit();
					if (player.getHp() < 0) {
						player.playerMinusLife();
						if (player.getlives() == 0) {
							game = GAME_OVER1;
							bluegameovertext.draw(window);
						}
						player.restoreHp();
						lives1.pop_back();
					}

				}
			}
			(*laser1Sprites).remove_if([](Laser* laser1) { return laser1->getHit(); });
			(*laser1Sprites).remove_if([](Laser* laser1) { return laser1->offScreen(); });



			sf::FloatRect player1Bounds = player1.getHitBox();
			auto laserSprites = player.getLasers();
			for (auto laser : (*laserSprites)) {
				sf::FloatRect laserBounds = laser->getHitBox();
				if (laserBounds.intersects(player1Bounds)) {
					player1.decreaseHp(laser->getDamage());
					laser->hit();
					if (player1.getHp() < 0) {
						player1.playerMinusLife();
						if (player1.getlives() == 0) {
							game = GAME_OVER;
							redgameovertext.draw(window);

						}
						player1.restoreHp();
						lives.pop_back();
					}
				}
			}

			(*laserSprites).remove_if([](Laser* laser) { return laser->getHit(); });
			(*laserSprites).remove_if([](Laser* laser) { return laser->offScreen(); });
		}
				 auto laser1Sprites = player1.getLasers();
				 for (auto laser1 : (*laser1Sprites)) {
					 sf::FloatRect letBounds = let.getHitBox();
					 sf::FloatRect laser1Bounds = laser1->getHitBox();
					 if (letBounds.intersects(laser1Bounds)) {
						 let.setRandomPosition();
						 laser1->hit();
					 }

				 }
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->getHit(); });
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->offScreen(); });
				 auto laserSprites = player.getLasers();
				 for (auto laser : (*laserSprites)) {
					 sf::FloatRect letBounds = let.getHitBox();
					 sf::FloatRect laserBounds = laser->getHitBox();
					 if (letBounds.intersects(laserBounds)) {
						 let.setRandomPosition();
						 laser->hit();
					 }

				 }
				 (*laserSprites).remove_if([](Laser* laser) { return laser->getHit(); });
				 (*laserSprites).remove_if([](Laser* laser) { return laser->offScreen(); });
				 /*
				 auto laser1Sprites = player1.getLasers();
				 for (auto laser1 : (*laser1Sprites)) {
					 sf::FloatRect let1Bounds = let1.getHitBox();
					 sf::FloatRect laser1Bounds = laser1->getHitBox();
					 if (let1Bounds.intersects(laser1Bounds)) {
						 let1.setRandomPosition();
						 laser1->hit();
					 }

				 }
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->getHit(); });
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->offScreen(); });
				 auto laserSprites = player.getLasers();
				 for (auto laser : (*laserSprites)) {
					 sf::FloatRect let1Bounds = let1.getHitBox();
					 sf::FloatRect laserBounds = laser->getHitBox();
					 if (let1Bounds.intersects(laserBounds)) {
						 let1.setRandomPosition();
						 laser->hit();
					 }

				 }
				 (*laserSprites).remove_if([](Laser* laser) { return laser->getHit(); });
				 (*laserSprites).remove_if([](Laser* laser) { return laser->offScreen(); });
				 
				 auto laser1Sprites = player1.getLasers();
				 for (auto laser1 : (*laser1Sprites)) {
					 sf::FloatRect let2Bounds = let2.getHitBox();
					 sf::FloatRect laser1Bounds = laser1->getHitBox();
					 if (let2Bounds.intersects(laser1Bounds)) {
						 let2.setRandomPosition();
						 laser1->hit();
					 }

				 }
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->getHit(); });
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->offScreen(); });
				 auto laserSprites = player.getLasers();
				 for (auto laser : (*laserSprites)) {
					 sf::FloatRect let2Bounds = let2.getHitBox();
					 sf::FloatRect laserBounds = laser->getHitBox();
					 if (let2Bounds.intersects(laserBounds)) {
						 let2.setRandomPosition();
						 laser->hit();
					 }

				 }
				 (*laserSprites).remove_if([](Laser* laser) { return laser->getHit(); });
				 (*laserSprites).remove_if([](Laser* laser) { return laser->offScreen(); });
				 auto laser1Sprites = player1.getLasers();
				 for (auto laser1 : (*laser1Sprites)) {
					 sf::FloatRect let3Bounds = let3.getHitBox();
					 sf::FloatRect laser1Bounds = laser1->getHitBox();
					 if (let3Bounds.intersects(laser1Bounds)) {
						 let3.setRandomPosition();
						 laser1->hit();
					 }

				 }
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->getHit(); });
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->offScreen(); });
				 auto laserSprites = player.getLasers();
				 for (auto laser : (*laserSprites)) {
					 sf::FloatRect let3Bounds = let3.getHitBox();
					 sf::FloatRect laserBounds = laser->getHitBox();
					 if (let3Bounds.intersects(laserBounds)) {
						 let3.setRandomPosition();
						 laser->hit();
					 }

				 }
				 (*laserSprites).remove_if([](Laser* laser) { return laser->getHit(); });
				 (*laserSprites).remove_if([](Laser* laser) { return laser->offScreen(); });
				 auto laser1Sprites = player1.getLasers();
				 for (auto laser1 : (*laser1Sprites)) {
					 sf::FloatRect let4Bounds = let4.getHitBox();
					 sf::FloatRect laser1Bounds = laser1->getHitBox();
					 if (let4Bounds.intersects(laser1Bounds)) {
						 let4.setRandomPosition();
						 laser1->hit();
					 }

				 }
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->getHit(); });
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->offScreen(); });
				 auto laserSprites = player.getLasers();
				 for (auto laser : (*laserSprites)) {
					 sf::FloatRect let4Bounds = let4.getHitBox();
					 sf::FloatRect laserBounds = laser->getHitBox();
					 if (let4Bounds.intersects(laserBounds)) {
						 let4.setRandomPosition();
						 laser->hit();
					 }

				 }
				 (*laserSprites).remove_if([](Laser* laser) { return laser->getHit(); });
				 (*laserSprites).remove_if([](Laser* laser) { return laser->offScreen(); });
				 auto laser1Sprites = player1.getLasers();
				 for (auto laser1 : (*laser1Sprites)) {
					 sf::FloatRect let5Bounds = let5.getHitBox();
					 sf::FloatRect laser1Bounds = laser1->getHitBox();
					 if (let5Bounds.intersects(laser1Bounds)) {
						 let5.setRandomPosition();
						 laser1->hit();
					 }

				 }
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->getHit(); });
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->offScreen(); });
				 auto laserSprites = player.getLasers();
				 for (auto laser : (*laserSprites)) {
					 sf::FloatRect let5Bounds = let5.getHitBox();
					 sf::FloatRect laserBounds = laser->getHitBox();
					 if (let5Bounds.intersects(laserBounds)) {
						 let5.setRandomPosition();
						 laser->hit();
					 }

				 }
				 (*laserSprites).remove_if([](Laser* laser) { return laser->getHit(); });
				 (*laserSprites).remove_if([](Laser* laser) { return laser->offScreen(); });
				 auto laser1Sprites = player1.getLasers();
				 for (auto laser1 : (*laser1Sprites)) {
					 sf::FloatRect let6Bounds = let6.getHitBox();
					 sf::FloatRect laser1Bounds = laser1->getHitBox();
					 if (let6Bounds.intersects(laser1Bounds)) {
						 let6.setRandomPosition();
						 laser1->hit();
					 }

				 }
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->getHit(); });
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->offScreen(); });
				 auto laserSprites = player.getLasers();
				 for (auto laser : (*laserSprites)) {
					 sf::FloatRect let6Bounds = let.getHitBox();
					 sf::FloatRect laserBounds = laser->getHitBox();
					 if (let6Bounds.intersects(laserBounds)) {
						 let6.setRandomPosition();
						 laser->hit();
					 }

				 }
				 (*laserSprites).remove_if([](Laser* laser) { return laser->getHit(); });
				 (*laserSprites).remove_if([](Laser* laser) { return laser->offScreen(); });
				 auto laser1Sprites = player1.getLasers();
				 for (auto laser1 : (*laser1Sprites)) {
					 sf::FloatRect let7Bounds = let7.getHitBox();
					 sf::FloatRect laser1Bounds = laser1->getHitBox();
					 if (let7Bounds.intersects(laser1Bounds)) {
						 let7.setRandomPosition();
						 laser1->hit();
					 }

				 }
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->getHit(); });
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->offScreen(); });
				 auto laserSprites = player.getLasers();
				 for (auto laser : (*laserSprites)) {
					 sf::FloatRect let7Bounds = let7.getHitBox();
					 sf::FloatRect laserBounds = laser->getHitBox();
					 if (let7Bounds.intersects(laserBounds)) {
						 let7.setRandomPosition();
						 laser->hit();
					 }

				 }
				 (*laserSprites).remove_if([](Laser* laser) { return laser->getHit(); });
				 (*laserSprites).remove_if([](Laser* laser) { return laser->offScreen(); });
				 auto laser1Sprites = player1.getLasers();
				 for (auto laser1 : (*laser1Sprites)) {
					 sf::FloatRect let8Bounds = let8.getHitBox();
					 sf::FloatRect laser1Bounds = laser1->getHitBox();
					 if (let8Bounds.intersects(laser1Bounds)) {
						 let8.setRandomPosition();
						 laser1->hit();
					 }

				 }
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->getHit(); });
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->offScreen(); });
				 auto laserSprites = player.getLasers();
				 for (auto laser : (*laserSprites)) {
					 sf::FloatRect let8Bounds = let8.getHitBox();
					 sf::FloatRect laserBounds = laser->getHitBox();
					 if (let8Bounds.intersects(laserBounds)) {
						 let8.setRandomPosition();
						 laser->hit();
					 }

				 }
				 (*laserSprites).remove_if([](Laser* laser) { return laser->getHit(); });
				 (*laserSprites).remove_if([](Laser* laser) { return laser->offScreen(); });
				 auto laser1Sprites = player1.getLasers();
				 for (auto laser1 : (*laser1Sprites)) {
					 sf::FloatRect let9Bounds = let9.getHitBox();
					 sf::FloatRect laser1Bounds = laser1->getHitBox();
					 if (let9Bounds.intersects(laser1Bounds)) {
						 let9.setRandomPosition();
						 laser1->hit();
					 }

				 }
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->getHit(); });
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->offScreen(); });
				 auto laserSprites = player.getLasers();
				 for (auto laser : (*laserSprites)) {
					 sf::FloatRect let9Bounds = let9.getHitBox();
					 sf::FloatRect laserBounds = laser->getHitBox();
					 if (let9Bounds.intersects(laserBounds)) {
						 let9.setRandomPosition();
						 laser->hit();
					 }

				 }
				 (*laserSprites).remove_if([](Laser* laser) { return laser->getHit(); });
				 (*laserSprites).remove_if([](Laser* laser) { return laser->offScreen(); });
				 auto laser1Sprites = player1.getLasers();
				 for (auto laser1 : (*laser1Sprites)) {
					 sf::FloatRect let10Bounds = let10.getHitBox();
					 sf::FloatRect laser1Bounds = laser1->getHitBox();
					 if (let10Bounds.intersects(laser1Bounds)) {
						 let10.setRandomPosition();
						 laser1->hit();
					 }

				 }
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->getHit(); });
				 (*laser1Sprites).remove_if([](Laser* laser1) { return laser1->offScreen(); });
				 auto laserSprites = player.getLasers();
				 for (auto laser : (*laserSprites)) {
					 sf::FloatRect let10Bounds = let10.getHitBox();
					 sf::FloatRect laserBounds = laser->getHitBox();
					 if (let10Bounds.intersects(laserBounds)) {
						 let10.setRandomPosition();
						 laser->hit();
					 }

				 }
				 (*laserSprites).remove_if([](Laser* laser) { return laser->getHit(); });
				 (*laserSprites).remove_if([](Laser* laser) { return laser->offScreen(); });*/
		}
	}

	void draw() {
		switch (game) {
		case PLAY: {
			window.clear();


			
			sand.draw(window);
			let.draw(window);
			let1.draw(window);
			let2.draw(window);
			let3.draw(window);
			let4.draw(window);
			let5.draw(window);
			let6.draw(window);
			let7.draw(window);
			let8.draw(window);
			let9.draw(window);
			let10.draw(window);
			player.draw(window);
			player1.draw(window);
			hpbar.draw(window);
			hpbar1.draw(window);
			for (auto& life : lives) {
				life->draw(window);
			}
			for (auto& life1 : lives1) {
				life1->draw(window);
			}


			window.display();
			break;
		case GAME_OVER1:
			window.clear();
			redgameovertext.draw(window);
			
			window.display();
			break;
		case GAME_OVER:
			window.clear();
			bluegameovertext.draw(window);

			window.display();
			break;
		}
		}
	}



	void play() {
		while (window.isOpen()) {
			checkEvents();
			update();
			checkCollisions();
			draw();
		}
	}

};
