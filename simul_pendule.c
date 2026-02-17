#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


#define FPS 60
#define RADIUS 20.0
#define G 9.81

const int width = 2000;
const int height = 1350;
const float frictions = .5f;
const float scale_vitesse = 4.0f;


const Vector2 start = {.x = width/2, .y = 250};
Vector2 position;


void 	ft_draw_pendule(int len, float masse, float angle)
{
	DrawLineDashed(start, (Vector2){.x = start.x, .y = start.y+len+30}, 10, 5, BLUE);
	DrawCircleLinesV(start, RADIUS, BLUE);
	DrawCircleV(position, RADIUS + masse/2, RED);
	DrawLineEx(start, position, 5, BLACK);
}



int main(int argc, char *argv[])
{
	// angle, a0 = angle de base, omega=vitesse angulaire, alpha = acceleration angulaire;
	int len;
	float masse, dt, a0, angle, omega, alpha;
	bool can_move;
	Vector2 angle_actu;
	char str[10];


	if (argc > 2)
	{
		len = atoi(argv[1]);
		masse = (float) atof(argv[2]);
	} else {
		len = 700;
		masse = 10.0;
	} 

	angle = a0 = omega = 0.0;
	can_move = false;	
	position.x = start.x;
	position.y = start.y + len;
	
	InitWindow(width, height, "Movement de pendule");
	SetTargetFPS(FPS);
	while (!WindowShouldClose())
	{
		dt = GetFrameTime();
		if (IsMouseButtonPressed(0))
		{
			can_move = false;
			Vector2 mouse = GetMousePosition();
			a0 = atan2f(mouse.x-start.x, mouse.y-start.y);
			position.x = start.x + len * sinf(a0);
			position.y = start.y + len * cosf(a0);
			angle  = a0;
			omega = 0;
			printf("position = (%2f, %2f) | a0 = %3f.\n", position.x, position.y, a0 * RAD2DEG);
		}

		if (IsKeyPressed(KEY_SPACE)){
			can_move = ! can_move;
			printf("Touche espace appuyee.\n");
		}

		if (can_move){
			alpha = - (G / len * 500) * sinf(angle) - frictions * omega ;
			omega += alpha * dt ;
			angle += omega * dt ;

			position.x = start.x + len * sinf(angle);
			position.y = start.y + len * cosf(angle);
			sprintf(str, "%2f", angle*RAD2DEG);
		}
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Simulation du mouvement de pendule", 25, 30, 34, BLACK);
			DrawText("Longueur du fil : ", 25, 70, 34, RED);
			DrawText(argv[1], 150, 105, 34, GREEN);
			DrawText("Masse du pendule : ", 25, 140, 34, RED);
			DrawText(argv[2], 150, 180, 34, GREEN);
			DrawText(str, width/2 + 250, 10, 34, BLUE);
			ft_draw_pendule(len, masse, angle);


		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}