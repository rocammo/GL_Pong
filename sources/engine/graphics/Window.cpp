/*
 * This file is part of PongGL.
 * Copyright (C) 2018 Rodrigo Casamayor.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Window.hpp"

#include "engine/Params.hpp"
#include "engine/logic/State.hpp"

namespace engine { namespace graphics {

	Window::Window(const char *title, int width, int height)
	: _title(title), _width(width), _height(height)
	{
		if(!init())
			glfwTerminate();
	}

	Window::~Window()
	{
        while (!states.empty()) {
            states.back()->clear();
            states.pop_back();
        }

		glfwTerminate();
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "[ERR] " << "Failed to initialize GLFW!" << std::endl;
			return false;
		}

        GLFWmonitor *monitor = NULL;
		if (Params::FULLSCREEN) monitor = glfwGetPrimaryMonitor();

		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		_window = glfwCreateWindow(_width, _height, _title, monitor, NULL);
		if (!_window)
		{
			std::cout << "[ERR] " << "Failed to create GLFW window!" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(_window);
		return true;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	
	void Window::update()
    {
        states.back()->update(this);
        states.back()->render(this);

		glfwSwapBuffers(_window);
		glfwPollEvents();
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(_window);
	}

	// ---

	void Window::ChangeState(engine::logic::State *state) {
        // cleanup the current state
        if (!states.empty()) {
            states.back()->clear();
            states.pop_back();
        }

        // store and init the new state
        states.push_back(state);
        states.back()->init();
	}

	void Window::PushState(engine::logic::State *state) {
		// pause the current state
		if (!states.empty()) {
			states.back()->pause();
		}

		// store and init the new state
		states.push_back(state);
		states.back()->init();
	}

	void Window::PopState(engine::logic::State *state) {
		// cleanup the current state
		if (!states.empty()) {
			states.back()->clear();
			states.pop_back();
		}

		// resume the previous state
		if (!states.empty()) {
			states.back()->resume();
		}
	}

} }