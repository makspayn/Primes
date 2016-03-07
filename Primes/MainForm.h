#pragma once

#include "Primes.h"

public ref class MainForm : public System::Windows::Forms::Form
{
public:
	MainForm(void);
protected:
	~MainForm();
private: 
	System::Windows::Forms::Button^  btnTask1;
	System::Windows::Forms::Button^  btnTask2;
	System::Windows::Forms::Button^  btnTask3;
	System::Windows::Forms::DataVisualization::Charting::Chart^  Graph;
	System::ComponentModel::Container ^components;
private: System::Windows::Forms::ProgressBar^  pbRun;

				 Thread ^primesThread;
	Void Primes();
	System::Void btnTask1_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void btnTask2_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void btnTask3_Click(System::Object^  sender, System::EventArgs^  e);

#pragma region Windows Form Designer generated code
	void InitializeComponent(void)
		{
			this->btnTask1 = (gcnew System::Windows::Forms::Button());
			this->btnTask2 = (gcnew System::Windows::Forms::Button());
			this->btnTask3 = (gcnew System::Windows::Forms::Button());
			this->Graph = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->pbRun = (gcnew System::Windows::Forms::ProgressBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Graph))->BeginInit();
			this->SuspendLayout();
			// 
			// btnTask1
			// 
			this->btnTask1->Location = System::Drawing::Point(334, 511);
			this->btnTask1->Name = L"btnTask1";
			this->btnTask1->Size = System::Drawing::Size(89, 23);
			this->btnTask1->TabIndex = 0;
			this->btnTask1->Text = L"Задание №1";
			this->btnTask1->UseVisualStyleBackColor = true;
			this->btnTask1->Click += gcnew System::EventHandler(this, &MainForm::btnTask1_Click);
			// 
			// btnTask2
			// 
			this->btnTask2->Location = System::Drawing::Point(429, 511);
			this->btnTask2->Name = L"btnTask2";
			this->btnTask2->Size = System::Drawing::Size(89, 23);
			this->btnTask2->TabIndex = 1;
			this->btnTask2->Text = L"Задание №2";
			this->btnTask2->UseVisualStyleBackColor = true;
			this->btnTask2->Click += gcnew System::EventHandler(this, &MainForm::btnTask2_Click);
			// 
			// btnTask3
			// 
			this->btnTask3->Location = System::Drawing::Point(524, 511);
			this->btnTask3->Name = L"btnTask3";
			this->btnTask3->Size = System::Drawing::Size(89, 23);
			this->btnTask3->TabIndex = 2;
			this->btnTask3->Text = L"Задание №3";
			this->btnTask3->UseVisualStyleBackColor = true;
			this->btnTask3->Click += gcnew System::EventHandler(this, &MainForm::btnTask3_Click);
			// 
			// Graph
			// 
			this->Graph->Location = System::Drawing::Point(11, 12);
			this->Graph->Name = L"Graph";
			this->Graph->Size = System::Drawing::Size(985, 465);
			this->Graph->TabIndex = 3;
			this->Graph->Text = L"chart1";
			// 
			// pbRun
			// 
			this->pbRun->Location = System::Drawing::Point(12, 485);
			this->pbRun->Name = L"pbRun";
			this->pbRun->Size = System::Drawing::Size(984, 23);
			this->pbRun->Step = 1;
			this->pbRun->TabIndex = 4;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 537);
			this->Controls->Add(this->pbRun);
			this->Controls->Add(this->Graph);
			this->Controls->Add(this->btnTask3);
			this->Controls->Add(this->btnTask2);
			this->Controls->Add(this->btnTask1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Простые числа";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Graph))->EndInit();
			this->ResumeLayout(false);

	}
#pragma endregion
};