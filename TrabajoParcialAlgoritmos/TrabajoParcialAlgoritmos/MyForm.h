#pragma once

namespace TrabajoParcialAlgoritmos {

	#include "CLista.h"
	#include "CNodo.h"
	#include "CLista.cpp"
	#include "CNodo.cpp"
	#include "CFondo.h"
	#include "CFondo.cpp"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			txtDato->Select();
			listaCuadrados = new CLista();
			fondo = new CFondo();
			x = 300;
			y = 200;
			bmp_Fondo = gcnew Bitmap("fondoTP1.jpg");
			comboBoxInsertar->SelectedIndex = 0;
			quitarRelleno = false;
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonInsertar;
	protected:
	private: System::Windows::Forms::TextBox^  txtDato;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		CLista* listaCuadrados;
		CFondo* fondo;
		int x, y;
		bool quitarRelleno;
	private: System::Windows::Forms::ComboBox^  comboBoxInsertar;
	private: System::Windows::Forms::Label^  lblDato;

	private: System::Windows::Forms::TextBox^  txtPosicion;
	private: System::Windows::Forms::Label^  lblPosicion;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel1;


			 Bitmap ^bmp_Fondo;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->buttonInsertar = (gcnew System::Windows::Forms::Button());
			this->txtDato = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->comboBoxInsertar = (gcnew System::Windows::Forms::ComboBox());
			this->lblDato = (gcnew System::Windows::Forms::Label());
			this->txtPosicion = (gcnew System::Windows::Forms::TextBox());
			this->lblPosicion = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonInsertar
			// 
			this->buttonInsertar->BackColor = System::Drawing::SystemColors::ControlLight;
			this->buttonInsertar->Location = System::Drawing::Point(164, 13);
			this->buttonInsertar->Name = L"buttonInsertar";
			this->buttonInsertar->Size = System::Drawing::Size(75, 23);
			this->buttonInsertar->TabIndex = 0;
			this->buttonInsertar->Text = L"Insertar";
			this->buttonInsertar->UseVisualStyleBackColor = false;
			this->buttonInsertar->Click += gcnew System::EventHandler(this, &MyForm::buttonInsertar_Click);
			// 
			// txtDato
			// 
			this->txtDato->Location = System::Drawing::Point(58, 13);
			this->txtDato->Name = L"txtDato";
			this->txtDato->Size = System::Drawing::Size(100, 20);
			this->txtDato->TabIndex = 1;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// comboBoxInsertar
			// 
			this->comboBoxInsertar->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxInsertar->FormattingEnabled = true;
			this->comboBoxInsertar->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"+ Al inicio", L"+ Al final", L"+ En posición",
					L"» Buscar", L"- Eliminar"
			});
			this->comboBoxInsertar->Location = System::Drawing::Point(243, 13);
			this->comboBoxInsertar->Name = L"comboBoxInsertar";
			this->comboBoxInsertar->Size = System::Drawing::Size(85, 21);
			this->comboBoxInsertar->TabIndex = 2;
			this->comboBoxInsertar->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxInsertar_SelectedIndexChanged);
			// 
			// lblDato
			// 
			this->lblDato->AutoSize = true;
			this->lblDato->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDato->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(61)));
			this->lblDato->Location = System::Drawing::Point(2, 21);
			this->lblDato->Name = L"lblDato";
			this->lblDato->Size = System::Drawing::Size(33, 13);
			this->lblDato->TabIndex = 3;
			this->lblDato->Text = L"Dato:";
			// 
			// txtPosicion
			// 
			this->txtPosicion->Location = System::Drawing::Point(58, 41);
			this->txtPosicion->Name = L"txtPosicion";
			this->txtPosicion->Size = System::Drawing::Size(43, 20);
			this->txtPosicion->TabIndex = 5;
			this->txtPosicion->Visible = false;
			// 
			// lblPosicion
			// 
			this->lblPosicion->AutoSize = true;
			this->lblPosicion->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(61)));
			this->lblPosicion->Location = System::Drawing::Point(2, 44);
			this->lblPosicion->Name = L"lblPosicion";
			this->lblPosicion->Size = System::Drawing::Size(50, 13);
			this->lblPosicion->TabIndex = 4;
			this->lblPosicion->Text = L"Posicion:";
			this->lblPosicion->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(93, 25);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->txtPosicion);
			this->panel1->Controls->Add(this->lblDato);
			this->panel1->Controls->Add(this->lblPosicion);
			this->panel1->Controls->Add(this->comboBoxInsertar);
			this->panel1->Controls->Add(this->txtDato);
			this->panel1->Controls->Add(this->buttonInsertar);
			this->panel1->Location = System::Drawing::Point(299, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(337, 61);
			this->panel1->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 561);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1000, 600);
			this->MinimumSize = System::Drawing::Size(1000, 600);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Listas Simples";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 Graphics ^gr = this->CreateGraphics();
				 BufferedGraphicsContext ^bgc = BufferedGraphicsManager::Current;
				 BufferedGraphics ^bg = bgc->Allocate(gr, this->ClientRectangle);

				 fondo->Mostrar(bg->Graphics, bmp_Fondo);
				 listaCuadrados->mostrar(bg->Graphics);				 
				 bg->Render(gr);

				 delete bg;
				 delete bgc;
				 delete gr;
	}

	private: System::Void buttonInsertar_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (txtDato->Text->Length > 0){
					 char dato[1];
					 sprintf(dato, "%s", txtDato->Text);
					 if (comboBoxInsertar->SelectedIndex == 0){						 
						 listaCuadrados->InsertarInicio(x, y, dato);			 
					 }
					 else if (comboBoxInsertar->SelectedIndex == 1){
						 listaCuadrados->insertarFin(x, y, dato);
					 }
					 else if (comboBoxInsertar->SelectedIndex == 2){
						 if (txtPosicion->Text->Length > 0){
							 int posicion = Convert::ToInt32(txtPosicion->Text);
							 listaCuadrados->insertarEnPosicion(x, y, dato, posicion);
						 }
						 else{
							 MessageBox::Show("Ingrese posición!");
						 }
						 txtPosicion->Text = "";
					 }
					 else if (comboBoxInsertar->SelectedIndex == 3){
						 if (quitarRelleno == true) quitarRelleno = listaCuadrados->quitarRelleno(quitarRelleno);
						 listaCuadrados->buscar(dato); 
						 txtDato->Text = "";
						 txtDato->Select();
						 quitarRelleno = true;						 
						 return;
					 }
					 else if (comboBoxInsertar->SelectedIndex == 4){
						 listaCuadrados->eliminar(dato);
					 }
					 listaCuadrados->ordenarNodos();
					 txtDato->Text = "";	
					 txtDato->Select();
					 quitarRelleno = listaCuadrados->quitarRelleno(quitarRelleno);
					 x += 70;
				 }
				 else{
					 MessageBox::Show("Ingrese dato!");
				 }
	}


	private: System::Void comboBoxInsertar_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (comboBoxInsertar->SelectedIndex == 2){
					 lblPosicion->Visible = true;
					 txtPosicion->Visible = true;
					 panel1->Height = 70;
					 buttonInsertar->Text = "Insertar";
				 }
				 else{
					 if (comboBoxInsertar->SelectedIndex == 3)
						 buttonInsertar->Text = "Buscar";
					 else if(comboBoxInsertar->SelectedIndex == 4)
						 buttonInsertar->Text = "Eliminar";
					 else
						 buttonInsertar->Text = "Insertar";			 

					 lblPosicion->Visible = false;
					 txtPosicion->Visible = false;
					 panel1->Height = 50;					
				 }

	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 int size = listaCuadrados->getSize();
			 MessageBox::Show(size.ToString());
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
