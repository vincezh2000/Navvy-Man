#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#pragma comment(lib,"Winmm.lib")



void startUp();							// ���ݳ�ʼ��
void mapStartUp();						// ��ͼ��ʼ��
void show();							// ������ʾ
void associated();						// ���ڴ�������ṹ���еı���
void updateWithoutInput();				// ���û������޹صı���
void statusChange();					// ״̬�ı仯
void updateWithInput();					// ���û������йصı���
void startMenu();						// ��ʼ�˵�����
void pauseMenu();						// ��Ϸ��ͣ��˵����棬һ�㰴ESC���������ý���
void readRecordFile();					// ��ȡ��Ϸ�����ļ��浵
void writeRecordFile();					// �洢��Ϸ�����ļ��浵
void gameOver();						// ��Ϸ����



#define high 670						//�����ĸ߶�
#define width 900						//�����Ŀ��
#define person_high 72					//�����ڵ�С�ӵĸ߶�
#define person_width 64					//�����ڵ�С�ӵĿ��
#define monster_high 60					//�������ĸ߶�
#define monster_width 56				//�������Ŀ��
#define monster_num 3					//����Ĺ���
#define shoesperson_high 92				//�����ڵ�С�ӷ���ʱ�ĸ߶�
#define shoesperson_width 64			//�����ڵ�С�ӷ���ʱ�Ŀ��
#define digdownperson_high 80			//�����ڵ�С��������ʱ�ĸ߶�
#define digdownperson_width 64			//�����ڵ�С��������ʱ�Ŀ��
#define digleftperson_high 78			//�����ڵ�С��������ʱ�ĸ߶�
#define digleftperson_width 64			//�����ڵ�С��������ʱ�Ŀ��
#define digrightperson_high 78			//�����ڵ�С��������ʱ�ĸ߶�
#define digrightperson_width 64			//�����ڵ�С��������ʱ�Ŀ��
#define num_stonewidth 14				//����ʯ�����
#define num_stonehigh 11				//����ʯ�����
#define num_scene 3						//�ؿ�����
#define stone_high 64					//ש��ĸ�
#define stone_width 64					//ש��Ŀ�
#define apper_1stone 414				//��һ���п�ʼ����ש���yλ��
#define apper_2stone 0					//�ڶ����п�ʼ����ש���yλ��
#define bomb_money 50					//ը���ļ۸�
#define bomb_high 64					//ը���Լ���ը����ĸ߶�
#define bomb_width 64					//ը���Լ���ը����Ŀ��



IMAGE img_bk;							//���屳��ͼƬ
IMAGE img_ebg;							//��Ϸ����ͼƬ
IMAGE img_success;						//��Ϸ�ɹ�ʱ��ͼƬ
IMAGE img_1;							//�����һ�ص�ͼƬ
IMAGE img_stone_0, img_stone_1, img_stone_2, img_stone_3, img_stone_4, img_stone_5, img_stone_6, img_stone_7, img_stone_1314;
										//����ʯ���ͼƬ
IMAGE img_coal_1, img_coal_2, img_coal_3, img_coal_4, img_coal_5, img_coal_0;
										//����ú���ͼƬ
IMAGE img_copper_1, img_copper_2, img_copper_3, img_copper_4, img_copper_5, img_copper_6, img_copper_0;
										//����ͭ���ͼƬ
IMAGE img_silver_1, img_silver_2, img_silver_3, img_silver_4, img_silver_5, img_silver_0;
										//���������ͼƬ
IMAGE img_stone_99;						//ʯ��
IMAGE img_person_0, img_person_00;		//�����ڵ�С�ӵ�����ͼƬ    0��ʾ�ڰװ� 00��ʾ�ʰ�
IMAGE img_monsterrun_0, img_monsterrun_00;
										//���������·��ͼƬ	    0��ʾ�ڰװ� 00��ʾ�ʰ�
IMAGE img_person_1, img_person_2;		//�����ڵ�С�������ߵ�ͼƬ  1��ʾ�ڰװ� 2��ʾ�ʰ�
IMAGE img_shoes_1, img_shoes_2;			//������ЬͼƬ			1��ʾ�ڰװ� 2��ʾ�ʰ�
IMAGE img_digleftperson_1, img_digleftperson_2;
										//�����ڵ�С�������ڵ���Ƭ  1��ʾ�ڰװ� 2��ʾ�ʰ�
IMAGE img_digrightperson_1, img_digrightperson_2;
										//�����ڵ�С�������ڵ���Ƭ  1��ʾ�ڰװ� 2��ʾ�ʰ�
IMAGE img_digdownperson_1, img_digdownperson_2;
										//�����ڵ�С�������ڵ���Ƭ  1��ʾ�ڰװ� 2��ʾ�ʰ�
IMAGE img_bomb_1, img_bomb_boom, img_bwbomb_boom;
										//ը��
IMAGE img_bwbomb_1;						//ը���ڰ�
IMAGE img_energy;						//����ͼƬ
IMAGE img_oxygen;						//����ͼƬ
IMAGE img_ener_oxy1;					//�����ڰ�
IMAGE img_ener_oxy2;					//����
IMAGE img_shop;							//�̵�
MOUSEMSG m;								//����һ��������



int scene;			
/*					scene  
	-5��Ϸ�ɹ�   	-4��Ϸ����	-3��Ϸ��ͣ 
	-2��Ϸ��ʼ�˵�  -1�̵�		0��Ϸ���뻭�� 
	1��Ϸ��һ��      2��Ϸ�ڶ���		
*/
int left_i;						//��¼�������ƶ���ͼƬ
int right_i;					//��¼�������ƶ���ͼƬ
int mleft_i[monster_num];		//��¼���������ƶ���ͼƬ
int mright_i[monster_num];		//��¼���������ƶ���ͼƬ
int boom_i;						//��¼��ը����ըʱ��ͼƬ
int G;							//�������ٶ�
int shoes_a;					//���Ь���ٶ�
int digbf;						//���ڼ�¼�ж��Ƿ���������	 0��ʾû�� 1��ʾ��
int digleftbf;					//���ڼ�¼�ж��Ƿ���������	 0��ʾû�� 1��ʾ��
int digrightbf;					//���ڼ�¼�ж��Ƿ���������	 0��ʾû�� 1��ʾ��
int flyleftbf;					//���ڼ�¼�ж��Ƿ��������	 0��ʾû�� 1��ʾ��
int flyrightbf;					//���ڼ�¼�ж��Ƿ������ҷ�	 0��ʾû�� 1��ʾ��
int exist_leftstone;			//���ڼ�¼�ж��Ƿ������ש�� 0��ʾû�� 1��ʾ��
int exist_rightstone;			//���ڼ�¼�ж��Ƿ��Ҷ���ש�� 0��ʾû�� 1��ʾ��
int exist_downstone;			//���ڼ�¼�ж��Ƿ��¶���ש�� 0��ʾû�� 1��ʾ��
int exist_flyleftstone;			//���ڼ�¼�жϷ���ʱ�Ƿ������ש�� 0��ʾû�� 1��ʾ��
int exist_flyrightstone;		//���ڼ�¼�жϷ���ʱ�Ƿ��Ҷ���ש�� 0��ʾû�� 1��ʾ��
float energy_i;					//����ͼƬ�仯������
float energy_j;					//����ͼƬ�仯������
float oxygen_i;					//����ͼƬ�仯�ĺ�����
float oxygen_j;					//����ͼƬ�仯��������
int put_bomb;					//����ը��
int score;						//������¼
int k;							//�ؿ�����

//����ṹ��������
typedef struct thing
{
	/*���޺��˹���*/
	float left_x;				//���x����
	float left_y;				//���y����
	float right_x;				//�Ҷ�x����
	float right_y;				//�Ҷ�y����
	float top_x;				//�϶�x����
	float top_y;				//�϶�y����
	float bottom_x;				//�ײ�x����
	float bottom_y;				//�ײ�y����
	float center_x;				//����x����
	float center_y;				//����y����

	 /*������*/
	float v;					//�ڵ�С����ֱ�����ٶ�
	int bomb;					//�ڵ�С��Я��ը���ĸ���
	int oxygen;					//����Я���������ĸ���
	int energy;					//����Я���������ĸ���
	int scene;					//���������ڵĹؿ�λ��
	int oxygen_level;			//�����ȼ�
	int energy_level;			//�����ȼ�

	/*���ڹ���*/
	int direction;				//������·�ķ��� 0���������� 1��ʾ������
	int status;					//��������״̬ 1��ʾ���	 0��ʾ����
}thing;
thing person;				//������
thing monster[monster_num]; //�������

//����ṹ������resourece
struct stone
{
	float left_x;	//���x����
	float left_y;	//���y����
	float right_x;	//�Ҷ�x����
	float right_y;	//�Ҷ�y����
	float top_x;	//�϶�x����
	float top_y;	//�϶�y����
	float bottom_x;	//�ײ�x����
	float bottom_y;	//�ײ�y����
	float center_x;	//����x����
	float center_y;	//����y����
	float status;	//��ʾש���״̬ 0��ʾ�� 1Ϊԭʼ 2����1 3����2 4����3 5����4 6����5 7����6
	int scene;		//ʯͷ�ؿ���״̬
}stone[num_scene][num_stonehigh][num_stonewidth];//����Ľṹ��һ��56��ש��
struct stone bomb;	//�洢ը���Ľṹ��

//��Ϸ���忪����� 
void main()
{

	startUp();
	mapStartUp();
	while (1)
	{
		show();
		associated();
		updateWithoutInput();
		statusChange();
		updateWithInput();
	}
	gameOver();

}

void startUp()
{

	int i, j, k;
	initgraph(width, high);							//����
	loadimage(&img_bk, _T("background.jpg"));		//������Ϸ��ʼ����
	loadimage(&img_ebg, _T("endbackground.jpg"));	//������Ϸ��������
	loadimage(&img_success, _T("success.jpg"));		//������Ϸʤ������
	loadimage(&img_1, _T("level_1.jpg"));			//�����һ�ص�ͼƬ
	loadimage(&img_energy, _T("energy.jpg"));		//����������ͼƬ
	loadimage(&img_oxygen, _T("oxygen.jpg"));		//����������ͼƬ
	loadimage(&img_ener_oxy1, _T("ener_oxy1.jpg"));	//���������ڰ���
	loadimage(&img_ener_oxy2, _T("ener_oxy2.jpg"));	//��������
	loadimage(&img_shop, _T("shop.jpg"));			//�����̵��ͼƬ
	loadimage(&img_person_0, _T("person_0.jpg"));	//�������������ͼƬ�ڰװ�
	loadimage(&img_person_00, _T("person_00.jpg"));	//�������������ͼƬ�ʰ�
	loadimage(&img_monsterrun_0, _T("monsterrun_0.jpg"));	//���������·ͼƬ�Ĳʰ�
	loadimage(&img_monsterrun_00, _T("monsterrun_00.jpg"));	//���������·ͼƬ�ĺڰװ�
	loadimage(&img_person_1, _T("person_1.jpg"));	//��������������·��ͼƬ�ĺڰװ�
	loadimage(&img_person_2, _T("person_2.jpg"));	//��������������·��ͼƬ�ʰ�
	loadimage(&img_stone_0, _T("stone_0.jpg"));		//����յ�ͼƬ
	loadimage(&img_stone_1, _T("stone_1.jpg"));		//����ʯ��ԭͼ��ͼƬ
	loadimage(&img_stone_2, _T("stone_2.jpg"));		//��������1��ͼƬ
	loadimage(&img_stone_3, _T("stone_3.jpg"));		//��������2��ͼƬ
	loadimage(&img_stone_4, _T("stone_4.jpg"));		//��������3��ͼƬ
	loadimage(&img_stone_5, _T("stone_5.jpg"));		//��������4��ͼƬ
	loadimage(&img_stone_6, _T("stone_6.jpg"));		//��������5��ͼƬ
	loadimage(&img_stone_7, _T("stone_7.jpg"));		//��������6��ͼƬ
	loadimage(&img_stone_99, _T("stone_99.jpg"));	//����ʯͷ
	loadimage(&img_stone_1314, _T("stone_1314.jpg"));//�ظ�
	loadimage(&img_coal_1, _T("coal_1.jpg"));		//��������ú
	loadimage(&img_coal_2, _T("coal_2.jpg"));		//��������1ú
	loadimage(&img_coal_3, _T("coal_3.jpg"));		//��������2,ú
	loadimage(&img_coal_4, _T("coal_4.jpg"));		//��������3ú
	loadimage(&img_coal_5, _T("coal_5.jpg"));		//��������4ú
	loadimage(&img_coal_0, _T("coal_0.jpg"));		//��ȫ�����ú
	loadimage(&img_copper_1, _T("Copper_1.jpg"));	//��������ͭ
	loadimage(&img_copper_2, _T("Copper_2.jpg"));	//��������1ͭ
	loadimage(&img_copper_3, _T("Copper_3.jpg"));	//��������2ͭ
	loadimage(&img_copper_4, _T("Copper_4.jpg"));	//��������3ͭ
	loadimage(&img_copper_5, _T("Copper_5.jpg"));	//��������4ͭ
	loadimage(&img_copper_6, _T("Copper_6.jpg"));	//��������5ͭ
	loadimage(&img_copper_0, _T("Copper_0.jpg"));	//��ȫ�����ͭ
	loadimage(&img_silver_1, _T("silver_1.jpg"));	//����������
	loadimage(&img_silver_2, _T("silver_2.jpg"));	//��������1��
	loadimage(&img_silver_3, _T("silver_3.jpg"));	//��������2��
	loadimage(&img_silver_4, _T("silver_4.jpg"));	//��������3��
	loadimage(&img_silver_5, _T("silver_5.jpg"));	//��������4��
	loadimage(&img_silver_0, _T("silver_0.jpg"));	//��ȫ�������
	loadimage(&img_shoes_1, _T("shoes_1.jpg"));		//����������ͼƬ�ڰװ�
	loadimage(&img_shoes_2, _T("shoes_2.jpg"));		//����������ͼƬ�ʰ�
	loadimage(&img_digleftperson_1, _T("digleftperson_1.jpg"));	 //���������ڵ�ͼƬ�ĺڰװ�
	loadimage(&img_digleftperson_2, _T("digleftperson_2.jpg"));	 //���������ڵ�ͼƬ�Ĳʰ�
	loadimage(&img_digrightperson_1, _T("digrightperson_1.jpg"));//���������ڵ�ͼƬ�ĺڰװ�
	loadimage(&img_digrightperson_2, _T("digrightperson_2.jpg"));//���������ڵ�ͼƬ�Ĳʰ�
	loadimage(&img_digdownperson_1, _T("digdownperson_1.jpg"));	 //���������ڵ�ͼƬ�ĺڰװ�
	loadimage(&img_digdownperson_2, _T("digdownperson_2.jpg"));	 //���������ڵ�ͼƬ�Ĳʰ�
	loadimage(&img_bomb_1, _T("bomb_1.jpg"));			//ը��ԭʼ
	loadimage(&img_bwbomb_1, _T("bwbomb_1.jpg"));		//ը��ԭʼ�ڰ�
	loadimage(&img_bomb_boom, _T("bomb_boom.jpg"));		//ը����ը�����й���ͼƬ
	loadimage(&img_bwbomb_boom, _T("bwbomb_boom.jpg")); //ը����ը�����й��̺ڰ�ͼƬ
	mciSendString(_T("open bkmusic.mp3 alias bkmusic"), NULL, 0, NULL); //���뱳������
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);			//ѭ����������



	scene = 0;		//�����ʼ����
	shoes_a = 0;	//���Ь���ٶ�
	exist_leftstone = 0; //��ʼʱ���û��ש�� exist_leftstone==0��ʾ���û��ש�� exist_leftstone==1��ʾ�����ש��
	exist_rightstone = 0;//��ʼʱ�ұ�û��ש�� exist_rightstone==0��ʾ���û��ש�� exist_leftrightstone==1��ʾ�����ש��
	exist_downstone = 0; //��ʼʱ�±�û��ש�� exist_downstone==0��ʾ���û��ש�� exist_downstone==1��ʾ�����ש��
	exist_flyleftstone = 0;
	exist_flyrightstone = 0;
	digleftbf = 0;		//�ж��Ƿ�����ʼ��
	digrightbf = 0;		//�ж��Ƿ����ҿ�ʼ��
	flyleftbf = 0;		//�ж��Ƿ������
	flyrightbf = 0;//�ж��Ƿ����ҷ�
	put_bomb = 0;

	/*��ը�����г�ʼ��*/
	bomb.center_x = -1000;
	bomb.center_y = -1000;
	bomb.left_x	  = -1000;
	bomb.left_y	  = -1000;
	bomb.right_x  = -1000;
	bomb.right_y  = -1000;
	bomb.top_x    = -1000;
	bomb.top_y    = -1000;
	bomb.bottom_x = -1000;
	bomb.bottom_y = -1000;
	bomb.status   = 0;
	bomb.scene    = 100;

	/*��ÿ��ש����г�ʼ��*/
	for (k = 0; k < 3; k++)
		for (i = 0; i < num_stonehigh; i++)
			for (j = 0; j < num_stonewidth; j++)
			{
				stone[k][i][j].center_x = -1000;
				stone[k][i][j].center_y = -1000;
				stone[k][i][j].left_x	= -1000;
				stone[k][i][j].left_y	= -1000;
				stone[k][i][j].right_x	= -1000;
				stone[k][i][j].right_y	= -1000;
				stone[k][i][j].top_x	= -1000;
				stone[k][i][j].top_y	= -1000;
				stone[k][i][j].bottom_x = -1000;
				stone[k][i][j].bottom_y = -1000;
				stone[k][i][j].status	= -1000;
			}

	/*����ÿ��ʯ��Ĺ̶�λ��*/
	for (i = 7; i < num_stonehigh; i++)
		//��һ�ص�ʯ��λ��
		for (j = 0; j < num_stonewidth; j++)
		{
			stone[1][i][j].center_x = stone_width / 2 + j * stone_width;		//��ʼ��ÿ��ש�������x����
			stone[1][i][j].center_y = apper_1stone + stone_high / 2 + (i - 7) * stone_high;//��ʼ��ÿ��ש�������y����
			stone[1][i][j].left_x	= j * stone_width;							//��ʼ��ÿ��ש������x����
			stone[1][i][j].left_y	= apper_1stone + stone_high / 2 + (i - 7) * stone_high;//��ʼ��ÿ��ש������y����
			stone[1][i][j].right_x	= stone_width + j * stone_width;			//��ʼ��ÿ��ש����Ҷ�x����
			stone[1][i][j].right_y	= apper_1stone + stone_high / 2 + (i - 7) * stone_high;//��ʼ��ÿ��ש����Ҷ�y����
			stone[1][i][j].top_x	= stone_width / 2 + j * stone_width;		//��ʼ��ÿ��ש����϶�x����
			stone[1][i][j].top_y	= apper_1stone + (i - 7) * stone_high;		//��ʼ��ÿ��ש����϶�y����
			stone[1][i][j].bottom_x = stone_width / 2 + j * stone_width;		//��ʼ��ÿ��ש����¶�x����
			stone[1][i][j].bottom_y = apper_1stone + stone_high + (i - 7) * stone_high;//��ʼ��ÿ��ש����¶�y����
			stone[1][i][j].status	= 1;
		}

	for (i = 0; i < num_stonehigh; i++)
		//�ڶ��ص�ʯ��λ��
		for (j = 0; j < num_stonewidth; j++)
		{
			stone[2][i][j].center_x = stone_width / 2 + j * stone_width;	//��ʼ��ÿ��ש�������x����
			stone[2][i][j].center_y = apper_2stone + stone_high / 2 + i * stone_high;//��ʼ��ÿ��ש�������y����
			stone[2][i][j].left_x	= j * stone_width;						//��ʼ��ÿ��ש������x����
			stone[2][i][j].left_y	= apper_2stone + stone_high / 2 + i * stone_high;//��ʼ��ÿ��ש������y����
			stone[2][i][j].right_x  = stone_width + j * stone_width;		//��ʼ��ÿ��ש����Ҷ�x����
			stone[2][i][j].right_y	= apper_2stone + stone_high / 2 + i * stone_high;//��ʼ��ÿ��ש����Ҷ�y����
			stone[2][i][j].top_x	= stone_width / 2 + j * stone_width;	//��ʼ��ÿ��ש����϶�x����
			stone[2][i][j].top_y	= apper_2stone + i * stone_high;		//��ʼ��ÿ��ש����϶�y����
			stone[2][i][j].bottom_x = stone_width / 2 + j * stone_width;	//��ʼ��ÿ��ש����¶�x����
			stone[2][i][j].bottom_y = apper_2stone + stone_high + i * stone_high;//��ʼ��ÿ��ש����¶�y����
			stone[2][i][j].status	= 1;
		}

	/*�ڵ�С�Ӹ���ʼֵ */
	person.center_x		= width / 2;
	person.center_y		= apper_1stone - person_high / 2;
	person.bomb			= 0;	//��ʼû��ը��
	person.status		= 1;	//��ʼ�ڵ�С�ӻ���
	person.oxygen_level = 1;	//�����ȼ�
	person.energy_level = 1;	//�����ȼ�
	person.oxygen		= 1;	//������
	person.energy		= 1;	//������

	/*�Թ�����г�ʼ��*/
	for (i = 0; i < monster_num; i++)
	{
		monster[0].center_x = stone_width;
		monster[0].center_y = stone_high * 9 - monster_high / 2;
		monster[1].center_x = stone_width * 6;
		monster[1].center_y = stone_high * 4 - monster_high / 2;
		monster[2].center_x = stone_width * 10;
		monster[2].center_y = stone_high * 7 - monster_high / 2;
		monster[i].direction = 0;
		monster[i].status = 1;//��ʾ���
	}

	/*�ƶ�������ֵ*/
	left_i	 = 0;
	right_i	 = 0;
	energy_i = 120;	//�������ĳ���
	energy_j = 19;	//�������Ŀ��
	oxygen_i = 107;	//�������ĳ���
	oxygen_j = 54;	//�������Ŀ��
	boom_i	 = 0;
	person.v = 0;	/*�����·�����ٶ�   
					  ����Ϊ�� ������Ϊ��*/

	/*������ʼ*/
	score = 500000;
	BeginBatchDraw();
}

void mapStartUp()
{
	int i, j;
	for (i = 7; i<11; i++)
		for (j = 0; j<2; j++)
		{
			stone[1][i][j].status = 99;
		}
	for (i = 7; i<8; i++)
		for (j = 8; j<14; j++)
		{
			stone[1][i][j].status = 99;
		}
	for (i = 9; i<10; i++)
		for (j = 4; j<6; j++)
		{
			stone[1][i][j].status = 11;
		}
	for (i = 10; i<11; i++)
		for (j = 2; j<7; j++)
		{
			stone[1][i][j].status = 11;
		}
	for (i = 10; i<11; i++)
		for (j = 9; j<14; j++)
		{
			stone[1][i][j].status = 11;
		}
	for (i = 8; i<9; i++)
		for (j = 1; j<5; j++)//����
		{
			stone[2][i][j].status = 0;
		}
	for (i = 3; i<4; i++)
		for (j = 5; j<9; j++)//����
		{
			stone[2][i][j].status = 0;
		}
	for (i = 6; i<7; i++)
		for (j = 9; j<13; j++)//����
		{
			stone[2][i][j].status = 0;
		}
	for (i = 2; i<6; i++)
		for (j = 3; j<5; j++)
		{
			stone[2][i][j].status = 31;
		}
	for (i = 1; i<5; i++)
		for (j = 12; j<13; j++)
		{
			stone[2][i][j].status = 11;
		}
	for (i = 9; i<10; i++)
		for (j = 1; j<5; j++)
		{
			stone[2][i][j].status = 21;
		}
	for (i = 7; i<8; i++)
		for (j = 7; j<14; j++)
		{
			stone[2][i][j].status = 21;
		}
	for (i = 6; i<7; i++)
		for (j = 5; j<9; j++)
		{
			stone[2][i][j].status == 31;
		}
}
/* 
			���� 
	0��ʾ�� 1Ϊԭʼ 2����1 3����2 4����3 5����4 6����5 7����6

			ú�� 
	11��ʾԭʼ 12��ʾ����1 13��ʾ����2 14��ʾ����3 15��ʾ����4  16��ʾú

			ͭ�� 
	21��ʾԭʼ 22��ʾ����1 23��ʾ����2 24��ʾ����3 25��ʾ����4  26��ʾ����5 27��ʾͭ��

			���� 
	31��ʾԭʼ 32��ʾ����1 33��ʾ����2 34��ʾ����3 35��ʾ����4  36��ʾ����
*/

void show()
{
	int i, j;					//ѭ������
	k = 0;
	if (scene == 0)				//�л�����
	{
		putimage(0, 0, &img_bk);//��������ͼƬ
		FlushBatchDraw();
	}
	while (scene == -2)
		startMenu();			//��ʼ�˵�����
	while (scene == -3)
		pauseMenu();			//��Ϸ��ͣ��˵����棬һ�㰴ESC���������ý���
	if (scene == 1)				//�л�������1
	{
		putimage(0, 0, &img_1);	//������һ�ص�ͼ
		k = 1;
	}
	else if (scene == 2)
	{
		putimage(0, 0, &img_1);	//������һ�ص�ͼƬ��Դ�������˵ڶ��ص��趨
		k = 2;
	}
	for (i = 0; i < num_stonehigh; i++)
		for (j = 0; j < num_stonewidth; j++)
		{

			/*ԭʼ����*/
			if (stone[k][i][j].status == 0)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_stone_0);//��ȫ�����ͼƬ
			else if (stone[k][i][j].status == 1)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_stone_1);//ש���ʼ��
			else if (stone[k][i][j].status == 2)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_stone_2);//����1��ͼƬ
			else if (stone[k][i][j].status == 3)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_stone_3);//����2��ͼƬ
			else if (stone[k][i][j].status == 4)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_stone_4);//����3��ͼƬ
			else if (stone[k][i][j].status == 5)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_stone_5);//����4��ͼƬ
			else if (stone[k][i][j].status == 6)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_stone_6);//����5��ͼƬ
			else if (stone[k][i][j].status == 7)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_stone_7);//����6��ͼƬ
			
			/*ú��*/
			else if (stone[k][i][j].status == 11)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_coal_1);	//����ú��ͼƬ
			else if (stone[k][i][j].status == 12)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_coal_2);	//ú����1��ͼƬ
			else if (stone[k][i][j].status == 13)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_coal_3);	//ú����2��ͼƬ
			else if (stone[k][i][j].status == 14)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_coal_4);	//ú����3��ͼƬ
			else if (stone[k][i][j].status == 15)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_coal_5);	//ú����4��ͼƬ
			else if (stone[k][i][j].status == 16)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_coal_0);	//��ȫú�����ͼƬ
		
			/*ͭ��*/
			else if (stone[k][i][j].status == 21)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_copper_1);//����ͭ��ͼƬ
			else if (stone[k][i][j].status == 22)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_copper_2);//ͭ����1��ͼƬ
			else if (stone[k][i][j].status == 23)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_copper_3);//ͭ����2��ͼƬ
			else if (stone[k][i][j].status == 24)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_copper_4);//ͭ����3��ͼƬ
			else if (stone[k][i][j].status == 25)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_copper_5);//ͭ����4��ͼƬ
			else if (stone[k][i][j].status == 26)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_copper_6);//ͭ����5��ͼƬ
			else if (stone[k][i][j].status == 27)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_copper_0);//ͭ
		
			/*����*/
			else if (stone[k][i][j].status == 31)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_silver_1);//����ú��ͼƬ
			else if (stone[k][i][j].status == 32)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_silver_2);//ú����1��ͼƬ
			else if (stone[k][i][j].status == 33)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_silver_3);//ú����2��ͼƬ
			else if (stone[k][i][j].status == 34)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_silver_4);//ú����3��ͼƬ
			else if (stone[k][i][j].status == 35)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_silver_5);//ú����4��ͼƬ
			else if (stone[k][i][j].status == 36)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_silver_0);//��ȫú�����ͼƬ
			else if (stone[k][i][j].status == 99)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_stone_99);//ש���ʼ��
			else if (stone[k][i][j].status == -1)
				putimage(stone[k][i][j].left_x, stone[k][i][j].top_y, &img_stone_1314);//ש���ʼ��
		}

	if (scene == 2)
	{
		putimage(width - 610, 0, &img_ener_oxy1, NOTSRCERASE);	//��������������������ϵ�ͼƬ������
		putimage(width - 610, 0, &img_ener_oxy2, SRCINVERT);	//��������������������ϵ�ͼƬ�Ĳʰ�
	}

	/*������������������*/
	if (scene == 1 || scene == 2)
	{
		putimage(735, 213, energy_i, energy_j, &img_energy, 0, 0);//����������
		putimage(740, 248, oxygen_i, oxygen_j, &img_oxygen, 0, 0);//����������
	}

	/*�̵�*/
	if (scene == -1)				//�л��������̵�
	{
		putimage(0, 0, &img_shop);	//��������ͼƬ
	}
}
void associated()					//���ڴ�������ṹ���еı���
{
	int i;

	/*����������� ÿ��ֵ������������������� ��ǿ����������*/
	person.left_x	= person.center_x - person_width / 2;
	person.left_y	= person.center_y;
	person.right_x	= person.center_x + person_width / 2;
	person.right_y	= person.center_y;
	person.top_x	= person.center_x;
	person.top_y	= person.center_y - person_high / 2;
	person.bottom_x = person.center_x;
	person.bottom_y = person.center_y + person_high / 2;

	/*����������� ÿ��ֵ������������������ ��ǿ����������*/
	for (i = 0; i < monster_num; i++)
	{
		monster[i].left_x	= monster[i].center_x - monster_width / 2;
		monster[i].left_y	= monster[i].center_y;
		monster[i].right_x	= monster[i].center_x + monster_width / 2;
		monster[i].right_y	= monster[i].center_y;
		monster[i].top_x	= monster[i].center_x;
		monster[i].top_y	= monster[i].center_y - monster_high / 2;
		monster[i].bottom_x = monster[i].center_x;
		monster[i].bottom_y = monster[i].center_y - monster_high / 2;
	}
}
void updateWithoutInput()
{
	int i, j;
	G = 1;//�������ٶȳ�ֵ

	/*�ؿ�ͬ��*/
	if (scene != -3 && scene != -2 && scene != 0)//ֻ�ж�������Щ�ؿ�ʱ����ִ�С���||����ʵ�����Ч����
		person.scene = scene;			//������ڵĹؿ�ͬ��

    /*���������겻�ܷ�*/
	if (energy_i <= 0)
		shoes_a = 0;

	/*�ؿ�����ά����ͬ��*/
	if (scene == 1)
		k = 1;
	else if (scene == 2)
		k = 2;
	else
		k = 1;

	/*�ж������Ƿ�վ��ש����*/
	for (i = 0; i < num_stonehigh; i++)
		for (j = 0; j < num_stonewidth; j++)
		{
			//�ж��Ƿ����ש���ϣ�ͨ���ж�������ש��֮�����������,�ж�������ש��֮�������֮��Ĺ�ϵ,ש���״̬��
			if (stone[k][i][j].center_y - person.center_y <= person_high / 2 + stone_high / 2		 &&
				stone[k][i][j].center_y - person.center_y >= (person_high / 2 + stone_high / 2) / 2  &&
				//ͨ���ж�������ש��֮�����������
				person.center_x <= stone[k][i][j].center_x + stone_width / 2 + person_width / 2 - 15 &&
				person.center_x >= stone[k][i][j].center_x - stone_width / 2 - person_width / 2 + 15 &&
				//�ж�������ש��֮�������֮��Ĺ�ϵ
				stone[k][i][j].status != 0  && stone[k][i][j].status != 16 && 
				stone[k][i][j].status != 27 && stone[k][i][j].status != 36
				)
				
			{
				exist_downstone = 1;//�¶˴���ש��
				G = 0;				//�������ٶȱ�Ϊ0
				person.v		= 0;//�ȵ�ש�������ﲻ����
				person.center_y = stone[k][i][j].center_y - person_high / 2 - stone_high / 2;
				//����������ש��ļ��
				break;
			}
		}

	/*�ж��������ʱ�Ƿ��Ϸ���ש��*/
	//����������ʱ�����Ϸ�ͷ������ש�飬�������Ϸ�
	if (shoes_a == -2)
	{
		for (i = 0; i < num_stonehigh; i++)
			for (j = 0; j < num_stonewidth; j++)
			{
				if (person.center_y - stone[k][i][j].center_y <= stone_high - person_high / 2 + stone_high / 2		 &&
					person.center_y - stone[k][i][j].center_y >= (stone_high - person_high / 2 + stone_high / 2) / 2 &&//ͨ���ж�������ש��֮�����������
					person.center_x <= stone[k][i][j].center_x + person_width / 2 + stone_width / 2 - 10			 &&
					person.center_x >= stone[k][i][j].center_x - person_width / 2 - stone_width / 2 + 10			 &&//�ж�������ש��֮�������֮��Ĺ�ϵ
					stone[k][i][j].status != 0 && stone[k][i][j].status != 16 && stone[k][i][j].status != 27 && stone[k][i][j].status != 36)//״̬��Ϊ��
				{
					person.v = 0;	//�ٶ�Ϊ��
					shoes_a  = -1;	//���������ٶȵ��������������Ϊ�㣬�ô���1.����ʱͼƬ����Ϊ��������ͼƬ 2.���ֺ�������£�
					break;
				}
			}
	}

	/*�ж��Ƿ���������*/

	for (i = 0; i < num_stonehigh; i++)
		for (j = 0; j < num_stonewidth; j++)
		{
			//�ж��Ƿ����ש���ϣ�ͨ���ж�������ש��֮�����������,�ж�������ש��֮�������֮��Ĺ�ϵ,ש���״̬��
			if (
				stone[k][i][j].center_y - person.center_y <= person_high / 2 + stone_high / 2		&&
				stone[k][i][j].center_y - person.center_y >= (person_high / 2 + stone_high / 2) / 2 &&
				//ͨ���ж�������ש��֮�����������
				person.center_x <= stone[k][i][j].center_x + stone_width / 2						&&
				person.center_x >= stone[k][i][j].center_x - stone_width / 2  
				//�ж�������ש��֮�������֮��Ĺ�ϵ
				)
			{
				//�����������·���ש��
				if (
					digbf == 1					&& stone[k][i][j].status != 0  &&
					exist_downstone == 1		&& stone[k][i][j].status != 16 &&
					stone[k][i][j].status != 27 && stone[k][i][j].status != 36
					)
				{
					person.center_x = stone[k][i][j].center_x;	//����������ש��d�ĺ��������
					static int speed_2 = 0;						//�������������ڵ��ٶ�  ����״̬�仯����
					if (speed_2 < 60)
						speed_2++;
					else if (speed_2 == 60)
					{
						stone[k][i][j].status++;		//״̬��1
						speed_2 = 0;
					}
					//ש����ʧ
					if (stone[k][i][j].status == 8)
						stone[k][i][j].status = 0;	
					//״̬���99 ����ʯͷ
					if (stone[k][i][j].status == 100)
						stone[k][i][j].status = 99;		
				}
			}
		}

	/*�ж���������Ƿ���ש��  ������*/

	for (i = 0; i < num_stonehigh; i++)
		for (j = 0; j < num_stonewidth; j++)
		{
			if (
				person.center_x - stone[k][i][j].center_x <= stone_width / 2 + person_width / 2			 &&
				person.center_x - stone[k][i][j].center_x >= (stone_width / 2 + person_width / 2) / 2	 &&
				stone[k][i][j].center_y - person.center_y == person_high / 2 - stone_high / 2			 &&
				stone[k][i][j].status != 0 && stone[k][i][j].status != 16 && stone[k][i][j].status != 27 && 
				stone[k][i][j].status != 36
				)
			{
				exist_leftstone = 1;		//��˴���ש��
				if (digleftbf == 1)			//��ʼ������
				{
					person.center_x = stone[k][i][j].center_x + stone_width / 2 + person_width / 2;//����ڹ�λ
					static int speed_3 = 0;	//�������������ڵ��ٶ�
					if (speed_3 < 60)
						speed_3++;
					else if (speed_3 == 60)
					{
						stone[k][i][j].status++;		//״̬��1
						speed_3 = 0;
					}
					if (stone[k][i][j].status == 8)
						stone[k][i][j].status = 0;		//ש����ʧ
					if (stone[k][i][j].status == 100)
						stone[k][i][j].status = 99;		//ʯͷ�ڲ���
				}
			}
		}

	/*�ж������ұ��Ƿ���ש�� ������*/
	for (i = 0; i < num_stonehigh; i++)
		for (j = 0; j < num_stonewidth; j++)
		{
			if (
				stone[k][i][j].center_x - person.center_x <= stone_width / 2 + person_width / 2			 &&
				stone[k][i][j].center_x - person.center_x >= (stone_width / 2 + person_width / 2) / 2	 &&
				stone[k][i][j].center_y - person.center_y == person_high / 2 - stone_high / 2			 &&
				stone[k][i][j].status != 0				  &&	stone[k][i][j].status != 16				 && 
				stone[k][i][j].status != 27				  &&	stone[k][i][j].status != 36
				)
			{
				exist_rightstone = 1;		//�Ҷ˴���ש��
				if (digrightbf == 1)		//��ʼ������
				{
					person.center_x = stone[k][i][j].center_x - stone_width / 2 - person_width / 2;//�ұ��ڹ�λ
					static int speed_3 = 0; //�������������ڵ��ٶ�
					if (speed_3 < 60)
						speed_3++;
					else if (speed_3 == 60)
					{
						stone[k][i][j].status++;	//״̬��1
						speed_3 = 0;
					}
					if (stone[k][i][j].status == 8)
						stone[k][i][j].status = 0;	//ש����ʧ
					if (stone[k][i][j].status == 100)
						stone[k][i][j].status = 99;	//ʯͷ�ڲ���
				}
			}
		}

	/*�ж��������ʱ����Ƿ���ש��*/
	for (i = 0; i < num_stonehigh; i++)
		for (j = 0; j < num_stonewidth; j++)
		{
			if (
				person.left_x == stone[k][i][j].right_x && person.left_y - stone[k][i][j].right_y <= person_high / 2 + stone_high / 2 - 12
				&& person.left_y - stone[k][i][j].right_y >= -person_high / 2 - stone_high / 2 + 12
				&& stone[k][i][j].status != 0 && stone[k][i][j].status != 16 && stone[k][i][j].status != 27 
				&& stone[k][i][j].status != 36 && shoes_a < 0
				)
			{
					exist_flyleftstone = 1;
			}
		}

	/*�ж��������ʱ�ұ��Ƿ���ש��*/
	for (i = 0; i < num_stonehigh; i++)
		for (j = 0; j < num_stonewidth; j++)
		{
			if (
				person.right_x == stone[k][i][j].left_x 
				&& person.right_y - stone[k][i][j].left_y <= person_high / 2 + stone_high / 2 - 12
				&& person.right_y - stone[k][i][j].left_y >= -person_high / 2 - stone_high / 2 + 12
				&& stone[k][i][j].status != 0 
				&& stone[k][i][j].status != 16 
				&& stone[k][i][j].status != 27 
				&& stone[k][i][j].status != 36 
				&& shoes_a < 0
				)
			{
					exist_flyrightstone = 1;
			}
		}

	/*�жϹ�����˶�*/
	int m;
	/*����*/
	for (m = 0; m < monster_num; m++)
		for (i = 0; i < num_stonehigh; i++)
			for (j = 0; j < num_stonewidth; j++)
			{
				if (
					monster[m].center_x - stone[k][i][j].center_x <= stone_width / 2 + monster_width / 2 
					&& monster[m].center_x - stone[k][i][j].center_x >= (stone_width / 2 + monster_width / 2) / 2 
					&& monster[m].center_y - stone[k][i][j].center_y == stone_high / 2 - monster_high / 2 
					&& stone[k][i][j].status != 0 
					&& stone[k][i][j].status != 16 && stone[k][i][j].status != 27 
					&& stone[k][i][j].status != 36)
				{
					monster[m].direction = 0;//��˴���ש��������  
				}
			}
	/*����*/
	for (m = 0; m < monster_num; m++)
		for (i = 0; i < num_stonehigh; i++)
			for (j = 0; j < num_stonewidth; j++)
			{
				if (
					stone[k][i][j].center_x - monster[m].center_x <= stone_width / 2 + monster_width / 2 
					&& stone[k][i][j].center_x - monster[m].center_x >= (stone_width / 2 + monster_width / 2) / 2 
					&& monster[m].center_y - stone[k][i][j].center_y == stone_high / 2 - monster_high / 2 
					&& stone[k][i][j].status != 0 && stone[k][i][j].status != 16 && stone[k][i][j].status != 27 
					&& stone[k][i][j].status != 36
					)
				{
					monster[m].direction = 1;//�Ҷ˴���ש��������   
				}
			}

	/*�����������*/

	static int speed_1 = 0;//��������������ٶ�
	if (speed_1 < 10)
		speed_1++;
	else if (speed_1 == 10)
	{
		person.v = person.v + G + shoes_a;//�ٶȵı仯��
		if (person.v >= 25)//�����趨
			person.v = 25;
		if (person.v <= -12)//�����趨
			person.v = -12;
		person.center_y = person.center_y + person.v;//������ֱ����λ�ñ仯
		speed_1			= 0;
	}

	/*ʰȡ��Ʒ*/

	for (i = 0; i < num_stonehigh; i++)
		for (j = 0; j < num_stonewidth; j++)
		{

			//ʰȡú��
			if (stone[k][i][j].status == 16 
				&& person.center_x < stone[k][i][j].center_x + 10
				&& person.center_x > stone[k][i][j].center_x - 10 
				&& person.center_y < stone[k][i][j].center_y + 40
				&& person.center_y > stone[k][i][j].center_y - 40)
			{
				stone[k][i][j].status = -1;
				score				 += 100;//һ��ú��100��
			}

			//ʰȡͭ��
			if (stone[k][i][j].status == 27 && person.center_x <stone[k][i][j].center_x + 10
				&& person.center_x > stone[k][i][j].center_x - 10 
				&& person.center_y < stone[k][i][j].center_y + 40
				&& person.center_y > stone[k][i][j].center_y - 40)
			{
				stone[k][i][j].status = 0;
				score				 += 500;//һ����300��
			}

			//ʰȡ����
			if (stone[k][i][j].status == 36 && person.center_x < stone[k][i][j].center_x + 10
				&& person.center_x > stone[k][i][j].center_x - 10 
				&& person.center_y < stone[k][i][j].center_y + 40
				&& person.center_y > stone[k][i][j].center_y - 40)
			{
				stone[k][i][j].status = 0;
				score				 += 300;//һ������500��
			}
		}

	/*ú��Ļָ�*/
	static int speed_10[num_scene][num_stonehigh][num_stonewidth] = { 0 };
	for (i = 0; i < num_stonehigh; i++)
		for (j = 0; j < num_stonewidth; j++)
		{
			//ש���״̬��Ϊ��ȫ�����
			if (stone[k][i][j].status == -1)
			{
				speed_10[k][i][j]++;
				//ש��ָ����ٶ�
				if (speed_10[k][i][j] == 4000)
				{
					stone[k][i][j].status = 11;//ֻ�ָܻ�һ��
					speed_10[k][i][j]	  = 0;
				}
			}
		}

	/*����ը��������ը���ı仯*/
	if (put_bomb == 1)
	{
		bomb.center_x = person.center_x;
		bomb.center_y = person.center_y + 10;
		bomb.scene	  = scene;//ը��Ҫ�͹ؿ�һ��
	}
	if (bomb.center_x < 900 && 
		bomb.center_x > 0	&& 
		bomb.center_y < 670 && 
		bomb.center_y > 0)
	{
		static int speed_4 = 0;
		if (speed_4 < 200)//ը���仯�Ŀ���
			speed_4++;
		else if (speed_4 == 200)
		{
			bomb.status++;//״̬��1
			speed_4 = 0;
		}
	}

	/*ը��ը��������ж�*/
	for (i = 0; i < monster_num; i++)
	{
		if (bomb.status >= 6 
			&& bomb.center_x - monster[i].center_x <= bomb_width / 2 + monster_width / 2
			&& bomb.center_x - monster[i].center_x >= -bomb_width / 2 - monster_width / 2 
			&& bomb.center_y - monster[i].center_y <= bomb_high - monster_high + 4
			&& bomb.center_y - monster[i].center_y >= -bomb_high + monster_high - 4)//ը��λ���������λ�÷�Χ���ж�
		{
			score			  = (score + 3000 * monster[i].status);//������������500��
			monster[i].status = 0;								   //��������
		}
	}

	/*�������������Ѫ*/
	for (i = 0; i < monster_num; i++)
	{
		if (person.center_x - monster[i].center_x    <= person_width / 2 + monster_width / 2
			&& person.center_x - monster[i].center_x >= -person_width / 2 - monster_width / 2 
			&& person.center_y - monster[i].center_y <= person_high - monster_high + 4
			&& person.center_y - monster[i].center_y >= -person_high + monster_high - 4)
		{
			oxygen_i = oxygen_i - 0.1;//�������ı仯
		}
	}

	/*ը��ը������ж�*/
	if (bomb.status >= 6 
		&& bomb.center_x - person.center_x <= bomb_width / 2 + person_width / 2 - 4
		&& bomb.center_x - person.center_x >= -bomb_width / 2 - person_width / 2 + 4 
		&& bomb.center_y - person.center_y <= bomb_high / 2 + person_high / 2 - 4
		&& bomb.center_y - person.center_y >= -bomb_high / 2 - person_high / 2 + 4)
	{
		oxygen_i = oxygen_i - 4;//�������ı仯
	}

	/*����������ָ�*/
	if (shoes_a < 0)
	{
		if (energy_i > 0)
			energy_i = energy_i - 0.08 * (5 - person.energy_level); //�������ı仯
	}
	else if (shoes_a == 0)
	{
		energy_i = energy_i + 0.04;									//�������ı仯
	}
	if (energy_i >= 120)
		energy_i = 120;

	/*����������ָ�*/
	if (scene == 1 && person.top_y <= apper_1stone)
	{
		oxygen_i = oxygen_i + 0.04;								//�������ı仯
	}
	if ((scene == 1 && person.top_y > apper_1stone) || scene == 2)
	{
		oxygen_i = oxygen_i - 0.008 * (5 - person.oxygen_level);	//�������ı仯
	}
	if (oxygen_i >= 107)
		oxygen_i = 107;

	/*���������ж�*/
	if (oxygen_i < 0)
	{
		person.status = 0;
		scene = -4; //-4��Ϸ����
		putimage(0, 0, &img_ebg);//��Ϸʧ��
	}

	/*����ʤ���ж�*/
	for (i = 0; i < monster_num; i++)
	{
		if (monster[i].status != 0)
			break;
		scene = -5; //-5��Ϸ�ɹ� 
		putimage(0, 0, &img_success);//��Ϸ�ɹ�
	}

	/*��ʾ����*/
	if (scene == 1 || scene == 2 || scene == -1)
	{
		TCHAR s[10], s1[10], s2[10], s3[10], s4[10], s5[10];
		setbkmode(TRANSPARENT);//����͸��
		_stprintf(s, _T("%d"), score);
		_stprintf(s1, _T("%d"), person.bomb);
		_stprintf(s2, _T("%d"), person.energy_level);
		_stprintf(s3, _T("%d"), person.oxygen_level);
		_stprintf(s4, _T("%d"), person.energy);
		_stprintf(s5, _T("%d"), person.oxygen);
		outtextxy(90, 12, s);
		outtextxy(150, 40, s1);
		outtextxy(150, 65, s2);
		outtextxy(130, 90, s3);
		outtextxy(100, 115, s4);
		outtextxy(100, 140, s5);
		outtextxy(10, 40, _T("ը��������"));
		outtextxy(10, 65, _T("������ȼ���"));
		outtextxy(10, 90, _T("�����ȼ���"));
		outtextxy(10, 115, _T("��������"));
		outtextxy(10, 140, _T("��������"));
		settextstyle(25, 0, _T("����"));
		settextcolor(BLACK);
	}

	/*�����Զ�����*/

	{
		static int speed_9 = 0;
		if (speed_9 < 180)
			speed_9++;
		else if (speed_9 == 180)
		{
			speed_9 = 0;
			score = score + 1;
		}
	}

	/*��Ϸ���Ʊ߽�*/

	if (scene == 1)
	{
		if (person.left_x < 0)			//������߽�
			person.center_x = person_width / 2;
		else if (person.right_x > 900)	//�����ұ߽�
			person.center_x = 900 - person_width / 2;
		else if (person.top_y < 0)		//�����ϱ߽�
			person.center_y = person_high / 2;
	}

	/*�ؿ���Ծ*/

	if (scene == 1 && person.bottom_y > high)	//��һ�ص��ڶ���
	{
		scene = 2;
		person.center_y = -person_width / 2;	//�ؿ��仯ʱ������������֮�仯
	}
	else if (scene == 2 && person.bottom_y < 0)	//�ӵڶ��ط��ص�һ��
	{
		scene = 1;
		person.center_y = high - person_high;
	}
}

//״̬�ı����ͼƬ
void statusChange()
{
	int i, j;
	if (scene == 1 || scene == 2)
	{
		/*�����ﲻ��ʱת������ */
		if (shoes_a == 0 && digbf == 0 && digleftbf == 3 && digrightbf == 3)	//��ֵ��Ϊ��ʼֵʱ��ʱ����ʾ����ͼƬ
		{
			putimage(person.left_x, person.top_y, &img_person_0, NOTSRCERASE);	//������������
			putimage(person.left_x, person.top_y, &img_person_00, SRCINVERT);	//��������ʰ�
			Sleep(1);
		}

		/*����wʱ�������Ϸ�*/
		else if (shoes_a < 0 && flyleftbf == 0 && flyrightbf == 0)
		{
			putimage(person.center_x - shoesperson_width / 2, person.center_y - shoesperson_high / 2, &img_shoes_1, NOTSRCERASE);//�������Ϸɺڰװ�
			putimage(person.center_x - shoesperson_width / 2, person.center_y - shoesperson_high / 2, &img_shoes_2, SRCINVERT);//�������Ϸɲʰ�
			Sleep(1);
		}

		/*����������� ��wa*/
		else if (shoes_a < 0 && flyleftbf == 1)
		{
			if (exist_flyleftstone == 0)				//��߲�����ʯ��
				person.center_x = person.center_x - 1;	//�������������x����
			putimage(person.center_x - shoesperson_width / 2, person.center_y - shoesperson_high / 2, &img_shoes_1, NOTSRCERASE);//�������Ϸɺڰװ�
			putimage(person.center_x - shoesperson_width / 2, person.center_y - shoesperson_high / 2, &img_shoes_2, SRCINVERT);//�������Ϸɲʰ�
			Sleep(1);
		}

		/*�������ҷ��� ��wd*/
		else if (shoes_a < 0 && flyrightbf == 1)
		{
			if (exist_flyrightstone == 0)
				person.center_x = person.center_x + 1;//�������������x����
			putimage(person.center_x - shoesperson_width / 2, person.center_y - shoesperson_high / 2, &img_shoes_1, NOTSRCERASE);//�������Ϸɺڰװ�
			putimage(person.center_x - shoesperson_width / 2, person.center_y - shoesperson_high / 2, &img_shoes_2, SRCINVERT);//�������Ϸɲʰ�
			Sleep(1);
		}

		/*����ת��Ϊ�����ڵ�ͼƬ*/
		else if (digbf == 1)
		{
			putimage(person.center_x - digdownperson_width / 2, person.center_y - digdownperson_high / 2, &img_digdownperson_1, NOTSRCERASE);//���������ںڰ�
			putimage(person.center_x - digdownperson_width / 2, person.center_y - digdownperson_high / 2, &img_digdownperson_2, SRCINVERT);//���������ڲ�
			Sleep(1);
		}

		/*�������*/
		static int speed_8;
		if (speed_8 < 50)
			speed_8++;
		if (digleftbf == 0)
		{
			if (speed_8 == 50)
			{
				left_i++;
				person.center_x = person.center_x - 15;//�������������x����
				speed_8 = 0;
			}
			putimage(person.left_x, person.top_y, person_width, person_high, &img_person_1, left_i * person_width, 0, NOTSRCERASE);//���������ߵĺڰ�ͼƬ
			putimage(person.left_x, person.top_y, person_width, person_high, &img_person_2, left_i * person_width, 0, SRCINVERT);//���������ߵĲ�ͼ
			if (left_i == 3)
				left_i = 0;
		}

		/*��������*/
		else if (digleftbf == 1)
		{
			putimage(person.center_x - digleftperson_width / 2, person.center_y - digleftperson_high / 2, &img_digleftperson_1, NOTSRCERASE);//���������ںڰ�
			putimage(person.center_x - digleftperson_width / 2, person.center_y - digleftperson_high / 2, &img_digleftperson_2, SRCINVERT);//���������ڲ�
			Sleep(1);
		}

		/*�ұ�����*/
		static int speed_7;
		if (speed_7 < 50)
			speed_7++;
		if (digrightbf == 0)
		{
			if (speed_7 == 50)
			{
				person.center_x = person.center_x + 15;//�������������x����
				right_i++;							   //������ͼ
				speed_7 = 0;
			}
			putimage(person.left_x, person.top_y, person_width, person_high, &img_person_1, right_i * person_width, person_high, NOTSRCERASE);//���������ߵĺڰ�ͼƬ
			putimage(person.left_x, person.top_y, person_width, person_high, &img_person_2, right_i * person_width, person_high, SRCINVERT);//���������ߵĲ�ͼ
			if (right_i == 3)
				right_i = 0;
		}

		/*��������*/
		else if (digrightbf == 1)
		{
			putimage(person.center_x - digrightperson_width / 2, person.center_y - digrightperson_high / 2, &img_digrightperson_1, NOTSRCERASE);//���������ںڰ�
			putimage(person.center_x - digrightperson_width / 2, person.center_y - digrightperson_high / 2, &img_digrightperson_2, SRCINVERT);//���������ڲ�
			Sleep(1);
		}
	}

	/*ը���仯*/
	if (bomb.status <= 5 && scene == bomb.scene)
	{

		putimage(bomb.center_x - 32, bomb.center_y - 32, &img_bwbomb_1, NOTSRCERASE);//����ը������
		putimage(bomb.center_x - 32, bomb.center_y - 32, &img_bomb_1, SRCINVERT);	 //����ը����ͼ
	}
	else if (bomb.status >= 6)
	{
		if (scene == bomb.scene)
		{
			putimage(bomb.center_x - 32, bomb.center_y - 32, bomb_width, bomb_high, &img_bwbomb_boom, boom_i * bomb_width, 0, NOTSRCERASE);//����ը���ĺڰ�ͼƬ
			putimage(bomb.center_x - 32, bomb.center_y - 32, bomb_width, bomb_high, &img_bomb_boom, boom_i * bomb_width, 0, SRCINVERT);//����ը���Ĳ�ͼ
		}
		boom_i++;
		Sleep(100);
		if (boom_i == 8)
		{
			bomb.status = 0;
			bomb.center_x = -1000;
			bomb.center_y = -1000;
			boom_i = 0;
			person.bomb--;//��һ��ը��
		}
	}

	/*��������*/
	static int speed_5[monster_num] = { 0 }, speed_6[monster_num] = { 0 };
	if (scene == 2)
	{
		for (i = 0; i < monster_num; i++)
		{
			if (speed_5[i] < 60)//�������ߵ��ٶ�
				speed_5[i]++;
			if (speed_6[i] < 60)
				speed_6[i]++;
			if (monster[i].direction == 1 && monster[i].status == 1)
			{
				if (speed_5[i] == 60)
				{
					monster[i].center_x = monster[i].center_x - 10;//�������������x����
					mleft_i[i]++;
					speed_5[i] = 0;
				}
				putimage(monster[i].left_x, monster[i].top_y, monster_width, monster_high, &img_monsterrun_00, mleft_i[i] * monster_width, monster_high, NOTSRCERASE);//���ù�����·�ĺڰ�ͼƬ
				putimage(monster[i].left_x, monster[i].top_y, monster_width, monster_high, &img_monsterrun_0, mleft_i[i] * monster_width, monster_high, SRCINVERT);//���ù�����·�Ĳ�ͼ

				if (mleft_i[i] == 3)
					mleft_i[i] = 0;
			}
			else if (monster[i].direction == 0 && monster[i].status == 1)
			{
				if (speed_6[i] == 60)
				{
					monster[i].center_x = monster[i].center_x + 10;//�������������x����
					mright_i[i]++;
					speed_6[i] = 0;
				}
				putimage(monster[i].left_x, monster[i].top_y, monster_width, monster_high, &img_monsterrun_00, mright_i[i] * monster_width, 0, NOTSRCERASE);//���ù�����·�ĺڰ�ͼƬ
				putimage(monster[i].left_x, monster[i].top_y, monster_width, monster_high, &img_monsterrun_0, mright_i[i] * monster_width, 0, SRCINVERT);//���ù�����·�Ĳ�ͼ

				if (mright_i[i] == 3)
					mright_i[i] = 0;
			}
		}
	}
	FlushBatchDraw();

	/*�ع�ԭֵ���� �·����Ʋ��ֿ��Ըı�ֵ*/
	shoes_a = 0;	//�����ٶȹ�Ϊԭֵ����w�ı䣩
	digbf = 0;		//�����ڻع�ԭֵ����s�ı䣩
	digleftbf = 3;	//�����ڻع�ԭֵ����a�ı䣩
	digrightbf = 3;	//�����ڻع�ԭֵ����d�ı䣩
	flyleftbf = 0;	//����ɻع�ԭֵ
	flyrightbf = 0;	//���ҷɻع�ԭֵ
	put_bomb = 0;	//������ը��
}

void updateWithInput()
{

	/*����������ʱ���� "�����������" ������Ϸ*/
	if (MouseHit())
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONUP && scene == 0)
		{
			//������Χ�ж�
			if (m.x <= 563 && m.x >= 316 && 
				m.y <= 602 && m.y >= 570)
			{
				scene = -2;
			}
		}
	}

	if (scene == 1 || scene == 2)//��һ��
	{
		//�������a���·���ʯ�飬���ƶ�
		if ((GetAsyncKeyState(0x41) & 0x8000) && 
			exist_leftstone == 0 && exist_downstone == 1)
		{
			digleftbf = 0;//��ʾ������
		}

		//�������a������
		if ((GetAsyncKeyState(0x41) & 0x8000) && 
			exist_leftstone == 1)
		{
			digleftbf = 1;//��ʾ����
		}

		//�������a���·�ûʯ�飬����ƶ�
		if ((GetAsyncKeyState(0x41) & 0x8000) && 
			exist_leftstone == 0 && exist_downstone == 0)
		{
			flyleftbf = 1;
		}

		//�������d���·���ʯ�飬���ƶ�
		if ((GetAsyncKeyState(0x44) & 0x8000) && 
			exist_rightstone == 0 && exist_downstone == 1)
		{
			digrightbf = 0;//��ʾ������
		}

		//�������d������
		if ((GetAsyncKeyState(0x44) & 0x8000) && 
			exist_rightstone == 1)
		{
			digrightbf = 1;//��ʾ����
		}

		//�������d���·�ûʯ�飬���ƶ�
		if ((GetAsyncKeyState(0x44) & 0x8000) && 
			exist_rightstone == 0 && exist_downstone == 0)
		{
			flyrightbf = 1;
		}

		//��w
		if (GetAsyncKeyState(0x57) & 0x8000)	
		{
			shoes_a = -2;
		}

		//��s��
		if (GetAsyncKeyState(0x53) & 0x8000 && exist_downstone == 1)
		{
			digbf = 1;//��ʾ������
		}

		//���ո�����̵�
		if (GetAsyncKeyState(0x20) & 0x8000 && 
			person.bottom_y == apper_1stone && 
			person.center_x < 570 && 
			person.center_x > 500)
		{
			scene = -1;//�����̵�
		}

		//��j����ը��
		if (GetAsyncKeyState(0x4A) & 0x8000 && 
			person.bomb > 0)
		{
			put_bomb = 1;
		}

		//��kʹ��������
		if (GetAsyncKeyState(0x4B) & 0x8000 && 
			person.energy > 0)
		{
			if (energy_i < 120)
			{
				energy_i += 80;
				person.energy--;
			}
		}

		//��lʹ��������
		if (GetAsyncKeyState(0x4C) & 0x8000 && 
			person.oxygen > 0)
		{
			if (oxygen_i < 107)
			{
				person.oxygen--;
				oxygen_i += 60;
			}
		}
	}

	//��Ϸ��ͣ��esc��
	if (GetAsyncKeyState(0x1B) & 0x8000 && 
		(scene == 1 || scene == 2 || scene == -1))
	{
		scene = -3;//��Ϸ��ͣ����
	}

	//�̵�
	if (scene == -1)
	{
		char input;
		if (kbhit())
		{
			input = getch();
			if (input == 'q')
				scene = 1;					 //�˳��̵�
			if (input == '1' && score >= 500)//����ը��
			{
				person.bomb++;
				score = score - 500;
			}
			if (input == '2' && score >= 500)//���������ȼ�
			{
				score = score - 500 * person.energy_level;
				person.energy_level++;
			}
			if (input == '3' && score >= 500)//���������ȼ�
			{
				score = score - 500 * person.oxygen_level;
				person.oxygen_level++;
			}
			if (input == '4' && score >= 200)//����������
			{
				score = score - 200;
				person.oxygen += 1;
			}
			if (input == '5' && score >= 200)//����������
			{
				score = score - 200;
				person.energy += 1;
			}
		}
	}

	/*�ع�ԭֵ���� �ع������ƶ��жϵ�ֵ*/
	exist_leftstone = 0;
	exist_rightstone = 0;
	exist_downstone = 0;
	exist_flyleftstone = 0;
	exist_flyrightstone = 0;
}

void startMenu()		//��ʼ�˵�����
{

	setfillcolor(BLACK);//����Ϊ��ɫ
	fillrectangle(0, 0, 900, 670);
	settextcolor(WHITE);
	settextstyle(50, 0, _T("����"));
	outtextxy(width*0.3, high*0.2, _T("1 ����Ϸ"));
	outtextxy(width*0.3, high*0.3, _T("2 ��ȡ��Ϸ�浵"));
	outtextxy(width*0.3, high*0.4, _T("3 �˳�"));
	FlushBatchDraw();
	Sleep(2);
	char input;

	//�ж��Ƿ�������
	if (kbhit())			
	{
		//�����û��Ĳ�ͬ�������ƶ�����������س�
		input = getch();	
		if (input == '1')
			scene = 1;
		else if (input == '2')
		{
			readRecordFile();
		}
		else if (input == '3')
		{
			exit(0);
		}
	}
}

//��Ϸ��ͣ��˵����棬һ�㰴ESC���������ý���
void pauseMenu() 
{
	setfillcolor(BLACK);  //����Ϊ��ɫ
	fillrectangle(0, 0, 900, 670);
	settextcolor(WHITE);
	settextstyle(50, 0, _T("����"));
	outtextxy(width*0.3, high*0.2, _T("1 ������Ϸ"));
	outtextxy(width*0.3, high*0.3, _T("2 ���浵��"));
	outtextxy(width*0.3, high*0.4, _T("3 �˳�"));
	FlushBatchDraw();
	Sleep(2);
	char input;
	if (kbhit())		  //�ж��Ƿ�������
	{
		input = getch();  //�����û��Ĳ�ͬ�������ƶ�����������س�
		if (input == '1')
			scene = person.scene;
		else if (input == '2')
		{
			writeRecordFile();
		}
		else if (input == '3')
		{
			exit(0);
		}
	}
}

// �ļ���������ȡ��Ϸ�浵
void readRecordFile()
{
	FILE *fp;
	int i, j, k;
	fp = fopen(".\\gameRecord.dat", "r");
	//
	fscanf(fp, "%f %f %d %d %d", &person.center_x, &person.center_y, &person.scene, &score, &scene);
	for (k = 1; k < 3; k++)
		for (i = 0; i < num_stonehigh; i++)
			for (j = 0; j < num_stonewidth; j++)
			{
				fscanf(fp, " %d", &stone[k][i][j].status);
			}

	scene = person.scene;
	fclose(fp);
}

// �ļ�������д����Ϸ�浵
void writeRecordFile()
{
	FILE *fp;
	int i, j, k;
	fp = fopen(".\\gameRecord.dat", "w");
	//
	fprintf(fp, "%f %f %d %d %d", person.center_x, person.center_y, person.scene, score, scene);
	for (k = 1; k < 3; k++)
		for (i = 0; i < num_stonehigh; i++)
			for (j = 0; j < num_stonewidth; j++)
			{
				fprintf(fp, " %d", stone[k][i][j].status);
			}
	scene = person.scene;
	fclose(fp);
}

//��Ϸ��������
void gameOver()
{
	EndBatchDraw();
	getch();
	closegraph();
}