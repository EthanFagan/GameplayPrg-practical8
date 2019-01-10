#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{

}

Game::~Game() {}

float vertices[] = { 
	1.0f, 1.0f, -5.0f, // 0
	-1.0f, 1.0f, -5.0f, // 1
  	-1.0f, -1.0f, -5.0f, // 2
	1.0f, -1.0f, -5.0f, // 3
	1.0f, 1.0f, -15.0f, // 4
	-1.0f, 1.0f, -15.0f, // 5
	-1.0f, -1.0f, -15.0f,// 6
	1.0f, -1.0f, -15.0f // 7
	 };

float colors[] = { 
5.0f,  0.0f,  0.0f,
0.0f,  5.0f,  0.0f,
0.0f,  0.0f,  5.0f,
5.0f,  5.0f,  0.0f,
0.0f,  5.0f,  5.0f,
5.0f,  0.0f,  5.0f,
0.0f, 0.0f, 0.0f,
0.0f, 0.0f, 0.0f
 };
unsigned int vertex_index[] = {
0, 1 , 2,
2, 3, 0,
1, 4, 5,
1, 0, 4,
0, 7, 4,
3, 7 ,0,
6, 7, 3,
6, 3, 2,
6, 2, 1,
6, 1 ,5,
6, 4, 5,
6, 7, 4
};

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	/*glClearColor(0.0f, 0.0f, 0.0f, 0.0f);*/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		for (int i = 0; i < 36; i++)
		{
				faces[i][x] = MyMatrix3::rotationZ(rotationAngle) * faces[i][x];
		}
	}

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	/*glDrawArrays(GL_TRIANGLES, 0, );*/

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

