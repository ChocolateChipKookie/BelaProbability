﻿// BelaZvanja.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>

/*
 * Najvisa 2 bita(3. i 4.) predstavljaju boju
 *		Boja je nebitna, osim ako se radi o adutu koji cemo oznaciti s 00
 * Najniza 3 bita(0., 1., 2.) predstavljaju kartu
 *		0 - 7
 *		1 - 8
 *		2 - 9
 *		3 - 10
 *		4 - Decko
 *		5 - Dama
 *		6 - Kralj
 *		7 - As
 */

int zvanje(int* arr)
{
	int result{ 0 };
	int numberOfCards[8]{ 0 };
	int numberPerColor[4]{ 0 };

	bool damaAdut{false};
	bool kraljAdut{false};

	for (int i = 0; i < 8; i++)
	{
		numberOfCards[arr[i] % 8]++;
		numberPerColor[arr[i] >> 3]++;

		if (arr[i] == 5)damaAdut = true;
		else if (arr[i] == 6)kraljAdut = true;

	}

	//Brojanje cetvorka
	if(numberOfCards[4]==4)result+=200;
	if (numberOfCards[2] == 4)result += 150;
	if (numberOfCards[3] == 4 ||
		numberOfCards[5] == 4 ||
		numberOfCards[6] == 4 ||
		numberOfCards[7] == 4
		)result += 100;
	
	//Brojanje nizova
	int uNizu{0};

	for (int i = 0; i < 6;)
	{
		if (i < 2 && 
			arr[i] >> 3 == arr[i + 1] >> 3 && arr[i] + 1 == arr[i + 1] &&
			arr[i] >> 3 == arr[i + 2] >> 3 && arr[i] + 2 == arr[i + 2] &&
			arr[i] >> 3 == arr[i + 3] >> 3 && arr[i] + 3 == arr[i + 3] &&
			arr[i] >> 3 == arr[i + 4] >> 3 && arr[i] + 4 == arr[i + 4] &&
			arr[i] >> 3 == arr[i + 5] >> 3 && arr[i] + 5 == arr[i + 5] &&
			arr[i] >> 3 == arr[i + 6] >> 3 && arr[i] + 6 == arr[i + 6]
			)
		{
			result += 100;
			i += 7;
		}
		else if (i < 3 &&
			arr[i] >> 3 == arr[i + 1] >> 3 && arr[i] + 1 == arr[i + 1] &&
			arr[i] >> 3 == arr[i + 2] >> 3 && arr[i] + 2 == arr[i + 2] &&
			arr[i] >> 3 == arr[i + 3] >> 3 && arr[i] + 3 == arr[i + 3] &&
			arr[i] >> 3 == arr[i + 4] >> 3 && arr[i] + 4 == arr[i + 4] &&
			arr[i] >> 3 == arr[i + 5] >> 3 && arr[i] + 5 == arr[i + 5]
			)
		{
			result += 100;
			i += 6;
		}
		else if (i < 4 &&
			arr[i] >> 3 == arr[i + 1] >> 3 && arr[i] + 1 == arr[i + 1] &&
			arr[i] >> 3 == arr[i + 2] >> 3 && arr[i] + 2 == arr[i + 2] &&
			arr[i] >> 3 == arr[i + 3] >> 3 && arr[i] + 3 == arr[i + 3] &&
			arr[i] >> 3 == arr[i + 4] >> 3 && arr[i] + 4 == arr[i + 4]
			)
		{
			result += 100;
			i += 5;
		}
		else if (i < 5 &&
			arr[i] >> 3 == arr[i + 1] >> 3 && arr[i] + 1 == arr[i + 1] &&
			arr[i] >> 3 == arr[i + 2] >> 3 && arr[i] + 2 == arr[i + 2] &&
			arr[i] >> 3 == arr[i + 3] >> 3 && arr[i] + 3 == arr[i + 3]
			)
		{
			result += 50;
			i += 4;
		}
		else if (i < 6 &&
			arr[i] >> 3 == arr[i + 1] >> 3 && arr[i] + 1 == arr[i + 1] &&
			arr[i] >> 3 == arr[i + 2] >> 3 && arr[i] + 2 == arr[i + 2]
			)
		{
			result += 20;
			i += 3;
		}
		else
		{
			i++;
		}
	}

	//Belot
	for (int i = 0; i < 4; i++)
	{
		if (numberPerColor[i] == 8)return 1001;
	}

	//Bela
	if (damaAdut && kraljAdut) result += 20;

	return result;
}

int sumArray(int *arr, int len)
{
	int result{0};
	for(int i =0; i<len;i++)
	{
		result += arr[i];
	}
	return result;
}

int main()
{
	int results[24]{ 0 };
	int i{ 0 }, j{ 0 };
	const clock_t begin_time = clock();
	
	for (int i0 = 0; i0 < 25; i0++)
	{
		for (int i1 = i0 + 1; i1 < 26; i1++)
		{
			for (int i2 = i1 + 1; i2 < 27; i2++)
			{
				for (int i3 = i2 + 1; i3 < 28; i3++)
				{
					for (int i4 = i3 + 1; i4 < 29; i4++)
					{
						for (int i5 = i4 + 1; i5 < 30; i5++)
						{
							for (int i6 = i5 + 1; i6 < 31; i6++)
							{
								for (int i7 = i6 + 1; i7 < 32; i7++)
								{
									int arr[]{i0, i1, i2, i3, i4, i5, i6, i7};

									switch(int rez = zvanje(arr))
									{
									case 0:
										results[0]++;
										break;
									case 20:
										results[1]++;
										break;
									case 40:
										results[2]++;
										break;
									case 50:
										results[3]++;
										break;
									case 60:
										results[4]++;
										break;
									case 70:
										results[5]++;
										break;
									case 90:
										results[6]++;
										break;
									case 100:
										results[7]++;
										break;
									case 120:
										results[8]++;
										break;
									case 140:
										results[9]++;
										break;
									case 150:
										results[10]++;
										break;
									case 160:
										results[11]++;
										break;
									case 170:
										results[12]++;
										break;
									case 190:
										results[13]++;
										break;
									case 200:
										results[14]++;
										break;
									case 220:
										results[15]++;
										break;
									case 240:
										results[16]++;
										break;
									case 250:
										results[17]++;
										break;
									case 260:
										results[18]++;
										break;
									case 270:
										results[19]++;
										break;
									case 300:
										results[20]++;
										break;
									case 320:
										results[21]++;
										break;
									case 350:
										results[22]++;
										break;
									case 1001:
										results[23]++;
										break;
									default:
										std::cout << rez<<std::endl;
										break;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	std::cout << std::fixed << std::setprecision(13);
	std::cout << "0: \t" << results[0] << "\t" << static_cast<double>(results[0]) / 10518300. << std::endl;
	std::cout << "20: \t" << results[1] << "\t" << static_cast<double>(results[1]) / 10518300. << std::endl;
	std::cout << "40: \t" << results[2] << "\t" << static_cast<double>(results[2]) / 10518300. << std::endl;
	std::cout << "50: \t" << results[3] << "\t" << static_cast<double>(results[3]) / 10518300. << std::endl;
	std::cout << "60: \t" << results[4] << "\t" << static_cast<double>(results[4]) / 10518300. << std::endl;
	std::cout << "70: \t" << results[5] << "\t" << static_cast<double>(results[5]) / 10518300. << std::endl;
	std::cout << "90: \t" << results[6] << "\t" << static_cast<double>(results[6]) / 10518300. << std::endl;
	std::cout << "100: \t" << results[7] << "\t" << static_cast<double>(results[7]) / 10518300. << std::endl;
	std::cout << "120: \t" << results[8] << "\t" << static_cast<double>(results[8]) / 10518300. << std::endl;
	std::cout << "140: \t" << results[9] << "\t" << static_cast<double>(results[9]) / 10518300. << std::endl;
	std::cout << "150: \t" << results[10] << "\t" << static_cast<double>(results[10]) / 10518300. << std::endl;
	std::cout << "160: \t" << results[11] << "\t" << static_cast<double>(results[11]) / 10518300. << std::endl;
	std::cout << "170: \t" << results[12] << "\t" << static_cast<double>(results[12]) / 10518300. << std::endl;
	std::cout << "190: \t" << results[13] << "\t" << static_cast<double>(results[13]) / 10518300. << std::endl;
	std::cout << "200: \t" << results[14] << "\t" << static_cast<double>(results[14]) / 10518300. << std::endl;
	std::cout << "220: \t" << results[15] << "\t" << static_cast<double>(results[15]) / 10518300. << std::endl;
	std::cout << "240: \t" << results[16] << "\t" << static_cast<double>(results[16]) / 10518300. << std::endl;
	std::cout << "250: \t" << results[17] << "\t" << static_cast<double>(results[17]) / 10518300. << std::endl;
	std::cout << "260: \t" << results[18] << "\t" << static_cast<double>(results[18]) / 10518300. << std::endl;
	std::cout << "270: \t" << results[19] << "\t" << static_cast<double>(results[19]) / 10518300. << std::endl;
	std::cout << "300: \t" << results[20] << "\t" << static_cast<double>(results[20]) / 10518300. << std::endl;
	std::cout << "320: \t" << results[21] << "\t" << static_cast<double>(results[21]) / 10518300. << std::endl;
	std::cout << "350: \t" << results[22] << "\t" << static_cast<double>(results[22]) / 10518300. << std::endl;
	std::cout << "1001: \t" << results[23] <<"\t" << static_cast<double>(results[23]) / 10518300. << std::endl;

	std::cout << "SUM: \t" << sumArray(results, 24) << "\t" << static_cast<double>(sumArray(results, 24)) / 10518300. << std::endl;

	std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC;
	std::cin >> i;
	return 0;
}

