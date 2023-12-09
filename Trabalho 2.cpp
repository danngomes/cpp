#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void MsgErro()
{
	cout << "\nOp��o incorreta! Informe um valor v�lido (1, 2 ou 3): ";
}

void InfoCliente(string cli, int veic, int serv, int pagar)
{
	setlocale(LC_ALL, "portuguese");

	cout << "__________________________________________________________________________________";
	cout << "\nCliente: " << cli << endl;
	
	switch(veic)
	{
		case 1:
			cout << "Ve�culo pequeno (popular)" << endl;
			break;		
		case 2:
			cout << "Ve�culo m�dio (SUV/Camionete)" << endl;
			break;			
		case 3:
			cout << "Ve�culo grande (Van/Micro-�nibus)" << endl;
			break;
	}
	
	switch(serv)
	{
		case 1:
			cout << "Lava��o externa" << endl;
			break;		
		case 2:
			cout << "Lava��o externa + interna" << endl;
			break;			
		case 3:
			cout << "Lava��o externa + interna + cera" << endl;
			break;
	}
	
	cout << "Valor total: R$" << pagar << ",00" << endl << endl;
}

void ListaClientes(string cliente[], int quant, int tipo[], int servico[])
{
	int i, preco[3][3] = {{30, 50, 70},{50, 70, 90},{70, 90, 110}};
	system("CLS");
	cout << "LAVA��O AUTOMOTIVA\n\nRela��o de clientes atendidos(as)\n";
		
	for(i=0; i<quant; i++)
	{
		cout << "______________________________________\n" << cliente[i] << ": ";
		
		if(tipo[i]==1)
			cout << "Ve�culo pequeno |";
		else if(tipo[i]==2)
			cout << "Ve�culo m�dio |";
		else
			cout << "Ve�culo grande |";
			
		if(servico[i]==1)
			cout << "Lava��o externa |";
		else if(servico[i]==2)
			cout << "Lava��o externa + interna |";
		else
			cout << "Lava��o externa + interna + cera |";
			
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

	cout << "LAVA��O AUTOMOTIVA\n\nInforme a quantidade de atendimentos do dia: ";
	cin >> tot_atend;
	system("PAUSE");
	
	string cliente[tot_atend];
	int tipo[tot_atend], servico[tot_atend], valor[tot_atend], veic1=0, veic2=0, veic3=0, serv1=0, serv2=0, serv3=0;	
	
	for(i=0; i<tot_atend; i++)
	{
		system("CLS");
		cout << "LAVA��O AUTOMOTIVA\n\nNome do(a) cliente: ";
		cin >> cliente[i];
		
		cout << "\nTipo do ve�culo (1- Pequeno / 2- M�dio / 3- Grande): ";
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
		
		cout << "\nServi�o realizado (1- Lava��o externa / 2- Lava��o externa + interna / 3 - Lava��o externa + interna + cera): ";
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
		cout << "LAVA��O AUTOMOTIVA\n\nRelat�rio di�rio\n\nVe�culos atendidos no dia: " << tot_atend;
		cout << "\n__________________________________________________________________________________";
		cout << "\n\nSelecione uma op��o\n\n1 - Rela��o de clientes\n2 - Percentuais de atendimentos por categoria de ve�culo\n3 - Percentuais de atendimentos por tipo de servi�o\n";
		cout << "4 - Valor total arrecadado\n5 - Ve�culo mais atendido\n6 - Servi�o mais atendido\n7 - Sair\n";
		cin >> opcao;
		
		switch(opcao)
		{
			case 1:								
				ListaClientes(cliente, tot_atend, tipo, servico);				
				break;
				
			case 2:
				system("CLS");
				cout << "LAVA��O AUTOMOTIVA\n\nPercentuais de atendimentos por categoria de ve�culo:\n\n";
				cout << "Ve�culos Pequenos___________________________________" << vei1*100.0/tot_atend << "%" << endl;	
				cout << "Ve�culos M�dios_____________________________________" << vei2*100.0/tot_atend << "%" << endl;			
				cout << "Ve�culos Grandes____________________________________" << vei3*100.0/tot_atend << "%" << endl << endl;			
				system("PAUSE");
				system("CLS");
				break;
			
			case 3:
				system("CLS");
				cout << "LAVA��O AUTOMOTIVA\n\nPercentuais de atendimentos por tipo de servi�o realizado:\n\n";
				cout << "Lava��o externa___________________________________" << sv1*100.0/tot_atend << "%" << endl;	
				cout << "Lava��o externa + interna_________________________" << sv2*100.0/tot_atend << "%" << endl;			
				cout << "Lava��o externa + interna + cera__________________" << sv3*100.0/tot_atend << "%" << endl << endl;			
				system("PAUSE");
				system("CLS");
				break;
				
			case 4:
				system("CLS");
				cout << "LAVA��O AUTOMOTIVA\n\nValor total arrecadado\n\nPor tipo de ve�culo:\n\n";
				cout << "Ve�culos pequenos________________________________R$" << veic1 << ",00" << endl; 
				cout << "Ve�culos m�dios__________________________________R$" << veic2 << ",00" << endl; 
				cout << "Ve�culos grandes_________________________________R$" << veic3 << ",00" << endl;
				cout << "\nPor tipo de servi�o:\n\n";
				cout << "Lava��o externa__________________________________R$" << serv1 << ",00" << endl; 
				cout << "Lava��o externa + interna________________________R$" << serv2 << ",00" << endl; 
				cout << "Lava��o externa + interna + cera_________________R$" << serv3 << ",00" << endl;
				cout << "\nTOTAL ARRECADADO NO DIA__________________________R$" << total_arrec << ",00" << "\n\n" <<flush;
				system("PAUSE");
				system("CLS");
				break;
				
			case 5:
				system("CLS");
				cout << "LAVA��O AUTOMOTIVA\n\n";
				if(vei1>vei2 && vei1>vei3)
					cout << "\nVe�culo mais atendido do dia: carro pequeno.\nTotal de atendimentos: " << vei1 << "\n\n";
				else if(vei2>vei1 && vei2>vei3)			
					cout << "\nVe�culo mais atendido do dia: carro medio.\nTotal de atendimentos: " << vei2 << "\n\n";
				else if(vei3>vei1 && vei3>vei2)
					cout << "\nVe�culo mais atendido do dia: carro grande.\nTotal de atendimentos: " << vei3 << "\n\n";
				else if(vei1==vei2 && vei1>vei3)				
					cout << "\nVe�culos mais atendidos do dia: carros pequenos e medios.\nTotal de atendimentos (cada): " << vei1 << "\n\n";				
				else if(vei1==vei3 && vei1>vei2)				
					cout << "\nVe�culos mais atendidos do dia: carros pequenos e grandes.\nTotal de atendimentos (cada): " << vei1 << "\n\n";				
				else if(vei2==vei3 && vei2>vei1)				
					cout << "\nVe�culos mais atendidos do dia: carros medios e grandes.\nTotal de atendimentos (cada): " << vei2 << "\n\n";				
				else				
					cout << "\nMesma quantidade de ve�culo pequenos, medios e grandes atendidos no dia.\nTotal de atendimentos (cada): " << vei1 << "\n\n";
				system("PAUSE");
				system("CLS");
				break;
				
			case 6:
				system("CLS");
				cout << "LAVA��O AUTOMOTIVA\n\n";
				if(sv1>sv2 && sv1>sv3)
					cout << "\nServi�o mais realizado do dia: lava��o externa.\nTotal de atendimentos: " << sv1 << "\n\n";
				else if(sv2>sv1 && sv2>sv3)			
					cout << "\nServi�o mais realizado do dia: lava��o externa + interna.\nTotal de atendimentos: " << sv2 << "\n\n";
				else if(sv3>sv1 && sv3>sv2)
					cout << "\nServi�o mais realizado do dia: lava��o externa + interna + cera.\nTotal de atendimentos: " << sv3 << "\n\n";
				else if(sv1==sv2 && sv1>sv3)				
					cout << "\nServi�os mais realizados do dia: lava��o externa E externa + interna.\nTotal de atendimentos (cada): " << sv1 << "\n\n";				
				else if(sv1==sv3 && sv1>sv2)				
					cout << "\nServi�os mais realizados do dia: lava��o externa E externa + interna + cera.\nTotal de atendimentos (cada): " << sv1 << "\n\n";				
				else if(sv2==sv3 && sv2>sv1)				
					cout << "\nServi�o mais realizado do dia: lava��o externa + interna E externa + interna + cera.\nTotal de atendimentos (cada): " << sv2 << "\n\n";				
				else				
					cout << "\nMesma quantidade de servi�os realizados no dia.\nTotal de atendimentos (cada): " << sv1 << "\n\n";
				system("PAUSE");
				system("CLS");
				break;							
			 
			 case 7:
			 	cout << "\n\n****************** O sistema foi encerrado! Tenha um bom dia! ******************\n\n" << endl;
			 	system("PAUSE");
				break;
			 	
			default:
				cout << "\nOp��o incorreta!!!\n\n" << flush;
				system("PAUSE");
				system("CLS");
				break;										
		}
				
	}while(opcao!=7);	
	
	return 0;
}
