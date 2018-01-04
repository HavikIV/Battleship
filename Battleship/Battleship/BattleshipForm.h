#pragma once

#include <vector>
#include "Grid.h"
#include "Ship.h"
#include "GameMaster.h"

namespace Battleship {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for BattleshipForm
	/// </summary>
	public ref class BattleshipForm : public System::Windows::Forms::Form
	{
		// Global Variables
		bool inSetupMode = true; // Determines if the player is still setting up their game board; This variable becomes false once all ships on placed on board
		bool attackMode = false; // Used to prevent the user from making any attacks before the ready button is clicked
	private: System::Windows::Forms::TextBox^  txtOutput;

			 GameMaster^ gm;
			 delegate void logDelegate(String^ message);
	public:
		BattleshipForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			// Let's start up the Game Master and the AI on separate threads
			//Thread^ gameMasterThread = gcnew Thread(gcnew ThreadStart(this, &BattleshipForm::StartGameMaster)); // Start the function on a separate thread
			gm = gcnew GameMaster();
			Thread^ gameMasterThread = gcnew Thread(gcnew ThreadStart(gm, &GameMaster::Start));
			gameMasterThread->Start();

			outputLog("Welcome to Battleship. Please set up your game board and press ready when you are done.");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BattleshipForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:

	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  J10;
	private: System::Windows::Forms::Label^  J9;


	private: System::Windows::Forms::Label^  J8;

	private: System::Windows::Forms::Label^  J7;

	private: System::Windows::Forms::Label^  J6;

	private: System::Windows::Forms::Label^  J5;

	private: System::Windows::Forms::Label^  J4;

	private: System::Windows::Forms::Label^  J3;

	private: System::Windows::Forms::Label^  J2;

	private: System::Windows::Forms::Label^  J1;

	private: System::Windows::Forms::Label^  I10;
	private: System::Windows::Forms::Label^  I9;


	private: System::Windows::Forms::Label^  I8;

	private: System::Windows::Forms::Label^  I7;

	private: System::Windows::Forms::Label^  I6;

	private: System::Windows::Forms::Label^  I5;

	private: System::Windows::Forms::Label^  I4;

	private: System::Windows::Forms::Label^  I3;

	private: System::Windows::Forms::Label^  I2;

	private: System::Windows::Forms::Label^  I1;

	private: System::Windows::Forms::Label^  H10;
	private: System::Windows::Forms::Label^  H9;


	private: System::Windows::Forms::Label^  H8;

	private: System::Windows::Forms::Label^  H7;

	private: System::Windows::Forms::Label^  H6;

	private: System::Windows::Forms::Label^  H5;

	private: System::Windows::Forms::Label^  H4;

	private: System::Windows::Forms::Label^  H3;

	private: System::Windows::Forms::Label^  H2;

	private: System::Windows::Forms::Label^  H1;

	private: System::Windows::Forms::Label^  G10;
	private: System::Windows::Forms::Label^  G9;


	private: System::Windows::Forms::Label^  G8;

	private: System::Windows::Forms::Label^  G7;

	private: System::Windows::Forms::Label^  G6;

	private: System::Windows::Forms::Label^  G5;

	private: System::Windows::Forms::Label^  G4;

	private: System::Windows::Forms::Label^  G3;


	private: System::Windows::Forms::Label^  G2;

	private: System::Windows::Forms::Label^  G1;

	private: System::Windows::Forms::Label^  F10;
	private: System::Windows::Forms::Label^  F9;


	private: System::Windows::Forms::Label^  F8;

	private: System::Windows::Forms::Label^  F7;

	private: System::Windows::Forms::Label^  F6;

	private: System::Windows::Forms::Label^  F5;

	private: System::Windows::Forms::Label^  F4;

private: System::Windows::Forms::Label^  F3;

private: System::Windows::Forms::Label^  F2;

	private: System::Windows::Forms::Label^  F1;

	private: System::Windows::Forms::Label^  E10;
private: System::Windows::Forms::Label^  E9;


private: System::Windows::Forms::Label^  E8;

private: System::Windows::Forms::Label^  E7;

private: System::Windows::Forms::Label^  E6;

private: System::Windows::Forms::Label^  E5;

private: System::Windows::Forms::Label^  E4;

private: System::Windows::Forms::Label^  E3;

private: System::Windows::Forms::Label^  E2;

private: System::Windows::Forms::Label^  E1;

private: System::Windows::Forms::Label^  D10;
private: System::Windows::Forms::Label^  D9;


private: System::Windows::Forms::Label^  D8;

private: System::Windows::Forms::Label^  D7;

private: System::Windows::Forms::Label^  D6;

private: System::Windows::Forms::Label^  D5;

private: System::Windows::Forms::Label^  D4;

private: System::Windows::Forms::Label^  D3;

private: System::Windows::Forms::Label^  D2;

private: System::Windows::Forms::Label^  D1;

private: System::Windows::Forms::Label^  C10;
private: System::Windows::Forms::Label^  C9;


private: System::Windows::Forms::Label^  C8;

private: System::Windows::Forms::Label^  C7;

private: System::Windows::Forms::Label^  C6;

private: System::Windows::Forms::Label^  C5;

private: System::Windows::Forms::Label^  C4;

private: System::Windows::Forms::Label^  C3;

private: System::Windows::Forms::Label^  C2;

private: System::Windows::Forms::Label^  C1;

private: System::Windows::Forms::Label^  B10;
private: System::Windows::Forms::Label^  B9;


private: System::Windows::Forms::Label^  B8;

private: System::Windows::Forms::Label^  B7;

private: System::Windows::Forms::Label^  B6;

private: System::Windows::Forms::Label^  B5;

private: System::Windows::Forms::Label^  B4;

private: System::Windows::Forms::Label^  B3;

private: System::Windows::Forms::Label^  B2;

private: System::Windows::Forms::Label^  B1;

private: System::Windows::Forms::Label^  A10;
private: System::Windows::Forms::Label^  A9;


private: System::Windows::Forms::Label^  A8;

private: System::Windows::Forms::Label^  A7;

private: System::Windows::Forms::Label^  A6;

private: System::Windows::Forms::Label^  A5;

private: System::Windows::Forms::Label^  A4;

private: System::Windows::Forms::Label^  A3;

private: System::Windows::Forms::Label^  A2;

private: System::Windows::Forms::Label^  A1;
private: System::Windows::Forms::Label^  lblGameMaster;

private: System::Windows::Forms::GroupBox^  gbSetup;
private: System::Windows::Forms::ListBox^  Battleships;
private: System::Windows::Forms::GroupBox^  gbOrientation;
private: System::Windows::Forms::RadioButton^  rbVertical;
private: System::Windows::Forms::RadioButton^  rbHorizontal;
private: System::Windows::Forms::Button^  btnReady;
private: System::Windows::Forms::Button^  btnReset;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->J10 = (gcnew System::Windows::Forms::Label());
			this->J9 = (gcnew System::Windows::Forms::Label());
			this->J8 = (gcnew System::Windows::Forms::Label());
			this->J7 = (gcnew System::Windows::Forms::Label());
			this->J6 = (gcnew System::Windows::Forms::Label());
			this->J5 = (gcnew System::Windows::Forms::Label());
			this->J4 = (gcnew System::Windows::Forms::Label());
			this->J3 = (gcnew System::Windows::Forms::Label());
			this->J2 = (gcnew System::Windows::Forms::Label());
			this->J1 = (gcnew System::Windows::Forms::Label());
			this->I10 = (gcnew System::Windows::Forms::Label());
			this->I9 = (gcnew System::Windows::Forms::Label());
			this->I8 = (gcnew System::Windows::Forms::Label());
			this->I7 = (gcnew System::Windows::Forms::Label());
			this->I6 = (gcnew System::Windows::Forms::Label());
			this->I5 = (gcnew System::Windows::Forms::Label());
			this->I4 = (gcnew System::Windows::Forms::Label());
			this->I3 = (gcnew System::Windows::Forms::Label());
			this->I2 = (gcnew System::Windows::Forms::Label());
			this->I1 = (gcnew System::Windows::Forms::Label());
			this->H10 = (gcnew System::Windows::Forms::Label());
			this->H9 = (gcnew System::Windows::Forms::Label());
			this->H8 = (gcnew System::Windows::Forms::Label());
			this->H7 = (gcnew System::Windows::Forms::Label());
			this->H6 = (gcnew System::Windows::Forms::Label());
			this->H5 = (gcnew System::Windows::Forms::Label());
			this->H4 = (gcnew System::Windows::Forms::Label());
			this->H3 = (gcnew System::Windows::Forms::Label());
			this->H2 = (gcnew System::Windows::Forms::Label());
			this->H1 = (gcnew System::Windows::Forms::Label());
			this->G10 = (gcnew System::Windows::Forms::Label());
			this->G9 = (gcnew System::Windows::Forms::Label());
			this->G8 = (gcnew System::Windows::Forms::Label());
			this->G7 = (gcnew System::Windows::Forms::Label());
			this->G6 = (gcnew System::Windows::Forms::Label());
			this->G5 = (gcnew System::Windows::Forms::Label());
			this->G4 = (gcnew System::Windows::Forms::Label());
			this->G3 = (gcnew System::Windows::Forms::Label());
			this->G2 = (gcnew System::Windows::Forms::Label());
			this->G1 = (gcnew System::Windows::Forms::Label());
			this->F10 = (gcnew System::Windows::Forms::Label());
			this->F9 = (gcnew System::Windows::Forms::Label());
			this->F8 = (gcnew System::Windows::Forms::Label());
			this->F7 = (gcnew System::Windows::Forms::Label());
			this->F6 = (gcnew System::Windows::Forms::Label());
			this->F5 = (gcnew System::Windows::Forms::Label());
			this->F4 = (gcnew System::Windows::Forms::Label());
			this->F3 = (gcnew System::Windows::Forms::Label());
			this->F2 = (gcnew System::Windows::Forms::Label());
			this->F1 = (gcnew System::Windows::Forms::Label());
			this->E10 = (gcnew System::Windows::Forms::Label());
			this->E9 = (gcnew System::Windows::Forms::Label());
			this->E8 = (gcnew System::Windows::Forms::Label());
			this->E7 = (gcnew System::Windows::Forms::Label());
			this->E6 = (gcnew System::Windows::Forms::Label());
			this->E5 = (gcnew System::Windows::Forms::Label());
			this->E4 = (gcnew System::Windows::Forms::Label());
			this->E3 = (gcnew System::Windows::Forms::Label());
			this->E2 = (gcnew System::Windows::Forms::Label());
			this->E1 = (gcnew System::Windows::Forms::Label());
			this->D10 = (gcnew System::Windows::Forms::Label());
			this->D9 = (gcnew System::Windows::Forms::Label());
			this->D8 = (gcnew System::Windows::Forms::Label());
			this->D7 = (gcnew System::Windows::Forms::Label());
			this->D6 = (gcnew System::Windows::Forms::Label());
			this->D5 = (gcnew System::Windows::Forms::Label());
			this->D4 = (gcnew System::Windows::Forms::Label());
			this->D3 = (gcnew System::Windows::Forms::Label());
			this->D2 = (gcnew System::Windows::Forms::Label());
			this->D1 = (gcnew System::Windows::Forms::Label());
			this->C10 = (gcnew System::Windows::Forms::Label());
			this->C9 = (gcnew System::Windows::Forms::Label());
			this->C8 = (gcnew System::Windows::Forms::Label());
			this->C7 = (gcnew System::Windows::Forms::Label());
			this->C6 = (gcnew System::Windows::Forms::Label());
			this->C5 = (gcnew System::Windows::Forms::Label());
			this->C4 = (gcnew System::Windows::Forms::Label());
			this->C3 = (gcnew System::Windows::Forms::Label());
			this->C2 = (gcnew System::Windows::Forms::Label());
			this->C1 = (gcnew System::Windows::Forms::Label());
			this->B10 = (gcnew System::Windows::Forms::Label());
			this->B9 = (gcnew System::Windows::Forms::Label());
			this->B8 = (gcnew System::Windows::Forms::Label());
			this->B7 = (gcnew System::Windows::Forms::Label());
			this->B6 = (gcnew System::Windows::Forms::Label());
			this->B5 = (gcnew System::Windows::Forms::Label());
			this->B4 = (gcnew System::Windows::Forms::Label());
			this->B3 = (gcnew System::Windows::Forms::Label());
			this->B2 = (gcnew System::Windows::Forms::Label());
			this->B1 = (gcnew System::Windows::Forms::Label());
			this->A10 = (gcnew System::Windows::Forms::Label());
			this->A9 = (gcnew System::Windows::Forms::Label());
			this->A8 = (gcnew System::Windows::Forms::Label());
			this->A7 = (gcnew System::Windows::Forms::Label());
			this->A6 = (gcnew System::Windows::Forms::Label());
			this->A5 = (gcnew System::Windows::Forms::Label());
			this->A4 = (gcnew System::Windows::Forms::Label());
			this->A3 = (gcnew System::Windows::Forms::Label());
			this->A2 = (gcnew System::Windows::Forms::Label());
			this->A1 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblGameMaster = (gcnew System::Windows::Forms::Label());
			this->gbSetup = (gcnew System::Windows::Forms::GroupBox());
			this->Battleships = (gcnew System::Windows::Forms::ListBox());
			this->gbOrientation = (gcnew System::Windows::Forms::GroupBox());
			this->rbVertical = (gcnew System::Windows::Forms::RadioButton());
			this->rbHorizontal = (gcnew System::Windows::Forms::RadioButton());
			this->btnReady = (gcnew System::Windows::Forms::Button());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->txtOutput = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->gbSetup->SuspendLayout();
			this->gbOrientation->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->label20);
			this->panel1->Controls->Add(this->label19);
			this->panel1->Controls->Add(this->label18);
			this->panel1->Controls->Add(this->label17);
			this->panel1->Controls->Add(this->label16);
			this->panel1->Controls->Add(this->label15);
			this->panel1->Controls->Add(this->label14);
			this->panel1->Controls->Add(this->label13);
			this->panel1->Controls->Add(this->label12);
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(456, 458);
			this->panel1->TabIndex = 0;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->J10);
			this->panel3->Controls->Add(this->J9);
			this->panel3->Controls->Add(this->J8);
			this->panel3->Controls->Add(this->J7);
			this->panel3->Controls->Add(this->J6);
			this->panel3->Controls->Add(this->J5);
			this->panel3->Controls->Add(this->J4);
			this->panel3->Controls->Add(this->J3);
			this->panel3->Controls->Add(this->J2);
			this->panel3->Controls->Add(this->J1);
			this->panel3->Controls->Add(this->I10);
			this->panel3->Controls->Add(this->I9);
			this->panel3->Controls->Add(this->I8);
			this->panel3->Controls->Add(this->I7);
			this->panel3->Controls->Add(this->I6);
			this->panel3->Controls->Add(this->I5);
			this->panel3->Controls->Add(this->I4);
			this->panel3->Controls->Add(this->I3);
			this->panel3->Controls->Add(this->I2);
			this->panel3->Controls->Add(this->I1);
			this->panel3->Controls->Add(this->H10);
			this->panel3->Controls->Add(this->H9);
			this->panel3->Controls->Add(this->H8);
			this->panel3->Controls->Add(this->H7);
			this->panel3->Controls->Add(this->H6);
			this->panel3->Controls->Add(this->H5);
			this->panel3->Controls->Add(this->H4);
			this->panel3->Controls->Add(this->H3);
			this->panel3->Controls->Add(this->H2);
			this->panel3->Controls->Add(this->H1);
			this->panel3->Controls->Add(this->G10);
			this->panel3->Controls->Add(this->G9);
			this->panel3->Controls->Add(this->G8);
			this->panel3->Controls->Add(this->G7);
			this->panel3->Controls->Add(this->G6);
			this->panel3->Controls->Add(this->G5);
			this->panel3->Controls->Add(this->G4);
			this->panel3->Controls->Add(this->G3);
			this->panel3->Controls->Add(this->G2);
			this->panel3->Controls->Add(this->G1);
			this->panel3->Controls->Add(this->F10);
			this->panel3->Controls->Add(this->F9);
			this->panel3->Controls->Add(this->F8);
			this->panel3->Controls->Add(this->F7);
			this->panel3->Controls->Add(this->F6);
			this->panel3->Controls->Add(this->F5);
			this->panel3->Controls->Add(this->F4);
			this->panel3->Controls->Add(this->F3);
			this->panel3->Controls->Add(this->F2);
			this->panel3->Controls->Add(this->F1);
			this->panel3->Controls->Add(this->E10);
			this->panel3->Controls->Add(this->E9);
			this->panel3->Controls->Add(this->E8);
			this->panel3->Controls->Add(this->E7);
			this->panel3->Controls->Add(this->E6);
			this->panel3->Controls->Add(this->E5);
			this->panel3->Controls->Add(this->E4);
			this->panel3->Controls->Add(this->E3);
			this->panel3->Controls->Add(this->E2);
			this->panel3->Controls->Add(this->E1);
			this->panel3->Controls->Add(this->D10);
			this->panel3->Controls->Add(this->D9);
			this->panel3->Controls->Add(this->D8);
			this->panel3->Controls->Add(this->D7);
			this->panel3->Controls->Add(this->D6);
			this->panel3->Controls->Add(this->D5);
			this->panel3->Controls->Add(this->D4);
			this->panel3->Controls->Add(this->D3);
			this->panel3->Controls->Add(this->D2);
			this->panel3->Controls->Add(this->D1);
			this->panel3->Controls->Add(this->C10);
			this->panel3->Controls->Add(this->C9);
			this->panel3->Controls->Add(this->C8);
			this->panel3->Controls->Add(this->C7);
			this->panel3->Controls->Add(this->C6);
			this->panel3->Controls->Add(this->C5);
			this->panel3->Controls->Add(this->C4);
			this->panel3->Controls->Add(this->C3);
			this->panel3->Controls->Add(this->C2);
			this->panel3->Controls->Add(this->C1);
			this->panel3->Controls->Add(this->B10);
			this->panel3->Controls->Add(this->B9);
			this->panel3->Controls->Add(this->B8);
			this->panel3->Controls->Add(this->B7);
			this->panel3->Controls->Add(this->B6);
			this->panel3->Controls->Add(this->B5);
			this->panel3->Controls->Add(this->B4);
			this->panel3->Controls->Add(this->B3);
			this->panel3->Controls->Add(this->B2);
			this->panel3->Controls->Add(this->B1);
			this->panel3->Controls->Add(this->A10);
			this->panel3->Controls->Add(this->A9);
			this->panel3->Controls->Add(this->A8);
			this->panel3->Controls->Add(this->A7);
			this->panel3->Controls->Add(this->A6);
			this->panel3->Controls->Add(this->A5);
			this->panel3->Controls->Add(this->A4);
			this->panel3->Controls->Add(this->A3);
			this->panel3->Controls->Add(this->A2);
			this->panel3->Controls->Add(this->A1);
			this->panel3->Location = System::Drawing::Point(38, 27);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(415, 418);
			this->panel3->TabIndex = 20;
			// 
			// J10
			// 
			this->J10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->J10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->J10->Location = System::Drawing::Point(363, 363);
			this->J10->Name = L"J10";
			this->J10->Size = System::Drawing::Size(40, 40);
			this->J10->TabIndex = 99;
			this->J10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->J10->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->J10->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->J10->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// J9
			// 
			this->J9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->J9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->J9->Location = System::Drawing::Point(323, 363);
			this->J9->Name = L"J9";
			this->J9->Size = System::Drawing::Size(40, 40);
			this->J9->TabIndex = 98;
			this->J9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->J9->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->J9->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->J9->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// J8
			// 
			this->J8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->J8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->J8->Location = System::Drawing::Point(283, 363);
			this->J8->Name = L"J8";
			this->J8->Size = System::Drawing::Size(40, 40);
			this->J8->TabIndex = 97;
			this->J8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->J8->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->J8->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->J8->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// J7
			// 
			this->J7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->J7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->J7->Location = System::Drawing::Point(243, 363);
			this->J7->Name = L"J7";
			this->J7->Size = System::Drawing::Size(40, 40);
			this->J7->TabIndex = 96;
			this->J7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->J7->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->J7->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->J7->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// J6
			// 
			this->J6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->J6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->J6->Location = System::Drawing::Point(203, 363);
			this->J6->Name = L"J6";
			this->J6->Size = System::Drawing::Size(40, 40);
			this->J6->TabIndex = 95;
			this->J6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->J6->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->J6->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->J6->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// J5
			// 
			this->J5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->J5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->J5->Location = System::Drawing::Point(163, 363);
			this->J5->Name = L"J5";
			this->J5->Size = System::Drawing::Size(40, 40);
			this->J5->TabIndex = 94;
			this->J5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->J5->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->J5->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->J5->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// J4
			// 
			this->J4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->J4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->J4->Location = System::Drawing::Point(123, 363);
			this->J4->Name = L"J4";
			this->J4->Size = System::Drawing::Size(40, 40);
			this->J4->TabIndex = 93;
			this->J4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->J4->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->J4->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->J4->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// J3
			// 
			this->J3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->J3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->J3->Location = System::Drawing::Point(83, 363);
			this->J3->Name = L"J3";
			this->J3->Size = System::Drawing::Size(40, 40);
			this->J3->TabIndex = 92;
			this->J3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->J3->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->J3->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->J3->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// J2
			// 
			this->J2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->J2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->J2->Location = System::Drawing::Point(43, 363);
			this->J2->Name = L"J2";
			this->J2->Size = System::Drawing::Size(40, 40);
			this->J2->TabIndex = 91;
			this->J2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->J2->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->J2->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->J2->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// J1
			// 
			this->J1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->J1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->J1->Location = System::Drawing::Point(3, 363);
			this->J1->Name = L"J1";
			this->J1->Size = System::Drawing::Size(40, 40);
			this->J1->TabIndex = 90;
			this->J1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->J1->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->J1->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->J1->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// I10
			// 
			this->I10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->I10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I10->Location = System::Drawing::Point(363, 323);
			this->I10->Name = L"I10";
			this->I10->Size = System::Drawing::Size(40, 40);
			this->I10->TabIndex = 89;
			this->I10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->I10->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->I10->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->I10->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// I9
			// 
			this->I9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->I9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I9->Location = System::Drawing::Point(323, 323);
			this->I9->Name = L"I9";
			this->I9->Size = System::Drawing::Size(40, 40);
			this->I9->TabIndex = 88;
			this->I9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->I9->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->I9->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->I9->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// I8
			// 
			this->I8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->I8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I8->Location = System::Drawing::Point(283, 323);
			this->I8->Name = L"I8";
			this->I8->Size = System::Drawing::Size(40, 40);
			this->I8->TabIndex = 87;
			this->I8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->I8->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->I8->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->I8->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// I7
			// 
			this->I7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->I7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I7->Location = System::Drawing::Point(243, 323);
			this->I7->Name = L"I7";
			this->I7->Size = System::Drawing::Size(40, 40);
			this->I7->TabIndex = 86;
			this->I7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->I7->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->I7->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->I7->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// I6
			// 
			this->I6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->I6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I6->Location = System::Drawing::Point(203, 323);
			this->I6->Name = L"I6";
			this->I6->Size = System::Drawing::Size(40, 40);
			this->I6->TabIndex = 85;
			this->I6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->I6->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->I6->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->I6->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// I5
			// 
			this->I5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->I5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I5->Location = System::Drawing::Point(163, 323);
			this->I5->Name = L"I5";
			this->I5->Size = System::Drawing::Size(40, 40);
			this->I5->TabIndex = 84;
			this->I5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->I5->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->I5->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->I5->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// I4
			// 
			this->I4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->I4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I4->Location = System::Drawing::Point(123, 323);
			this->I4->Name = L"I4";
			this->I4->Size = System::Drawing::Size(40, 40);
			this->I4->TabIndex = 83;
			this->I4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->I4->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->I4->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->I4->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// I3
			// 
			this->I3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->I3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I3->Location = System::Drawing::Point(83, 323);
			this->I3->Name = L"I3";
			this->I3->Size = System::Drawing::Size(40, 40);
			this->I3->TabIndex = 82;
			this->I3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->I3->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->I3->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->I3->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// I2
			// 
			this->I2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->I2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I2->Location = System::Drawing::Point(43, 323);
			this->I2->Name = L"I2";
			this->I2->Size = System::Drawing::Size(40, 40);
			this->I2->TabIndex = 81;
			this->I2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->I2->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->I2->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->I2->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// I1
			// 
			this->I1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->I1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I1->Location = System::Drawing::Point(3, 323);
			this->I1->Name = L"I1";
			this->I1->Size = System::Drawing::Size(40, 40);
			this->I1->TabIndex = 80;
			this->I1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->I1->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->I1->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->I1->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// H10
			// 
			this->H10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->H10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->H10->Location = System::Drawing::Point(363, 283);
			this->H10->Name = L"H10";
			this->H10->Size = System::Drawing::Size(40, 40);
			this->H10->TabIndex = 79;
			this->H10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->H10->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->H10->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->H10->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// H9
			// 
			this->H9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->H9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->H9->Location = System::Drawing::Point(323, 283);
			this->H9->Name = L"H9";
			this->H9->Size = System::Drawing::Size(40, 40);
			this->H9->TabIndex = 78;
			this->H9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->H9->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->H9->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->H9->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// H8
			// 
			this->H8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->H8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->H8->Location = System::Drawing::Point(283, 283);
			this->H8->Name = L"H8";
			this->H8->Size = System::Drawing::Size(40, 40);
			this->H8->TabIndex = 77;
			this->H8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->H8->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->H8->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->H8->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// H7
			// 
			this->H7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->H7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->H7->Location = System::Drawing::Point(243, 283);
			this->H7->Name = L"H7";
			this->H7->Size = System::Drawing::Size(40, 40);
			this->H7->TabIndex = 76;
			this->H7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->H7->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->H7->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->H7->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// H6
			// 
			this->H6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->H6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->H6->Location = System::Drawing::Point(203, 283);
			this->H6->Name = L"H6";
			this->H6->Size = System::Drawing::Size(40, 40);
			this->H6->TabIndex = 75;
			this->H6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->H6->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->H6->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->H6->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// H5
			// 
			this->H5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->H5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->H5->Location = System::Drawing::Point(163, 283);
			this->H5->Name = L"H5";
			this->H5->Size = System::Drawing::Size(40, 40);
			this->H5->TabIndex = 74;
			this->H5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->H5->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->H5->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->H5->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// H4
			// 
			this->H4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->H4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->H4->Location = System::Drawing::Point(123, 283);
			this->H4->Name = L"H4";
			this->H4->Size = System::Drawing::Size(40, 40);
			this->H4->TabIndex = 73;
			this->H4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->H4->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->H4->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->H4->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// H3
			// 
			this->H3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->H3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->H3->Location = System::Drawing::Point(83, 283);
			this->H3->Name = L"H3";
			this->H3->Size = System::Drawing::Size(40, 40);
			this->H3->TabIndex = 72;
			this->H3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->H3->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->H3->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->H3->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// H2
			// 
			this->H2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->H2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->H2->Location = System::Drawing::Point(43, 283);
			this->H2->Name = L"H2";
			this->H2->Size = System::Drawing::Size(40, 40);
			this->H2->TabIndex = 71;
			this->H2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->H2->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->H2->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->H2->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// H1
			// 
			this->H1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->H1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->H1->Location = System::Drawing::Point(3, 283);
			this->H1->Name = L"H1";
			this->H1->Size = System::Drawing::Size(40, 40);
			this->H1->TabIndex = 70;
			this->H1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->H1->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->H1->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->H1->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// G10
			// 
			this->G10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->G10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->G10->Location = System::Drawing::Point(363, 243);
			this->G10->Name = L"G10";
			this->G10->Size = System::Drawing::Size(40, 40);
			this->G10->TabIndex = 69;
			this->G10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->G10->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->G10->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->G10->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// G9
			// 
			this->G9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->G9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->G9->Location = System::Drawing::Point(323, 243);
			this->G9->Name = L"G9";
			this->G9->Size = System::Drawing::Size(40, 40);
			this->G9->TabIndex = 68;
			this->G9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->G9->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->G9->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->G9->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// G8
			// 
			this->G8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->G8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->G8->Location = System::Drawing::Point(283, 243);
			this->G8->Name = L"G8";
			this->G8->Size = System::Drawing::Size(40, 40);
			this->G8->TabIndex = 67;
			this->G8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->G8->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->G8->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->G8->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// G7
			// 
			this->G7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->G7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->G7->Location = System::Drawing::Point(243, 243);
			this->G7->Name = L"G7";
			this->G7->Size = System::Drawing::Size(40, 40);
			this->G7->TabIndex = 66;
			this->G7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->G7->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->G7->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->G7->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// G6
			// 
			this->G6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->G6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->G6->Location = System::Drawing::Point(203, 243);
			this->G6->Name = L"G6";
			this->G6->Size = System::Drawing::Size(40, 40);
			this->G6->TabIndex = 65;
			this->G6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->G6->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->G6->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->G6->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// G5
			// 
			this->G5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->G5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->G5->Location = System::Drawing::Point(163, 243);
			this->G5->Name = L"G5";
			this->G5->Size = System::Drawing::Size(40, 40);
			this->G5->TabIndex = 64;
			this->G5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->G5->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->G5->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->G5->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// G4
			// 
			this->G4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->G4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->G4->Location = System::Drawing::Point(123, 243);
			this->G4->Name = L"G4";
			this->G4->Size = System::Drawing::Size(40, 40);
			this->G4->TabIndex = 63;
			this->G4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->G4->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->G4->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->G4->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// G3
			// 
			this->G3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->G3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->G3->Location = System::Drawing::Point(83, 243);
			this->G3->Name = L"G3";
			this->G3->Size = System::Drawing::Size(40, 40);
			this->G3->TabIndex = 62;
			this->G3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->G3->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->G3->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->G3->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// G2
			// 
			this->G2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->G2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->G2->Location = System::Drawing::Point(43, 243);
			this->G2->Name = L"G2";
			this->G2->Size = System::Drawing::Size(40, 40);
			this->G2->TabIndex = 61;
			this->G2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->G2->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->G2->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->G2->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// G1
			// 
			this->G1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->G1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->G1->Location = System::Drawing::Point(3, 243);
			this->G1->Name = L"G1";
			this->G1->Size = System::Drawing::Size(40, 40);
			this->G1->TabIndex = 60;
			this->G1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->G1->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->G1->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->G1->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// F10
			// 
			this->F10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->F10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->F10->Location = System::Drawing::Point(363, 203);
			this->F10->Name = L"F10";
			this->F10->Size = System::Drawing::Size(40, 40);
			this->F10->TabIndex = 59;
			this->F10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->F10->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->F10->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->F10->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// F9
			// 
			this->F9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->F9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->F9->Location = System::Drawing::Point(323, 203);
			this->F9->Name = L"F9";
			this->F9->Size = System::Drawing::Size(40, 40);
			this->F9->TabIndex = 58;
			this->F9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->F9->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->F9->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->F9->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// F8
			// 
			this->F8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->F8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->F8->Location = System::Drawing::Point(283, 203);
			this->F8->Name = L"F8";
			this->F8->Size = System::Drawing::Size(40, 40);
			this->F8->TabIndex = 57;
			this->F8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->F8->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->F8->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->F8->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// F7
			// 
			this->F7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->F7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->F7->Location = System::Drawing::Point(243, 203);
			this->F7->Name = L"F7";
			this->F7->Size = System::Drawing::Size(40, 40);
			this->F7->TabIndex = 56;
			this->F7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->F7->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->F7->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->F7->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// F6
			// 
			this->F6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->F6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->F6->Location = System::Drawing::Point(203, 203);
			this->F6->Name = L"F6";
			this->F6->Size = System::Drawing::Size(40, 40);
			this->F6->TabIndex = 55;
			this->F6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->F6->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->F6->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->F6->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// F5
			// 
			this->F5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->F5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->F5->Location = System::Drawing::Point(163, 203);
			this->F5->Name = L"F5";
			this->F5->Size = System::Drawing::Size(40, 40);
			this->F5->TabIndex = 54;
			this->F5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->F5->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->F5->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->F5->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// F4
			// 
			this->F4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->F4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->F4->Location = System::Drawing::Point(123, 203);
			this->F4->Name = L"F4";
			this->F4->Size = System::Drawing::Size(40, 40);
			this->F4->TabIndex = 53;
			this->F4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->F4->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->F4->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->F4->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// F3
			// 
			this->F3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->F3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->F3->Location = System::Drawing::Point(83, 203);
			this->F3->Name = L"F3";
			this->F3->Size = System::Drawing::Size(40, 40);
			this->F3->TabIndex = 52;
			this->F3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->F3->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->F3->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->F3->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// F2
			// 
			this->F2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->F2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->F2->Location = System::Drawing::Point(43, 203);
			this->F2->Name = L"F2";
			this->F2->Size = System::Drawing::Size(40, 40);
			this->F2->TabIndex = 51;
			this->F2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->F2->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->F2->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->F2->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// F1
			// 
			this->F1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->F1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->F1->Location = System::Drawing::Point(3, 203);
			this->F1->Name = L"F1";
			this->F1->Size = System::Drawing::Size(40, 40);
			this->F1->TabIndex = 50;
			this->F1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->F1->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->F1->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->F1->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// E10
			// 
			this->E10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->E10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->E10->Location = System::Drawing::Point(363, 163);
			this->E10->Name = L"E10";
			this->E10->Size = System::Drawing::Size(40, 40);
			this->E10->TabIndex = 49;
			this->E10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->E10->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->E10->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->E10->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// E9
			// 
			this->E9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->E9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->E9->Location = System::Drawing::Point(323, 163);
			this->E9->Name = L"E9";
			this->E9->Size = System::Drawing::Size(40, 40);
			this->E9->TabIndex = 48;
			this->E9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->E9->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->E9->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->E9->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// E8
			// 
			this->E8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->E8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->E8->Location = System::Drawing::Point(283, 163);
			this->E8->Name = L"E8";
			this->E8->Size = System::Drawing::Size(40, 40);
			this->E8->TabIndex = 47;
			this->E8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->E8->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->E8->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->E8->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// E7
			// 
			this->E7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->E7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->E7->Location = System::Drawing::Point(243, 163);
			this->E7->Name = L"E7";
			this->E7->Size = System::Drawing::Size(40, 40);
			this->E7->TabIndex = 46;
			this->E7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->E7->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->E7->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->E7->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// E6
			// 
			this->E6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->E6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->E6->Location = System::Drawing::Point(203, 163);
			this->E6->Name = L"E6";
			this->E6->Size = System::Drawing::Size(40, 40);
			this->E6->TabIndex = 45;
			this->E6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->E6->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->E6->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->E6->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// E5
			// 
			this->E5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->E5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->E5->Location = System::Drawing::Point(163, 163);
			this->E5->Name = L"E5";
			this->E5->Size = System::Drawing::Size(40, 40);
			this->E5->TabIndex = 44;
			this->E5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->E5->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->E5->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->E5->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// E4
			// 
			this->E4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->E4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->E4->Location = System::Drawing::Point(123, 163);
			this->E4->Name = L"E4";
			this->E4->Size = System::Drawing::Size(40, 40);
			this->E4->TabIndex = 43;
			this->E4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->E4->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->E4->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->E4->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// E3
			// 
			this->E3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->E3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->E3->Location = System::Drawing::Point(83, 163);
			this->E3->Name = L"E3";
			this->E3->Size = System::Drawing::Size(40, 40);
			this->E3->TabIndex = 42;
			this->E3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->E3->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->E3->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->E3->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// E2
			// 
			this->E2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->E2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->E2->Location = System::Drawing::Point(43, 163);
			this->E2->Name = L"E2";
			this->E2->Size = System::Drawing::Size(40, 40);
			this->E2->TabIndex = 41;
			this->E2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->E2->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->E2->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->E2->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// E1
			// 
			this->E1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->E1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->E1->Location = System::Drawing::Point(3, 163);
			this->E1->Name = L"E1";
			this->E1->Size = System::Drawing::Size(40, 40);
			this->E1->TabIndex = 40;
			this->E1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->E1->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->E1->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->E1->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// D10
			// 
			this->D10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->D10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D10->Location = System::Drawing::Point(363, 123);
			this->D10->Name = L"D10";
			this->D10->Size = System::Drawing::Size(40, 40);
			this->D10->TabIndex = 39;
			this->D10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->D10->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->D10->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->D10->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// D9
			// 
			this->D9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->D9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D9->Location = System::Drawing::Point(323, 123);
			this->D9->Name = L"D9";
			this->D9->Size = System::Drawing::Size(40, 40);
			this->D9->TabIndex = 38;
			this->D9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->D9->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->D9->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->D9->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// D8
			// 
			this->D8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->D8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D8->Location = System::Drawing::Point(283, 123);
			this->D8->Name = L"D8";
			this->D8->Size = System::Drawing::Size(40, 40);
			this->D8->TabIndex = 37;
			this->D8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->D8->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->D8->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->D8->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// D7
			// 
			this->D7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->D7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D7->Location = System::Drawing::Point(243, 123);
			this->D7->Name = L"D7";
			this->D7->Size = System::Drawing::Size(40, 40);
			this->D7->TabIndex = 36;
			this->D7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->D7->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->D7->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->D7->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// D6
			// 
			this->D6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->D6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D6->Location = System::Drawing::Point(203, 123);
			this->D6->Name = L"D6";
			this->D6->Size = System::Drawing::Size(40, 40);
			this->D6->TabIndex = 35;
			this->D6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->D6->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->D6->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->D6->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// D5
			// 
			this->D5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->D5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D5->Location = System::Drawing::Point(163, 123);
			this->D5->Name = L"D5";
			this->D5->Size = System::Drawing::Size(40, 40);
			this->D5->TabIndex = 34;
			this->D5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->D5->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->D5->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->D5->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// D4
			// 
			this->D4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->D4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D4->Location = System::Drawing::Point(123, 123);
			this->D4->Name = L"D4";
			this->D4->Size = System::Drawing::Size(40, 40);
			this->D4->TabIndex = 33;
			this->D4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->D4->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->D4->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->D4->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// D3
			// 
			this->D3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->D3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D3->Location = System::Drawing::Point(83, 123);
			this->D3->Name = L"D3";
			this->D3->Size = System::Drawing::Size(40, 40);
			this->D3->TabIndex = 32;
			this->D3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->D3->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->D3->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->D3->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// D2
			// 
			this->D2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->D2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D2->Location = System::Drawing::Point(43, 123);
			this->D2->Name = L"D2";
			this->D2->Size = System::Drawing::Size(40, 40);
			this->D2->TabIndex = 31;
			this->D2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->D2->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->D2->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->D2->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// D1
			// 
			this->D1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->D1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D1->Location = System::Drawing::Point(3, 123);
			this->D1->Name = L"D1";
			this->D1->Size = System::Drawing::Size(40, 40);
			this->D1->TabIndex = 30;
			this->D1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->D1->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->D1->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->D1->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// C10
			// 
			this->C10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->C10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->C10->Location = System::Drawing::Point(363, 83);
			this->C10->Name = L"C10";
			this->C10->Size = System::Drawing::Size(40, 40);
			this->C10->TabIndex = 29;
			this->C10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->C10->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->C10->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->C10->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// C9
			// 
			this->C9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->C9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->C9->Location = System::Drawing::Point(323, 83);
			this->C9->Name = L"C9";
			this->C9->Size = System::Drawing::Size(40, 40);
			this->C9->TabIndex = 28;
			this->C9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->C9->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->C9->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->C9->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// C8
			// 
			this->C8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->C8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->C8->Location = System::Drawing::Point(283, 83);
			this->C8->Name = L"C8";
			this->C8->Size = System::Drawing::Size(40, 40);
			this->C8->TabIndex = 27;
			this->C8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->C8->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->C8->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->C8->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// C7
			// 
			this->C7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->C7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->C7->Location = System::Drawing::Point(243, 83);
			this->C7->Name = L"C7";
			this->C7->Size = System::Drawing::Size(40, 40);
			this->C7->TabIndex = 26;
			this->C7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->C7->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->C7->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->C7->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// C6
			// 
			this->C6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->C6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->C6->Location = System::Drawing::Point(203, 83);
			this->C6->Name = L"C6";
			this->C6->Size = System::Drawing::Size(40, 40);
			this->C6->TabIndex = 25;
			this->C6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->C6->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->C6->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->C6->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// C5
			// 
			this->C5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->C5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->C5->Location = System::Drawing::Point(163, 83);
			this->C5->Name = L"C5";
			this->C5->Size = System::Drawing::Size(40, 40);
			this->C5->TabIndex = 24;
			this->C5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->C5->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->C5->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->C5->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// C4
			// 
			this->C4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->C4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->C4->Location = System::Drawing::Point(123, 83);
			this->C4->Name = L"C4";
			this->C4->Size = System::Drawing::Size(40, 40);
			this->C4->TabIndex = 23;
			this->C4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->C4->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->C4->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->C4->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// C3
			// 
			this->C3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->C3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->C3->Location = System::Drawing::Point(83, 83);
			this->C3->Name = L"C3";
			this->C3->Size = System::Drawing::Size(40, 40);
			this->C3->TabIndex = 22;
			this->C3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->C3->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->C3->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->C3->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// C2
			// 
			this->C2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->C2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->C2->Location = System::Drawing::Point(43, 83);
			this->C2->Name = L"C2";
			this->C2->Size = System::Drawing::Size(40, 40);
			this->C2->TabIndex = 21;
			this->C2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->C2->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->C2->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->C2->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// C1
			// 
			this->C1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->C1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->C1->Location = System::Drawing::Point(3, 83);
			this->C1->Name = L"C1";
			this->C1->Size = System::Drawing::Size(40, 40);
			this->C1->TabIndex = 20;
			this->C1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->C1->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->C1->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->C1->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// B10
			// 
			this->B10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->B10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B10->Location = System::Drawing::Point(363, 43);
			this->B10->Name = L"B10";
			this->B10->Size = System::Drawing::Size(40, 40);
			this->B10->TabIndex = 19;
			this->B10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->B10->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->B10->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->B10->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// B9
			// 
			this->B9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->B9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B9->Location = System::Drawing::Point(323, 43);
			this->B9->Name = L"B9";
			this->B9->Size = System::Drawing::Size(40, 40);
			this->B9->TabIndex = 18;
			this->B9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->B9->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->B9->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->B9->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// B8
			// 
			this->B8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->B8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B8->Location = System::Drawing::Point(283, 43);
			this->B8->Name = L"B8";
			this->B8->Size = System::Drawing::Size(40, 40);
			this->B8->TabIndex = 17;
			this->B8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->B8->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->B8->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->B8->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// B7
			// 
			this->B7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->B7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B7->Location = System::Drawing::Point(243, 43);
			this->B7->Name = L"B7";
			this->B7->Size = System::Drawing::Size(40, 40);
			this->B7->TabIndex = 16;
			this->B7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->B7->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->B7->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->B7->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// B6
			// 
			this->B6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->B6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B6->Location = System::Drawing::Point(203, 43);
			this->B6->Name = L"B6";
			this->B6->Size = System::Drawing::Size(40, 40);
			this->B6->TabIndex = 15;
			this->B6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->B6->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->B6->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->B6->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// B5
			// 
			this->B5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->B5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B5->Location = System::Drawing::Point(163, 43);
			this->B5->Name = L"B5";
			this->B5->Size = System::Drawing::Size(40, 40);
			this->B5->TabIndex = 14;
			this->B5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->B5->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->B5->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->B5->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// B4
			// 
			this->B4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->B4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B4->Location = System::Drawing::Point(123, 43);
			this->B4->Name = L"B4";
			this->B4->Size = System::Drawing::Size(40, 40);
			this->B4->TabIndex = 13;
			this->B4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->B4->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->B4->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->B4->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// B3
			// 
			this->B3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->B3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B3->Location = System::Drawing::Point(83, 43);
			this->B3->Name = L"B3";
			this->B3->Size = System::Drawing::Size(40, 40);
			this->B3->TabIndex = 12;
			this->B3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->B3->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->B3->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->B3->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// B2
			// 
			this->B2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->B2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B2->Location = System::Drawing::Point(43, 43);
			this->B2->Name = L"B2";
			this->B2->Size = System::Drawing::Size(40, 40);
			this->B2->TabIndex = 11;
			this->B2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->B2->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->B2->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->B2->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// B1
			// 
			this->B1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->B1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->B1->Location = System::Drawing::Point(3, 43);
			this->B1->Name = L"B1";
			this->B1->Size = System::Drawing::Size(40, 40);
			this->B1->TabIndex = 10;
			this->B1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->B1->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->B1->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->B1->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// A10
			// 
			this->A10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->A10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->A10->Location = System::Drawing::Point(363, 3);
			this->A10->Name = L"A10";
			this->A10->Size = System::Drawing::Size(40, 40);
			this->A10->TabIndex = 9;
			this->A10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->A10->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->A10->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->A10->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// A9
			// 
			this->A9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->A9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->A9->Location = System::Drawing::Point(323, 3);
			this->A9->Name = L"A9";
			this->A9->Size = System::Drawing::Size(40, 40);
			this->A9->TabIndex = 8;
			this->A9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->A9->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->A9->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->A9->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// A8
			// 
			this->A8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->A8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->A8->Location = System::Drawing::Point(283, 3);
			this->A8->Name = L"A8";
			this->A8->Size = System::Drawing::Size(40, 40);
			this->A8->TabIndex = 7;
			this->A8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->A8->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->A8->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->A8->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// A7
			// 
			this->A7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->A7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->A7->Location = System::Drawing::Point(243, 3);
			this->A7->Name = L"A7";
			this->A7->Size = System::Drawing::Size(40, 40);
			this->A7->TabIndex = 6;
			this->A7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->A7->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->A7->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->A7->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// A6
			// 
			this->A6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->A6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->A6->Location = System::Drawing::Point(203, 3);
			this->A6->Name = L"A6";
			this->A6->Size = System::Drawing::Size(40, 40);
			this->A6->TabIndex = 5;
			this->A6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->A6->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->A6->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->A6->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// A5
			// 
			this->A5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->A5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->A5->Location = System::Drawing::Point(163, 3);
			this->A5->Name = L"A5";
			this->A5->Size = System::Drawing::Size(40, 40);
			this->A5->TabIndex = 4;
			this->A5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->A5->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->A5->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->A5->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// A4
			// 
			this->A4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->A4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->A4->Location = System::Drawing::Point(123, 3);
			this->A4->Name = L"A4";
			this->A4->Size = System::Drawing::Size(40, 40);
			this->A4->TabIndex = 3;
			this->A4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->A4->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->A4->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->A4->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// A3
			// 
			this->A3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->A3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->A3->Location = System::Drawing::Point(83, 3);
			this->A3->Name = L"A3";
			this->A3->Size = System::Drawing::Size(40, 40);
			this->A3->TabIndex = 2;
			this->A3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->A3->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->A3->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->A3->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// A2
			// 
			this->A2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->A2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->A2->Location = System::Drawing::Point(43, 3);
			this->A2->Name = L"A2";
			this->A2->Size = System::Drawing::Size(40, 40);
			this->A2->TabIndex = 1;
			this->A2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->A2->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->A2->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->A2->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// A1
			// 
			this->A1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->A1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->A1->Location = System::Drawing::Point(3, 3);
			this->A1->Name = L"A1";
			this->A1->Size = System::Drawing::Size(40, 40);
			this->A1->TabIndex = 0;
			this->A1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->A1->Click += gcnew System::EventHandler(this, &BattleshipForm::slotClick);
			this->A1->MouseEnter += gcnew System::EventHandler(this, &BattleshipForm::slotMousEnter);
			this->A1->MouseLeave += gcnew System::EventHandler(this, &BattleshipForm::slotMouseLeave);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label20->Location = System::Drawing::Point(404, 9);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(21, 15);
			this->label20->TabIndex = 19;
			this->label20->Text = L"10";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label19->Location = System::Drawing::Point(365, 9);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(15, 15);
			this->label19->TabIndex = 18;
			this->label19->Text = L"9";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label18->Location = System::Drawing::Point(326, 9);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(15, 15);
			this->label18->TabIndex = 17;
			this->label18->Text = L"8";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label17->Location = System::Drawing::Point(287, 9);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(15, 15);
			this->label17->TabIndex = 16;
			this->label17->Text = L"7";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label16->Location = System::Drawing::Point(248, 9);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(15, 15);
			this->label16->TabIndex = 15;
			this->label16->Text = L"6";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label15->Location = System::Drawing::Point(209, 9);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(15, 15);
			this->label15->TabIndex = 14;
			this->label15->Text = L"5";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label14->Location = System::Drawing::Point(170, 9);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(15, 15);
			this->label14->TabIndex = 13;
			this->label14->Text = L"4";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label13->Location = System::Drawing::Point(131, 9);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(15, 15);
			this->label13->TabIndex = 12;
			this->label13->Text = L"3";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label12->Location = System::Drawing::Point(92, 9);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(15, 15);
			this->label12->TabIndex = 11;
			this->label12->Text = L"2";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label11->Location = System::Drawing::Point(53, 9);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(15, 15);
			this->label11->TabIndex = 10;
			this->label11->Text = L"1";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label10->Location = System::Drawing::Point(9, 402);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(14, 15);
			this->label10->TabIndex = 9;
			this->label10->Text = L"J";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label9->Location = System::Drawing::Point(10, 362);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(12, 15);
			this->label9->TabIndex = 8;
			this->label9->Text = L"I";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label8->Location = System::Drawing::Point(8, 322);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 15);
			this->label8->TabIndex = 7;
			this->label8->Text = L"H";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label7->Location = System::Drawing::Point(8, 282);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(17, 15);
			this->label7->TabIndex = 6;
			this->label7->Text = L"G";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->Location = System::Drawing::Point(9, 242);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(15, 15);
			this->label6->TabIndex = 5;
			this->label6->Text = L"F";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->Location = System::Drawing::Point(8, 202);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(16, 15);
			this->label5->TabIndex = 4;
			this->label5->Text = L"E";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->Location = System::Drawing::Point(8, 162);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 15);
			this->label4->TabIndex = 3;
			this->label4->Text = L"D";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->Location = System::Drawing::Point(8, 122);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(16, 15);
			this->label3->TabIndex = 2;
			this->label3->Text = L"C";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Location = System::Drawing::Point(8, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"B";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Location = System::Drawing::Point(8, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"A";
			// 
			// lblGameMaster
			// 
			this->lblGameMaster->AutoSize = true;
			this->lblGameMaster->Location = System::Drawing::Point(492, 21);
			this->lblGameMaster->Name = L"lblGameMaster";
			this->lblGameMaster->Size = System::Drawing::Size(73, 13);
			this->lblGameMaster->TabIndex = 1;
			this->lblGameMaster->Text = L"Game Master:";
			// 
			// gbSetup
			// 
			this->gbSetup->Controls->Add(this->Battleships);
			this->gbSetup->Controls->Add(this->gbOrientation);
			this->gbSetup->Location = System::Drawing::Point(492, 182);
			this->gbSetup->Name = L"gbSetup";
			this->gbSetup->Size = System::Drawing::Size(252, 140);
			this->gbSetup->TabIndex = 3;
			this->gbSetup->TabStop = false;
			// 
			// Battleships
			// 
			this->Battleships->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Battleships->FormattingEnabled = true;
			this->Battleships->ItemHeight = 20;
			this->Battleships->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Carrier", L"Battleship", L"Cruiser", L"Submarine",
					L"Destroyer"
			});
			this->Battleships->SelectedIndex = 0;
			this->Battleships->Location = System::Drawing::Point(6, 19);
			this->Battleships->Name = L"Battleships";
			this->Battleships->Size = System::Drawing::Size(138, 104);
			this->Battleships->TabIndex = 3;
			// 
			// gbOrientation
			// 
			this->gbOrientation->Controls->Add(this->rbVertical);
			this->gbOrientation->Controls->Add(this->rbHorizontal);
			this->gbOrientation->Location = System::Drawing::Point(163, 20);
			this->gbOrientation->Name = L"gbOrientation";
			this->gbOrientation->Size = System::Drawing::Size(83, 65);
			this->gbOrientation->TabIndex = 2;
			this->gbOrientation->TabStop = false;
			this->gbOrientation->Text = L"Orientation";
			// 
			// rbVertical
			// 
			this->rbVertical->AutoSize = true;
			this->rbVertical->Location = System::Drawing::Point(6, 38);
			this->rbVertical->Name = L"rbVertical";
			this->rbVertical->Size = System::Drawing::Size(60, 17);
			this->rbVertical->TabIndex = 1;
			this->rbVertical->Text = L"Vertical";
			this->rbVertical->UseVisualStyleBackColor = true;
			// 
			// rbHorizontal
			// 
			this->rbHorizontal->AutoSize = true;
			this->rbHorizontal->Checked = true;
			this->rbHorizontal->Location = System::Drawing::Point(6, 15);
			this->rbHorizontal->Name = L"rbHorizontal";
			this->rbHorizontal->Size = System::Drawing::Size(72, 17);
			this->rbHorizontal->TabIndex = 0;
			this->rbHorizontal->TabStop = true;
			this->rbHorizontal->Text = L"Horizontal";
			this->rbHorizontal->UseVisualStyleBackColor = true;
			// 
			// btnReady
			// 
			this->btnReady->Enabled = false;
			this->btnReady->Location = System::Drawing::Point(498, 374);
			this->btnReady->Name = L"btnReady";
			this->btnReady->Size = System::Drawing::Size(75, 23);
			this->btnReady->TabIndex = 4;
			this->btnReady->Text = L"Ready";
			this->btnReady->UseVisualStyleBackColor = true;
			this->btnReady->Click += gcnew System::EventHandler(this, &BattleshipForm::readyClick);
			// 
			// btnReset
			// 
			this->btnReset->Enabled = false;
			this->btnReset->Location = System::Drawing::Point(655, 374);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(75, 23);
			this->btnReset->TabIndex = 5;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Click += gcnew System::EventHandler(this, &BattleshipForm::resetClick);
			// 
			// txtOutput
			// 
			this->txtOutput->Location = System::Drawing::Point(498, 38);
			this->txtOutput->Multiline = true;
			this->txtOutput->Name = L"txtOutput";
			this->txtOutput->ReadOnly = true;
			this->txtOutput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtOutput->Size = System::Drawing::Size(252, 133);
			this->txtOutput->TabIndex = 6;
			// 
			// BattleshipForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(777, 477);
			this->Controls->Add(this->txtOutput);
			this->Controls->Add(this->btnReset);
			this->Controls->Add(this->btnReady);
			this->Controls->Add(this->gbSetup);
			this->Controls->Add(this->lblGameMaster);
			this->Controls->Add(this->panel1);
			this->Name = L"BattleshipForm";
			this->Text = L"Battleship";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->gbSetup->ResumeLayout(false);
			this->gbOrientation->ResumeLayout(false);
			this->gbOrientation->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void slotMousEnter(System::Object^ sender, System::EventArgs^ e)
{
	Label^ label = (Label^)sender;
	//label->BackColor = System::Drawing::Color::LightPink;
	
	// Test to see if I can highlight slot adjacent to the sender
	/*String^ name = label->Name;
	wchar_t c = name[1];
	c++;
	String^ f = "" + name[0] + c;
	cli::array<Control^, 1>^ results = Controls->Find(f, true);
	results[0]->BackColor = System::Drawing::Color::LightPink;*/

	// This function only highlight slots while the player is still setting up their game board
	// otherwise it doesn't do anything.
	if (inSetupMode)
	{
		int noSlotToFind = shipSize(); // The number of slots to find depend of the ship that user has selected

		// Get the slots whose color needs to be changed to indicate them being highlighted
		// Pass in the number of slots that to find, the orientation, and the name of the slot that is being pointed to by the mouse
		cli::array<Control^, 1>^ slots = findSlots(noSlotToFind, rbHorizontal->Checked, label->Name);
		for (int i = 0; i < slots->Length; i++)
		{
			slots[i]->BackColor = System::Drawing::Color::LightPink;
		}
	}
	else if (attackMode)
	{
		// The player is thinking about attacking the selected slot
		label->BackColor = System::Drawing::Color::LightPink;
	}
}
private: System::Void slotMouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	Label^ label = (Label^)sender;
	//label->BackColor = SystemColors::Control;

	// Test to see if I can turn the slot adjacent to the sender back to the original color
	/*String^ name = label->Name;
	wchar_t c = name[1];
	c++;
	String^ f = "" + name[0] + c;
	cli::array<Control^, 1>^ results = Controls->Find(f, true);
	results[0]->BackColor = SystemColors::Control;*/

	// This function should only have to de-highlight the slots while in setup mode
	if (inSetupMode)
	{
		int noSlotToFind = shipSize(); // The number of slots to find depend of the ship that user has selected

		// Get the slots that need to be changed back to the original color again
		// Pass in the number of slots that to find, the orientation, and the name of the slot that is being pointed to by the mouse
		cli::array<Control^, 1>^ slots = findSlots(noSlotToFind, rbHorizontal->Checked, label->Name);
		for (int i = 0; i < slots->Length; i++)
		{
			slots[i]->BackColor = SystemColors::Control; // Change back to the original color
		}
	}
	else if (attackMode)
	{
		label->BackColor = SystemColors::Control;
	}
}

//	This function returns the number of slots that the selected ship in the ListBox occupies
private: int shipSize()
{
	String^ selectedShip = Battleships->GetItemText(Battleships->SelectedItem);
	// Determine which ship is selected in the Battleship ListBox
	if (selectedShip == "Carrier")
	{
		return 5; // Carrier
	}
	else if (selectedShip == "Battleship")
	{
		return 4; // Battleship
	}
	else if (selectedShip == "Destroyer")
	{
		return 2; // Destroyer
	}
	
	return 3; // Cruiser or Submarine
}

//	This function takes in the size, and the orientation of the ship that the player going to place on the grid
//	and also the slot that is being pointed at by the mouse. Using this provided information, this function will
//	return an cli::array containing the slots that the ship would occupying with the pointedSlot being the middle.
private: cli::array<Control^, 1>^ findSlots(int shipSize, bool horsOrientation, String^ pointedSlot)
{
	cli::array<Control^, 1>^ slots = gcnew cli::array<Control^, 1>(shipSize);

	// Check if the ship is to be placed horizontally or vertically
	if (horsOrientation)
	{
		slots = horizontallyNearSlots(shipSize, pointedSlot); // Find the slots that are horizontally near to the pointed Slot
	}
	else
	{
		slots = verticallyNearSlots(shipSize, pointedSlot); // Find the slots that are vertically near to the pointed Slot
	}

	// Added the pointedSlot to the array too
	cli::array<Control^, 1>^ result = Controls->Find(pointedSlot, true); // Find the matching slot
	slots[shipSize - 1] = result[0]; // Add the slot to the array and increment the index for the next iteration
	//System::Array::Sort(slots); // Sort the array in ascending order

	return slots; // Return the filled array of slots
}

//	Find the slots that are horizontally near the slot that's pointed to by the mouse
private: cli::array<Control^, 1>^ horizontallyNearSlots(int shipSize, String^ pointedSlot)
{
	wchar_t c; // char to adjust to find additional slots; either the row or column
	cli::array<Control^, 1>^ slots = gcnew cli::array<Control^, 1>(shipSize);
	String^ slotToFind;
	int index = 0;
	int slotsNeeded = (shipSize - 1) / 2; // Number of slots find to the right of the pointedSlot

	if (pointedSlot->Length == 3)
	{
		c = ':'; // It's the 10th column but there's no character for 10; : is the character after 9
	}
	else
	{
		c = pointedSlot[1]; // Since the ship is horizontal, c will be the column
	}

	// Check to see if need to adjust the number of slots to find on the right side
	if ((c - '1') < (shipSize - 1 - slotsNeeded))
	{
		int adjustment = (shipSize - 1 - slotsNeeded) - (c - '1');
		slotsNeeded += adjustment;
	}

	// find the slots to the right of the pointedSlot
	for (int i = 0; i < slotsNeeded; i++)
	{
		c++; // move column to the right
		if (c > 58)
		{
			break; // Not possible to find any slots to the right as the pointedSlot is in the rightmost column already
		}
		if (c == 58)
		{
			// Since there's no character for 10, need to create string this way instead
			slotToFind = "" + pointedSlot[0] + "10"; // Name of the slot to look for in the ControlCollection
		}
		else
		{
			slotToFind = "" + pointedSlot[0] + c; // Name of the slot to look for in the ControlCollection
		}
		cli::array<Control^, 1>^ result = Controls->Find(slotToFind, true); // Find the matching slot
		slots[index++] = result[0]; // Add the slot to the array and increment the index for the next iteration
	}

	slotsNeeded = (shipSize - 1) - index; // Number of the slots to find the left of the pointedSlot
										  // Reset c to the column of the pointedSlot before looking for slots to the left of it
	if (pointedSlot->Length == 3)
	{
		c = ':';
	}
	else
	{
		c = pointedSlot[1];
	}

	// Find the slots to the left of the pointedSlot
	for (int i = 0; i < slotsNeeded; i++)
	{
		c--; // move column to the left
		if (c < '1')
		{
			break; // Not possible to find any slots to the left as the pointedSlot is in the leftmost column already
		}
		slotToFind = "" + pointedSlot[0] + c; // Name of the slot to look for in the ControlCollection
		cli::array<Control^, 1>^ result = Controls->Find(slotToFind, true); // Find the matching slot
		slots[index++] = result[0]; // Add the slot to the array and increment the index for the next iteration
	}

	return slots;
}

private: cli::array<Control^, 1>^ verticallyNearSlots(int shipSize, String^ pointedSlot)
{
	wchar_t c; // char to adjust to find additional slots; either the row or column
	cli::array<Control^, 1>^ slots = gcnew cli::array<Control^, 1>(shipSize);
	String^ slotToFind;
	int index = 0;
	int slotsNeeded = (shipSize - 1) / 2; // Number of slots find to the above the pointedSlot

	c = pointedSlot[0]; // Since the ship is vertical, c will be the row

	// Check to see if need to adjust the number of slots to find above
	if (('J' - c) < (shipSize - 1 - slotsNeeded))
	{
		int adjustment = (shipSize - 1 - slotsNeeded) - ('J' - c);
		slotsNeeded += adjustment;
	}

	// find the slots above the pointedSlot
	for (int i = 0; i < slotsNeeded; i++)
	{
		c--; // move up a row
		if (c < 'A')
		{
			break; // Not possible to find any slots above as the pointedSlot is in the topmost row already
		}
		// Name of the slot to look for in the ControlCollection
		if (pointedSlot->Length == 3)
		{
			slotToFind = "" + c + "10";
		}
		else
		{
			slotToFind = "" + c + pointedSlot[1];
		}
		cli::array<Control^, 1>^ result = Controls->Find(slotToFind, true); // Find the matching slot
		slots[index++] = result[0]; // Add the slot to the array and increment the index for the next iteration
	}

	slotsNeeded = (shipSize - 1) - index; // Number of the slots to find below the pointedSlot
	c = pointedSlot[0]; // Reset c to the row of the pointedSlot before looking for slots below it

	// Find the slots below the pointedSlot
	for (int i = 0; i < slotsNeeded; i++)
	{
		c++; // move down a row
		if (c > 'J')
		{
			break; // Not possible to find any slots below as the pointedSlot is in the bottommost row already
		}
		// Name of the slot to look for in the ControlCollection
		if (pointedSlot->Length == 3)
		{
			slotToFind = "" + c + "10";
		}
		else
		{
			slotToFind = "" + c + pointedSlot[1];
		}
		cli::array<Control^, 1>^ result = Controls->Find(slotToFind, true); // Find the matching slot
		slots[index++] = result[0]; // Add the slot to the array and increment the index for the next iteration
	}

	return slots;
}

//	This function checks if there will be any overlaps at the pointed location
private: bool anyOverlaps(cli::array<Control^, 1>^ slots)
{
	// Let's check each of the slot's Text property to make sure that it's empty, otherwise an overlap will occur
	for (int i = 0; i < slots->Length; i++)
	{
		if (slots[i]->Text != "")
		{
			outputLog("You cannot place the ship there as it will overlap.");
			return true; // The slot's text property isn't empty, an overlap will occur if the ship is place on this slot
		}
	}

	return false; // No overlaps, so it's safe to place the ship on the selected slots
}

//	This function is called whenever a slot is clicked on.
//	While the player is setting up the game board, the selected ship is placed on the board.
//	When this function is called when the player is attacking, it will inform the game master
//	of the attack and the handle the results of it
private: System::Void slotClick(System::Object^ sender, System::EventArgs^ e)
{
	Label^ label = (Label^)sender;

	if (inSetupMode)
	{
		int noSlotToFind = shipSize();
		String^ selectedShip = Battleships->GetItemText(Battleships->SelectedItem);
		cli::array<Control^, 1>^ slots = findSlots(noSlotToFind, rbHorizontal->Checked, label->Name);

		// TODO: Before moving on, we need to determine that the selected location is valid (no overlaps occur)
		if (!anyOverlaps(slots))
		{
			// Since there's no overlaps let's continue with placing the ship on the board
			for (int i = 0; i < slots->Length; i++)
			{
				// Display what ship was placed at the highlighted slots
				if (selectedShip == "Cruiser")
					slots[i]->Text = "R"; // R for Cruiser as C is taken for Carrier
				else
					slots[i]->Text = "" + selectedShip[0]; // Display the first character of the ship's name
			}

			// de-highlight the selected slots
			slotMouseLeave(sender, e);

			// Since the ship has already been placed on the board, remove it from the ListBox
			Battleships->Items->Remove(selectedShip);

			// Enable the reset button
			btnReset->Enabled = true;

			// Once all of the ships have been placed on the board, it's time to end the setup mode
			if (Battleships->Items->Count == 0)
			{
				inSetupMode = false;
				btnReady->Enabled = true; // Enable the ready button since all 5 ships have been place on the board
			}
			else
				Battleships->SelectedIndex = 0; // Select the first item in the list box
		}
	}
	else if (attackMode)
	{
		Monitor::Enter(gm);
		gm->setAttack(label->Name);
		Monitor::Exit(gm);

		Thread::Sleep(100);

		Monitor::Enter(gm);
		bool x = gm->getAttackResult();
		if (x) label->Text = "X"; else label->Text = "O";
		slotMouseLeave(sender, e);
		Monitor::Exit(gm);

		Thread::Sleep(100);
	}
}

//	Resets the Text property of all of the labels that are being used as slots in the game board
//	to be empty. It also resets the ships in the ListBox and makes sure that the game is in setup mode.
private: System::Void resetClick(System::Object^ sender, System::EventArgs^ e)
{
	Control::ControlCollection^ slots = panel3->Controls;
	// Clear the Text property of all of the Slots
	for each (Label^ slot in slots)
	{
		slot->Text = "";
	}

	// Reset the ships in the ListBox by first removing everything that's in it
	Battleships->Items->Clear(); // Makes sure that the ListBox is empty before adding ships back in, otherwise they would just be appended to the list
	Battleships->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
		L"Carrier", L"Battleship", L"Cruiser", L"Submarine",
			L"Destroyer"
	});
	Battleships->SelectedIndex = 0; // Selected the Carrier
	inSetupMode = true; // Turn on setup mode

	// Disable both the Reset and Ready buttons
	btnReady->Enabled = false;
	btnReset->Enabled = false;
}

//	The following function will run in a separate thread and will act as the game master that
//	handles all communication being the player and AI during their attack phases.
private: System::Void StartGameMaster()
{
	txtOutput->Text += "Game Master has started on a separate thread. \r\n";
}

private: System::Void readyClick(System::Object^ sender, System::EventArgs^ e)
{
	vector<vector<pair<int, int>>> ships (5, vector<pair<int, int>>(0));
	Control::ControlCollection^ slots = panel3->Controls;
	for each (Label^ slot in slots)
	{
		int i;
		int row;
		int col;

		char intial = '\0';
		if (slot->Text != "")
		{
			intial = slot->Text[0];
			slot->Text = ""; // Clear the Text out so that player can start attacking the AI's Grid
		}

		if (intial == 'C')
			i = 0;
		else if (intial == 'B')
			i = 1;
		else if (intial == 'R')
			i = 2;
		else if (intial == 'S')
			i = 3;
		else if (intial == 'D')
			i = 4;
		else
			i = -1;

		row = slot->Name[0] - 'A';
		if (slot->Name->Length == 3)
			col = 9;
		else
			col = slot->Name[1] - '1';

		if (i != -1)
		{
			ships[i].push_back(make_pair(row, col));
		}
	}

	for (int i = 0; i < ships.size(); i++)
	{
		gm->updateShip(true, i + 1, ships[i]);
	}

	btnReady->Enabled = false;
	btnReset->Enabled = false;
	gbSetup->Enabled = false;
	attackMode = true;
}

private: void outputLog(String^ message)
{
	if (txtOutput->InvokeRequired)
	{
		logDelegate^ d = gcnew logDelegate(this, &BattleshipForm::outputLog);
		Invoke(d, gcnew cli::array<Object^> {message});
	}
	else
		txtOutput->AppendText(message + "\r\n");
}
};
}
