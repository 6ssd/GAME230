#include "Game.h"

using namespace std;
using namespace sf;
using namespace gm;

//constructor
Game::Game() : c(), deltaTime(0), paddle1(paddle1DefaultPos, Vector2f(15, 80)), paddle2(paddle2DefaultPos, Vector2f(15, 80)), ball(ballDefaultPos, Vector2f(20,20)), gameState(gameState::gameStop), gameMode(gameMode::onePlayer) {
    //score values
    player1Score = 0;
    player2Score = 0;

    //load font
    f.loadFromFile("arial.ttf");

    //set text
    player1Text.setFont(f);
    player2Text.setFont(f);
    winText.setFont(f);

    player1Text.setString(to_string(player1Score));
    player2Text.setString(to_string(player2Score));
    winText.setString("");

    player1Text.setCharacterSize(64);
    player2Text.setCharacterSize(64);
    winText.setCharacterSize(40);

    player1Text.setPosition(Vector2f(90.0f, 35.0f));
    player2Text.setPosition(Vector2f(788.0f, 35.0f));
    winText.setPosition(winTextDefaultPos);

    //load sounds
    paddleHitSfx.loadFromFile("paddle.wav");
    scoreSfx.loadFromFile("score.wav");
    wallHitSfx.loadFromFile("wall.wav");
    winSfx.loadFromFile("win.wav");
    s.setBuffer(paddleHitSfx);
}

//functions

void Game::play(RenderWindow& window) {
    while (window.isOpen()) {
        deltaTime = c.restart().asSeconds();
        handleInput(window);
        update(window);
        render(window);
    }
}

void Game::handleInput(RenderWindow& window) {
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::KeyPressed)
        {
            //press space to begin play
            if (gameState == gameStop)
            {
                if (event.key.code == Keyboard::Space) {
                    gameState = gamePlay;
                    winText.setString("");
                }
                if (event.key.code == Keyboard::Num1)
                {
                    gameMode = onePlayer;
                }
                if (event.key.code == Keyboard::Num2)
                {
                    gameMode = twoPlayer;
                }
            }

            //player 1 controls
            if (event.key.code == Keyboard::W)
            {
                paddle1.setMoveDirection(Up);
            }
            if (event.key.code == Keyboard::S) {
                paddle1.setMoveDirection(Down);
            }

            //player 2 controls
            //only on two player mode
            if(gameMode == twoPlayer)
            {
                if (event.key.code == Keyboard::Up)
                {
                    paddle2.setMoveDirection(Up);
                }
                if (event.key.code == Keyboard::Down) {
                    paddle2.setMoveDirection(Down);
                }
            }
        }

        if (event.type == Event::KeyReleased) {
            //player 1 key release
            if (event.key.code == Keyboard::W && paddle1.getMoveDirection() == moveDir::Up) {
                paddle1.setMoveDirection(moveDir::None);
            }
            if (event.key.code == Keyboard::S && paddle1.getMoveDirection() == moveDir::Down) {
                paddle1.setMoveDirection(moveDir::None);
            }

            //player 2 key release
            //only on two player mode
            if (gameMode == twoPlayer)
            {
                if (event.key.code == Keyboard::Up && paddle2.getMoveDirection() == moveDir::Up) {
                    paddle2.setMoveDirection(moveDir::None);
                }
                if (event.key.code == Keyboard::Down && paddle2.getMoveDirection() == moveDir::Down) {
                    paddle2.setMoveDirection(moveDir::None);
                }
            }
        }

        //Exit program
        if (event.type == Event::Closed)
            window.close();
    }
}

void Game::update(RenderWindow& window){
    {
        if (gameState == gamePlay)
        {
            paddle1.update(window, deltaTime);
            paddle2.update(window, deltaTime);
            ball.update(window, deltaTime);

            //move paddle 2
            //only on one player mode
            if(gameMode == onePlayer)
            {
                if (paddle2.getCollider().top > ball.getCollider().top + ball.getCollider().height / 2)
                {
                    paddle2.setMoveDirection(Up);
                }
                else if (paddle2.getCollider().height + paddle2.getCollider().top < ball.getCollider().top + ball.getCollider().height / 2)
                {
                    paddle2.setMoveDirection(Down);
                }
                else
                {
                    paddle2.setMoveDirection(None);
                }
            }

            //if hits paddle or wall
            if (ball.getCollider().top <= 0 || ball.getCollider().height+ball.getCollider().top >= window.getSize().y)
            {
                s.setBuffer(wallHitSfx);
                s.play();
                ball.bounce(1);
            }
            if ((paddle1.collide(ball.getCollider()) || paddle2.collide(ball.getCollider())) && ball.getCanCollide())
            {
                s.setBuffer(paddleHitSfx);
                s.play();
                ball.bounce(2);
            }

            //while ball is not intersecting with a paddle
            {
                if ((paddle1.collide(ball.getCollider()) || paddle2.collide(ball.getCollider())) == false && ball.getCanCollide() == false) 
                {
                    ball.switchCanCollide();
                }
            }

            //if out of bounds
            if (ball.getCollider().left <= 0 || ball.getCollider().left + ball.getCollider().width >= window.getSize().x)
            {
                //pause game
                gameState = gameStop;
                
                //add score
                s.setBuffer(scoreSfx);
                s.play();
                if (ball.getCollider().left <= 0) {
                    player2Score++;
                    player2Text.setString(to_string(player2Score));
                }
                else {
                    player1Score++;
                    player1Text.setString(to_string(player1Score));
                }
                cout << "player 1 score: " << player1Score << " \n" << "player 2 score: " << player2Score << endl;
                //reset positions
                reset();
            }
        }
    }
}

void Game::render(RenderWindow& window) {
    window.clear();

    window.draw(player1Text);
    window.draw(player2Text);
    window.draw(winText);
    paddle1.render(window, deltaTime);
    paddle2.render(window, deltaTime);
    ball.render(window, deltaTime);

    window.display();
        
}

void Game::reset()
{
    paddle1.setPosition(paddle1DefaultPos);
    paddle2.setPosition(paddle2DefaultPos);
    paddle1.setMoveDirection(None);

    ball.setPosition(ballDefaultPos);
    ball.resetVel();

    if (player1Score == 5 || player2Score == 5) 
    {
        s.setBuffer(winSfx);
        s.play();
        if (player1Score == 5) 
        {
            cout << "player 1 wins!" << endl;
            winText.setString("Player 1 Wins!");
            winText.setPosition(Vector2f(455 - winText.getGlobalBounds().width/2.0f, 67.0f - winText.getGlobalBounds().height / 2.0f));
        }
        else 
        {
            cout << "player 2 wins!" << endl;
            winText.setString("Player 2 Wins!");
            winText.setPosition(Vector2f(455 - winText.getGlobalBounds().width / 2.0f, 67.0f - winText.getGlobalBounds().height / 2.0f));
        }
        player1Score = 0;
        player2Score = 0;

        player1Text.setString(to_string(player1Score));
        player2Text.setString(to_string(player2Score));
    }
}

Game::~Game() {

}