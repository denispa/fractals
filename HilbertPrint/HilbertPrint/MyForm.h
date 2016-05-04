#include <stdio.h>
#include "CurveDraw.h"
#pragma once

namespace HilbertPrint {

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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lineColorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fontColorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  inverseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  falseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::CheckBox^  checkBox1;

	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lineColorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fontColorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->inverseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->falseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(18, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 72);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(18, 135);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(192, 192);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(293, 62);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(512, 512);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Britannic Bold", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Location = System::Drawing::Point(18, 353);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(191, 88);
			this->button2->TabIndex = 3;
			this->button2->Text = L"print!";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 106);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"  ";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->settingsToolStripMenuItem, this->aboutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(886, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->newToolStripMenuItem, this->saveToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->newToolStripMenuItem->Text = L"New";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::newToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->lineColorToolStripMenuItem,
					this->fontColorToolStripMenuItem, this->inverseToolStripMenuItem
			});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// lineColorToolStripMenuItem
			// 
			this->lineColorToolStripMenuItem->Name = L"lineColorToolStripMenuItem";
			this->lineColorToolStripMenuItem->Size = System::Drawing::Size(130, 22);
			this->lineColorToolStripMenuItem->Text = L"Line Color";
			this->lineColorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::lineColorToolStripMenuItem_Click);
			// 
			// fontColorToolStripMenuItem
			// 
			this->fontColorToolStripMenuItem->Name = L"fontColorToolStripMenuItem";
			this->fontColorToolStripMenuItem->Size = System::Drawing::Size(130, 22);
			this->fontColorToolStripMenuItem->Text = L"Font Color";
			this->fontColorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fontColorToolStripMenuItem_Click);
			// 
			// inverseToolStripMenuItem
			// 
			this->inverseToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->trueToolStripMenuItem,
					this->falseToolStripMenuItem
			});
			this->inverseToolStripMenuItem->Name = L"inverseToolStripMenuItem";
			this->inverseToolStripMenuItem->Size = System::Drawing::Size(130, 22);
			this->inverseToolStripMenuItem->Text = L"Inverse";
			// 
			// trueToolStripMenuItem
			// 
			this->trueToolStripMenuItem->Name = L"trueToolStripMenuItem";
			this->trueToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->trueToolStripMenuItem->Text = L"True";
			this->trueToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::trueToolStripMenuItem_Click);
			// 
			// falseToolStripMenuItem
			// 
			this->falseToolStripMenuItem->Name = L"falseToolStripMenuItem";
			this->falseToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->falseToolStripMenuItem->Text = L"False";
			this->falseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::falseToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(57, 468);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(94, 29);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"Inverse";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(886, 661);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"HilbertPrint";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Bitmap ^ bmp_for_draw;
	private:String ^ full_name_of_image;
	private:Color  Linecolor = Color::FromArgb(0xFF000000);
	private:Color  Fontcolor = Color::FromArgb(0xFFFFFFFF);
	private:Boolean  Inverse = false;

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "bmp files|*.bmp";
		openFileDialog1->Title = "Opening";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			full_name_of_image = openFileDialog1->FileName;
			bmp_for_draw = gcnew Bitmap(openFileDialog1->FileName);
			this->pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
			pictureBox1->Image = bmp_for_draw;
			pictureBox1->Invalidate();
			label1->Text = full_name_of_image;
		}
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		System::Drawing::Graphics ^grr = MyForm::pictureBox2->CreateGraphics();
		System::Drawing::Pen^ my_pen = gcnew System::Drawing::Pen(Linecolor, 1);
		grr->Clear(Fontcolor);
		DrawCurve(grr, my_pen, full_name_of_image, Inverse);
		//return bitmap		 
	}

	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "bmp files|*.bmp";
		openFileDialog1->Title = "Opening";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			full_name_of_image = openFileDialog1->FileName;
			bmp_for_draw = gcnew Bitmap(openFileDialog1->FileName);
			this->pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
			pictureBox1->Image = bmp_for_draw;
			pictureBox1->Invalidate();
			label1->Text = full_name_of_image;
		}
	}
	private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if ((pictureBox2 != nullptr) && (full_name_of_image != nullptr)){
			String ^format = full_name_of_image->Substring(full_name_of_image->Length - 4, 4);
			SaveFileDialog ^savedialog = gcnew SaveFileDialog();
			savedialog->Title = "Save as ...";
			savedialog->OverwritePrompt = true;
			savedialog->CheckPathExists = true;
			savedialog->Filter = "Image Files(*.BMP)|*.bmp";
			savedialog->ShowHelp = true;
			// If selected, save
			if (savedialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				pictureBox2->Image->Save(savedialog->FileName, System::Drawing::Imaging::ImageFormat::Bmp);

			}
			//ELSE
			//message: select image 
		}
	}

	private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//NEWWW
	}

	private: System::Void lineColorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Linecolor = colorDialog1->Color;
		}
	}

	private: System::Void fontColorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Fontcolor = colorDialog1->Color;
		}
	}

	private: System::Void trueToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Inverse = true;
	}

	private: System::Void falseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Inverse = false;
	}

	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (checkBox1->Checked)
		{
			Inverse = true;
		}
		else
		{
			Inverse = false;
		}
	}
	};
}