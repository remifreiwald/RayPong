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

class Player {
public:
	Vector2 pos;
	float width;
	float height;
	Color color;

	void Draw() {
		DrawRectangle(pos.x - width / 2.f, pos.y - height / 2.f, width, height, color);
	}
};

class CPU : public Player {

};

int main() {
	InitWindow(windowWidth, windowHeight, "RayPong");
	SetTargetFPS(60);

	Player player = Player();
	player.pos = Vector2{ (float)windowWidth - 50, windowHeight / 2.f };
	player.width = 25;
	player.height = 120;
	player.color = WHITE;

	CPU cpu = CPU();
	cpu.pos = Vector2{ (float)50, windowHeight / 2.f };
	cpu.width = 25;
	cpu.height = 120;
	cpu.color = WHITE;

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(BLACK);
		DrawLine(windowWidth / 2.f, 0, windowWidth / 2.f, windowHeight, WHITE);

		player.Draw();
		cpu.Draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
