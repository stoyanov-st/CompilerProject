#pragma once
#include "findTab.h"
#include "Grammar.h";
#include <string>
#include <msclr\marshal_cppstd.h>
namespace CppWinForm1 {

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
	private: System::Windows::Forms::RichTextBox^  inputBox;
	private: System::Windows::Forms::RichTextBox^  positionListBox;
	private: System::Windows::Forms::RichTextBox^  outputBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;



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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->inputBox = (gcnew System::Windows::Forms::RichTextBox());
			this->positionListBox = (gcnew System::Windows::Forms::RichTextBox());
			this->outputBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(218, 150);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 76);
			this->button1->TabIndex = 0;
			this->button1->Text = L"LEX";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// inputBox
			// 
			this->inputBox->Location = System::Drawing::Point(33, 59);
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(168, 244);
			this->inputBox->TabIndex = 1;
			this->inputBox->Text = L"";
			// 
			// positionListBox
			// 
			this->positionListBox->Location = System::Drawing::Point(315, 59);
			this->positionListBox->Name = L"positionListBox";
			this->positionListBox->ReadOnly = true;
			this->positionListBox->Size = System::Drawing::Size(83, 243);
			this->positionListBox->TabIndex = 2;
			this->positionListBox->Text = L"";
			// 
			// outputBox
			// 
			this->outputBox->Location = System::Drawing::Point(423, 59);
			this->outputBox->Name = L"outputBox";
			this->outputBox->ReadOnly = true;
			this->outputBox->Size = System::Drawing::Size(159, 242);
			this->outputBox->TabIndex = 3;
			this->outputBox->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Input";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(312, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"PositionList";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(420, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"SymbolTable";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(594, 369);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->outputBox);
			this->Controls->Add(this->positionListBox);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->Text = L"Compiler";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		positionList = {};
		symbolTable = {};
		fillTable();
		positionListBox->Text = gcnew String("");
		outputBox->Text = gcnew String("");
		msclr::interop::marshal_context context;
		std::string input = context.marshal_as<std::string>(inputBox->Text->ToString());
		lexicalAnalyze(input);
		positionListBox->Text = printQueue(positionList);
		outputBox->Text = printMap(symbolTable);
		syntaxAnalize(positionList);
	}

};
}
