#include "Display.h"

Display::Display()
  :window_(nullptr), running_(false), lastTick_(0)
{
}

Display::~Display()
{
}

bool Display::Initialize()
{
  if (!glfwInit())
  {
    return false;
  }
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  window_ = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window_)
  {
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(window_);
  glewExperimental = true;
  if (glewInit() != GLEW_OK)
  {
    glfwTerminate();
    return false;
  }
  
  bool *pRunning = &running_;
  glfwSetKeyCallback(window_, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
    /*  The action is one of GLFW_PRESS, GLFW_REPEAT or GLFW_RELEASE.
    *  The key will be GLFW_KEY_UNKNOWN if GLFW lacks a key token for it,
    *  for example E-mail and Play keys.
    */
    if (action == GLFW_PRESS)
    {
      switch (key)
      {
      case GLFW_KEY_Q:
      default:
        break;
      }
    }
  });
  running_ = true;
  return true;
}

void Display::Update()
{
  unsigned long tick = GetTickCount();
  if (tick < lastTick_)
  {
    tick = lastTick_;
  }
  delta_ = static_cast<float>(tick - lastTick_);
  lastTick_ = tick;
  glfwSwapBuffers(window_);
  glfwPollEvents();
}

void Display::Destroy()
{
  glfwTerminate();
  window_ = nullptr;
  running_ = false;
}

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  /*  The action is one of GLFW_PRESS, GLFW_REPEAT or GLFW_RELEASE.
   *  The key will be GLFW_KEY_UNKNOWN if GLFW lacks a key token for it,
   *  for example E-mail and Play keys.
   */
  if (action == GLFW_PRESS)
  {
    switch (key)
    {
    case GLFW_KEY_Q:
    default:
      break;
    }
  }
}