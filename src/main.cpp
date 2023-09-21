/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include STL
#include <iostream>

// Include OpenGL
#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// DEFINES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

constexpr const int RESULT_OK = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// MAIN
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int OPEN_GL_VERSION_MAJOR = 3;
const int OPEN_GL_VERSION_MINOR = 0;
GLFWwindow *mWindow;
int mFrameBufferWidth = 0;
int mFrameBufferHeight = 0;

static void handleGLFWErrors(int error, const char* description)
{
  std::cout << "error_callback: " << description << "\n";
}

static void handleKeyEvents(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (!mWindow)
  {
    return;
  }

  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(mWindow, GLFW_TRUE);
  }
}

void handleFramebufferSizeChange(GLFWwindow *pWindow, int width, int height)
{
  if (!mWindow)
  {
    return;
  }

  mFrameBufferWidth = width;
  mFrameBufferHeight = height;
  glViewport(0, 0, mFrameBufferWidth, mFrameBufferHeight);
}

bool onSurfaceReady()
{
  glfwGetFramebufferSize(mWindow, &mFrameBufferWidth, &mFrameBufferHeight);
  glViewport(0, 0, mFrameBufferWidth, mFrameBufferHeight);

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  return true;
}

bool init()
{
  if (!glfwInit())
  {
    std::cout << "init: failed to init\n";
    return false;
  }

  glfwSetErrorCallback(handleGLFWErrors);

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPEN_GL_VERSION_MAJOR);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPEN_GL_VERSION_MINOR);
  mWindow = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL Triangle", nullptr, nullptr);
  if (!mWindow)
  {
    std::cout << "init: failed to create window\n";
    return false;
  }

  glfwSetKeyCallback(mWindow, handleKeyEvents);

  glfwMakeContextCurrent(mWindow);
  gladLoadGL(glfwGetProcAddress);

  glfwSetFramebufferSizeCallback(mWindow, handleFramebufferSizeChange);
  if (!onSurfaceReady())
  {
    std::cout << "init: failed to load assets\n";
    return false;
  }

  return true;
}

void render()
{
  glClear(GL_COLOR_BUFFER_BIT);
}

void mainLoop()
{
  while (!glfwWindowShouldClose(mWindow))
  {
    render();

    glfwSwapBuffers(mWindow);
    glfwPollEvents();
  }
}

void terminate()
{
  if (mWindow)
  {
    glfwDestroyWindow(mWindow);
  }

  glfwTerminate();
}

int main()
{
  if (init())
  {
    mainLoop();
  }

  terminate();

  return RESULT_OK;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
