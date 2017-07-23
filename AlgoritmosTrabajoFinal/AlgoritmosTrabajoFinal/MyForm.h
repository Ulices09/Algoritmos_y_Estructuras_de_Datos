#pragma once
#include "JuegoController.h"
namespace AlgoritmosTrabajoFinal {

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
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		JuegoController* juego;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 40;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1045, 690);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MinimumSize = System::Drawing::Size(1061, 728);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				juego = new JuegoController();
				timer1->Enabled = true;

	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 System::Drawing::Graphics ^gr = this->CreateGraphics();
				 BufferedGraphicsContext ^bgc = BufferedGraphicsManager::Current;
				 BufferedGraphics ^bg = bgc->Allocate(gr, this->ClientRectangle);

				 bg->Graphics->Clear(System::Drawing::SystemColors::ButtonFace);
				 juego->Mostrar(bg->Graphics);			
				 bg->Render(gr);

				 delete bg;
				 delete bgc;
				 delete gr;
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 juego->Mover(e->KeyCode);
	}
	};
}
