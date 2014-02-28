#pragma once

#include "Mouse.h"
#include "Cell.h"
#include <array>

namespace Project7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  btnStart;
	protected: 

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  turnLeft;
	private: System::Windows::Forms::Button^  move;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->turnLeft = (gcnew System::Windows::Forms::Button());
			this->move = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(42, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(500, 400);
			this->panel1->TabIndex = 0;
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(145, 435);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &MyForm::btnStart_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(340, 435);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Stop";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// turnLeft
			// 
			this->turnLeft->Location = System::Drawing::Point(145, 477);
			this->turnLeft->Name = L"turnLeft";
			this->turnLeft->Size = System::Drawing::Size(75, 23);
			this->turnLeft->TabIndex = 2;
			this->turnLeft->Text = L"TurnLeft";
			this->turnLeft->UseVisualStyleBackColor = true;
			this->turnLeft->Click += gcnew System::EventHandler(this, &MyForm::turnLeft_Click);
			// 
			// move
			// 
			this->move->Location = System::Drawing::Point(340, 477);
			this->move->Name = L"move";
			this->move->Size = System::Drawing::Size(75, 23);
			this->move->TabIndex = 3;
			this->move->Text = L"Move";
			this->move->UseVisualStyleBackColor = true;
			this->move->Click += gcnew System::EventHandler(this, &MyForm::move_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 512);
			this->Controls->Add(this->move);
			this->Controls->Add(this->turnLeft);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	Mouse^ myMouse;
	array <Cell^, 2>^ maze;
	char direction;

	Graphics^ g;
	Brush^ grayBrush;
	Brush^ whiteBrush;
	Brush^ burlyBrush;
	Pen^ blackPen;

	static const int NUMROWS = 16;
	static const int NUMCOLS = 20;
	static const int CELLSIZE = 25;
	
	private: void drawMaze()
			 {
				 int row, col;
				 int x, y;

				 panel1->Refresh();

				 for (row = 0; row < NUMROWS; row++)
					 for (col = 0; col < NUMCOLS; col++)
					 {
						 x = col * CELLSIZE;
						 y = row * CELLSIZE;
						 Rectangle gridRect = Rectangle(x,y, CELLSIZE-1, CELLSIZE-1);
						 g->FillRectangle(whiteBrush, gridRect);
						 g->DrawRectangle(blackPen, gridRect);
					 }
			 }


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

				 int row, col;

				 g = panel1->CreateGraphics();
				 grayBrush = gcnew System::Drawing::SolidBrush(Color::Gray);
				 blackPen = gcnew System::Drawing::Pen(Color::Black);
				 whiteBrush = gcnew System::Drawing::SolidBrush(Color::White);
				 burlyBrush = gcnew System::Drawing::SolidBrush(Color::BurlyWood);

				 maze = gcnew array<Cell^, 2>(NUMROWS,NUMCOLS);
				 for (row = 0; row < NUMROWS; row++)
					 for (col = 0; col < NUMCOLS; col++)
						 maze[row,col] = gcnew Cell(row,col,true);
			 }
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {

				 int x, y;
				 Drawing::Icon ^ cheese = gcnew
			  System::Drawing::Icon("cheese.ico");

				 int mouseRow = 8;
				 int mouseCol = 0;

				 int cheeseRow = 11;
				 int cheeseCol = 8;

				 direction = 'r';

				 myMouse = gcnew Mouse(mouseRow, mouseCol);

				 drawMaze();

				 x = cheeseCol * CELLSIZE;
				 y = cheeseRow * CELLSIZE;
				 Rectangle cheeseRect = Rectangle(x,y,CELLSIZE,CELLSIZE);
				 g->DrawIcon(cheese, cheeseRect);
				 maze[cheeseRow,cheeseCol]->setCheese(true);

				 myMouse->setRow(mouseRow);
				 myMouse->setCol(mouseCol);
				 x = mouseCol * CELLSIZE;
				 y = mouseRow * CELLSIZE;
				 Rectangle mouseRect = Rectangle(x,y,CELLSIZE,CELLSIZE);
				 g->DrawIcon (myMouse->getIcon(),mouseRect);

				 timer1->Start();
			 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void turnLeft_Click(System::Object^  sender, System::EventArgs^  e) {
			 int x, y;
			 int mouseRow, mouseCol;
			 mouseRow = myMouse->getRow();
			 mouseCol = myMouse->getCol();
			 myMouse->setRow(mouseRow);
		     myMouse->setCol(mouseCol);
			 x = mouseCol * CELLSIZE;
			 y = mouseRow * CELLSIZE;
			 Rectangle mouseRect = Rectangle(x,y,CELLSIZE,CELLSIZE);
			 myMouse->turnLeft();
			 g->DrawIcon (myMouse->getIcon(),mouseRect);
			 
		 }
private: System::Void move_Click(System::Object^  sender, System::EventArgs^  e) {
			 int x, y;
			 int mouseRow, mouseCol;
			 mouseRow = myMouse->getRow();
			 mouseCol = myMouse->getCol();
			 x = mouseCol * CELLSIZE;
			 y = mouseRow * CELLSIZE;
			 Rectangle oldRect = Rectangle(x,y,CELLSIZE,CELLSIZE);
			 g->FillRectangle(burlyBrush, oldRect);
			 g->DrawRectangle(blackPen, oldRect);

			 myMouse->move();
			 mouseRow = myMouse->getRow();
			 mouseCol = myMouse->getCol();
			 myMouse->setRow(mouseRow);
		     myMouse->setCol(mouseCol);
			 x = mouseCol * CELLSIZE;
			 y = mouseRow * CELLSIZE;
			 Rectangle mouseRect = Rectangle(x,y,CELLSIZE,CELLSIZE);
			 g->DrawIcon (myMouse->getIcon(),mouseRect);
			 
		 }
};
}
