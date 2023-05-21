#pragma once 
#include "settings.h" 
#include "gameObj.h" 
#include "Laser.h" 

class Player1 :public gameObj {
private:

	int angle;
	float speed, speedx, speedy;
	float dv = 0.5f;
	float maxSpeed = 5.f;
	sf::Clock timer;
	int prevFireTime;
	std::list<Laser*> lasers;
	sf::FloatRect bounds = sprite.getLocalBounds();
	int hp = 100;
	int damage = 10;
	int lives = MAX_PLAYER_LIVES;

public:
	Player1() : prevFireTime{ timer.getElapsedTime().asMilliseconds() } {
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		angle = 0;
		speed = 0.f;
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(WINDOW_WIDTH / 7, WINDOW_HEIGHT/2);

	}
	void update() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			angle -= 3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			angle += 3;
		}
		sprite.setRotation((float)angle);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			speed += dv;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			speed -= dv / 2;
		}
		if (speed < 0) speed = 0.f;
		else if (speed > maxSpeed) speed = maxSpeed;
		speedx = speed * (float)sin(angle * PI / 180);
		speedy = -speed * (float)cos(angle * PI / 180);
		sprite.move(speedx, speedy);
		fire();
		for (auto laser : lasers) {
			laser->update();
		}
		if (sprite.getPosition().x <= 30)
		{
			speed = -speed;
		}
		if (sprite.getPosition().x >= (WINDOW_WIDTH - 30))
		{
			speed = -speed;

		}
		if (sprite.getPosition().y <= 30 || sprite.getPosition().y >=
			(WINDOW_HEIGHT - 30))
		{
			speed = -speed;
		}
	}

	void fire() {
		int currTime = timer.getElapsedTime().asMilliseconds();
		if (currTime - prevFireTime > FIRE_COOLDOWN) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				auto laser = new Laser(sprite.getPosition(), angle);
				lasers.push_back(laser);
				prevFireTime = currTime;
			}
		}
	}

	void draw(sf::RenderWindow& window) {
		for (auto laser : lasers) {
			laser->draw(window);
		}
		window.draw(sprite);
	}
	int getHp() { return hp; }

	std::list<Laser*>* getLasers() { return &lasers; }
	void decreaseHp(int damage) { hp -= damage; }
	void playerAddLife() { lives++; }

	void playerMinusLife() { lives--; }
	void restoreHp() { hp = MAX_PLAYER_HP; }
	int getlives() { return lives; }
	int getDamage() { return damage; }
};