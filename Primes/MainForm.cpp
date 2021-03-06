#include "MainForm.h"

MainForm::MainForm(void)
{
	InitializeComponent();
	System::Windows::Forms::Control::CheckForIllegalCrossThreadCalls = false;
	n = 180000000;
	count = 10000000;
	a = gcnew array<bool>(n);
	primes = gcnew array<int>(count);
}

MainForm::~MainForm()
{
	if (components) {
		delete components;
	}
	if (primesThread) {
		primesThread->Abort();
		delete primesThread;
	}
	if (sumThread) {
		sumThread->Abort();
		delete sumThread;
	}
}

Void MainForm::Primes()
{
	btnTask1->Enabled = false;
	btnTask2->Enabled = false;
	btnTask3->Enabled = false;
	pbRun->Value = 0;
	for (int i = 0; i < n; i++) {
		a[i] = true;
	}
	a[0] = a[1] = false;
	int k = 0, m = count / 100 + 1;
	double start = 0.0, time = 0.0;
	start = clock();
	for (int i = 2; k < count; ++i) {
		if (a[i]) {
			k++;
			if (k % m == 0) {
				pbRun->Value++;
			}
			if (i * 1ll * i < n) {
				for (int j = i * i; j < n; j += i) {
					a[j] = false;
				}
			}
		}
	}
	time = clock() - start;
	MessageBox::Show("����� ����������: " + time.ToString() + " ��");
	pbRun->Value = 0;
	k = 0;
	FileStream ^output = gcnew FileStream("primes.txt", FileMode::Create);
	StreamWriter ^writer = gcnew StreamWriter(output);
	String ^str = "";
	for (int i = 0; k < count; i++) {
		if (a[i]) {
			primes[k] = i;
			str = (k + 1).ToString() + " : " + i.ToString();
			writer->WriteLine(str);
			k++;
			if (k % m == 0) {
				pbRun->Value++;
			}
		}
	}
	writer->Close();
	output->Close();
	pbRun->Value = 0;
	btnTask1->Enabled = true;
	btnTask2->Enabled = true;
	btnTask3->Enabled = true;
}

Void MainForm::Sum()
{
	btnTask1->Enabled = false;
	btnTask2->Enabled = false;
	btnTask3->Enabled = false;
	FileStream ^output = gcnew FileStream("sum.txt", FileMode::Create);
	StreamWriter ^writer = gcnew StreamWriter(output);
	String ^str = "";
	int l = 0, m = (primes[primes->Length - 1] / 2 - 1) / 100 + 1;
	pbRun->Value = 0;
	double start = 0.0, time = 0.0;
	start = clock();
	for (int i = 4; i < primes[primes->Length - 1] + 1; i += 2) {
		for (int j = 0; j < count; j++) {
			if (a[i - primes[j]]) {
				str = i.ToString() + " = " + primes[j].ToString() + " + " + (i - primes[j]).ToString();
				writer->WriteLine(str);
				if (l % m == 0) {
					pbRun->Value++;
				}
				l++;
				break;
			}
		}
	}
	time = clock() - start;
	MessageBox::Show("����� ����������: " + time.ToString() + " ��");
	pbRun->Value = 0;
	writer->Close();
	output->Close();
	pbRun->Value = 0;
	btnTask1->Enabled = true;
	btnTask2->Enabled = true;
	btnTask3->Enabled = true;
}

System::Void MainForm::btnTask1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (primesThread) {
		delete primesThread;
	}
	primesThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::Primes));
	primesThread->Start();
}

System::Void MainForm::btnTask2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	array<int> ^intervals = gcnew array<int>(30);
	for (int i = 0; i < 30; i++) {
		intervals[i] = 0;
	}
	for (int i = 0; i < count - 1; i++) {
		if ((primes[i + 1] - primes[i]) > intervals[0]) {
			intervals[0] = primes[i + 1] - primes[i];
			intervals->Sort(intervals);
		}
	}
	ChartArea ^chartArea = gcnew ChartArea();
	chartArea->Name = "chartArea";
	Series ^series = gcnew Series();
	series->ChartType = SeriesChartType::Column;
	series->ChartArea = "chartArea";
	if (Graph->Series->Count) {
		Graph->Series->Clear();
		Graph->ChartAreas->Clear();
	}
	Graph->ChartAreas->Add(chartArea);
	Graph->Series->Add(series); 
	for (int i = 0; i < 30; i++) {
		series->Points->AddY(intervals[i]);
	}
}

System::Void MainForm::btnTask3_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (sumThread) {
		delete sumThread;
	}
	sumThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::Sum));
	sumThread->Start();
}