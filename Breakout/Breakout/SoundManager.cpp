#include "SoundManager.h"

using namespace std;
using namespace sf;
using namespace gm;

SoundManager::SoundManager() {
    //load sounds
    paddleHitSfx.loadFromFile("paddle.wav");
    arr[0] = paddleHitSfx;

    wallHitSfx.loadFromFile("wall.wav");
    arr[1] = wallHitSfx;

    winSfx.loadFromFile("win.wav");
    arr[2] = winSfx;

    lifeLoseSfx.loadFromFile("ballLost.wav");
    arr[3] = lifeLoseSfx;

    breakSfx.loadFromFile("break.wav");
    arr[4] = breakSfx;

    shatterSfx.loadFromFile("shatter.wav");
    arr[5] = shatterSfx;

    loseSfx.loadFromFile("lose.wav");
    arr[6] = loseSfx;

    s.setBuffer(arr[0]);
}

//0 = paddleHitSfx, 1 = wallHitSfx, 2 = winSfx, 3 = lifeLoseSfx, 4 = breakSfx, 5 = shatterSfx, 6 = loseSfx
void SoundManager::playSfx(int index){
    s.setBuffer(arr[index]);
    s.play();
}

SoundManager::~SoundManager() {
}