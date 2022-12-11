#include "unit.h"
#include "game.h"

using namespace std;
using namespace sf;

Unit::Unit() {
    dead = 0;
    hp = 100;
    position.x = 0;
    position.y = 0;
    speed = 0.2;
    weapon = nullptr;
    texture = new Texture;
    texture->loadFromFile("Textures/Units/Player.png");
    sprite.setTexture(*texture);
}

void Unit::draw(RenderWindow &window) {
    if (dead == 0) {
        sprite.setPosition(position.x, position.y);
        window.draw(sprite);
    }
}

void Unit::move_x(double x) {
    position.x = position.x + x;
}

void Unit::move_y(double y) {
    position.y = position.y + y;
}

void Unit::set_position(double x, double y) {
    position.x = x;
    position.y = y;
}

void Unit::get_damage(double damage) {
    if (hp - damage <= 0) {
        dead = 1;
    } else {
        hp -= damage;
    }
}

void Unit::drop_weapon() {
    if (weapon) {
        weapon->check = 0;
        weapon = nullptr;
    }
}

void Unit::set_weapon(shared_ptr<Item>(&new_weapon)) {
    weapon = new_weapon;
}

