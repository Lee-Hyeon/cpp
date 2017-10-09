#include <iostream>
#include <time.h>

using namespace std;

#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK,
	BATTLE_END
};

enum ITEM_TYPE
{
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};

enum STORE_MENU
{
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};

struct _tagItem
{
	char strName[NAME_SIZE];
	char strTypeName[NAME_SIZE];
	ITEM_TYPE eType;
	int iMin;
	int iMax;
	int iPrice;
	int iSell;
	char strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory
{
	_tagItem titem[INVENTORY_MAX];
	int iItemCount;
	int iGold;
};

struct _tagPlayer
{
	char strName[NAME_SIZE];
	char strJobName[NAME_SIZE];
	JOB	 eJob;
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iExp;
	int iLevel;
	_tagInventory tInventory;
};

struct _tagMonster
{
	char strName[NAME_SIZE];
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iLevel;
	int iExpDrop;
	int iGoldDropMin;
	int iGoldDropMax;
};

int main()
{
	srand((unsigned int)time(0));

	_tagPlayer tPlayer = {};
	cout << "Name : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. knight" << endl;
		cout << "2. Archer" << endl;
		cout << "3. Wizard" << endl;
		cout << "Select your Job : ";
		cin >> iJob;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
	 }

	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.eJob = (JOB)iJob;
	tPlayer.tInventory.iGold = 10000;

	switch (tPlayer.eJob)
	{
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "Knight");
		tPlayer.iAttackMin = 5;
		tPlayer.iAttackMax = 10;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHPMax = 500;
		tPlayer.iHP = 500;
		tPlayer.iMPMax = 100;
		tPlayer.iMP = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "Archer");
		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMax = 15;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 15;
		tPlayer.iHPMax = 400;
		tPlayer.iHP = 400;
		tPlayer.iMPMax = 200;
		tPlayer.iMP = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "Wizard");
		tPlayer.iAttackMax = 20;
		tPlayer.iAttackMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;
		tPlayer.iHPMax = 300;
		tPlayer.iHP = 300;
		tPlayer.iMPMax = 300;
		tPlayer.iMP = 300;
		break;
	}

	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	strcpy_s(tMonsterArr[0].strName, "Goblin");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExpDrop = 1000;
	tMonsterArr[0].iGoldDropMin = 500;
	tMonsterArr[0].iGoldDropMax = 1500;

	strcpy_s(tMonsterArr[1].strName, "Troll");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExpDrop = 7000;
	tMonsterArr[1].iGoldDropMin = 600;
	tMonsterArr[1].iGoldDropMax = 8000;

	strcpy_s(tMonsterArr[2].strName, "Dragon");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExpDrop = 30000;
	tMonsterArr[2].iGoldDropMin = 20000;
	tMonsterArr[2].iGoldDropMax = 50000;

	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};


	while (1)
	{
		system("cls");
		cout << "1. map" << endl;
		cout << "2. shop" << endl;
		cout << "3. inventory" << endl;
		cout << "4. exit" << endl;
		cout << "Select Menu : ";
		int iMenu;
		cin >> iMenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_MAP:
			while (1)
			{
				system("cls");
				cout << "1. easy" << endl;
				cout << "2. normal" << endl;
				cout << "3. hard" << endl;
				cout << "4. return to main menu" << endl;
				cout << "Select menu : ";
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				if (iMenu == MT_BACK)
					break;

				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (1)
				{
					system("cls");
					switch (iMenu)
					{
					case MT_EASY:
							break;
					case MT_NORMAL:
							break;
					case MT_HARD:
						break;
					}
					cout << "===================+++ Player +++===================" << endl;
					cout << "Name : " << tPlayer.strName << "\tJob : " << tPlayer.strJobName << endl;
					cout << "Level : " << tPlayer.iLevel << "\tExp : " << tPlayer.iExp << endl;
					cout << "Attact : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax << "\tArmor : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
					cout << "HP : " << tPlayer.iHP << " / " << tPlayer.iHPMax << "\tMP : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

					cout << "===================+++ Monster +++===================" << endl;
					cout << "Name : " << tMonster.strName << "Level : " << tMonster.iLevel << endl;
					cout << "Attact : " << tMonster.iAttackMin << " - " << tMonster.iAttackMax << "\tArmor : " << tMonster.iArmorMin << " - " << tMonster.iArmorMax << endl;
					cout << "HP : " << tMonster.iHP << " / " << tMonster.iHPMax << "\tMP : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "Exp Drop : " << tMonster.iExpDrop << "\tGold Drop : " << tMonster.iGoldDropMin << " - " << tMonster.iGoldDropMax << endl;

					cout << "1. Attack" << endl;
					cout << "2. Run Away" << endl;
					cout << "Select Menu : ";
					cin >> iMenu;

					if (cin.fail())
					{
						cin.ignore();
						cin.clear(1024, '\n');
						continue;
					}

					else if (iMenu == BATTLE_BACK)
						break;

					switch (iMenu)
					{
					case BATTLE_ATTACK:
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin) + tPlayer.iAttackMin;
						int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin) + tMonster.iArmorMin;
						int iDamage = iAttack - iArmor;
						iDamage = iDamage < 1 ? iDamage = 1 : iDamage;
						tMonster.iHP -= iDamage;

						cout << tPlayer.strName << " dealed " << iDamage << " damage to " << tMonster.strName << "." << endl;

						if (tMonster.iHP <= 0)
						{
							cout << tPlayer.strName << " killed " << tMonster.strName << "." << endl;

							tPlayer.iExp += tMonster.iExpDrop;
							int iGold = rand() % (tMonster.iGoldDropMax - tMonster.iGoldDropMin) + tMonster.iGoldDropMin;
							tPlayer.tInventory.iGold += iGold;

							cout << "Player gained " << tMonster.iExpDrop << " Exp" << endl;
							cout << "Player gained " << iGold << " Gold" << endl;

							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;
							system("pause");
							break;
						}

						iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin) + tMonster.iAttackMin;
						iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin) + tPlayer.iArmorMin;
						iDamage = iAttack - iArmor;
						iDamage = iDamage < 1 ? iDamage = 1 : iDamage;
						tPlayer.iHP -= iDamage;

						cout << tMonster.strName << " dealed " << iDamage << " damage to " << tPlayer.strName << "." << endl;

						if (tPlayer.iHP <= 0)
						{
							cout << tPlayer.strName << " is killed by" << tMonster.strName << "." << endl;
							int iGoldDrop = tPlayer.tInventory.iGold *0.1f;
							int iExpDrop = tPlayer.iExp *0.1f;

							tPlayer.iExp -= iExpDrop;
							tPlayer.tInventory.iGold -= iGoldDrop;

							cout << "Player lost " << iExpDrop << " Exp." << endl;
							cout << "Player lost " << iGoldDrop << " Gold." << endl;

							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
						}

						system("pause");
						break;

					}
				}
			}
			break;
		case MM_STORE:
			while (1)
			{
				system("cls");
				cout << "1. Weapon shop" << endl;
				cout << "2. Armor shop" << endl;
				cout << "3. Back to Menu" << endl;
				cout << "Select : ";
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				else if (iMenu == SM_BACK)
					break;

				switch (iMenu)
				{
				case SM_WEAPON:
					while (1)
					{
						system("cls")

					}
					break;
				case SM_ARMOR:
					break;
				}
			}
			break;
		case MM_INVENTORY:
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
	}

	return 0;
}