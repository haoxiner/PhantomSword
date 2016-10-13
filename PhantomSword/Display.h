#pragma once
#include <GL/glew.h>
#include <Windows.h>
#include <GLFW/glfw3.h>
class Display
{
public:
  Display();
  ~Display();
  bool Initialize();
  void Update();
  void Destroy();
  bool IsRunning() { return running_ && !glfwWindowShouldClose(window_); }
  float GetDelta() { return delta_; }
private:
  GLFWwindow *window_;
  bool running_;
  unsigned long lastTick_;
  float delta_;
};

