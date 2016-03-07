#include "MainForm.h"

MainForm::MainForm(void)
{
	InitializeComponent();
	System::Windows::Forms::Control::CheckForIllegalCrossThreadCalls = false;
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
}

Void MainForm::Primes()
{
	btnTask1->Enabled = false;
	pbRun->Value = 0;
	int n = 180000000;
	int count = 10000000;
	std::vector<char> a(n, true);
	a[0] = a[1] = true;
	int k = 2;
	double start = 0.0, time = 0.0;
	start = clock();
	for (int i = 2; k < count; ++i) {
		if (a[i]) {
			k++;
			if (k % (count / 100) == 0) {
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
	MessageBox::Show("Время выполнения: " + time.ToString() + " мс");
	pbRun->Value = 0;
	k = 0;
	FileStream ^output = gcnew FileStream("primes.txt", FileMode::Create);
	StreamWriter ^writer = gcnew StreamWriter(output);
	String ^str = "";
	for (int i = 0; k < count; i++) {
		if (a[i]) {
			str = (k + 1).ToString() + " : " + i.ToString();
			writer->WriteLine(str);
			k++;
		}
	}
	writer->Close();
	output->Close();
	this->btnTask1->Enabled = true;
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
	return System::Void();
}

System::Void MainForm::btnTask3_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	return System::Void();
}
