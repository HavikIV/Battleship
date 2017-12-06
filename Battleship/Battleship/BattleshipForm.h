#pragma once

#include "Grid.h"
#include "Ship.h"

namespace Battleship {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BattleshipForm
	/// </summary>
	public ref class BattleshipForm : public System::Windows::Forms::Form
	{
	public:
		BattleshipForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Panel^  panel2;

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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(466, 285);
			this->panel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(12, 312);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(466, 285);
			this->panel2->TabIndex = 1;
			// 
			// BattleshipForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(490, 609);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"BattleshipForm";
			this->Text = L"BattleshipForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
