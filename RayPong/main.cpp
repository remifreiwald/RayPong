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
	Vector2 pos;
	float width;
	float height;
	float speed;
	Color color;

	void Update(float deltaTime) {
		if (IsKeyDown(KEY_UP)) {
			pos.y -= speed * deltaTime;
		}
		if (IsKeyDown(KEY_DOWN)) {
			pos.y += speed * deltaTime;
		}
	}

	void Draw() {
		DrawRectangle(pos.x - width / 2.f, pos.y - height / 2.f, width, height, color);
	}
};

class Ball {
public:
	Vector2 pos;
	float radius;
	float speedX;
	float speedY;
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

	Paddle playerRight = Paddle();
	playerRight.pos = Vector2{ (float)windowWidth - 50, windowHeight / 2.f };
	playerRight.width = 25;
	playerRight.height = 120;
	playerRight.speed = 500;
	playerRight.color = WHITE;

	Paddle playerLeft = Paddle();
	playerLeft.pos = Vector2{ (float)50, windowHeight / 2.f };
	playerLeft.width = 25;
	playerLeft.height = 120;
	playerLeft.speed = 500;
	playerLeft.color = WHITE;

	Ball ball = Ball();
	ball.pos = Vector2{ (float)windowWidth /2.f, windowHeight / 2.f };
	ball.radius = 10;
	ball.speedX = 250;
	ball.speedY = 250;
	ball.color = WHITE;

	while (!WindowShouldClose()) {
		BeginDrawing();

		float deltaTime = GetFrameTime();

		playerRight.Update(deltaTime);
		playerLeft.Update(deltaTime);
		ball.Update(deltaTime);

		ClearBackground(BLACK);
		DrawLine(windowWidth / 2.f, 0, windowWidth / 2.f, windowHeight, WHITE);

		playerRight.Draw();
		playerLeft.Draw();
		ball.Draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
