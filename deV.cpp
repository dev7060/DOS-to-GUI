#include <windows.h>
#include <fstream>
#include <iostream>
using namespace std;
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
  HWND Stealth;
  AllocConsole();
  Stealth = FindWindowA("ConsoleWindowClass", NULL);
  ShowWindow(Stealth, 0);
  char * command = "systeminfo > temp";
  system(command);
  ifstream ifs("temp");
  string content((istreambuf_iterator < char > (ifs)),
    (istreambuf_iterator < char > ()));
  const char * cstr = content.c_str();
  ifs.close();
  system("del temp");
  return MessageBox(NULL, cstr, "caption", 0);
}
