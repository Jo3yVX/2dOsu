#include "../include/Game.h"
#include "../include/Texture.h"


Game::Game() {

}

Game::~Game() {

}


void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flag = 0;
	if (fullscreen) flag = SDL_WINDOW_FULLSCREEN;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "SDL Init" << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
		if (window != NULL) {
			cout << "Window created" << endl;
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer != NULL) {
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				cout << "Renderer created" << endl;
				isRunning = true;
			}
			else {
				isRunning = false;
				clean();
			}
		}
		else {
			isRunning = false;
			return;
		}
	}
	else {
		isRunning = false;
		return;
	}
	if (TTF_Init() != 0) {
		cout << "TTF ERROR" << endl;
		isRunning = false;
	}
	return;
}

void Game::update() {

}

void Game::handleEvents() {
	SDL_Event e;
	SDL_PollEvent(&e);
	//check one per time
	switch (e.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	window = NULL;
	renderer = NULL;
	cout << "Quit!" << endl;
	SDL_Quit();
}

void Game::render() {
	//clear previous renderer if existed
	SDL_RenderClear(renderer);
	// add stuff to render here
	//tx = Texture::loadTexture("1.png", renderer);
	//SDL_RenderCopy(renderer, tx, NULL, &destR);
	//SDL_RenderCopy(renderer, background, NULL, NULL);
	SDL_RenderPresent(renderer);
}

bool Game::running() {
	return isRunning;
}