#pragma once
#include <iostream>
#include<string>
#include <string.h>
#include <cctype>

namespace serialcomms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			getPorts();
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
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnConnect;
	private: System::Windows::Forms::Button^ btnExit;


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ btnRead;
	private: System::Windows::Forms::Timer^ readTimer;




	private: System::ComponentModel::IContainer^ components;
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
			this->components = (gcnew System::ComponentModel::Container());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btnRead = (gcnew System::Windows::Forms::Button());
			this->readTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(388, 12);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 0;
			// 
			// serialPort1
			// 
			this->serialPort1->ReadTimeout = 23;
			this->serialPort1->WriteTimeout = 30;
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm::serialPort1_DataReceived);
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"9600", L"115200" });
			this->comboBox2->Location = System::Drawing::Point(388, 39);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(313, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"COM PORT";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(313, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"BAUD RATE\r\n";
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(388, 97);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(121, 37);
			this->btnConnect->TabIndex = 4;
			this->btnConnect->Text = L"CONNECT";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(388, 140);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(121, 37);
			this->btnExit->TabIndex = 5;
			this->btnExit->Text = L"EXIT";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 17);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(243, 133);
			this->textBox1->TabIndex = 6;
			// 
			// btnRead
			// 
			this->btnRead->Location = System::Drawing::Point(12, 170);
			this->btnRead->Name = L"btnRead";
			this->btnRead->Size = System::Drawing::Size(243, 34);
			this->btnRead->TabIndex = 8;
			this->btnRead->Text = L"READ";
			this->btnRead->UseVisualStyleBackColor = true;
			this->btnRead->Click += gcnew System::EventHandler(this, &MyForm::btnRead_Click);
			// 
			// readTimer
			// 
			this->readTimer->Tick += gcnew System::EventHandler(this, &MyForm::readTimer_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(521, 261);
			this->Controls->Add(this->btnRead);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnConnect);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: void getPorts(void) {
		array<Object^>^ arrayObj = SerialPort::GetPortNames();
		this->comboBox1->Items->AddRange(arrayObj);
	}

	//Connect buttton event handler
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//Connection error
		bool conError;
		//this->textBox1->Text = "Hellow";
		if (this->comboBox1->Text != String::Empty && this->comboBox2->Text != String::Empty) {
			this->textBox1->Text = String::Empty;
			try {
				if (!this->serialPort1->IsOpen) {
					this->serialPort1->PortName = comboBox1->Text;
					this->serialPort1->BaudRate = Int32::Parse(comboBox2->Text);
					readTimer->Enabled = false;
					this->serialPort1->Open();
				}
			}
			catch (UnauthorizedAccessException^) { conError = true; }
			catch (System::IO::IOException^) { conError = true; }
			catch (ArgumentException^) { conError = true; }
			if (conError) MessageBox::Show(this, "Could not open COM port. Port could be in use!");
		}
		else {
			MessageBox::Show("Please select all COM Port settings");
		}

	}

	//Exit button event handler
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->serialPort1->Close();
		this->btnRead->Enabled = true;
		this->btnConnect->Enabled = true;
	}
	private: System::Void btnRead_Click(System::Object^ sender, System::EventArgs^ e) {
		serialPort1->Close();
		serialPort1->Open();
		//if (!(this->serialPort1->IsOpen)) {

			//serialPort1->Open();

			readTimer->Enabled = true;
			serialPort1->DiscardInBuffer();
			serialPort1->DiscardOutBuffer();
			//try {
			//	this->textBox1->Text = this->serialPort1->ReadExisting();
			//	//this->textBox1->Text="I see something";
			//}
			//catch (TimeoutException^) {
			//	MessageBox::Show("Timeout Exception");
			//}
		//}
	}
	private: System::Void serialPort1_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
	//textBox1->AppendText(serialPort1->ReadLine() + "\n");
		}


private: System::Void readTimer_Tick(System::Object^ sender, System::EventArgs^ e) {

	if (this->serialPort1->IsOpen) {
		this->textBox1->Text = this->serialPort1->ReadExisting();
	}
	
}
};
}
