#include "Snake.h"
#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<Windows.h>
#include <ctime>
#include <chrono>
#include<string>
#include <thread>

using namespace std;
Snake::Snake()
{
	direction = "stop";
	press = false;
	score = 0;
	scorecheck = 0;
	check_small = false;
	snake.reserve(20);
}
void Snake::initial() {
	snake.push_back(44);
	snake.push_back(43);
	foodpos = 100;
	badfoodpos = 150;
}
void Snake::draw()
{
	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	cout << "                                                                                                   Snake Game                                                                                                      \n";




	if (gameOver(check_small))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "Game Over\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Player Score:" << score << endl;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "Good Food: $\n\n";
		if (choose == '2')
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			cout << "Bad Food: X\n\n";
		}
		else if (choose == '3')
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
			cout << "Don't Touch Middle Walls \n\n";
		}

		for (int i = 0; i < height; i++)
		{

			for (int j = 0; j < width; j++)
			{

				bool print = false;

				for (int k = 1; k < snake.size(); k++) {
					if ((j + (i * 40)) == snake[k]) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
						cout << "o";
						print = true;
					}
				}
				if ((j + (i * 40)) == snake[0]) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					cout << "@";
					print = true;
				}
				else if (j == 0 || j == 39 || i == 0 || i == 39 || (choose == '3' && ((i == 10 && (j < 25 || j>30)) || (i == 20 && (j < 10 || j>15)) || (i == 30 && (j < 15 || j>20))))) {


					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "#";

					print = true;

				}
				else if ((j + (i * 40)) == badfoodpos && choose == '2')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					cout << "X";
					print = true;
				}
				else if ((j + (i * 40)) == foodpos) {

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << "$";
					print = true;
				}

				if (print == false)
					cout << " ";
			}
			cout << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "Player Score:" << score << endl;
	}
}
void Snake::input()
{


	if (_kbhit())//1-if keyboard is pressed return pos num if pressed and if nothing is pressed will return zero
	{
		press = true;

		if (_getch() == 'a')//2-return ascci value of char that was pressed by user//left
		{
			if (direction == "right")
				direction = "right";
			else
				direction = "left";
		}
		else if (_getch() == 'w')//up
		{
			if (direction == "down")
				direction = "down";
			else
				direction = "up";
		}
		else if (_getch() == 's')//down
		{
			if (direction == "up")
				direction = "up";
			else
				direction = "down";
		}
		else if (_getch() == 'd')//right
		{
			if (direction == "left")
				direction = "left";
			else
				direction = "right";
		}
	}

}
void Snake::initialhard() {
	snake.push_back(41);
	snake.push_back(42);
	foodpos = 1352;
}
void Snake::drawhard()
{

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	cout << "                                                                                                   Snake Game                                                                                                      \n";


	if (gameOverhard())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

		cout << "Game Over\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Player Score:" << score << endl;
	}
	else

	{

		for (int i = 0; i < width; i++)
		{

			for (int j = 0; j < height; j++)
			{
				int u = j + (i * 40);
				bool print = false;
				bool print2 = false;
				for (int k = 1; k < snake.size(); k++) {
					if ((j + (i * 40)) == snake[k]) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
						cout << "o";
						print = true;
						print2 = true;
					}
				}
				/*if (i == 40&&j==5)
				{
				for (int x = 0; x < 6; x++,i+=40)
				{


				cout << "#";
				print = true;
				print2 = true;

				}
				}*/
				if ((j + (i * 40)) == snake[0]) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					cout << "@";
					print = true;
					print2 = true;
				}
				else if (u % 40 == 8 && u < 328 && u>8)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "#";
					print = true;

				}
				else if (u > 320 && u < 329) {


					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					//	/*for (int x = 0; x < 8; x++)
					//	{*/
					cout << "#";
					print = true;


					//	//}

				}
				else if (u % 40 == 31 && u < 1552 && u>1270)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

					cout << "#";
					print = true;

				}
				else if (u > 1271 && u < 1279) {

					//	/*for (int x = 0; x < 8; x++)
					//	{*/
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "#";
					print = true;


					//	//}

				}
				else if (j == 0 || j == 39 || i == 0 || i == 39) {
					if (print2 == false) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << "#";
						print = true;
					}
				}

				else if ((j + (i * 40)) == foodpos) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << "$";
					print = true;
				}

				if (print == false)
					cout << " ";
			}
			cout << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "Player Score:" << score << endl;
	}
}
void Snake::moveing()
{
	int prevPos = snake[0];
	string prevDirection = direction;

	for (int i = snake.size() - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];
	}

	if (direction == "left") {
		snake[0] -= 1;


	}
	else if (direction == "right")
	{
		snake[0] += 1;


	}
	else if (direction == "up")
	{
		snake[0] -= 40;


	}
	else if (direction == "down")
	{
		snake[0] += 40;


	}
	bool whole = false;
	float x = ((snake[0] + 1) / 40.00);
	if (floor(x) == x)//to know if x is a whole num or not;
		whole = true;
	bool whole2 = false;
	float y = ((snake[0]) / 40.00);
	if (floor(y) == y)//same as x
		whole2 = true;
	if (openwall == 'c' || openwall == 'C')
	{
		if ((whole))//if it reaches end right 
			hit_wall = true;
		else if ((whole2))//if it reaches end left
			hit_wall = true;
		else if ((snake[0] <= 39))//if it reaches end up
			hit_wall = true;
		else if ((snake[0] >= (40 * 39)))//if it reaches end down
			hit_wall = true;
	}
	else
	{
		if (whole)//if it reaches end right 
			snake[0] -= 38;
		else if (whole2)//if it reaches end left
			snake[0] += 38;
		else if (snake[0] <= 39)//if it reaches end up
			snake[0] = (snake[0] - 40) + (40 * 40);
		else if ((snake[0] >= (40 * 39)))//if it reaches end down
			snake[0] = snake[0] - (40 * 40);
	}

}
bool Snake::eatfood()
{

	if (snake[0] == foodpos)
	{
		snake.push_back(snake[snake.size() - 1] + 1);
		score++;
		scorecheck++;
		return true;
	}
	return false;
}
bool Snake::eatbadfood()
{
	if (snake[0] == badfoodpos)
	{
		if (snake.size() > 2)
		{
			snake.pop_back();
			score--;
		}
		else
			check_small = true;
		return true;
	}
	return false;
}
void Snake::generate_food()
{
	srand(time(NULL));
	int foodposx = 1 + (rand() % ((width)-2));
	int  foodposy = 1 + (rand() % ((width)-2));
	foodpos = foodposx + (width*foodposy);
	if (choose == '3')
	{
		if (foodposy == 20 || foodposy == 30 || foodposy == 10)
			generate_food();
	}
	auto it = snake.begin();
	while (it != snake.end())
	{
		if (foodpos == (*it))
		{
			generate_food();

		}
		it++;
	}
}
void Snake::generate_badfood()
{
	srand(time(NULL));
	int badfoodposx = 1 + (rand() % ((width)-2));
	int  badfoodposy = 1 + (rand() % ((width)-2));
	badfoodpos = badfoodposx + (width*badfoodposy);
	if (choose == '3')
	{
		if (badfoodposy == 20 || badfoodposy == 30 || badfoodposy == 10)
			generate_food();
	}
	auto it = snake.begin();
	if (badfoodpos == foodpos)
		generate_badfood();
	for (it; it < snake.end(); it++)
	{
		if (badfoodpos == (*it))
			generate_badfood();
	}
}
//check_small 3al4an lma yakol bad food f awl mara kan bay3mal run time f lw check_small true ya5sar
bool Snake::gameOver(bool check_small) {

	if (check_small)
		return true;
	if (choose == '3')
	{
		if ((snake[0] >= 400 && snake[0] <= 425) || (snake[0] >= 430 && snake[0] <= 440) || (snake[0] >= 800 && snake[0] <= 810) || (snake[0] >= 815 && snake[0] <= 840) || (snake[0] >= 1200 && snake[0] <= 1215) || (snake[0] >= 1220 && snake[0] <= 1240))
			return true;
	}

	if (openwall == 'c' || openwall == 'C')
	{
		if (hit_wall == true)
			return true;

	}

	for (int i = 1; i < snake.size() - 1; i++) {
		if (snake[i] == snake[0] || snake.size() == 1)
			return true;
	}
	return false;
}
int  Snake::gameScore() {
	int x = 0;
	if (scorecheck == 5) {
		scorecheck = 0;
		x += 10;
	}
	return x;
}
void Snake::moveinghard()
{
	int prevPos = snake[0];
	string prevDirection = direction;

	for (int i = snake.size() - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];
	}

	if (direction == "left") {
		snake[0] -= 1;


	}
	else if (direction == "right")
	{
		snake[0] += 1;


	}
	else if (direction == "up")
	{
		snake[0] -= 40;


	}
	else if (direction == "down")
	{
		snake[0] += 40;


	}


	if (snake[0] > 0 && snake[0] < 9)
	{
		snake[0] = snake[0] + 1591;
	}
	else if (snake[0] > 1591 && snake[0] < 1599)
	{
		snake[0] = snake[0] - 1591;
	}
	else if (snake[0] > 0 && snake[0] < 320 && snake[0] % 40 == 0)
	{
		snake[0] = 1279 + snake[0];
	}
	else if (snake[0] > 1279 && snake[0] < 1599 && snake[0] % 40 == 39)
	{
		snake[0] = snake[0] - 1279;

	}

}
bool Snake::gameOverhard() {

	for (int i = 1; i < snake.size() - 1; i++) {
		if (snake[i] == snake[0])
			return true; break;
	}
	for (int i = 8; i < 328; i += 40) {

		if (snake[0] == i)
		{
			return true;
			break;
		}
	}
	for (int i = 320; i < 328; i++)
	{
		if (snake[0] == i)
		{
			return true;
			break;
		}
	}
	for (int i = 1271; i < 1591; i += 40) {

		if (snake[0] == i)
		{
			return true;
			break;
		}
	}
	for (int i = 1271; i < 1279; i++)
	{
		if (snake[0] == i)
		{
			return true;
			break;
		}
	}



	return false;
}
void Snake::generatehardfoodupper()
{
	srand(time(NULL));
	int foodposx = 1 + rand() % 5;
	int  foodposy = 1 + rand() % 5;
	foodpos = foodposx + (40 * foodposy);
	auto it = snake.begin();
	while (it != snake.end())
	{
		if (foodpos == (*it))
		{
			generatehardfoodupper();
			break;
		}
		it++;
	}

}
void Snake::generatehardfoodlower()
{
	srand(time(NULL));
	int foodposx = 32 + rand() % 6;
	int  foodposy = 32 + rand() % 6;
	foodpos = foodposx + (40 * foodposy);
	auto it = snake.begin();
	while (it != snake.end())
	{
		if (foodpos == (*it))
		{
			generatehardfoodlower();
			break;
		}
		it++;
	}

}
void Snake::generatehardfood() {

	int x = rand() % 10;


	if (x % 2 == 0)
	{
		generatehardfoodupper();
	}
	else {
		generatehardfoodlower();

	}

}
void Snake::game()
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	cout << "Welcome To Snake Game ooo@\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
	cout << "Choose Level:\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 245);
	cout << "Enter 1 for Easy, Enter 2 for Medium, Enter 3 for Hard,Enter 4 for very Hard:\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cin >> choose;
	while (choose != '1' && choose != '2' && choose != '3'&& choose != '4')
	{
		cout << "Please Enter correct Level\n";
		cin >> choose;
	}

	if (choose == '1' || choose == '2' || choose == '3')
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 245);
		cout << "Enter O For Open Wall And C for closed Wall\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cin >> openwall;
		while (openwall != 'o' &&openwall != 'O' && openwall != 'C' &&openwall != 'c')
		{
			cout << "Please Enter correct option\n";
			cin >> openwall;
		}
		initial();
		draw();

		while (!gameOver(check_small) && snake.size() < 20)
		{
			input();
			moveing();
			if (eatfood()) {
				generate_food();
			}
			if (eatbadfood()) {
				generate_badfood();
			}
			draw();
			int x = gameScore();
			std::this_thread::sleep_for(std::chrono::milliseconds(10 + x));

		}
		draw();
	}
	else if (choose == '4')
	{
		initialhard();
		drawhard();

		while (!gameOverhard() && snake.size() < 20)
		{
			input();
			moveinghard();
			if (eatfood()) {
				generatehardfood();
			}
			drawhard();
			int x = gameScore();
			std::this_thread::sleep_for(std::chrono::milliseconds(10 + x));
		}

	}
}
Snake::~Snake() {};