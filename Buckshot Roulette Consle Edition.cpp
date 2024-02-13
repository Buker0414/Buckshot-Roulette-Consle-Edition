#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int ZD[8];
string myDJ[8];
string dfDJ[8];
string ver="R1";
int ZDS,SD,KD,JS,k,dq;//子弹数，实弹，空弹,局数
time_t t;
int wh,dh;//我方血量,敌方血量 
void reload_ZD(){
	srand((unsigned) time(&t)+rand());
	cout<<"[信息]随机生成子弹数中……"<<endl;
	sleep(1);
	cout<<"[信息]上弹的声音……"<<endl; 
	sleep(1);
	ZDS=rand()%8+1;
	SD=rand()%ZDS;
	KD=ZDS-SD;
	cout<<"[恶魔]这里有"<<ZDS<<"发子弹，"<<SD<<"发实弹"<<KD<<"发空弹"<<endl; 
	sleep(1);
	cout<<"[信息]你的子弹是[";
	for(int i=0;i<ZDS;i++){
		if(rand()%2==1){
		 	if(SD>0){
		 		cout<<"实弹";
		 		ZD[i]=1;
				SD--;
			}
			else{
				cout<<"空弹";
				ZD[i]=0;
				KD--;
			}
		}
		else{
			if(KD>0){
				cout<<"空弹";
				ZD[i]=0;
				KD--;
			}
			else{
				cout<<"实弹";
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
	int turn=1,cnt=0;//0恶魔 1我方 
	bool SFDJ=JS>1;
	int dx=0; 
	cout<<"[恶魔]游戏开始……"<<endl;
	sleep(1);

	if (JS==2){
		cout<<"[恶魔]让我们玩一些有趣的吧……"<<endl; 
		sleep(1);
	}
	if(dh==wh){
		cout<<"[信息]本局双方血量为"<<wh<<endl;
	}
	else{
		cout<<"[信息]本局我方血量为"<<wh<<"恶魔血量为"<<dh<<endl;
	}
	while(dh>0 && wh>0 && cnt<ZDS){

		dq=GET_DQ();
		cnt++;
		if(turn==1){
			if(SFDJ){
				//道具功能开发中…… 
			}
			while(!(dx==1 || dx==2)){
			
				cout<<"[信息]请选择你要攻击的对象 1=我方2=恶魔：";
				cin>>dx;
			}
		} 
		else{
			srand((unsigned) time(&t));
			if(SFDJ){
				//道具功能开发中…… 
			}
			if(rand()%2==1){
				dx=1;
				cout<<"[恶魔]打自己"; 
			}
			else{
				dx=2;
				cout<<"[恶魔]打我方"; 
			}
		}
		if(turn==1){
			if(dx==1){
				if(ZD[dq]==0){
					cout<<"[信息][我方]是空弹，发射权交给自己"; 
				}
				else if(ZD[dq]==1){
					cout<<"[信息][我方]是实弹，我方血量-"<<"1"<<"，发射权交给恶魔"; 
					turn=0;
					wh--; 
				}
			}
			if(dx==2){
				if(ZD[dq]==0){
					cout<<"[信息][我方]是空弹，发射权交给恶魔"; 
					turn=0;
				}
				else{
					cout<<"[信息][我方]是实弹，恶魔血量-"<<"1"<<"，发射权交给自己"; 
					dh--;
				}
			}
		}
		else{
			if(dx==1){
				if(ZD[dq]==0){
					cout<<"[信息][恶魔]是空弹，发射权交给自己"; 
				}
				else if(ZD[dq]==1){
					cout<<"[信息][恶魔]是实弹，恶魔血量-"<<"1"<<"，发射权交给我方"; 
					turn=1;
					dh--; 
				}
			}
			if(dx==2){
				if(ZD[dq]==0){
					cout<<"[信息][恶魔]是空弹，发射权交给恶魔"; 
				}
				else{
					cout<<"[信息][恶魔]是实弹，我方血量-"<<"1"<<"，发射权交给自己"; 
					wh--;
				}
			}
				 
		}
		cout<<endl<<"[信息]子弹数："<<ZDS-cnt;
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
	cout<<"————Buckshot Roulette Consle Edition————"<<endl;
	sleep(1);
	cout<<"Powered by Buker0414,Version:"<<ver<<endl;
	sleep(1);
	//1
	cout<<"[信息]====================第一局开始===================="<<endl;
	sleep(1);
	wh=rand()%6+1;
	dh=wh;
	while(winORnot!=1 && winORnot!=2){
		JVSHU++;
		cout<<"[信息]==========第一局第"<<JVSHU<<"轮开始=========="<<endl; 
		winORnot=DJ(1);
	}
	if(winORnot == 2){
		cout<<"[信息]==========第一局你输了==========";
		return 0; 
	}
	if(winORnot == 1){
		cout<<"[信息]==========第一局你赢了==========";
		return 0; 
	}
	system("pause");
} 
