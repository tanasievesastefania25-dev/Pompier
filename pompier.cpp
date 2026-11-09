#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


enum Functie{servant,sefFormatie,voluntar,sofer};
class Pompier
{
	private:
	const int idPompier;
	string nume;
	Functie functie;
	int nrInterventii;
	float* durate;
	static  int contor;
	public:
	
	//constructor fara param
		Pompier() :idPompier(contor++)
		{
		this->nume="NA";
		this->functie=voluntar;
		this->nrInterventii=0;
		this->durate=NULL;

	}
	//constructor cu param -validari pt nume si functie 
		Pompier( string numeInit,Functie functieInit ,int nrInterventiiInit ,float* durateInit):idPompier(contor++)
		{
			if (numeInit.length()>0)
			{
			this->nume=numeInit;
		}
			else
			{
				this->nume="NA";
			}
			if (nrInterventiiInit > 0 && durateInit != nullptr)
			{
				this->nrInterventii = nrInterventiiInit;
				this->durate = new float[nrInterventiiInit];
				for (int i = 0; i < nrInterventiiInit;i++)
				{
					this->durate[i] = durateInit[i];
				}
			}

			else {
				this->durate = nullptr;
				this->nrInterventii = 0;
			}
			if (functieInit >= servant && functieInit <= sofer)
			{
			this->functie=functieInit;
			}
			else
			{
				this->functie=voluntar;
			}

		}
		//constructor de copiere 
		Pompier(const Pompier& p) :idPompier(contor++)
		{
			this->nume=p.nume;
			if (p.nrInterventii > 0 && p.durate != nullptr)
			{
				this->nrInterventii=p.nrInterventii;
				this->durate=new float[p.nrInterventii];
				for (int i = 0; i < p.nrInterventii;i++)
				{
					this->durate[i]=p.durate[i];
				}
				}

			else {
				this->durate=nullptr;
				this->nrInterventii=0;
			}
			this->functie=p.functie;
		


		}
		//op =
		Pompier& operator=(const Pompier& p)
		{
			if (this == &p) {
				return *this;
		}
			if (durate != nullptr)
			{
				delete[]this->durate;
			}

			this->nume=p.nume;
			this->functie = p.functie;
			if (p.nrInterventii > 0 && p.durate != nullptr)
			{
				this->nrInterventii = p.nrInterventii;
				this->durate = new float[p.nrInterventii];
				for (int i = 0; i < p.nrInterventii;i++)
				{
					this->durate[i] = p.durate[i];
				}
			}

			else {
				this->durate = nullptr;
				this->nrInterventii = 0;
			}
			return *this;



		

		}
		//destructor
		~Pompier() {

			if (durate != nullptr)
			{
				delete[]this->durate;
			}
		}
		//op <<
		friend ostream& operator<<(ostream& out ,const Pompier& p) 
		{
		out<<p.idPompier<<endl;
		out<<p.nume<<endl;

		
		out<<p.functie<<endl;
		out<<p.nrInterventii<<endl;
		for (int i = 0;i < p.nrInterventii;i++)
		{
			out<<p.durate[i]<<" ";
		}
		out<<endl;
		return out;
		
		}

		//op >>
		// nume
		friend istream& operator>>(istream& in, Pompier& p)
		{
			cout<<"Nume: ";
			string nume;
			getline(in,nume);
			if (nume.length() > 0)
			{
				p.nume=nume;
			}
			return in;
		}

		//op > compara lungimea numelor 
		bool operator>(const Pompier& p)
		{
			if (this->nume.length() > p.nume.length())
			{
				return this;
		}
			else
			{
				return false;
			}
		}
		//op ++
		//pre incrementare ++f
		Pompier& operator++() {
		this->nrInterventii++;
		return *this;
		}
		//post incrementare f++
		Pompier& operator++(int)
		{
			Pompier copie=*this;
			this->nrInterventii++;
			return copie;
		}
		////op +
		////ob+val
		//Pompier& operator+(float val)
		//{
		//	if (durate > 0) {

		//
		//	Pompier copie=new float[copie.nrInterventii];
		//	for(int i=0;i<copie.nrInterventii;i++)
		//	{ 
		//	copie.durate[i]=copie.nrInterventii[i];
		//	}
		//	copie.durate+=val;
		//	return copie;
		//	}
		//	}
		//	//ob+ob
		//	Pompier& operator+(const Pompier & p)
		//	{
		//		Pompier copie=*this;
		//		copie.durate+=p.durate;
		//		return copie;
		//	}

		////op ()
		//float operator()()const
		//{
		//	if (nrInterventii == 0 && this->durate==nullptr)
		//	{
		//		return 0;
		//		
		//	}
		//	float suma=0;
		//	for (int i = 0;i < this->nrInterventii;i++)
		//	{
		//		suma+=this->durate;
		//	}
		//	return += this->durate[i];
		//}

		//return suma/this->nrInterventii;
		//
		//
		
		//getter si setter 
		//getter pt interventii
		int getNrInterventii()
		{
			return this->nrInterventii;
		}
		// getter si setter pt nume si functie 
		//nume
		string  getNume() {
			return this->nume;
		}
		
		void setNume(string numeNou) {
			if (numeNou.length()> 0)
			{
			this->nume=numeNou;
			}
			}
			//pt functie setter intre servant si sofer 
		Functie getFunctie()
		{
		return this->functie;

			}
			void setFunctie(Functie functieNoua)
			{ 
				if (functieNoua >= servant && functieNoua <= sofer)
				{
					this->functie=functieNoua;
			}
			}
		
};
int Pompier::contor=0;
int main()
{
//constr fara param 
Pompier p1;
cout<<p1<<endl;

//constr cu param 
float d[]{1.5f,2.3f,4.0f};
Pompier p2("Popescu",sefFormatie,3,d);
cout<<p2<<endl;

//constructor de copiere
Pompier p3=p2;
cout<<p3<<endl;


//op=
p1=p2;
cout<<p1<<endl;

//get si set nume si functie
cout<<p1.getFunctie()<<endl;
p1.setFunctie(servant);
cout<<p1.getFunctie()<<endl;
cout<<p1.getNume()<<endl;
p1.setNume("Marian");
cout<<p1<<endl;

//>> 
Pompier p6;
cin>>p6;
cout<<p6<<endl;

//op >
Pompier p7("Popescu", sefFormatie, 3, d);
cout<<(p7>p2)<<endl;

//op ++
Pompier p8("Popescu", sefFormatie, 3, d);
cout<<(++p8).getNrInterventii()<<endl;
cout<<(p8++).getNrInterventii()<<endl;
cout<<p8.getNrInterventii()<<endl;



return 0;

}