#pragma once

#include "Karel.h"
#include "Cell.h"
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <array>
#include<sstream>
#include<cstring>



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
	private: System::Windows::Forms::Button^  btnStop;
	protected: 


	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  turnLeft;
	private: System::Windows::Forms::Button^  move;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  put_beeper;
	private: System::Windows::Forms::Button^  pick_beeper;
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
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->turnLeft = (gcnew System::Windows::Forms::Button());
			this->move = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->put_beeper = (gcnew System::Windows::Forms::Button());
			this->pick_beeper = (gcnew System::Windows::Forms::Button());
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
			this->btnStart->Location = System::Drawing::Point(12, 418);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(75, 23);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &MyForm::btnStart_Click);
			// 
			// btnStop
			// 
			this->btnStop->Location = System::Drawing::Point(93, 418);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(75, 23);
			this->btnStop->TabIndex = 1;
			this->btnStop->Text = L"Stop";
			this->btnStop->UseVisualStyleBackColor = true;
			this->btnStop->Click += gcnew System::EventHandler(this, &MyForm::btnStop_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// turnLeft
			// 
			this->turnLeft->Location = System::Drawing::Point(12, 447);
			this->turnLeft->Name = L"turnLeft";
			this->turnLeft->Size = System::Drawing::Size(75, 23);
			this->turnLeft->TabIndex = 2;
			this->turnLeft->Text = L"TurnLeft";
			this->turnLeft->UseVisualStyleBackColor = true;
			this->turnLeft->Click += gcnew System::EventHandler(this, &MyForm::turnLeft_Click);
			// 
			// move
			// 
			this->move->Location = System::Drawing::Point(93, 447);
			this->move->Name = L"move";
			this->move->Size = System::Drawing::Size(75, 23);
			this->move->TabIndex = 3;
			this->move->Text = L"Move";
			this->move->UseVisualStyleBackColor = true;
			this->move->Click += gcnew System::EventHandler(this, &MyForm::move_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::IndianRed;
			this->label1->Location = System::Drawing::Point(444, 418);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Number of Beepers";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(442, 434);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// put_beeper
			// 
			this->put_beeper->Location = System::Drawing::Point(174, 418);
			this->put_beeper->Name = L"put_beeper";
			this->put_beeper->Size = System::Drawing::Size(75, 23);
			this->put_beeper->TabIndex = 6;
			this->put_beeper->Text = L"putBeeper";
			this->put_beeper->UseVisualStyleBackColor = true;
			this->put_beeper->Click += gcnew System::EventHandler(this, &MyForm::put_beeper_Click);
			// 
			// pick_beeper
			// 
			this->pick_beeper->Location = System::Drawing::Point(174, 447);
			this->pick_beeper->Name = L"pick_beeper";
			this->pick_beeper->Size = System::Drawing::Size(75, 23);
			this->pick_beeper->TabIndex = 7;
			this->pick_beeper->Text = L"pickBeeper";
			this->pick_beeper->UseVisualStyleBackColor = true;
			this->pick_beeper->Click += gcnew System::EventHandler(this, &MyForm::pick_beeper_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 512);
			this->Controls->Add(this->pick_beeper);
			this->Controls->Add(this->put_beeper);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->move);
			this->Controls->Add(this->turnLeft);
			this->Controls->Add(this->btnStop);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	Karel^ myKarel;
	array <Cell^, 2>^ maze;

	Graphics^ g;
	Brush^ grayBrush;
	Brush^ whiteBrush;
	Brush^ burlyBrush;
	Pen^ blackPen;

	Drawing::Icon ^ bpr;

	static const int CELLSIZE = 50;
	
	private: void drawMaze(int worldRow, int worldCol)
			 {
				 int row, col;
				 int x, y;

				 panel1->Refresh();

				 for (row = 0; row < worldRow; row++)
					 for (col = 0; col < worldCol; col++)
					 {
						 x = col * CELLSIZE;
						 y = row * CELLSIZE;
						 Rectangle gridRect = Rectangle(x,y, CELLSIZE-1, CELLSIZE-1);
						 g->FillRectangle(whiteBrush, gridRect);
						 g->DrawRectangle(blackPen, gridRect);
					 }
			 }


	private: bool front_is_clear(int worldRow, int worldCol)
			 {
				 int wallCol;
				 int wallRow;
				 wallCol = myKarel->getCol();
				 wallRow = myKarel->getRow();

				 if (myKarel->getIco() == 0)
				 {
					 if ((myKarel->getCol() < worldCol -1) && (maze[wallCol+1, wallRow]->getAccess() == true)) return true;
				 }
				 else if (myKarel->getIco() == 1)
				 {
					 if ((myKarel->getCol() > 0) && (maze[wallCol-1, wallRow]->getAccess() == true)) return true;
				 }
				 else if (myKarel->getIco() == 3)
				 {
					 if ((myKarel->getRow() < worldRow -1) && (maze[wallCol, wallRow+1]->getAccess() == true)) return true;
				 }
				 else if (myKarel->getIco() == 2)
				 {
					 if ((myKarel->getRow() >  0) && (maze[wallCol, wallRow-1]->getAccess() == true)) return true;
				 }
				 return false;
				 }	

	private: int conversion_to_int(std::string info)
			 {
				 int value;
				 std::stringstream convert(info);
			
				 if (!(convert >> value))
				 {
					value = 0;
				 }
					return value;
			  }

	private: void karelMove()
			 {
				 int x, y;

				 bpr = gcnew System::Drawing::Icon("beeper.ico");

				 x = myKarel->getCol() * CELLSIZE;
				 y = myKarel->getRow() * CELLSIZE;

				 if (maze[myKarel->getCol(), myKarel->getRow()]->getBeeper() == false)
				 {
					Rectangle oldRect = Rectangle(x,y,CELLSIZE-1,CELLSIZE-1);
					g->FillRectangle(burlyBrush, oldRect);
					g->DrawRectangle(blackPen, oldRect);
				 }
				 else
				 {
					 Rectangle cbeeperRect = Rectangle(x,y,CELLSIZE,CELLSIZE);
					 g->DrawIcon(bpr, cbeeperRect);
				 }

				 myKarel->move();

				 x = myKarel->getCol() * CELLSIZE;
				 y = myKarel->getRow() * CELLSIZE;

				 Rectangle karelRect = Rectangle(x,y,CELLSIZE,CELLSIZE);
				 g->DrawIcon (myKarel->getIcon(),karelRect);
			 }

	private: void karelLeft()
			 {
				 int x, y;

				 x = myKarel->getCol() * CELLSIZE;
				 y = myKarel->getRow() * CELLSIZE;

				 Rectangle karelRect = Rectangle(x,y,CELLSIZE,CELLSIZE);
				 myKarel->turnLeft();
				 g->DrawIcon (myKarel->getIcon(),karelRect);
			 }

	private: void putBeeper()
			 {
				 int beeper;

				 Int32::TryParse(textBox1->Text, beeper);

				 if (beeper > 0)
				 {
					 beeper--;

					 maze[myKarel->getCol(), myKarel->getRow()]->setBeeper(true);
				 }
				 else MessageBox::Show("Karel has no beepers!");

				 textBox1->Text = Convert::ToString(beeper);
			 }

	private: void pickBeeper()
			 {
				 int beeper;

				 Int32::TryParse(textBox1->Text, beeper);

				 if ((maze[myKarel->getCol(), myKarel->getRow()]->getBeeper()) == true)
				 {
					 beeper++;

					 maze[myKarel->getCol(), myKarel->getRow()]->setBeeper(false);
				 }
				 else MessageBox::Show("No beeper!");

				 textBox1->Text = Convert::ToString(beeper);
			 }

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {


				 int row, col;

				 std::array <int,2> world;

				 std::string temp;

				 std::ifstream inputWorld("input world.txt");

				 while (!inputWorld.eof())
				{

					inputWorld >> temp;

					if (temp == "World")
					{
						inputWorld >> temp;
						world[0] = conversion_to_int(temp);
						inputWorld >> temp;
						world[1] = conversion_to_int(temp);
				
					}
				 }


				 g = panel1->CreateGraphics();
				 grayBrush = gcnew System::Drawing::SolidBrush(Color::Gray);
				 blackPen = gcnew System::Drawing::Pen(Color::Black);
				 whiteBrush = gcnew System::Drawing::SolidBrush(Color::White);
				 burlyBrush = gcnew System::Drawing::SolidBrush(Color::BurlyWood);

				 maze = gcnew array<Cell^, 2>(world[1],world[0]);
				 for (row = 0; row < world[1]; row++)
					 for (col = 0; col < world[0]; col++)
						 maze[row,col] = gcnew Cell(row,col,true);


			 }
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {

				 std::array <int,2> world;
				 std::array <int,4> robot;
				 std::vector <int> wall;
				 std::vector <int> beeper;

				 std::vector<int>::iterator walls;
				 std::vector<int>::iterator beepers;

				 std::string temp;

				 std::ifstream inputWorld("input world.txt");

				 while (!inputWorld.eof())
				 {

					 inputWorld >> temp;

					 if (temp == "World")
					 {
						 inputWorld >> temp;
						 world[0] = conversion_to_int(temp);
						 inputWorld >> temp;
						 world[1] = conversion_to_int(temp);
				
					 }
					 else if (temp == "Robot")
					 {
						 inputWorld >> temp;
						 robot[0] = conversion_to_int(temp);
						 inputWorld >> temp;
						 robot[1] = conversion_to_int(temp);
						 inputWorld >> temp;
						 robot[2] = conversion_to_int(temp);
						 inputWorld >> temp;
						 robot[3] = conversion_to_int(temp);
					 }
					 else  if (temp == "Wall")
					 {
						 for (int i = 0; i < 2; i++)
						 {
							 int tempWall;
							 inputWorld >> temp;
							 tempWall = conversion_to_int(temp);
							 wall.push_back(tempWall);
						 }
					 }
					 else if (temp == "Beepers")
					 {
						 for (int i = 0; i < 3; i++)
						 {
							 int tempBeeper;
							 inputWorld >> temp;
							 tempBeeper = conversion_to_int(temp);
							 beeper.push_back(tempBeeper);
						 }
					 }
				 }
				 
				 int karelRow = robot[0]-1;
				 int karelCol = robot[1]-1;

				 int x, y;

				 bpr = gcnew System::Drawing::Icon("beeper.ico");


				 myKarel = gcnew Karel(karelRow, karelCol);

				 drawMaze(world[0], world[1]);
				 
				 walls = wall.begin();
				 
				 while (walls < wall.end())
				 {
					 int wallRow;
					 int wallCol;
					 
					 wallCol = *walls-1;
					 walls++;
					 wallRow = *walls-1;
					 walls++;
					 
					 maze[wallCol, wallRow]->setAccess(false);

					 x = wallCol * CELLSIZE;
					 y = wallRow * CELLSIZE;

					 Rectangle wallRect = Rectangle(x,y, CELLSIZE-1, CELLSIZE-1);
					 g->FillRectangle(grayBrush, wallRect);
					 g->DrawRectangle(blackPen, wallRect);
				 }

				 beepers = beeper.begin();

				 while (beepers < beeper.end())
				 {
					 int beeperRow;
					 int beeperCol;
					 int beeperAmnt;

					 beeperCol = *beepers-1;
					 beepers++;
					 beeperRow = *beepers-1;
					 beepers++;
					 beeperAmnt = *beepers;
					 beepers++;
					 for (int i = 0; i < beeperAmnt; i++)
					 {
						 maze[beeperCol, beeperRow]->setBeeper(true);
						 x = beeperCol * CELLSIZE;
						 y = beeperRow * CELLSIZE;

						 Rectangle beeperRect = Rectangle(x,y, CELLSIZE,CELLSIZE);
						 g->DrawIcon(bpr, beeperRect);
					 }
				 }

				 myKarel->setRow(karelRow);
				 myKarel->setCol(karelCol);
				 x = karelCol * CELLSIZE;
				 y = karelRow * CELLSIZE;
				 Rectangle karelRect = Rectangle(x,y,CELLSIZE,CELLSIZE);
				 g->DrawIcon (myKarel->getIcon(),karelRect);

				 timer1->Start();

				 textBox1->Text = Convert::ToString(robot[3]);
		 }

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void turnLeft_Click(System::Object^  sender, System::EventArgs^  e) {
			 
					karelLeft();
		 }

private: System::Void move_Click(System::Object^  sender, System::EventArgs^  e) {
			 
					 
					 bool access;

					 std::array <int,2> world;

					 std::string temp;

					 std::ifstream inputWorld("input world.txt");

					 while (!inputWorld.eof())
					 {

						 inputWorld >> temp;

						 if (temp == "World")
						 {
							 inputWorld >> temp;
							 world[0] = conversion_to_int(temp);
							 inputWorld >> temp;
							 world[1] = conversion_to_int(temp);
						 }
					 }

					 access = front_is_clear(world[0], world[1]);

					 if (access == true)
					 {
						 karelMove();
					 }
					 else  if (access == false) MessageBox::Show("Edge or Wall");
		 }
private: System::Void put_beeper_Click(System::Object^  sender, System::EventArgs^  e) {
			 putBeeper();
		 }
private: System::Void pick_beeper_Click(System::Object^  sender, System::EventArgs^  e) {
			 pickBeeper();
		 }
private: System::Void btnStop_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }
};
}
