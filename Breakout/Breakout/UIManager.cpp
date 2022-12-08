#include "UIManager.h"

using namespace sf;
using namespace std;
using namespace gm;

UIManager::UIManager() {
}

UIManager::UIManager(int health, int score, int levelNum)
{

    //load font
    f.loadFromFile("arial.ttf");

    //set text
    playerHPText.setFont(f);
    playerScoreText.setFont(f);
    levelNumText.setFont(f);
    loseText.setFont(f);

    playerHPText.setString(to_string(health) + " balls left");
    playerScoreText.setString(to_string(score) + " Points");
    levelNumText.setString("Level " + to_string(levelNum));
    loseText.setString("");

    playerHPText.setCharacterSize(30);
    playerScoreText.setCharacterSize(30);
    levelNumText.setCharacterSize(30);
    loseText.setCharacterSize(64);

    playerHPText.setPosition(Vector2f(20.0f, 10.0f));
    playerScoreText.setPosition(Vector2f(760.0f - playerScoreText.getGlobalBounds().width, 10.0f));
    levelNumText.setPosition(Vector2f(390-playerScoreText.getGlobalBounds().width/2, 10.0f));
    loseText.setPosition(loseTextDefaultPos);

    //set up ui of upper bound of playable area
    ceilingLine.setPosition(0, 50);
    ceilingLine.setSize(Vector2f(780, 1));
    ceilingLine.setFillColor(Color::White);

}

void UIManager::render(sf::RenderWindow& window) {
    window.draw(playerHPText);
    window.draw(playerScoreText);
    window.draw(levelNumText);
    window.draw(loseText);
    window.draw(ceilingLine);
}


void UIManager::updateHP(int hp) {
    playerHPText.setString(to_string(hp) + " balls left");
}

void UIManager::updateScore(int score) {
    playerScoreText.setString(to_string(score) + " Points");
    playerScoreText.setPosition(Vector2f(760.0f - playerScoreText.getGlobalBounds().width, 10.0f));
}

void UIManager::updateLevelText(int levelNum) {
    levelNumText.setString("Level " + to_string(levelNum));
    levelNumText.setPosition(Vector2f(390 - playerScoreText.getGlobalBounds().width / 2, 10.0f));
}

void UIManager::updateLoseText(string str) {
    loseText.setString(str);
    loseText.setPosition(Vector2f(loseText.getPosition().x - loseText.getGlobalBounds().width / 2.0f, loseText.getPosition().y - loseText.getGlobalBounds().height / 2.0f));
}

UIManager::~UIManager() {

}