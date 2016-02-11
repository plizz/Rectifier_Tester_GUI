#pragma once

#include "RectifierParser.h"

#include <msclr/marshal.h>
using namespace msclr::interop;

RectifierParameters rectifierParameters;

namespace Rectifier_Tester_GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: RectifierParser* parser;

	private: System::Windows::Forms::NumericUpDown^  voltageValue;
	private: System::Windows::Forms::Button^  voltageInc1;
	private: System::Windows::Forms::Button^  voltageInc10;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  voltageDec01;
	private: System::Windows::Forms::Button^  voltageInc01;


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  currentDec01;
	private: System::Windows::Forms::Button^  currentInc10;

	private: System::Windows::Forms::Button^  currentInc01;
	private: System::Windows::Forms::Button^  currentInc1;

	private: System::Windows::Forms::NumericUpDown^  currentValue;
	private: System::Windows::Forms::CheckBox^  limitFlag;
	private: System::Windows::Forms::GroupBox^  moduleAlarm;

	private: System::Windows::Forms::CheckBox^  acFault;
	private: System::Windows::Forms::CheckBox^  fanFailure;
	private: System::Windows::Forms::CheckBox^  moduleSwitch;
	private: System::Windows::Forms::CheckBox^  moduleFault;
	private: System::Windows::Forms::ComboBox^  protectionCode;

	private: System::Windows::Forms::CheckBox^  isAlarm;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  comPortName;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Button^  comStart;

	private: System::ComponentModel::IContainer^  components;
	protected:

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
			this->voltageValue = (gcnew System::Windows::Forms::NumericUpDown());
			this->voltageInc1 = (gcnew System::Windows::Forms::Button());
			this->voltageInc10 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->voltageDec01 = (gcnew System::Windows::Forms::Button());
			this->voltageInc01 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->currentDec01 = (gcnew System::Windows::Forms::Button());
			this->currentInc10 = (gcnew System::Windows::Forms::Button());
			this->currentInc01 = (gcnew System::Windows::Forms::Button());
			this->currentInc1 = (gcnew System::Windows::Forms::Button());
			this->currentValue = (gcnew System::Windows::Forms::NumericUpDown());
			this->limitFlag = (gcnew System::Windows::Forms::CheckBox());
			this->moduleAlarm = (gcnew System::Windows::Forms::GroupBox());
			this->isAlarm = (gcnew System::Windows::Forms::CheckBox());
			this->acFault = (gcnew System::Windows::Forms::CheckBox());
			this->fanFailure = (gcnew System::Windows::Forms::CheckBox());
			this->moduleSwitch = (gcnew System::Windows::Forms::CheckBox());
			this->moduleFault = (gcnew System::Windows::Forms::CheckBox());
			this->protectionCode = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->comPortName = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->comStart = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->voltageValue))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentValue))->BeginInit();
			this->moduleAlarm->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// voltageValue
			// 
			this->voltageValue->DecimalPlaces = 1;
			this->voltageValue->Location = System::Drawing::Point(10, 35);
			this->voltageValue->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1005, 0, 0, 65536 });
			this->voltageValue->Name = L"voltageValue";
			this->voltageValue->Size = System::Drawing::Size(120, 20);
			this->voltageValue->TabIndex = 3;
			this->voltageValue->ValueChanged += gcnew System::EventHandler(this, &MainForm::voltageValue_ValueChanged);
			// 
			// voltageInc1
			// 
			this->voltageInc1->Location = System::Drawing::Point(187, 32);
			this->voltageInc1->Name = L"voltageInc1";
			this->voltageInc1->Size = System::Drawing::Size(45, 23);
			this->voltageInc1->TabIndex = 6;
			this->voltageInc1->Text = L"1";
			this->voltageInc1->UseVisualStyleBackColor = true;
			this->voltageInc1->Click += gcnew System::EventHandler(this, &MainForm::voltageInc1_Click);
			// 
			// voltageInc10
			// 
			this->voltageInc10->Location = System::Drawing::Point(238, 32);
			this->voltageInc10->Name = L"voltageInc10";
			this->voltageInc10->Size = System::Drawing::Size(45, 23);
			this->voltageInc10->TabIndex = 7;
			this->voltageInc10->Text = L"10";
			this->voltageInc10->UseVisualStyleBackColor = true;
			this->voltageInc10->Click += gcnew System::EventHandler(this, &MainForm::voltageInc10_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->voltageDec01);
			this->groupBox2->Controls->Add(this->voltageInc10);
			this->groupBox2->Controls->Add(this->voltageInc01);
			this->groupBox2->Controls->Add(this->voltageInc1);
			this->groupBox2->Controls->Add(this->voltageValue);
			this->groupBox2->Location = System::Drawing::Point(12, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(300, 85);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Voltage, В";
			// 
			// voltageDec01
			// 
			this->voltageDec01->Location = System::Drawing::Point(136, 48);
			this->voltageDec01->Name = L"voltageDec01";
			this->voltageDec01->Size = System::Drawing::Size(45, 23);
			this->voltageDec01->TabIndex = 8;
			this->voltageDec01->Text = L"-0,1";
			this->voltageDec01->UseVisualStyleBackColor = true;
			this->voltageDec01->Click += gcnew System::EventHandler(this, &MainForm::voltageDec01_Click);
			// 
			// voltageInc01
			// 
			this->voltageInc01->Location = System::Drawing::Point(136, 19);
			this->voltageInc01->Name = L"voltageInc01";
			this->voltageInc01->Size = System::Drawing::Size(45, 23);
			this->voltageInc01->TabIndex = 5;
			this->voltageInc01->Text = L"+0,1";
			this->voltageInc01->UseVisualStyleBackColor = true;
			this->voltageInc01->Click += gcnew System::EventHandler(this, &MainForm::voltageInc01_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->currentDec01);
			this->groupBox1->Controls->Add(this->currentInc10);
			this->groupBox1->Controls->Add(this->currentInc01);
			this->groupBox1->Controls->Add(this->currentInc1);
			this->groupBox1->Controls->Add(this->currentValue);
			this->groupBox1->Location = System::Drawing::Point(12, 103);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(300, 85);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Current, А";
			// 
			// currentDec01
			// 
			this->currentDec01->Location = System::Drawing::Point(136, 48);
			this->currentDec01->Name = L"currentDec01";
			this->currentDec01->Size = System::Drawing::Size(45, 23);
			this->currentDec01->TabIndex = 8;
			this->currentDec01->Text = L"-0,1";
			this->currentDec01->UseVisualStyleBackColor = true;
			this->currentDec01->Click += gcnew System::EventHandler(this, &MainForm::currentDec01_Click);
			// 
			// currentInc10
			// 
			this->currentInc10->Location = System::Drawing::Point(238, 32);
			this->currentInc10->Name = L"currentInc10";
			this->currentInc10->Size = System::Drawing::Size(45, 23);
			this->currentInc10->TabIndex = 7;
			this->currentInc10->Text = L"10";
			this->currentInc10->UseVisualStyleBackColor = true;
			this->currentInc10->Click += gcnew System::EventHandler(this, &MainForm::currentInc10_Click);
			// 
			// currentInc01
			// 
			this->currentInc01->Location = System::Drawing::Point(136, 19);
			this->currentInc01->Name = L"currentInc01";
			this->currentInc01->Size = System::Drawing::Size(45, 23);
			this->currentInc01->TabIndex = 5;
			this->currentInc01->Text = L"+0,1";
			this->currentInc01->UseVisualStyleBackColor = true;
			this->currentInc01->Click += gcnew System::EventHandler(this, &MainForm::currentInc01_Click);
			// 
			// currentInc1
			// 
			this->currentInc1->Location = System::Drawing::Point(187, 32);
			this->currentInc1->Name = L"currentInc1";
			this->currentInc1->Size = System::Drawing::Size(45, 23);
			this->currentInc1->TabIndex = 6;
			this->currentInc1->Text = L"1";
			this->currentInc1->UseVisualStyleBackColor = true;
			this->currentInc1->Click += gcnew System::EventHandler(this, &MainForm::currentInc1_Click);
			// 
			// currentValue
			// 
			this->currentValue->DecimalPlaces = 1;
			this->currentValue->Location = System::Drawing::Point(10, 35);
			this->currentValue->Name = L"currentValue";
			this->currentValue->Size = System::Drawing::Size(120, 20);
			this->currentValue->TabIndex = 3;
			this->currentValue->ValueChanged += gcnew System::EventHandler(this, &MainForm::currentValue_ValueChanged);
			// 
			// limitFlag
			// 
			this->limitFlag->AutoSize = true;
			this->limitFlag->Location = System::Drawing::Point(6, 19);
			this->limitFlag->Name = L"limitFlag";
			this->limitFlag->Size = System::Drawing::Size(70, 17);
			this->limitFlag->TabIndex = 12;
			this->limitFlag->Text = L"Limit Flag";
			this->limitFlag->UseVisualStyleBackColor = true;
			this->limitFlag->CheckedChanged += gcnew System::EventHandler(this, &MainForm::limitFlag_CheckedChanged);
			// 
			// moduleAlarm
			// 
			this->moduleAlarm->Controls->Add(this->isAlarm);
			this->moduleAlarm->Controls->Add(this->acFault);
			this->moduleAlarm->Controls->Add(this->fanFailure);
			this->moduleAlarm->Controls->Add(this->moduleSwitch);
			this->moduleAlarm->Controls->Add(this->moduleFault);
			this->moduleAlarm->Controls->Add(this->limitFlag);
			this->moduleAlarm->Location = System::Drawing::Point(318, 12);
			this->moduleAlarm->Name = L"moduleAlarm";
			this->moduleAlarm->Size = System::Drawing::Size(123, 167);
			this->moduleAlarm->TabIndex = 13;
			this->moduleAlarm->TabStop = false;
			this->moduleAlarm->Text = L"Module alarm";
			// 
			// isAlarm
			// 
			this->isAlarm->AutoSize = true;
			this->isAlarm->Location = System::Drawing::Point(6, 145);
			this->isAlarm->Name = L"isAlarm";
			this->isAlarm->Size = System::Drawing::Size(52, 17);
			this->isAlarm->TabIndex = 18;
			this->isAlarm->Text = L"Alarm";
			this->isAlarm->UseVisualStyleBackColor = true;
			this->isAlarm->CheckedChanged += gcnew System::EventHandler(this, &MainForm::isAlarm_CheckedChanged);
			// 
			// acFault
			// 
			this->acFault->AutoSize = true;
			this->acFault->Location = System::Drawing::Point(6, 111);
			this->acFault->Name = L"acFault";
			this->acFault->Size = System::Drawing::Size(63, 17);
			this->acFault->TabIndex = 16;
			this->acFault->Text = L"AC fault";
			this->acFault->UseVisualStyleBackColor = true;
			this->acFault->CheckedChanged += gcnew System::EventHandler(this, &MainForm::acFault_CheckedChanged);
			// 
			// fanFailure
			// 
			this->fanFailure->AutoSize = true;
			this->fanFailure->Location = System::Drawing::Point(6, 88);
			this->fanFailure->Name = L"fanFailure";
			this->fanFailure->Size = System::Drawing::Size(78, 17);
			this->fanFailure->TabIndex = 15;
			this->fanFailure->Text = L"Fan failure ";
			this->fanFailure->UseVisualStyleBackColor = true;
			this->fanFailure->CheckedChanged += gcnew System::EventHandler(this, &MainForm::fanFailure_CheckedChanged);
			// 
			// moduleSwitch
			// 
			this->moduleSwitch->AutoSize = true;
			this->moduleSwitch->Location = System::Drawing::Point(6, 65);
			this->moduleSwitch->Name = L"moduleSwitch";
			this->moduleSwitch->Size = System::Drawing::Size(94, 17);
			this->moduleSwitch->TabIndex = 14;
			this->moduleSwitch->Text = L"Module switch";
			this->moduleSwitch->UseVisualStyleBackColor = true;
			this->moduleSwitch->CheckedChanged += gcnew System::EventHandler(this, &MainForm::moduleSwitch_CheckedChanged);
			// 
			// moduleFault
			// 
			this->moduleFault->AutoSize = true;
			this->moduleFault->Location = System::Drawing::Point(6, 42);
			this->moduleFault->Name = L"moduleFault";
			this->moduleFault->Size = System::Drawing::Size(87, 17);
			this->moduleFault->TabIndex = 13;
			this->moduleFault->Text = L"Module Fault";
			this->moduleFault->UseVisualStyleBackColor = true;
			this->moduleFault->CheckedChanged += gcnew System::EventHandler(this, &MainForm::moduleFault_CheckedChanged);
			// 
			// protectionCode
			// 
			this->protectionCode->FormattingEnabled = true;
			this->protectionCode->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"0", L"1", L"2", L"3", L"4" });
			this->protectionCode->Location = System::Drawing::Point(6, 19);
			this->protectionCode->Name = L"protectionCode";
			this->protectionCode->Size = System::Drawing::Size(111, 21);
			this->protectionCode->TabIndex = 14;
			this->protectionCode->Text = L"0";
			this->protectionCode->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::protectionCode_SelectedIndexChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->protectionCode);
			this->groupBox3->Location = System::Drawing::Point(318, 194);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(123, 50);
			this->groupBox3->TabIndex = 15;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Type of protection";
			// 
			// comPortName
			// 
			this->comPortName->Location = System::Drawing::Point(6, 19);
			this->comPortName->Name = L"comPortName";
			this->comPortName->Size = System::Drawing::Size(100, 20);
			this->comPortName->TabIndex = 16;
			this->comPortName->Text = L"COM8";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->comStart);
			this->groupBox4->Controls->Add(this->comPortName);
			this->groupBox4->Location = System::Drawing::Point(12, 194);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(300, 50);
			this->groupBox4->TabIndex = 17;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Com port";
			// 
			// comStart
			// 
			this->comStart->Location = System::Drawing::Point(208, 18);
			this->comStart->Name = L"comStart";
			this->comStart->Size = System::Drawing::Size(75, 20);
			this->comStart->TabIndex = 17;
			this->comStart->Text = L"Start";
			this->comStart->UseVisualStyleBackColor = true;
			this->comStart->Click += gcnew System::EventHandler(this, &MainForm::comStart_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(454, 275);
			this->Controls->Add(this->moduleAlarm);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox4);
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Эмулятор выпрямителя";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->voltageValue))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentValue))->EndInit();
			this->moduleAlarm->ResumeLayout(false);
			this->moduleAlarm->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void voltageInc01_Click(System::Object^  sender, System::EventArgs^  e) {
		Decimal newValue = (Decimal)(Decimal::ToDouble(voltageValue->Value) + 0.1);
		if (voltageValue->Maximum >= newValue)
			voltageValue->Value = newValue;
	}

	private: System::Void voltageDec01_Click(System::Object^  sender, System::EventArgs^  e) {
		Decimal newValue = (Decimal)(Decimal::ToDouble(voltageValue->Value) - 0.1);
		if (voltageValue->Minimum <= newValue)
			voltageValue->Value = newValue;
	}

	private: System::Void voltageInc1_Click(System::Object^  sender, System::EventArgs^  e) {
		voltageValue->Increment = 1;
	}

	private: System::Void voltageInc10_Click(System::Object^  sender, System::EventArgs^  e) {
		voltageValue->Increment = 10;
	}

	private: System::Void currentInc01_Click(System::Object^  sender, System::EventArgs^  e) {
		Decimal newValue = (Decimal)(Decimal::ToDouble(currentValue->Value) + 0.1);
		if (currentValue->Maximum >= newValue)
			currentValue->Value = newValue;
	}

	private: System::Void currentDec01_Click(System::Object^  sender, System::EventArgs^  e) {
		Decimal newValue = (Decimal)(Decimal::ToDouble(currentValue->Value) - 0.1);
		if (currentValue->Minimum <= newValue)
			currentValue->Value = newValue;
	}

	private: System::Void currentInc1_Click(System::Object^  sender, System::EventArgs^  e) {
		currentValue->Increment = 1;
	}

	private: System::Void currentInc10_Click(System::Object^  sender, System::EventArgs^  e) {
		currentValue->Increment = 10;
	}

	private: System::Void voltageValue_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		rectifierParameters.voltage = Decimal::ToDouble(voltageValue->Value);
	}

	private: System::Void currentValue_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		rectifierParameters.current = Decimal::ToDouble(currentValue->Value);
	}
	private: System::Void limitFlag_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		rectifierParameters.isLimitFlag = limitFlag->Checked;
	}
	private: System::Void moduleFault_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		rectifierParameters.isModuleFault = moduleFault->Checked;
	}
	private: System::Void moduleSwitch_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		rectifierParameters.isModuleSwitch = moduleSwitch->Checked;
	}
	private: System::Void fanFailure_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		rectifierParameters.isFanFailure = fanFailure->Checked;
	}
	private: System::Void acFault_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		rectifierParameters.isAcFault = acFault->Checked;
	}
	private: System::Void isAlarm_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		rectifierParameters.isAlarm = isAlarm->Checked;
	}

	private: System::Void protectionCode_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		rectifierParameters.protectionCode = this->protectionCode->SelectedIndex;
	}


	private: System::Void comStart_Click(System::Object^  sender, System::EventArgs^  e) {
		marshal_context ^ context = gcnew marshal_context();
		const char* portName = context->marshal_as<const char*>(comPortName->Text);
		try {
			parser = new  RectifierParser(portName, rectifierParameters);
			comStart->Enabled = false;
		}
		catch (boost::system::system_error error) {
			delete parser;
			parser = nullptr;
		}
	}

	};
}
