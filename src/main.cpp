#include <chrono>
#include <stdio.h>
#include <gl_command_buffer.hpp>
#include <gl_resource_manager.hpp>

#define SDL_MAIN_HANDLED
#include <SDL.h>

SDL_GLContext g_Context;
void init_gl(SDL_Window* window)
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	int r, g, b, d, s;
	SDL_GL_GetAttribute(SDL_GL_RED_SIZE, &r);
	SDL_GL_GetAttribute(SDL_GL_GREEN_SIZE, &g);
	SDL_GL_GetAttribute(SDL_GL_BLUE_SIZE, &b);
	SDL_GL_GetAttribute(SDL_GL_DEPTH_SIZE, &d);
	SDL_GL_GetAttribute(SDL_GL_STENCIL_SIZE, &s);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetSwapInterval(0);
	g_Context = SDL_GL_CreateContext(window);
	
	int fail = gladLoadGLLoader(SDL_GL_GetProcAddress);
	if (fail == 0)
	{
		SDL_assert(false && "Failed to init OpenGL");
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);
	}
}

void sdlPumpEvents(bool& running)
{
	SDL_Event ev;
	while (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
		case SDL_QUIT:
			running = false;
			return;
		}
	}
}

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    auto window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
	init_gl(window);

	using hr_clock = std::chrono::high_resolution_clock;
	
	auto start = hr_clock::now();
	bool running = true;
	
	multigl::CommandBuffer buffer;
	multigl::ResourceManager resources;
	
	auto buf = resources.Buffers.create();
	while (running)
	{
		auto curTime = hr_clock::now();
		double timeSinceStart = std::chrono::duration<double>(curTime - start).count();

		sdlPumpEvents(running);

		buffer.ClearColor(0, sinf(float(timeSinceStart)), 0, 1);
		buffer.Clear(GL_COLOR_BUFFER_BIT);

		buffer.ProcessCommands();
		SDL_GL_SwapWindow(window);
	}

    return 0;
}