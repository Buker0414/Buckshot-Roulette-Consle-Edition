#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int ZD[8];
string myDJ[8];
string dfDJ[8];
string ver="R1";
int ZDS,SD,KD,JS,k,dq;//�ӵ�����ʵ�����յ�,����
time_t t;
int wh,dh;//�ҷ�Ѫ��,�з�Ѫ�� 
void reload_ZD(){
	srand((unsigned) time(&t)+rand());
	cout<<"[��Ϣ]��������ӵ����С���"<<endl;
	sleep(1);
	cout<<"[��Ϣ]�ϵ�����������"<<endl; 
	sleep(1);
	ZDS=rand()%8+1;
	SD=rand()%ZDS;
	KD=ZDS-SD;
	cout<<"[��ħ]������"<<ZDS<<"���ӵ���"<<SD<<"��ʵ��"<<KD<<"���յ�"<<endl; 
	sleep(1);
	cout<<"[��Ϣ]����ӵ���[";
	for(int i=0;i<ZDS;i++){
		if(rand()%2==1){
		 	if(SD>0){
		 		cout<<"ʵ��";
		 		ZD[i]=1;
				SD--;
			}
			else{
				cout<<"�յ�";
				ZD[i]=0;
				KD--;
			}
		}
		else{
			if(KD>0){
				cout<<"�յ�";
				ZD[i]=0;
				KD--;
			}
			else{
				cout<<"ʵ��";
				ZD[i]=1;
				SD--; 					
			}
		}
		if(i!=ZDS-1){
			cout<<",";
		}
		sleep(1);
	}
	cout<<"]"<<endl; 
} 
int GET_DQ(){
	for(k=0;k<ZDS;k++){
		if(ZD[k]!=-1){
			return k;
		}
	}

}
int DJ(int JS){
	reload_ZD();
	srand((unsigned) time(&t));
	int turn=1,cnt=0;//0��ħ 1�ҷ� 
	bool SFDJ=JS>1;
	int dx=0; 
	cout<<"[��ħ]��Ϸ��ʼ����"<<endl;
	sleep(1);

	if (JS==2){
		cout<<"[��ħ]��������һЩ��Ȥ�İɡ���"<<endl; 
		sleep(1);
	}
	if(dh==wh){
		cout<<"[��Ϣ]����˫��Ѫ��Ϊ"<<wh<<endl;
	}
	else{
		cout<<"[��Ϣ]�����ҷ�Ѫ��Ϊ"<<wh<<"��ħѪ��Ϊ"<<dh<<endl;
	}
	while(dh>0 && wh>0 && cnt<ZDS){

		dq=GET_DQ();
		cnt++;
		if(turn==1){
			if(SFDJ){
				//���߹��ܿ����С��� 
			}
			while(!(dx==1 || dx==2)){
			
				cout<<"[��Ϣ]��ѡ����Ҫ�����Ķ��� 1=�ҷ�2=��ħ��";
				cin>>dx;
			}
		} 
		else{
			srand((unsigned) time(&t));
			if(SFDJ){
				//���߹��ܿ����С��� 
			}
			if(rand()%2==1){
				dx=1;
				cout<<"[��ħ]���Լ�"; 
			}
			else{
				dx=2;
				cout<<"[��ħ]���ҷ�"; 
			}
		}
		if(turn==1){
			if(dx==1){
				if(ZD[dq]==0){
					cout<<"[��Ϣ][�ҷ�]�ǿյ�������Ȩ�����Լ�"; 
				}
				else if(ZD[dq]==1){
					cout<<"[��Ϣ][�ҷ�]��ʵ�����ҷ�Ѫ��-"<<"1"<<"������Ȩ������ħ"; 
					turn=0;
					wh--; 
				}
			}
			if(dx==2){
				if(ZD[dq]==0){
					cout<<"[��Ϣ][�ҷ�]�ǿյ�������Ȩ������ħ"; 
					turn=0;
				}
				else{
					cout<<"[��Ϣ][�ҷ�]��ʵ������ħѪ��-"<<"1"<<"������Ȩ�����Լ�"; 
					dh--;
				}
			}
		}
		else{
			if(dx==1){
				if(ZD[dq]==0){
					cout<<"[��Ϣ][��ħ]�ǿյ�������Ȩ�����Լ�"; 
				}
				else if(ZD[dq]==1){
					cout<<"[��Ϣ][��ħ]��ʵ������ħѪ��-"<<"1"<<"������Ȩ�����ҷ�"; 
					turn=1;
					dh--; 
				}
			}
			if(dx==2){
				if(ZD[dq]==0){
					cout<<"[��Ϣ][��ħ]�ǿյ�������Ȩ������ħ"; 
				}
				else{
					cout<<"[��Ϣ][��ħ]��ʵ�����ҷ�Ѫ��-"<<"1"<<"������Ȩ�����Լ�"; 
					wh--;
				}
			}
				 
		}
		cout<<endl<<"[��Ϣ]�ӵ�����"<<ZDS-cnt;
		cout<<endl;
		if(dh<=0){
			return 1;
		}
		if(wh<=0){
			return 2;
		}
		sleep(1);
		ZD[dq]=-1;
		dx=3;
	}
	return 0;
}

int main(){
	int winORnot=114514,JVSHU=0;
	cout<<"��������Buckshot Roulette Consle Edition��������"<<endl;
	sleep(1);
	cout<<"Powered by Buker0414,Version:"<<ver<<endl;
	sleep(1);
	//1
	cout<<"[��Ϣ]====================��һ�ֿ�ʼ===================="<<endl;
	sleep(1);
	wh=rand()%6+1;
	dh=wh;
	while(winORnot!=1 && winORnot!=2){
		JVSHU++;
		cout<<"[��Ϣ]==========��һ�ֵ�"<<JVSHU<<"�ֿ�ʼ=========="<<endl; 
		winORnot=DJ(1);
	}
	if(winORnot == 2){
		cout<<"[��Ϣ]==========��һ��������==========";
		return 0; 
	}
	if(winORnot == 1){
		cout<<"[��Ϣ]==========��һ����Ӯ��==========";
		return 0; 
	}
	system("pause");
} 
