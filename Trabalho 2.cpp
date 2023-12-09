#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void MsgErro()
{
	cout << "\nOpção incorreta! Informe um valor válido (1, 2 ou 3): ";
}

void InfoCliente(string cli, int veic, int serv, int pagar)
{
	setlocale(LC_ALL, "portuguese");

	cout << "__________________________________________________________________________________";
	cout << "\nCliente: " << cli << endl;
	
	switch(veic)
	{
		case 1:
			cout << "Veículo pequeno (popular)" << endl;
			break;		
		case 2:
			cout << "Veículo médio (SUV/Camionete)" << endl;
			break;			
		case 3:
			cout << "Veículo grande (Van/Micro-ônibus)" << endl;
			break;
	}
	
	switch(serv)
	{
		case 1:
			cout << "Lavação externa" << endl;
			break;		
		case 2:
			cout << "Lavação externa + interna" << endl;
			break;			
		case 3:
			cout << "Lavação externa + interna + cera" << endl;
			break;
	}
	
	cout << "Valor total: R$" << pagar << ",00" << endl << endl;
}

void ListaClientes(string cliente[], int quant, int tipo[], int servico[])
{
	int i, preco[3][3] = {{30, 50, 70},{50, 70, 90},{70, 90, 110}};
	system("CLS");
	cout << "LAVAÇÂO AUTOMOTIVA\n\nRelação de clientes atendidos(as)\n";
		
	for(i=0; i<quant; i++)
	{
		cout << "______________________________________\n" << cliente[i] << ": ";
		
		if(tipo[i]==1)
			cout << "Veículo pequeno |";
		else if(tipo[i]==2)
			cout << "Veículo médio |";
		else
			cout << "Veículo grande |";
			
		if(servico[i]==1)
			cout << "Lavação externa |";
		else if(servico[i]==2)
			cout << "Lavação externa + interna |";
		else
			cout << "Lavação externa + interna + cera |";
			
		cout << " Valor pago: R$" << preco[tipo[i]-1][servico[i]-1] << ",00\n";	
					
	}
	cout << endl;
	system("PAUSE");
	system("CLS");	
}


int main()
{
	setlocale(LC_ALL, "portuguese");
	
	int preco[3][3] = {{30, 50, 70},{50, 70, 90},{70, 90, 110}}, i, tot_atend, vei1=0, vei2=0, vei3=0, sv1=0, sv2=0, sv3=0, opcao, total_arrec=0;

	cout << "LAVAÇÃO AUTOMOTIVA\n\nInforme a quantidade de atendimentos do dia: ";
	cin >> tot_atend;
	system("PAUSE");
	
	string cliente[tot_atend];
	int tipo[tot_atend], servico[tot_atend], valor[tot_atend], veic1=0, veic2=0, veic3=0, serv1=0, serv2=0, serv3=0;	
	
	for(i=0; i<tot_atend; i++)
	{
		system("CLS");
		cout << "LAVAÇÃO AUTOMOTIVA\n\nNome do(a) cliente: ";
		cin >> cliente[i];
		
		cout << "\nTipo do veículo (1- Pequeno / 2- Médio / 3- Grande): ";
		cin >> tipo[i];
		
		while(tipo[i]>3 or tipo[i]<1)
		{
			MsgErro();
			cin >> tipo[i];
		}
		
		switch(tipo[i])
		{
			case 1:
				vei1++;
				break;			
			case 2:
				vei2++;
				break;				
			case 3:
				vei3++;
				break;
		}	
		
		cout << "\nServiço realizado (1- Lavação externa / 2- Lavação externa + interna / 3 - Lavação externa + interna + cera): ";
		cin >> servico[i];
		
		while(servico[i]>3 or servico[i]<1)
		{
			MsgErro();
			cin >> servico[i];
		}
		
		switch(servico[i])
		{
			case 1:
				sv1++;
				break;			
			case 2:
				sv2++;
				break;				
			case 3:
				sv3++;
				break;
		}

		valor[i]=preco[tipo[i]-1][servico[i]-1];
		total_arrec+=valor[i];
		
		switch(tipo[i])
		{
			case 1:
				veic1+=preco[0][servico[i]-1];
				break;
	
			case 2:
				veic2+=preco[1][servico[i]-1];
				break;
	
			case 3:
				veic3+=preco[2][servico[i]-1];
				break;			
		}
	
		switch(servico[i])
		{
			case 1:
				serv1+=preco[0][tipo[i]-1];
				break;
	
			case 2:
				serv2+=preco[1][tipo[i]-1];
				break;
	
			case 3:
				serv3+=preco[2][tipo[i]-1];	
				break;		
		}
		
		InfoCliente(cliente[i], tipo[i], servico[i], valor[i]);
		
		system("PAUSE");
		system("CLS");
	}

	do
	{
		cout << "LAVAÇÃO AUTOMOTIVA\n\nRelatório diário\n\nVeículos atendidos no dia: " << tot_atend;
		cout << "\n__________________________________________________________________________________";
		cout << "\n\nSelecione uma opção\n\n1 - Relação de clientes\n2 - Percentuais de atendimentos por categoria de veículo\n3 - Percentuais de atendimentos por tipo de serviço\n";
		cout << "4 - Valor total arrecadado\n5 - Veículo mais atendido\n6 - Serviço mais atendido\n7 - Sair\n";
		cin >> opcao;
		
		switch(opcao)
		{
			case 1:								
				ListaClientes(cliente, tot_atend, tipo, servico);				
				break;
				
			case 2:
				system("CLS");
				cout << "LAVAÇÂO AUTOMOTIVA\n\nPercentuais de atendimentos por categoria de veículo:\n\n";
				cout << "Veículos Pequenos___________________________________" << vei1*100.0/tot_atend << "%" << endl;	
				cout << "Veículos Médios_____________________________________" << vei2*100.0/tot_atend << "%" << endl;			
				cout << "Veículos Grandes____________________________________" << vei3*100.0/tot_atend << "%" << endl << endl;			
				system("PAUSE");
				system("CLS");
				break;
			
			case 3:
				system("CLS");
				cout << "LAVAÇÂO AUTOMOTIVA\n\nPercentuais de atendimentos por tipo de serviço realizado:\n\n";
				cout << "Lavação externa___________________________________" << sv1*100.0/tot_atend << "%" << endl;	
				cout << "Lavação externa + interna_________________________" << sv2*100.0/tot_atend << "%" << endl;			
				cout << "Lavação externa + interna + cera__________________" << sv3*100.0/tot_atend << "%" << endl << endl;			
				system("PAUSE");
				system("CLS");
				break;
				
			case 4:
				system("CLS");
				cout << "LAVAÇÂO AUTOMOTIVA\n\nValor total arrecadado\n\nPor tipo de veículo:\n\n";
				cout << "Veículos pequenos________________________________R$" << veic1 << ",00" << endl; 
				cout << "Veículos médios__________________________________R$" << veic2 << ",00" << endl; 
				cout << "Veículos grandes_________________________________R$" << veic3 << ",00" << endl;
				cout << "\nPor tipo de serviço:\n\n";
				cout << "Lavação externa__________________________________R$" << serv1 << ",00" << endl; 
				cout << "Lavação externa + interna________________________R$" << serv2 << ",00" << endl; 
				cout << "Lavação externa + interna + cera_________________R$" << serv3 << ",00" << endl;
				cout << "\nTOTAL ARRECADADO NO DIA__________________________R$" << total_arrec << ",00" << "\n\n" <<flush;
				system("PAUSE");
				system("CLS");
				break;
				
			case 5:
				system("CLS");
				cout << "LAVAÇÂO AUTOMOTIVA\n\n";
				if(vei1>vei2 && vei1>vei3)
					cout << "\nVeículo mais atendido do dia: carro pequeno.\nTotal de atendimentos: " << vei1 << "\n\n";
				else if(vei2>vei1 && vei2>vei3)			
					cout << "\nVeículo mais atendido do dia: carro medio.\nTotal de atendimentos: " << vei2 << "\n\n";
				else if(vei3>vei1 && vei3>vei2)
					cout << "\nVeículo mais atendido do dia: carro grande.\nTotal de atendimentos: " << vei3 << "\n\n";
				else if(vei1==vei2 && vei1>vei3)				
					cout << "\nVeículos mais atendidos do dia: carros pequenos e medios.\nTotal de atendimentos (cada): " << vei1 << "\n\n";				
				else if(vei1==vei3 && vei1>vei2)				
					cout << "\nVeículos mais atendidos do dia: carros pequenos e grandes.\nTotal de atendimentos (cada): " << vei1 << "\n\n";				
				else if(vei2==vei3 && vei2>vei1)				
					cout << "\nVeículos mais atendidos do dia: carros medios e grandes.\nTotal de atendimentos (cada): " << vei2 << "\n\n";				
				else				
					cout << "\nMesma quantidade de veículo pequenos, medios e grandes atendidos no dia.\nTotal de atendimentos (cada): " << vei1 << "\n\n";
				system("PAUSE");
				system("CLS");
				break;
				
			case 6:
				system("CLS");
				cout << "LAVAÇÂO AUTOMOTIVA\n\n";
				if(sv1>sv2 && sv1>sv3)
					cout << "\nServiço mais realizado do dia: lavação externa.\nTotal de atendimentos: " << sv1 << "\n\n";
				else if(sv2>sv1 && sv2>sv3)			
					cout << "\nServiço mais realizado do dia: lavação externa + interna.\nTotal de atendimentos: " << sv2 << "\n\n";
				else if(sv3>sv1 && sv3>sv2)
					cout << "\nServiço mais realizado do dia: lavação externa + interna + cera.\nTotal de atendimentos: " << sv3 << "\n\n";
				else if(sv1==sv2 && sv1>sv3)				
					cout << "\nServiços mais realizados do dia: lavação externa E externa + interna.\nTotal de atendimentos (cada): " << sv1 << "\n\n";				
				else if(sv1==sv3 && sv1>sv2)				
					cout << "\nServiços mais realizados do dia: lavação externa E externa + interna + cera.\nTotal de atendimentos (cada): " << sv1 << "\n\n";				
				else if(sv2==sv3 && sv2>sv1)				
					cout << "\nServiço mais realizado do dia: lavação externa + interna E externa + interna + cera.\nTotal de atendimentos (cada): " << sv2 << "\n\n";				
				else				
					cout << "\nMesma quantidade de serviços realizados no dia.\nTotal de atendimentos (cada): " << sv1 << "\n\n";
				system("PAUSE");
				system("CLS");
				break;							
			 
			 case 7:
			 	cout << "\n\n****************** O sistema foi encerrado! Tenha um bom dia! ******************\n\n" << endl;
			 	system("PAUSE");
				break;
			 	
			default:
				cout << "\nOpção incorreta!!!\n\n" << flush;
				system("PAUSE");
				system("CLS");
				break;										
		}
				
	}while(opcao!=7);	
	
	return 0;
}
