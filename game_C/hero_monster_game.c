#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <windows.h>
#include <unistd.h>
#include <math.h>
int hp = 0;
//������� �� ����� ��� ��� �������� ���
int menu(){
    int choise;
    printf("\n###-------------------------------- Select from the below options -------------------------------###\n");
    printf("\nContinue battles with the same stats :  Press (1)\n");
    printf("\nSmall Rest : Continue battles with the same heal 10/100 hp and lose 10/100 XP :  Press (2)\n");
    printf("\nBig Rest : Continue battles with the same heal 20/100 hp and lose 20/100 XP :  Press (3)\n");
    scanf("%d",&choise);
    return choise;
}
//����������� hp ��� ���� ���� ����� 
void update_hero_stats(int points_lost) {
    hp -= points_lost;
    if (hp < 0) {
        hp = 0;  //�� hp ��� �������� ���� ��� �������
    }
}
//�������� �� ���������� ��� ����
void print_stats_player(int level,int hp,int damage,int XP){
    printf("\nHero stats : level %d , Hit Points : %d , Damage : %d , XP : %d " , level,hp,damage,XP);
}
//������ �� �����
int * generate_monster(int diff ){ 
    srand(time(0)); //���������� ������������ �����
    static int monster_stats[2];//����������� ������� ��� ���������� monster_hp ��� monster_damage
    int monster_hp = (rand() % (diff *2-  diff + 1)) + diff; //����������� ��� monster_hp ������� �� ��� �������� ��� �������
    int monster_damage = (rand() % (diff/2 -  diff/4 + 1)) + diff/4; //���������� ��� monster_damage ������� �� ��� �������� ��� �������
    printf("\nMonster stats : Hit Points : %d , Damage : %d ," , monster_hp,monster_damage);
    //���������� ��������� ��� ������� ��� �������������� ���� ������� ������
    monster_stats[0]=monster_hp;
    monster_stats[1]=monster_damage;
    return monster_stats;
}
//������ ��������� ���� ��� ���� ��� �������
int  gainXP(int moster_hp,int monster_damage){
    return moster_hp+monster_damage;
}
//��������� ��� ������ hp ��� new_hp
int holdHp(int old_hp){
    int new_hp ;
    return new_hp = old_hp; 
}
//����
int fight(int level,int hp,int damage,int monster_hp,int monster_damage,int num_battles){
    printf("\n###------------------------------- ( Battle:  %d ) -----------------------------### \n",num_battles);//����������� � ������� ��� �����
    int round =1;
    while(hp>0 && monster_hp>0){//� ����� ��� �� ����� �������� ������ ������ � ������� ���� ���� while
        printf("\n----------------------------------- round:  %d ----------------------------- ",round);
        monster_hp -=damage ;
        update_hero_stats(monster_damage);
        printf("\nMonster hp : %d",monster_hp);//�� ��� monster_hp �� ���� round
        
        if (monster_hp <= 0){
            break;
        }
        hp -=  monster_damage;
        printf("\nHero hp : %d",hp);//�� ��� hero hp �� ���� round
        
        if(hp<=0){
            break;
        }
        round++;//�� rounds ������������
    }
	//���� ��������� � ���� (���� ����� � ����� ��� ���� �� �����)
    if (hp<=0){
        printf("\nHero die");
        return 0;  //� ����� ����� 
    }
    else{
        printf("\nMonster die");
        return 1; //� ����� ������
    }
}

int main(){
	//�� ���������� �� �� ����� ������ �� �������� 
    int level = 1;
    hp = 100;
    int new_hp = 100;
    int damage =10;
    int diff = 20; 
    int XP=0;
    int *monster_stats;
    print_stats_player(level,hp,damage,XP);
    monster_stats = generate_monster(diff);

	
    int choise;
    int num_battles = 1;
	//������ ��� �� ������������ �� �����
    while(fight(level, hp, damage,*(monster_stats),*(monster_stats+1),num_battles) !=0){
        XP+=gainXP(*(monster_stats) ,*(monster_stats+1));//���������� �� xp �� ���� �� monster_stats
		//�� � ����� ������� level
        if(XP>=  50*pow(2,level)){//������ ��������� ��� �� ������� level � �����
            sleep(4);//������� 4 sec
            level++;//��������� level
            damage +=5;//����������� damage ���� level
            hp =new_hp;//��� hp ����
            hp+=20;//�������� +20 hp ��� ���� level ��� ���������
            new_hp = hp;
            printf("\n Congratulation you level up \n Boost your Hp and Damage \n");
            print_stats_player(level,hp,damage,XP);//��� hero stats 
        }
        //�� � ����� ��� ������� level (��������)
        else{
            choise = menu();
            //��������� �� ��� ������� ����
	        if(choise==1){
	        }
	        //������������ ����
	        else if(choise ==2){
	   		hp=hp+10/100 * hp;
	        XP=XP-10/100*XP;
	        }
	        //������������ ����
	        else if (choise == 3){
	        hp=hp+20/100 * hp;
	        XP=XP-20/100*XP;  
			}
			else{
				printf("Wrong input try again from option (1) ,(2) ,(3)");
				choise = menu();
			}

        }
        diff+=4;//������ � ����� ��� � �������� ��������� ���� 4
        printf("\n %d \n",diff);
        monster_stats = generate_monster(diff);//����������� ��������� ��� �������
        
        print_stats_player(level,hp,damage,XP);//���������� �� ���������� ��� ����
        num_battles ++;//�� ����� ������������
    }
    return 0;
}

