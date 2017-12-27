// main.cpp : This source file is the entry point that will display the gui to the user when the program is executed.

#include "BattleshipForm.h"
#include <Windows.h>
#include <Windows.Applicationmodel.Activation.h>

using namespace System;
using namespace System::Windows::Forms;

int CALLBACK WinMain(_In_  HINSTANCE hInstance, _In_  HINSTANCE hPrevInstance, _In_  LPSTR lpCmdLine, _In_  int nCmdShow)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Battleship::BattleshipForm form;
	Application::Run(%form);
	return 0;
}