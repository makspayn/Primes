#pragma once

#include "Primes.h"

public ref class MainForm : public System::Windows::Forms::Form
{
public:
	MainForm(void);
protected:
	~MainForm();
private: System::Windows::Forms::Button^  btnTask1;
protected:
private: System::Windows::Forms::Button^  btnTask2;
private: System::Windows::Forms::Button^  btnTask3;
private: System::Windows::Forms::DataVisualization::Charting::Chart^  Graph;
private:
	System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	void InitializeComponent(void)
		{
			this->btnTask1 = (gcnew System::Windows::Forms::Button());
			this->btnTask2 = (gcnew System::Windows::Forms::Button());
			this->btnTask3 = (gcnew System::Windows::Forms::Button());
			this->Graph = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Graph))->BeginInit();
			this->SuspendLayout();
			// 
			// btnTask1
			// 
			this->btnTask1->Location = System::Drawing::Point(334, 502);
			this->btnTask1->Name = L"btnTask1";
			this->btnTask1->Size = System::Drawing::Size(89, 23);
			this->btnTask1->TabIndex = 0;
			this->btnTask1->Text = L"Задание №1";
			this->btnTask1->UseVisualStyleBackColor = true;
			// 
			// btnTask2
			// 
			this->btnTask2->Location = System::Drawing::Point(429, 502);
			this->btnTask2->Name = L"btnTask2";
			this->btnTask2->Size = System::Drawing::Size(89, 23);
			this->btnTask2->TabIndex = 1;
			this->btnTask2->Text = L"Задание №2";
			this->btnTask2->UseVisualStyleBackColor = true;
			// 
			// btnTask3
			// 
			this->btnTask3->Location = System::Drawing::Point(524, 502);
			this->btnTask3->Name = L"btnTask3";
			this->btnTask3->Size = System::Drawing::Size(89, 23);
			this->btnTask3->TabIndex = 2;
			this->btnTask3->Text = L"Задание №3";
			this->btnTask3->UseVisualStyleBackColor = true;
			// 
			// Graph
			// 
			this->Graph->Location = System::Drawing::Point(11, 12);
			this->Graph->Name = L"Graph";
			this->Graph->Size = System::Drawing::Size(985, 465);
			this->Graph->TabIndex = 3;
			this->Graph->Text = L"chart1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 537);
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