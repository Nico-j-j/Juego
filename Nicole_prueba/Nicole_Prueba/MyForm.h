#pragma once
#include"VecFigura.h"
#include "Linea.h"
#include "Juego.h"
#include "MyForm.h"

namespace NicolePrueba {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		CVecFiguras * oVecFigura = new CVecFiguras();
		
		CLinea * oLinea = new CLinea();
	private: System::Windows::Forms::Timer^  timerBala;

	public:
		Juego *juego = new Juego();

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
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
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerBala = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timerBala
			// 
			this->timerBala->Tick += gcnew System::EventHandler(this, &MyForm::timerBala_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(879, 501);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Click);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext ^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics ^ buffer = espacio->Allocate(g, this->ClientRectangle);
		oVecFigura->Dibujar(buffer->Graphics);
		oVecFigura->Mover(512, 362);
		oLinea->dibujar(buffer->Graphics);
		juego->fondo(buffer->Graphics);
		juego->dibujar(buffer->Graphics);
		//oVecFigura->Eliminar(dX,dY);
		buffer->Render(g);
		g->FillEllipse(Brushes::Red, 235, 10, 25, 25);
		g->FillEllipse(Brushes::Red, 260, 10, 25, 25);
		g->FillEllipse(Brushes::Red, 285, 10, 25, 25);
		g->FillEllipse(Brushes::Blue,310, 10, 25, 25);
		g->FillEllipse(Brushes::Green, 335, 10, 25, 25);
		g->FillEllipse(Brushes::Green, 360, 10, 25, 25);
		g->FillEllipse(Brushes::Red, 385, 10, 25, 25);
		g->FillEllipse(Brushes::Blue, 410, 10, 25, 25);
		g->FillEllipse(Brushes::Red, 435, 10, 25, 25);
		g->FillEllipse(Brushes::Green, 460, 10, 25, 25);
		g->FillEllipse(Brushes::Blue, 485, 10, 25, 25);
		g->FillEllipse(Brushes::Green, 510, 10, 25, 25);
		g->FillEllipse(Brushes::Red, 535, 10, 25, 25);
		g->FillEllipse(Brushes::Blue, 560, 10, 25, 25);
		g->FillEllipse(Brushes::Blue, 585, 10, 25, 25);
		g->FillEllipse(Brushes::Blue, 245, 32, 25, 25);
		g->FillEllipse(Brushes::Green, 270, 32, 25, 25);
		g->FillEllipse(Brushes::Green, 295, 32, 25, 25);
		g->FillEllipse(Brushes::Blue, 320, 32, 25, 25);
		g->FillEllipse(Brushes::Red, 345, 32, 25, 25);
		g->FillEllipse(Brushes::Blue, 370, 32, 25, 25);
		g->FillEllipse(Brushes::Green, 395, 32, 25, 25);
		g->FillEllipse(Brushes::Red, 420, 32, 25, 25);
		g->FillEllipse(Brushes::Red, 445, 32, 25, 25);
		g->FillEllipse(Brushes::Green, 470, 32, 25, 25);
		g->FillEllipse(Brushes::Blue, 495, 32, 25, 25);
		g->FillEllipse(Brushes::Blue, 520, 32, 25, 25);
		g->FillEllipse(Brushes::Green, 545, 32, 25, 25);
		g->FillEllipse(Brushes::Red, 570, 32, 25, 25);
		g->FillEllipse(Brushes::Blue, 259, 54, 25, 25);
		g->FillEllipse(Brushes::Green, 284,54 , 25, 25);
		g->FillEllipse(Brushes::Blue, 309, 54, 25, 25);
		g->FillEllipse(Brushes::Green, 334, 54, 25, 25);
		g->FillEllipse(Brushes::Green, 359, 54, 25, 25);
		g->FillEllipse(Brushes::Red, 384, 54, 25, 25);
		g->FillEllipse(Brushes::Blue, 409, 54, 25, 25);
		g->FillEllipse(Brushes::Red, 434, 54, 25, 25);
		g->FillEllipse(Brushes::Green, 459, 54, 25, 25);
		g->FillEllipse(Brushes::Red, 484, 54, 25, 25);
		g->FillEllipse(Brushes::Blue, 509, 54, 25, 25);
		g->FillEllipse(Brushes::Green, 534, 54, 25, 25);
		g->FillEllipse(Brushes::Red, 559, 54, 25, 25);
		g->FillEllipse(Brushes::Red, 270, 76, 25, 25);
		g->FillEllipse(Brushes::Blue, 295, 76, 25, 25);
		g->FillEllipse(Brushes::Blue, 320, 76, 25, 25);
		g->FillEllipse(Brushes::Green, 345, 76, 25, 25);
		g->FillEllipse(Brushes::Red, 370, 76, 25, 25);
		g->FillEllipse(Brushes::Green, 395, 76, 25, 25);
		g->FillEllipse(Brushes::Blue, 420, 76, 25, 25);
		g->FillEllipse(Brushes::Red, 445, 76, 25, 25);
		g->FillEllipse(Brushes::Red, 470, 76, 25, 25);
		g->FillEllipse(Brushes::Green, 495, 76, 25, 25);
		g->FillEllipse(Brushes::Red, 520, 76, 25, 25);
		g->FillEllipse(Brushes::Blue, 545, 76, 25, 25);
		g->FillEllipse(Brushes::Green, 282, 98, 25, 25);
		g->FillEllipse(Brushes::Red, 307, 98, 25, 25);
		g->FillEllipse(Brushes::Red, 332, 98, 25, 25);
		g->FillEllipse(Brushes::Blue, 357, 98, 25, 25);
		g->FillEllipse(Brushes::Red, 382, 98, 25, 25);
		g->FillEllipse(Brushes::Green, 407, 98, 25, 25);
		g->FillEllipse(Brushes::Green, 432, 98, 25, 25);
		g->FillEllipse(Brushes::Blue, 457, 98, 25, 25);
		g->FillEllipse(Brushes::Red, 482, 98, 25, 25);
		g->FillEllipse(Brushes::Red, 507, 98, 25, 25);
		g->FillEllipse(Brushes::Green, 532, 98, 25, 25);
		delete buffer;
		delete espacio;
		delete g;
		
	}


	private: System::Void MyForm_Click(System::Object^  sender, System::EventArgs^  e) {
		//oVecFigura->Agregar(256, 320, 25, 25, 5, 5);
		//int Tipo;
		////oVecFigura->Cambio(oLinea->getX(), oLinea->getY());
		//oVecFigura->Cambio(Tipo);
	}


	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		int Tipo = 0;
		
		if (e->KeyData == Keys::A)
			Tipo = 1;
		else if (e->KeyData == Keys::S)
			Tipo = 2;
		else if (e->KeyData == Keys::D)
			Tipo = 3;
		
		if (Tipo != 0)
			oVecFigura->Cambio(Tipo);
			//oVecFigura->Cambio(Tipo);
	}
	private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		oLinea->setX(e->X);
		oLinea->setY(e->Y);
	}
private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//oVecFigura->Cambio(5, 5);
	juego->disparar();
	timerBala->Enabled = true;
}
private: System::Void timerBala_Tick(System::Object^  sender, System::EventArgs^  e) {
	int pX, pY;
	juego->mover(512, 500);
	juego->eliminar(pX, pY);
	/*if (juego->colision = 0)
	timerBala->Enabled = false;*/
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	
}
};
}
