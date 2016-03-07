#include "MainForm.h"

MainForm::MainForm(void)
{
	InitializeComponent();
}

MainForm::~MainForm()
{
	if (components) {
		delete components;
	}
}