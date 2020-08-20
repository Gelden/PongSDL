#include "Game.h"

bool Game::Initialize()
{
    mBackground = Texture::Load("Backgrounds\\g845.png", System::GetRenderer()); 
    mPlayer = new Player(Vector2(20, System::GetScreenHeight() / 2), Texture::Load("Sprites\\PlayerSprite.jpg", System::GetRenderer()));  
    mBall = new Ball(Vector2(0, 0), Texture::Load("Sprites\\BallSprite.jpg", System::GetRenderer()));
    if (!mBackground || !&mPlayer)
        return false; 
    mBall->Reset();
    SDL_RenderClear(System::GetRenderer()); 
    Draw();
    return true;
}

void Game::Draw()
{ 
    SDL_Rect bkgndRect;
    bkgndRect.w = mBackground->GetWidth();
    bkgndRect.h = mBackground->GetHeight();
    bkgndRect.x = 0;
    bkgndRect.y = 0;
    SDL_RenderCopy(System::GetRenderer(), mBackground->GetTexture(), NULL, &bkgndRect);
}

void Game::Update(float dt)
{ 
    SDL_RenderClear(System::GetRenderer());
    mPlayer->Update();  
    mBall->Update(System::GetDeltaTime());
    Draw(); //Draw the background;
    mPlayer->Draw(System::GetRenderer());  //Draw The Player; 
    mBall->Draw(System::GetRenderer());
}
