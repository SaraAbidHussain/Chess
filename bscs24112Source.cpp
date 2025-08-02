#include "raylib.h"
#include "bscs24112Board.h"
#include "bscs24112Piece.h"

int main()
{
    Board b;
    b.playGUI();

    return 0;
}
//int main1(){
//    InitWindow(700, 700, "Chess");
//    Texture2D board = LoadTexture("Chess_Board.png");
//    static Texture2D textures[12];
//    textures[0] = LoadTexture("pawn-W.png");
//    textures[1] = LoadTexture("rook-W.png");
//    textures[2] = LoadTexture("knight-W.png");
//    textures[3] = LoadTexture("bishop-W.png");
//    textures[4] = LoadTexture("queen-W.png");
//    textures[5] = LoadTexture("king-W.png");
//    textures[6] = LoadTexture("pawn-B.png");
//    textures[7] = LoadTexture("rook-B.png");
//    textures[8] = LoadTexture("knight-B.png");
//    textures[9] = LoadTexture("bishop-B.png");
//    textures[10] = LoadTexture("queen-B.png");
//    textures[11] = LoadTexture("king-B.png");
//
//    Board B;
//
//    while (!WindowShouldClose()) {
//        BeginDrawing();
//        ClearBackground(RAYWHITE);
//        DrawTexture(board, 0, 0, WHITE);
//        EndDrawing();
//    }
//
//    UnloadTexture(board);
//    CloseWindow();
//    return 0;
//}



//int main0() {
//    const int screenWidth = 800;
//    const int screenHeight = 800;
//
//    InitWindow(screenWidth, screenHeight, "Raylib Chess");
//    SetTargetFPS(60);
//    Board B;
//
//
// //Piece::LoadTextures();
//
//
//    while (!WindowShouldClose()) {
//        BeginDrawing();
//        ClearBackground(RAYWHITE);
//
//        B.displayBoard();
//
//        EndDrawing();
//    }
//
//   /* Piece::UnloadTextures();*/
//    CloseWindow();
//    return 0;
//}
