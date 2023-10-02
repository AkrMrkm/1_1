//==========================
//�o�������X�g����
//==========================
//2023/10/02/16:00
//�쐬��:����P

#include <iostream>
#include <fstream>
#include <string>
#include "doubleList.h"

int main() 
{
	std::ifstream inputFile("Scores.txt"); //�t�@�C���ǂݍ���
	DoubleList playersList;

	if (inputFile.is_open())  //�t�@�C���ǂݍ��ݐ���
	{
		std::cerr << "�t�@�C���̓ǂݍ��݂ɐ������܂����B" << std::endl;

		// �t�@�C������ǂݍ��񂾒l���i�[����ϐ�
		int score;
		std::string name;

		// �t�@�C������f�[�^��ǂݍ���Ń��X�g�ɒǉ�
		while (inputFile >> score >> name)
		{
			playersList.Add(score, name);
		}

		// �t�@�C�������
		inputFile.close();
		
		//���X�g�\��
		playersList.Draw();

	}
	else // �t�@�C���ǂݍ��ݎ��s
	{
		std::cerr << "�t�@�C�����J���܂���B" << std::endl;
	}

	getchar();
	return 0;
}