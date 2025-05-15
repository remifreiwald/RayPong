/*
* Copyright (c) 2025, Remi Freiwald
* All rights reserved.
*
* This source code is licensed under the BSD-style license found in the
* LICENSE file in the root directory of this source tree.
*/

#include "raylib.h"

int windowWidth = 1280;
int windowHeight = 720;

class Paddle {
public:
	Vector2 pos; // center of the paddle
	float width;
	float height;
	float speed; // per second
	Color color;
	int keyUp;
	int keyDown;

	void Update(float deltaTime) {
		if (IsKeyDown(keyUp)) {
			pos.y -= speed * deltaTime;
		}
		if (IsKeyDown(keyDown)) {
			pos.y += speed * deltaTime;
		}
	}

	void CheckCollisionWithWall() {
		if (pos.y <= (height / 2.f)) {
			// collision with top wall
			pos.y = height / 2.f;
		}
		if (pos.y >= (windowHeight - height / 2.f)) {
			pos.y = windowHeight - height / 2.f;
		}
	}

	void Draw() {
		DrawRectangle(pos.x - width / 2.f, pos.y - height / 2.f, width, height, color);
	}
};

class Ball {
public:
	Vector2 pos; // center of the ball
	float radius;
	float speedX; // per second
	float speedY; // per second
	Color color;

	void Update(float deltaTime) {
		pos.x += speedX * deltaTime;
		pos.y += speedY * deltaTime;
	}

	void Draw() {
		DrawCircle(pos.x, pos.y, radius, color);
	}
};

int main() {
	InitWindow(windowWidth, windowHeight, "RayPong");
	SetTargetFPS(60);

	Paddle playerLeft = Paddle();
	playerLeft.pos = Vector2{ (float)50, windowHeight / 2.f };
	playerLeft.width = 25;
	playerLeft.height = 120;
	playerLeft.speed = 500;
	playerLeft.color = WHITE;
	playerLeft.keyUp = KEY_W;
	playerLeft.keyDown = KEY_S;

	Paddle playerRight = Paddle();
	playerRight.pos = Vector2{ (float)windowWidth - 50, windowHeight / 2.f };
	playerRight.width = 25;
	playerRight.height = 120;
	playerRight.speed = 500;
	playerRight.color = WHITE;
	playerRight.keyUp = KEY_UP;
	playerRight.keyDown = KEY_DOWN;

	Ball ball = Ball();
	ball.pos = Vector2{ (float)windowWidth /2.f, windowHeight / 2.f };
	ball.radius = 10;
	ball.speedX = 250;
	ball.speedY = 250;
	ball.color = WHITE;

	while (!WindowShouldClose()) {
		BeginDrawing();

		float deltaTime = GetFrameTime();

		playerLeft.Update(deltaTime);
		playerRight.Update(deltaTime);
		ball.Update(deltaTime);

		playerLeft.CheckCollisionWithWall();
		playerRight.CheckCollisionWithWall();

		ClearBackground(BLACK);
		DrawLine(windowWidth / 2.f, 0, windowWidth / 2.f, windowHeight, WHITE);

		playerLeft.Draw();
		playerRight.Draw();
		ball.Draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
