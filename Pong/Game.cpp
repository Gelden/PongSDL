#include "Game.h"

bool Game::Initialize()
{
    mBackground = Texture::Load("Backgrounds\\g845.png", System::GetRenderer()); 
    mPlayer = new Player(Vector2(20, System::GetScreenHeight() / 2), Texture::Load("Sprites\\PlayerSprite.jpg", System::GetRenderer()));   
    mBall = new Ball(Vector2(0, 0), Texture::Load("Sprites\\BallSprite.jpg", System::GetRenderer())); 
    mAI = new AI(Vector2(System::GetScreenWidth() - 20, System::GetScreenWidth() / 2), Texture::Load("Sprites\\PlayerSprite.jpg", System::GetRenderer()));
    if (!mBackground || !&mPlayer || !mBall || !mAI)
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
    HandleCollision();
    Draw(); //Draw the background;
    mPlayer->Draw(System::GetRenderer()); //Draw The Player;  
    mAI->Draw(System::GetRenderer());
    mBall->Draw(System::GetRenderer()); 
}
//Handle Collision for all Game Objects
void Game::HandleCollision()
{ 
    //BALL WORLD BOUNDS COLLISION  
    if (mBall->Top() < WorldTop())
    {
        mBall->SetTop(0.0f);
        mBall->SetYSpeed(-(mBall->GetYSpeed()));
    }
    if (mBall->Bottom()>WorldBottom())
    {
        mBall->SetBottom(WorldBottom());
        mBall->SetYSpeed(-(mBall->GetYSpeed()));
    } 
   
    //PLAYER WORLD BOUNDS COLLISION  
    if (mPlayer->Top() < WorldTop())
    {
        mPlayer->SetTop(WorldTop());
    } 
    if (mPlayer->Bottom() > WorldBottom())
    {
        mPlayer->SetBottom(WorldBottom());
    } 

    //AI WORLD BOUNDS COLLISION  
    if (mAI->Top() < WorldTop())
    {
        mAI->SetTop(WorldTop());
    } 
    if (mAI->Top() > WorldBottom())
    {
        mAI->SetBottom(WorldBottom());
    } 
    //BALL PLAYER COLLISION  
    
    


    //BALL AI COLLISION
}
