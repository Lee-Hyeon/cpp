#pragma once
void shuffle(int a[], int num)
{
	int iTemp, idx1, idx2;
	for (int i = 0; i < num; i++)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = a[idx1];
		a[idx1] = a[idx2];
		a[idx2] = iTemp;
	}

	return;
}